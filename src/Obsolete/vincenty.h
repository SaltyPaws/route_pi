#include "NavFunc.h"
#ifndef VINCENTE_H
#define VINCENTE_H
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
#endif //VINCENTE_H
