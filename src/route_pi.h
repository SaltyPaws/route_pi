/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
 * Author:   Brazil BrokeTail
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

#ifndef _ROUTEPI_H_
#define _ROUTEPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    1

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    8

#include <wx/fileconf.h>
#include <wx/filepicker.h>
#include <wx/file.h>
#include <wx/aui/aui.h>
#include "../../../include/ocpn_plugin.h"

#define ROUTE_TOOL_POSITION -1          // Request default positioning of toolbar tool

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

class ROUTEControl;

class route_pi : public opencpn_plugin_18, wxTimer
{
public:
      route_pi( void *ppimgr );

//    The required PlugIn Methods
      int Init( void );
      bool DeInit( void );

      int GetAPIVersionMajor();
      int GetAPIVersionMinor();
      int GetPlugInVersionMajor();
      int GetPlugInVersionMinor();
      wxBitmap *GetPlugInBitmap();
      wxString GetCommonName();
      wxString GetShortDescription();
      wxString GetLongDescription();

      void Notify();
      void SetInterval( int interval );

//    The optional method overrides
//      void SetNMEASentence( wxString &sentence );
//      void SetAISSentence( wxString &sentence );
      int GetToolbarToolCount( void );
      void OnToolbarToolCallback( int id );
      void SetColorScheme( PI_ColorScheme cs );

private:
      bool LoadConfig( void );
      bool SaveConfig( void );

      int               m_tb_item_id_record;
      int               m_tb_item_id_play;

      wxFileConfig     *m_pconfig;
      wxAuiManager     *m_pauimgr;
      ROUTEControl       *m_proutecontrol;
      wxString          m_ifilename;
      wxString          m_ofilename;
      int               m_interval;
      bool              m_recording;
      wxTextFile        m_istream;
      wxFile            m_ostream;
};

class ROUTEControl : public wxWindow
{
public:
      ROUTEControl( wxWindow *pparent, wxWindowID id, route_pi *route, int speed, int range );
      void SetColorScheme( PI_ColorScheme cs );
      void SetProgress( int progress );

private:
      void OnSliderUpdated( wxCommandEvent& event );

      route_pi           *m_proute;
      wxSlider         *m_pslider;
      wxGauge          *m_pgauge;
};

#endif
