#include "NavFunc.h"


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

    bool IsNumber(double x)
    {
        // This looks like it should always be true,
        // but it's false if x is a NaN.
        return (x == x);
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
C's fmod and Java's % do not work.) In this document, mod(y,x) is the remainder on dividing y by x and always lies in the range 0 <=mod <x.
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
double NmToMeters(double NM){
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

    InverseResult result;
    LLPoint pt1, pt2;
    pt1.latitude=toRad(lat1);
    pt1.longitude=toRad(lon1);
    pt2.latitude=toRad(lat2);
    pt2.longitude=toRad(lon2);

    bool test=DistVincenty( pt1,  pt2, & result);
    *dist = mtoNM(result.distance);
    *fwdAz = toDeg(result.azimuth);
    *revAz = toDeg(result.azimuth);
    return test;
}


void distVincenty(LLPoint pt1, LLPoint pt2, InverseResult * result)
	{
	InverseResult temp;
    //bool test =
    DistVincenty( pt1,  pt2,   &temp);
    *result=temp;
	}

	bool DistVincenty(LLPoint pt1, LLPoint pt2, InverseResult * result)
	{
		double L = pt2.longitude - pt1.longitude;
		double U1 = atan((1-Flattening()) * tan(pt1.latitude));
		double U2 = atan((1-Flattening()) * tan(pt2.latitude));

		double sinU1 = sin(U1);
		double cosU1 = cos(U1);
		double sinU2 = sin(U2);
		double cosU2 = cos(U2);

		double dCosU1CosU2 = cosU1 * cosU2;
		double dCosU1SinU2 = cosU1 * sinU2;

		double dSinU1SinU2 = sinU1 * sinU2;
		double dSinU1CosU2 = sinU1 * cosU2;


		double lambda = L;
		double lambdaP = M_2PI;
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
				(*result).reverseAzimuth = 0.0;
				(*result).azimuth = 0.0;
				(*result).distance = 0.0;
				return true;
			}
			cosSigma = dSinU1SinU2 + dCosU1CosU2 * cosLambda;
			sigma = atan2(sinSigma, cosSigma);
			sinAlpha = dCosU1CosU2 * sinLambda / sinSigma;
			cosSqAlpha = 1.0 - sinAlpha * sinAlpha;
			cos2SigmaM = cosSigma - 2.0 * dSinU1SinU2 / cosSqAlpha;

			if (!IsNumber(cos2SigmaM))
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

		(*result).distance = SemiMinorAxis() * A * (sigma - deltaSigma);
		(*result).azimuth = atan2(cosU2 * sinLambda, dCosU1SinU2 - dSinU1CosU2 * cosLambda);
		(*result).reverseAzimuth = M_PI + atan2(cosU1 * sinLambda, -dSinU1CosU2 + dCosU1SinU2 * cosLambda);

		if((*result).reverseAzimuth < 0.0)
			(*result).reverseAzimuth = M_2PI + (*result).reverseAzimuth;

		if((*result).azimuth < 0.0)
			(*result).azimuth = M_2PI + (*result).azimuth;
        if (iterLimit>98)
            return false;
        else
            return true;
	}


///////////////////////////////////////////////////////
//	LLPoint _stdcall DestVincenty(const LLPoint & pt, double brng, double dist)


/**
 * Calculates destination point given start point lat/long, bearing & distance,
 * using Vincenty inverse formula for ellipsoids
 *
 * ->   pt LLpoint in radius
 * ->   double brng: initial bearing in radius
 * ->   double dist: distance along bearing in metres
 * <-   pt (double lat2, lat2) final point in radius
 * <-   double final bearing in radius
 */
 LLPoint DestVincenty(LLPoint pt, double brng, double dist)
    {
    double dummy_revAz;
    return DestVincenty(pt, brng, dist, &dummy_revAz);
    }

LLPoint DestVincenty(LLPoint pt, double brng, double dist, double* revAz)
	{
		double s = dist;
		double alpha1 = brng;
		double sinAlpha1 = sin(alpha1);
		double cosAlpha1 = cos(alpha1);

		double tanU1 = (1.0 - Flattening()) * tan(pt.latitude);
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
		double sigmaP = M_2PI;
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
		double lat2 = atan2(sinU1 * cosSigma + cosU1 * sinSigma * cosAlpha1,
			(1.0 - Flattening()) * sqrt(sinAlpha * sinAlpha + tmp * tmp));
		double lambda = atan2(sinSigma * sinAlpha1, cosU1 * cosSigma - sinU1 * sinSigma * cosAlpha1);
		double C = Flattening() / 16.0 * cosSqAlpha * (4.0 + Flattening() * (4.0 -3.0 * cosSqAlpha));
		double L = lambda - (1.0 - C) * Flattening() * sinAlpha *
			(sigma + C * sinSigma * (cos2SigmaM + C * cosSigma * (-1.0 + 2.0 * cos2SigmaM * cos2SigmaM)));


    LLPoint return_value;
    return_value.latitude=lat2;
    return_value.longitude= pt.longitude + L;

    *revAz =atan2(sinAlpha, -tmp);
    return return_value;
	}

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
void DestVincenty(double lat1, double lon1, double brng, double distNM, double* lat2, double* lon2, double* revAz) {

   LLPoint pt;
   pt.latitude=toRad(lat1);
   pt.longitude=toRad(lon1);
   double distm=NmToMeters(distNM);
   double brngrad=toRad(brng);
   double revAzrad;
   LLPoint Result_dest=DestVincenty(pt,  brngrad,  distm, &revAzrad );


    *lat2=toDeg(Result_dest.latitude);
    *lon2=toDeg(Result_dest.longitude);
    *revAz =toDeg(revAzrad);  // final bearing, if required
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
    //double ecc = 0.08181919084255; //The eccentricity ecc of the WGS84 ellipsoid is
    double ecc2 = 0.00669437999012962; //(ecc²)/1
    double ecc4 = 4.48147234522478E-05;//(ecc⁴)/3
    double ecc6 = 3.0000678794192E-07;//(ecc⁶)/5
    double ecc8 = 2.00835943810145E-09;//(ecc⁸)/7 (check)
    double fromlat = toRad(lat1);//fromlat = fromlatdeg*Math.PI/180;
//    double fromlong = toRad(lon1);// fromlongdeg*Math.PI/180;
    double course = toRad(brng);//course = coursedeg*Math.PI/180;

    // Destination latitude
    double tolatmin = lat1*60 + dist*cos(course);
    double tolatdegree = tolatmin/60;
            std::cout<<"You are on the South Pole"<<std::endl;
    // Check Poles
    if (tolatdegree > 90) {
        tolatdegree = 90;
        std::cout<<"You are on the North Pole"<<std::endl;
        }
    if (tolatdegree < -90) {
        tolatdegree = -90;
        std::cout<<"You are on the South Pole"<<std::endl;
        }

    double tolat = toRad(tolatdegree);

    double tolongdegree=0;
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



/**	\file CrsIntersect.cpp
*	\brief
*/

/****************************************************************************/
/*	CrsIntersect.cpp													*/
/****************************************************************************/
/*                                                                          */
/*  Copyright 2008 - 2010 Paul Kohut                                        */
/*  Licensed under the Apache License, Version 2.0 (the "License"); you may */
/*  not use this file except in compliance with the License. You may obtain */
/*  a copy of the License at                                                */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or         */
/*  implied. See the License for the specific language governing            */
/*  permissions and limitations under the License.                          */
/*                                                                          */
/****************************************************************************/

//#include "Conversions.h"
//#include "GeoFormulas.h"


	/**
	*
	*/
	bool CrsIntersect(double lat1, double lon1, double az13,
		double lat2, double lon2, double az23, double dTol, double lati, double loni)
	{
		double az31, dist13, az32, dist23;
		az31 = az32 = 0.0;
		dist13 = dist23 = 0.0;
		return CrsIntersect1(lat1, lon1, az13,az31, dist13, lat2, lon2, az23, az32, dist23, dTol, lati, loni);

	}


	/**
	*
	*/
	bool  CrsIntersect1(double lat1, double lon1, double az13,
		double & az31, double & dist13, double lat2, double lon2, double az23,
		double & az32, double & dist23, double dTol, double lati, double loni)
	{
	    LLPoint pt1;
	    LLPoint pt2;
		pt1.latitude = lat1;
		pt1.longitude = lon1;
        pt2.latitude = lat2;
		pt2.longitude = lon2;

		double dAz13 = az13;
		double dAz23 = az23;

		InverseResult result;
		DistVincenty(pt1, pt2, &result);

		double dist12 = result.distance;
		double crs12 = result.azimuth;
		double crs21 = result.reverseAzimuth;

		double angle1 = fabs(SignAzimuthDifference(dAz13, crs12));
		double angle2 = fabs(SignAzimuthDifference(crs21, dAz23));
		if(angle1 < 0.0 && angle2 < 0.0)
		{
			angle1 = -angle1;
			angle2 = -angle2;
		}

		if(sin(angle1) == 0.0 && sin(angle2) == 0.0)
			return false;

		// step 7
		// locate approx intersection of point3 using spherical earth model. Section 3.2

		double cosA = cos(angle1);
		double sinA = sin(angle1);
		double cosB = cos(angle2);
		double sinB = sin(angle2);

		double C = acos( -cosA * cosB + sinA * sinB * cos(dist12 / SphereRadius()));

		double cosC = cos(C);
		double sinC = sin(C);
		double a = SphereRadius() * acos( (cosA + cosB * cosC) / (sinB * sinC) );
		double b = SphereRadius() * acos( (cosB + cosA * cosC) / (sinA * sinC) );

		if(!IsNumber(a) || !IsNumber(b))
			return false;

		LLPoint llIntersect = DestVincenty(pt1, dAz13, b);
		DistVincenty(pt1, llIntersect, &result);
		dist13 = result.distance;

		LLPoint llInv = llIntersect;
		llInv.latitude = -llInv.latitude;
		llInv.longitude = llInv.longitude + M_PI - (2*M_PI);
		DistVincenty(pt1, llInv, &result);

		if(dist13 > result.distance)
		{
			llIntersect = llInv;
			dist13 = result.distance;
			az31 = result.reverseAzimuth;
			dAz13 = dAz13 + M_PI;
			dAz23 = dAz23 + M_PI;
		}

		DistVincenty(pt2, llIntersect, &result);
		dist23 = result.distance;

		if(dist13 < NmToMeters(1))
		{
			pt1 = DestVincenty(pt1, dAz13 + M_PI, NmToMeters(1.0));
			DistVincenty(pt1, llIntersect, &result);
			dAz13 = result.azimuth;
		}
		if(dist23 < NmToMeters(1))
		{
			pt2 = DestVincenty(pt2, dAz23 + M_PI, NmToMeters(1.0));
			DistVincenty(pt2, llIntersect, &result);
			dAz23 = result.azimuth;
		}

		bool bSwapped = false;
		if(dist23 < dist13)
		{
			LLPoint newPt = pt1;
			pt1 = pt2;
			pt2 = newPt;
			double aaz13 = dAz13;
			dAz13 = dAz23;
			dAz23 = aaz13;
			dist13 = dist23;
			bSwapped = true;
		}

		double distarray[2], errarray[2];
		distarray[0] = dist13;
		llIntersect = DestVincenty(pt1, dAz13, dist13);
		DistVincenty(pt2, llIntersect, &result);
		double aacrs23 = result.azimuth;
		errarray[0] = SignAzimuthDifference(aacrs23, dAz23);
		distarray[1] = 1.01 * dist13;
		llIntersect = DestVincenty(pt1, dAz13, distarray[1]);
		DistVincenty(pt2, llIntersect, &result);
		aacrs23 = result.azimuth;
		errarray[1] = SignAzimuthDifference(aacrs23, dAz23);

		int k = 0;
		double dErr = 0;
		int nMaxCount = 15;

		while(k == 0 || ((dErr > dTol) && (k <= nMaxCount)))
		{
			FindLinearRoot(distarray, errarray, dist13);
			LLPoint newPt = DestVincenty(pt1, dAz13, dist13);
			DistVincenty(pt2, newPt, &result);
			aacrs23 = result.azimuth;

			DistVincenty(newPt, llIntersect, &result);
			dErr = result.distance;

			distarray[0] = distarray[1];
			distarray[1] = dist13;
			errarray[0] = errarray[1];
			errarray[1] = SignAzimuthDifference(aacrs23, dAz23);
			k++;
			llIntersect = newPt;
		}
		// display if k == maxinteratorcount (10) and show error message
		// because results might not have converged.
		if(k > nMaxCount && dErr > 1e-8)
			return false;

		if(bSwapped)
		{
			LLPoint newPt = pt1;
			pt1 = pt2;
			pt2 = newPt;
			double aaz13 = dAz13;
			dAz13 = dAz23;
			dAz23 = aaz13;
			dist13 = dist23;
		}
		DistVincenty(llIntersect, pt1, &result);
		az31 = result.azimuth;
		dist13 = result.distance;

		DistVincenty(llIntersect, pt2, &result);
		az32 = result.azimuth;
		dist23 = result.distance;

		return true;
	}

void FindLinearRoot( double *x, double *errArray, double & root )
	{
		if(x[0] == x[1]) {
			root = std::numeric_limits<double>::signaling_NaN();
		} else if(errArray[0] == errArray[1]) {
			if(IsNearZero(errArray[0] - errArray[1], 1e-15)) {
				root = x[0];
			} else {
				root = std::numeric_limits<double>::signaling_NaN();
			}
		} else {
			root = -errArray[0] * (x[1] - x[0]) / (errArray[1] - errArray[0]) + x[0];
		}
	}


double SignAzimuthDifference(double az1, double az2)
	{
		return mod(az1 - az2 + M_PI, M_2PI) - M_PI;
	}




