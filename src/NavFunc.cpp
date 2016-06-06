#include "NavFunc.h"
#include "wx/math.h"

//#include <string>

double toRad (double degree) {
  return degree * M_PI / 180;
}
/*
double toDeg (double radians) {
  return radians * 180 / M_PI;
}*/
/*
double sqr (double sqr2) {
  return sqr2*sqr2;
}
*/
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
//double asin_safe(double x){return asin(max(-1,min(x,1)));}
//double acos_safe(double x){return acos(max(-1,min(x,1)));}

/*
Note on the mod function. This appears to be implemented differently in different languages, with differing conventions on whether
the sign of the result follows the sign of the divisor or the dividend. (We want the sign to follow the divisor or be Euclidean.
C's fmod and Java's % do not work.) In this document, Mod(y,x) is the remainder on dividing y by x and always lies in the range 0 <=mod <x.
For instance: mod(2.3,2.)=0.3 and mod(-2.3,2.)=1.7
*/
/*double mod(double y, double x){
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
*/

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
/*
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
*/


/**
 * To find the lat/lon of a point on true course brng, distance dist from (lat1,lon1)
 * along a rhumbline (initial point cannot be a pole!):
 *
 * ->   double lat1, lon1: first point in decimal degrees
 * ->   double brng: bearing in decimal degrees
 * ->   double dist: distance along bearing in nautical miles
 * <-   double lat2, lat2 final point in decimal degrees

 */
/*
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
*/

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
    //double fromlong = toRad(lon1);// fromlongdeg*Math.PI/180;
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

    double tolongdegree = 0;
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
