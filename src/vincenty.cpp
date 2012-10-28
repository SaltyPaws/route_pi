#include "vincenty.h"

/*
Functions are modified from: http://wired2code.wordpress.com/2010/07/14/wgs84-ellipsoid-calculations/
Legal Stuff

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this software except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Which basically means: whatever you do, I can't be held accountable if something breaks.

Modifications:
* Functions take and return degree and NM, rather than rad and m
* Math functions adjusted to work with gcc compiler
* Functions removed from namespace
* library specific structs (for coordinates and return of values removed)
* Return by pointer
*/



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

        if (isnan(cos2SigmaM))
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
