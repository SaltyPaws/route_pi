/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
 * Author:   SaltyPaws
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Brazil BrokeTail                                *
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

#ifndef _CALCULATORGUI_IMPL_H_
#define _CALCULATORGUI_IMPL_H_

//#include <cstdlib>
//#include <cstdio>
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif
//#include "parser.h"

#include "routegui.h"
#include "route_pi.h"
#include "NavFunc.h"
//#include "../../include/georef.h"
//#include "../../include/gpxdocument.h"
#include "tinyxml.h"
using namespace std;

class route_pi;

class CfgDlg : public CfgDlgDef
{
public:
      CfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Calculator preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
};

class Dlg : public DlgDef
{
public:
        Dlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Calculator by SaltyPaws"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER );
        void OnCalculate( wxCommandEvent& event );
        void OnToggle( wxCommandEvent& event );
        void OnConverttoDegree( wxCommandEvent& event );
        void OnNoteBookFit( wxCommandEvent& event );
        void OnGCCalculate( wxCommandEvent& event );
        void OnGCLCalculate( wxCommandEvent& event );
        void OnGCLCalculate( wxCommandEvent& event, bool write_file );
        void OnFit( wxCommandEvent& event );
        void OnExportGC( wxCommandEvent& event );
        void OnExportGCL( wxCommandEvent& event );
        //void Addpoint(TiXmlElement* Route, double ptlat, double ptlon, wxString ptname, wxString ptsym, wxString pttype);
        void Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype);
        double BrentsMethodSolve(double lowerLimit, double upperLimit, double errorTol);
        //friend class function;
        route_pi *plugin;
private:
        wxPoint xy;
        wxSize  wh;
        double lat1, lon1, lat2, lon2, targetAz;
        double F(double x);
        bool error_found;
};

#endif
