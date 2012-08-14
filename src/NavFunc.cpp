#include "NavFunc.h"
#include "wx/math.h"

//#include <string>
double toRad (double degree) {
  return degree * M_PI / 180;
}

double toDeg (double radians) {
  return radians * 180 / M_PI;
}

double sqr (double sqr2) {
  return sqr2*sqr2;
}

double max ( const double a, const double b ) {
  return (a<b)?b:a;     // or: return comp(a,b)?b:a; for the comp version
}

double min ( double a, double b ) {
  return !(b<a)?a:b;     // or: return !comp(b,a)?a:b; for the comp version
}

/*
Another potential implementation problem is that the arguments of asin and/or acos may, because of rounding error,
exceed one in magnitude. With perfect arithmetic this can't happen. You may need to use "safe" versions of asin and acos on the lines of:
*/
double asin_safe(double x){return asin(max(-1,min(x,1)));}
double acos_safe(double x){return acos(max(-1,min(x,1)));}

/*
Note on the mod function. This appears to be implemented differently in different languages, with differing conventions on whether
the sign of the result follows the sign of the divisor or the dividend. (We want the sign to follow the divisor or be Euclidean.
C's fmod and Java's % do not work.) In this document, Mod(y,x) is the remainder on dividing y by x and always lies in the range 0 <=mod <x.
For instance: mod(2.3,2.)=0.3 and mod(-2.3,2.)=1.7
*/
double mod(double y, double x){
    double mod=y - x * (int)(y/x);
    if ( mod < 0) mod = mod + x;
    return mod;
}

//convert radians to NM
double radtoNM(double distance_radians){
return((180*60)/M_PI)*distance_radians;
}
//convert NM to radians
double NMtorad(double distance_NM){
return (M_PI/(180*60))*distance_NM;
}


// convert metres to NM
double mtoNM(double metres){
return metres/1852;
}

// convert NM to metres
double NMtom(double NM){
return NM*1852;
}


/****************************************************************************/
/* Convert dd mm'ss.s" (DMS-Format) to degrees.                             */
/****************************************************************************/

double fromDMStodouble(char *dms)
{
    int d = 0, m = 0;
    double s = 0.0;
    char buf[20];

    buf[0] = '\0';

    sscanf(dms, "%d%[ ]%d%[ ']%lf%[ \"NSWEnswe]", &d, buf, &m, buf, &s, buf);

    s = (double) (std::abs(d)) + ((double) m + s / 60.0) / 60.0;

    if (d >= 0 && strpbrk(buf, "SWsw") == NULL)
      return s;
    else
      return -s;
}

/****************************************************************************/
/* Convert degrees to dd mm'ss.s" (DMS-Format)                              */
/****************************************************************************/
void doubletoDMS(double a, char *bufp, int bufplen)
{
    short neg = 0;
    int d, m, s;
    long n;

    if (a < 0.0) {
      a = -a;
      neg = 1;
    }
    d = (int) a;
    n = (long) ((a - (double) d) * 36000.0);

    m = n / 600;
    s = n % 600;

    if (neg)
      d = -d;

    sprintf(bufp, "%d%02d'%02d.%01d\"", d, m, s / 10, s % 10);
    return;
}


/**
 * Calculates geodetic distance between two points specified by latitude/longitude using
 * Vincenty inverse formula for ellipsoids
 *
 * ->   double lat1, lon1: first point in decimal degrees
 * ->   double lat2, lon2: second point in decimal degrees
 * <-   double dist: distance along bearing in nautical miles
 * <-   double inital, final bearing in decimal degrees
 */


bool DistVincenty(double lat1, double lon1, double lat2, double lon2, double *dist, double *fwdAz, double *revAz){
    double L = toRad(lon2) - toRad(lon1);
    double U1 = atan((1-Flattening()) * tan(toRad(lat1)));
    double U2 = atan((1-Flattening()) * tan(toRad(lat2)));

    double sinU1 = sin(U1);
    double cosU1 = cos(U1);
    double sinU2 = sin(U2);
    double cosU2 = cos(U2);

    double dCosU1CosU2 = cosU1 * cosU2;
    double dCosU1SinU2 = cosU1 * sinU2;

    double dSinU1SinU2 = sinU1 * sinU2;
    double dSinU1CosU2 = sinU1 * cosU2;


    double lambda = L;
    double lambdaP = (M_PI*2);
    int iterLimit = 0;
    double cosSqAlpha;
    double sinSigma;
    double cos2SigmaM;
    double cosSigma;
    double sigma;
    double sinAlpha;
    double C;
    double sinLambda, cosLambda;

    do {
        sinLambda = sin(lambda);
        cosLambda = cos(lambda);
        sinSigma = sqrt((cosU2*sinLambda) * (cosU2*sinLambda) +
            (dCosU1SinU2 - dSinU1CosU2 * cosLambda) * (dCosU1SinU2 - dSinU1CosU2 * cosLambda));

        if (sinSigma==0)
        {
            *fwdAz = toDeg(0.0);
            *revAz = toDeg(0.0);
            *dist = 0.0;
            return true;
        }
        cosSigma = dSinU1SinU2 + dCosU1CosU2 * cosLambda;
        sigma = atan2(sinSigma, cosSigma);
        sinAlpha = dCosU1CosU2 * sinLambda / sinSigma;
        cosSqAlpha = 1.0 - sinAlpha * sinAlpha;
        cos2SigmaM = cosSigma - 2.0 * dSinU1SinU2 / cosSqAlpha;

        if (wxIsNaN(cos2SigmaM))
            cos2SigmaM = 0.0;  // equatorial line: cosSqAlpha=0 (§6)
        C = Flattening() / 16.0 * cosSqAlpha * (4.0 + Flattening() * (4.0 - 3.0 * cosSqAlpha));
        lambdaP = lambda;
        lambda = L + (1.0 - C) * Flattening() * sinAlpha *
            (sigma + C * sinSigma * (cos2SigmaM + C * cosSigma * (-1.0 + 2.0 * cos2SigmaM *cos2SigmaM)));
    } while (fabs(lambda-lambdaP) > Eps() && ++iterLimit < 100);

    double uSq = cosSqAlpha * (SemiMajorAxis() * SemiMajorAxis() - SemiMinorAxis() * SemiMinorAxis()) /
                              (SemiMinorAxis() * SemiMinorAxis());
    double A = 1.0 + uSq / 16384.0 * (4096.0 + uSq * (-768.0 + uSq * (320.0 - 175.0 * uSq)));
    double B = uSq / 1024.0 * (256.0 + uSq * (-128.0 + uSq * (74.0 - 47.0 * uSq)));
    double deltaSigma = B * sinSigma * (cos2SigmaM + B / 4.0 * (cosSigma * (-1.0 + 2.0 * cos2SigmaM * cos2SigmaM)-
        B / 6.0 * cos2SigmaM * (-3.0 + 4.0 * sinSigma * sinSigma) * (-3.0 + 4.0 * cos2SigmaM * cos2SigmaM)));

    *dist = mtoNM(SemiMinorAxis() * A * (sigma - deltaSigma));
    *fwdAz = atan2(cosU2 * sinLambda, dCosU1SinU2 - dSinU1CosU2 * cosLambda);
    *revAz = M_PI + atan2(cosU1 * sinLambda, -dSinU1CosU2 + dCosU1SinU2 * cosLambda);

    if(*revAz < 0.0)
        *revAz = (2*M_PI) + *revAz;

    if(*fwdAz < 0.0)
        *fwdAz = (2*M_PI) + *fwdAz;

    *fwdAz=toDeg(*fwdAz); //forward azimuth in degrees
    *revAz=toDeg(*revAz); //reverse azimuth in degrees

    if (iterLimit < 98) {return true;} else {return false;} //if false function failed to converge!

}
///////////////////////////////////////////////////////
//	LLPoint _stdcall DestVincenty(const LLPoint & pt, double brng, double dist)


/**
 * Calculates destination point given start point lat/long, bearing & distance,
 * using Vincenty inverse formula for ellipsoids
 *
 * ->   double lat1, lon1: first point in decimal degrees
 * ->   double brng: initial bearing in decimal degrees
 * ->   double dist: distance along bearing in nautical miles
 * <-   double lat2, lat2 final point in decimal degrees
 * <-   double final bearing in decimal degrees
 */

void DestVincenty(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2, double* revAz) {
    double s = NMtom(dist);
    double alpha1 = toRad(brng);
    double sinAlpha1 = sin(alpha1);
    double cosAlpha1 = cos(alpha1);

    double tanU1 = (1.0 - Flattening()) * tan(toRad(lat1));
    double cosU1 = 1.0 / sqrt((1.0 + tanU1*tanU1));
    double sinU1 = tanU1 * cosU1;
    double sigma1 = atan2(tanU1, cosAlpha1);
    double sinAlpha = cosU1 * sinAlpha1;
    double cosSqAlpha = 1.0 - sinAlpha * sinAlpha;
    double uSq = cosSqAlpha * (SemiMajorAxis() * SemiMajorAxis() - SemiMinorAxis() * SemiMinorAxis()) /
                              (SemiMinorAxis() * SemiMinorAxis());
    double A = 1.0 + uSq / 16384.0 * (4096.0 + uSq * (-768.0 + uSq * (320.0 - 175.0 * uSq)));
    double B = uSq / 1024.0 * (256.0 + uSq * (-128.0 + uSq * (74.0 - 47.0 * uSq)));

    double sigma = s / (SemiMinorAxis() * A);
    double sigmaP = (2*M_PI);
    double sinSigma = sin(sigma);
    double cosSigma = cos(sigma);
    double cos2SigmaM = cos(2.0 * sigma1 + sigma);
    int iterLimit = 0;
    while (fabs(sigma-sigmaP) > Eps() && ++iterLimit < 100) {
        cos2SigmaM = cos(2.0 * sigma1 + sigma);
        sinSigma = sin(sigma);
        cosSigma = cos(sigma);
        double cos2SigmaSq = cos2SigmaM * cos2SigmaM;
        double deltaSigma = B * sinSigma * (cos2SigmaM + B * 0.25 * (cosSigma * (-1.0 + 2.0 * cos2SigmaSq)-
            B / 6.0 * cos2SigmaM * (-3.0 + 4.0 * sinSigma * sinSigma) * (-3.0 + 4.0 * cos2SigmaSq)));

        sigmaP = sigma;
        sigma = s / (SemiMinorAxis() * A) + deltaSigma;
    }

    double tmp = sinU1 * sinSigma - cosU1 * cosSigma * cosAlpha1;
    double lat2rad = atan2(sinU1 * cosSigma + cosU1 * sinSigma * cosAlpha1,
        (1.0 - Flattening()) * sqrt(sinAlpha * sinAlpha + tmp * tmp));
    double lambda = atan2(sinSigma * sinAlpha1, cosU1 * cosSigma - sinU1 * sinSigma * cosAlpha1);
    double C = Flattening() / 16.0 * cosSqAlpha * (4.0 + Flattening() * (4.0 -3.0 * cosSqAlpha));
    double L = lambda - (1.0 - C) * Flattening() * sinAlpha *
        (sigma + C * sinSigma * (cos2SigmaM + C * cosSigma * (-1.0 + 2.0 * cos2SigmaM * cos2SigmaM)));

    //    return LLPoint(lat2, toRad(lon1) + L);
    *lat2=toDeg(lat2rad);
    *lon2=toDeg(toRad(lon1) + L);
    *revAz =toDeg(atan2(sinAlpha, -tmp));  // final bearing, if required
}

////////////////////////////
/**
 * Calculates rhumb line distance between two points specified by latitude/longitude
 * http://williams.best.vwh.net/avform.htm#Rhumb
 * ->   double lat1, lon1: first point in decimal degrees
 * ->   double lat2, lon2: second point in decimal degrees
 * <-   double dist: distance along bearing in nautical miles
 * <-   double bearing in decimal degrees
 * As stated in the introduction, North latitudes and West longitudes are treated as positive,
 * and South latitudes and East longitudes negative. It's easier to go with the flow, but if
 * you prefer another convention you can change the signs in the formulae.
*/
void distRhumb(double lat1,double lon1, double lat2, double lon2, double *distance, double *brng){
  lat1=toRad(lat1);
  lat2=toRad(lat2);
  lon1=toRad(lon1);
  lon2=toRad(lon2);

  double dlon_W=mod(lon2-lon1,(2*M_PI));
  double dlon_E=mod(lon1-lon2,(2*M_PI));
  double dphi=log(tan(lat2/2+M_PI/4)/tan(lat1/2+M_PI/4));
  double q=0;
  if (std::abs(lat2-lat1) < sqrt(Tol())){
     q=cos(lat1);
  } else {
     q= (lat2-lat1)/dphi;
  }
  if (dlon_W < dlon_E){// Westerly rhumb line is the shortest
      *brng=toDeg(mod(atan2(-dlon_W,dphi),(2*M_PI)));
      *distance= radtoNM(sqrt(sqr(q)*(sqr(dlon_W)) + sqr(lat2-lat1)));
  } else{
      *brng=toDeg(mod(atan2(dlon_E,dphi),(2*M_PI)));
      *distance= radtoNM(sqrt(sqr(q)*(sqr(dlon_E)) + sqr(lat2-lat1)));
      }
}



/**
 * To find the lat/lon of a point on true course brng, distance dist from (lat1,lon1)
 * along a rhumbline (initial point cannot be a pole!):
 *
 * ->   double lat1, lon1: first point in decimal degrees
 * ->   double brng: bearing in decimal degrees
 * ->   double dist: distance along bearing in nautical miles
 * <-   double lat2, lat2 final point in decimal degrees

 */

bool destRhumb(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2) {
  lat1=toRad(lat1);
  lon1=toRad(lon1);
  double d=NMtorad(dist);
  double tc=toRad(brng);
  double lat= lat1+d*cos(tc);
    if (std::abs(lat) > M_PI/2) return false;//"d too large. You can't go this far along this rhumb line!"
    double q;
    if (std::abs(lat-lat1) < sqrt(Tol())){
     q=cos(lat1);
  } else {
     double dphi=log(tan(lat/2+M_PI/4)/tan(lat1/2+M_PI/4));
     q= (lat-lat1)/dphi;
  }
    double dlon=-d*sin(tc)/q;
    *lon2=toDeg(mod(lon1+dlon+M_PI,2*M_PI)-M_PI);
    *lat2=toDeg(lat);
  return true;
}

//Loxodrome (Mercator) Destination the WGS ellipsoid
//http://koti.mbnet.fi/jukaukor/loxodrom.html
/**
 * To find the lat/lon of a point on true course brng, distance dist from (lat1,lon1)
 * along a rhumbline (initial point cannot be a pole!):
 *
 * ->   double lat1, lon1: first point in decimal degrees
 * ->   double brng: bearing in decimal degrees
 * ->   double dist: distance along bearing in nautical miles
 * <-   double lat2, lat2 final point in decimal degrees

 */
bool destLoxodrome(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2) {
    bool dbg=false;
    if (dbg) std::cout<<"dL lat1 "<<lat1<<" lon1: " <<lon1<<"brng "<<brng<<" dist " <<dist<< std::endl;
    //double ecc = 0.08181919084255; //The eccentricity ecc of the WGS84 ellipsoid is
    double ecc2 = 0.00669437999012962; //(ecc²)/1
    double ecc4 = 4.48147234522478E-05;//(ecc⁴)/3
    double ecc6 = 3.0000678794192E-07;//(ecc⁶)/5
    double ecc8 = 2.00835943810145E-09;//(ecc⁸)/7 (check)
    double fromlat = toRad(lat1);//fromlat = fromlatdeg*Math.PI/180;
    double fromlong = toRad(lon1);// fromlongdeg*Math.PI/180;
    double course = toRad(brng);//course = coursedeg*Math.PI/180;

    // Destination latitude
    double tolatmin = lat1*60 + dist*cos(course);
    double tolatdegree = tolatmin/60;
    // Check Poles
    if (tolatdegree > 90) {
        tolatdegree = 90;
        if (dbg) std::cout<<"You are on the North Pole"<<std::endl;
        }
    if (tolatdegree < -90) {
        if (dbg) std::cout<<"You are on the South Pole. tolatdegree"<<tolatdegree<<std::endl;
        tolatdegree = -90;
        }

    double tolat = toRad(tolatdegree);

    double tolongdegree;
    if ((tolatdegree != 90) && (tolatdegree != -90)) {
        double meridional1 = log(tan(M_PI/4 + fromlat/2)) - ecc2*sin(fromlat) - (ecc4/3)*pow(sin(fromlat),3) - (ecc6/5)*pow(sin(fromlat),5)-(ecc8/7)*pow(sin(fromlat),7);
        double meridionalmin1 = 10800*meridional1/M_PI;
        double meridional2 = log(tan(M_PI/4 + tolat/2)) - ecc2*sin(tolat) - (ecc4/3)*pow(sin(tolat),3) - (ecc6/5)*pow(sin(tolat),5)-(ecc8/7)*pow(sin(tolat),7);
        double meridionalmin2 = 10800*meridional2/M_PI;
        // deltaM is meridional difference in minutes
        double deltaM = meridionalmin2 - meridionalmin1;

        // Destination longitude, non parallel sailing
        if ((brng != 90) && (brng != 270))
            tolongdegree = lon1 + (deltaM*tan(course))/60;

        // parallel navigation, distance is in nautical miles = equator minutes;
        if (std::abs(brng-90)< 1e-10) {
            tolongdegree = lon1 + (dist/cos(fromlat))/60;
            tolatdegree = lat1;
        }
        if (std::abs(brng - 270) < 1e-10) {
            tolongdegree = lon1 - (dist/cos(fromlat))/60;
            tolatdegree = lat1;
        }
    }
    else
        return false;
    *lat2=tolatdegree;
    *lon2=tolongdegree;
    return true;
}
