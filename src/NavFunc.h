#ifndef ROUTE_NAV_FUNC_H
#define ROUTE_NAV_FUNC_H

#include <iostream>
#include <cmath>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../../include/georef.h"
#include "vincente.h"


const inline double Tol(void) { return 1.0e-9; }


double fromDMStodouble(char *dms);
void doubletoDMS(double a, char *bufp, int bufplen);

double toRad (double degree);
double toDeg (double radians);
double sqr (double radians);

double radtoNM(double distance_radians);
double NMtorad(double distance_NM);
double mtoNM(double metres);
double NMtom(double NM);

void DestVincenty(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2, double* revAz);
bool DistVincenty(double lat1, double lon1, double lat2, double lon2, double *dist, double *fwdAz, double *revAz);
void distRhumb(double lat1,double lon1, double lat2, double lon2, double *distance, double *brng);
bool destRhumb(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2);
bool destLoxodrome(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2);
#endif/* #define ROUTE_NAV_FUNC_H*/
