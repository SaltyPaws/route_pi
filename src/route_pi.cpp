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

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/stdpaths.h>
#include "route_pi.h"
//#define CURL_STATICLIB
//#include <curl/curl.h>
//#include <curl/easy.h>

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new route_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

void appendOSDirSlash(wxString* pString)
{

}
/*
// write downloaded data
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}
*/

//---------------------------------------------------------------------------------------------------------
//
//    Route PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

route_pi::route_pi(void *ppimgr)
      :opencpn_plugin_18(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
}


int route_pi::Init(void)
{

      m_bshuttingDown = false;
      m_lat = 999.0;
      m_lon = 999.0;

      AddLocaleCatalog( _T("opencpn-route_pi") );

      // Set some default private member parameters
      m_route_dialog_x = 0;
      m_route_dialog_y = 0;

      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
//      LoadConfig();

      //      Establish the location of the config file
      wxString dbpath;

//      Establish a "home" location
      /*wxStandardPathsBase& std_path = wxStandardPaths::Get();

      wxString pHome_Locn;
#ifdef __WXMSW__
      pHome_Locn.Append(std_path.GetConfigDir());          // on w98, produces "/windows/Application Data"
#else
      pHome_Locn.Append(std_path.GetUserConfigDir());
#endif
      //appendOSDirSlash(&pHome_Locn) ;
      */

      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_route_pi, _img_route_pi, wxITEM_NORMAL,
            _("Plot Route"), _T(""), NULL,
             ROUTE_TOOL_POSITION, 0, this);

      m_pRouteDialog = NULL;

      return (WANTS_TOOLBAR_CALLBACK    |
              INSTALLS_TOOLBAR_TOOL     |
              WANTS_CURSOR_LATLON       |
              WANTS_PREFERENCES         |
              WANTS_OVERLAY_CALLBACK    |
              WANTS_ONPAINT_VIEWPORT    |
              //WANTS_OPENGL_OVERLAY_CALLBACK |
              //WANTS_DYNAMIC_OPENGL_OVERLAY_CALLBACK |
              WANTS_CONFIG
           );
}

bool route_pi::DeInit(void)
{
      m_bshuttingDown = true;
     //    Record the dialog position
      if (NULL != m_pRouteDialog)
      {
            wxPoint p = m_pRouteDialog->GetPosition();
            SetRouteDialogX(p.x);
            SetRouteDialogY(p.y);

            m_pRouteDialog->Close();
            delete m_pRouteDialog;
            m_pRouteDialog = NULL;
      }

//      SaveConfig();
      return true;
}

int route_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int route_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int route_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int route_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *route_pi::GetPlugInBitmap()
{
      return _img_route_pi;
}

wxString route_pi::GetCommonName()
{
      return _("ROUTE");
}


wxString route_pi::GetShortDescription()
{
      return _("Route Plotting plugin for OpenCPN");
}

wxString route_pi::GetLongDescription()
{
      return _("Route Plotting plugin for OpenCPN\n\
Plots Great Circle routes, Limited Circle Routes and Rhumb lines.");

}

void route_pi::SetCursorLatLon(double lat, double lon)
{
      //m_cursor_lon = lon;
      //m_cursor_lat = lat;
      //wxLogMessage (_T("ROUTE_PI: OnToolbarToolCallback %d,%d\n"), lat,lon);
}

int route_pi::GetToolbarToolCount(void)
{
      return 1;
}

void route_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pRouteDialog)
            return;

      DimeWindow(m_pRouteDialog);
}

void route_pi::ShowPreferencesDialog( wxWindow* parent )
{
      WmmPrefsDialog *dialog = new WmmPrefsDialog( parent, wxID_ANY, _("WMM Preferences"), wxPoint( m_route_dialog_x, m_route_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->Fit();
      wxColour cl;
      GetGlobalColor(_T("DILG1"), &cl);
      dialog->SetBackgroundColour(cl);

      /*dialog->m_rbViewType->SetSelection(m_iViewType);
      dialog->m_cbShowAtCursor->SetValue(m_bShowAtCursor);
      dialog->m_cbLiveIcon->SetValue(m_bShowLiveIcon);
      dialog->m_sOpacity->SetValue(m_iOpacity);*/

      if(dialog->ShowModal() == wxID_OK)
      {
            /*m_iViewType = dialog->m_rbViewType->GetSelection();
            m_bShowAtCursor = dialog->m_cbShowAtCursor->GetValue();
            m_bShowLiveIcon = dialog->m_cbLiveIcon->GetValue();
            m_iOpacity = dialog->m_sOpacity->GetValue();

            RearangeWindow();

            SaveConfig();*/
      }
      delete dialog;
}

void route_pi::SetCurrentViewPort(PlugIn_ViewPort &vp)
{
  
}

void route_pi::OnToolbarToolCallback(int id)
{
      wxLogMessage (_T("ROUTE_PI: OnToolbarToolCallback\n"));
      // ROUTE Dialog (here we can select what types of objects to show)
      if(NULL == m_pRouteDialog)
      {
            m_pRouteDialog = new RouteDlg(m_parent_window);
            m_pRouteDialog->plugin = this;
            m_pRouteDialog->Move(wxPoint(m_route_dialog_x, m_route_dialog_y));
      }
      m_pRouteDialog->Show(!m_pRouteDialog->IsShown());
      
     // DownloadUrl(m_overpass_url);
}




