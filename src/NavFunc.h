/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
 * Author:   Walbert Schulpen (SaltyPaws)
 *
 ***************************************************************************
 *   Copyright (C) 2012-2016 by Walbert Schulpen                           *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */


#ifndef ROUTE_NAV_FUNC_H
#define ROUTE_NAV_FUNC_H

#include <iostream>
#include <cmath>
//#include <string.h>
//#include <ctype.h>
//#include <stdio.h>
#include "georef.h"
//#include "vincenty.h"


const inline double Tol(void) { return 1.0e-9; }

double toRad (double degree);
//double toDeg (double radians);
//double sqr (double radians);

//double radtoNM(double distance_radians);
//double NMtorad(double distance_NM);
//double mtoNM(double metres);
//double NMtom(double NM);

//void DestVincenty(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2, double* revAz);
//bool DistVincenty(double lat1, double lon1, double lat2, double lon2, double *dist, double *fwdAz, double *revAz);
//void distRhumb(double lat1,double lon1, double lat2, double lon2, double *distance, double *brng);
//bool destRhumb(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2);

double min ( double a, double b ) ;
double max ( double a, double b ) ;
bool destLoxodrome(double lat1, double lon1, double brng, double dist, double* lat2, double* lon2);
#endif/* #define ROUTE_NAV_FUNC_H*/
