#ifndef ROUTE_NAV_FUNC_H
#define ROUTE_NAV_FUNC_H

#include <iostream>
#include <cmath>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../../../include/georef.h"



	/*
	*	\brief Ellipsoid Inverse Flattening constant
	*
	*	298.25722356366546517369570015525
	*	\remarks WGS84 Ellipsoid constant
	*/
//#define InverseFlattening 298.25722356366546517369570015525
    const inline double InverseFlattening(void) { return 298.25722356366546517369570015525; }

	/*
	*	\brief Ellipsoid Flattening constant
	*
	*	Approximately 0.00335281
	*	\remarks WGS84 Ellipsoid constant
	*/
//#define Flattening 1.0 / InverseFlattening
    const inline double Flattening(void) { return 1.0 / InverseFlattening(); }
	/*
	*	\brief Ellipsoid Semi Major Axis
	*
	*	6378137.0
	*	\remarks WGS84 Ellipsoid constant
	*/
//#define SemiMajorAxis 6378137.0
    const inline double SemiMajorAxis(void) { return 6378137.0; }
    	/*
	*	\brief Ellipsoid Semi Minor Axis
	*
	*	Approximately 6356752.314245
	*	\remarks WGS84 Ellipsoid constant
	*/
//#define SemiMinorAxis SemiMajorAxis * (1 - Flattening)
    const inline double SemiMinorAxis(void) { return SemiMajorAxis() * (1 - Flattening()); }
    	/*
	*	\brief Epsilon
	*	\returns double epsilon of 0.5e-15.
	*	\note Order 8260.54A Appendix 2, 3.3 Tolerances, states
	*	"Empirical studies have shown that eps = 0.5e-13 and
	*	tol = 1.0-e9 work well."
	*
	*	When implementing the TerpsTest validation application
	*	eps must be set to 0.5e-15 for all tests to pass. If
	*	set as stated in section 3.3 of 8260.54A then the
	*	Tangent Fixed Radius Arc and Locus Tan Fixed Radius Arc
	*	fails validation.
	*
	*/
    const inline double Eps(void) { return 0.5e-15; }

    	/*
	*	\brief Tolerance
	*	\returns double tolerance of 1.0e-9
	*	\note Order 8260.54A Appendix 2, 3.3 Tolerances, states
	*	"Empirical studies have shown that eps = 0.5e-13 and
	*	tol = 1.0-e9 work well."
	*
	*	Functions in the GeoFormulas that use different values
	*	will be clearly marked in the comments and the value
	*	used.
	*
	*	See file "Application test Results.txt" for information
	*	about tolerances used in the "TerpsTest" application.
	*
	*/
    const inline double Tol(void) { return 1.0e-9; }


double fromDMStodouble(char *dms);
void doubletoDMS(double a, char *bufp, int bufplen);

double toRad (double degree);
double toDeg (double radians);
double sqr (double radians);
void destVincenty(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2, double* revAz);
bool distVincenty(double lat1, double lon1, double lat2, double lon2, double *dist, double *fwdAz, double *revAz);
void distRhumb(double lat1,double lon1, double lat2, double lon2, double *distance, double *brng);
bool destRhumb(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2);
bool destLoxodrome(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2);
#endif/* #define ROUTE_NAV_FUNC_H*/
