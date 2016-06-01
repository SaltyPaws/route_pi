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

#ifndef _ROUTEGUI_IMPL_H_
#define _ROUTEGUI_IMPL_H_

//#include <cstdlib>
//#include <cstdio>
#include <wx/clipbrd.h>
#include "tinyxml.h"
#include "NavFunc.h"

#include "route_pi.h"
#include "routegui.h"
#ifdef WX_PRECOMP
#include "wx/wx.h"
#endif

//#include "parser.h"


using namespace std;

class route_pi;

class CfgDlg : public CfgDlgDef
{
public:
      CfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Route preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
};

class Dlg : public DlgDef
{
public:
        Dlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Route Plugin by SaltyPaws"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER );
        void OnCalculate( wxCommandEvent& event );
        void OnStartPaste( wxCommandEvent& event );
        void OnDeleteRoute( wxString GUID);
        void OnEndPaste( wxCommandEvent& event );
        void OnToggle( wxCommandEvent& event );
        void OnConverttoDegree( wxCommandEvent& event );
        void OnConverttoDegree(void);
        void OnNoteBookFit( wxCommandEvent& event );
        void OnGCCalculate( wxCommandEvent& event );
        bool OnGCCalculate( void );
        void OnGCLCalculate( wxCommandEvent& event );
        bool OnGCLCalculate( wxCommandEvent& event, bool write_file, bool to_OpenCPN );
        void OnFit( wxCommandEvent& event );
        void OnExportGC( wxCommandEvent& event );
        void OnExportGC( wxCommandEvent& event, bool to_OpenCPN );
        void OnExportGCL( wxCommandEvent& event );
        void OnExportRH( wxCommandEvent& event );
        void OnExportRH( wxCommandEvent& event, bool to_OpenCPN );

        void SetStart (double lat, double lon);
        void SetFinish (double lat, double lon);

        void AddPoint( PlugIn_Waypoint *pNewPoint, PlugIn_Route *m_Route_ocpn);
        void Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype);
        double BrentsMethodSolve(double lowerLimit, double upperLimit, double errorTol);
        double Fraction_string_to_Decimal(wxString fraction_string);
        void Import_coordinate_pair_from_clipboard(bool start);
        wxString Clean_Coordinate (wxString Coordinate);
        //friend class function;
        route_pi *plugin;
private:
        wxPoint xy;
        wxSize  wh;
        double lat1, lon1, lat2, lon2, targetAz;
        double F(double x);
        bool error_found;
        bool dbg;
        wxString m_GUUD;
};

#endif
