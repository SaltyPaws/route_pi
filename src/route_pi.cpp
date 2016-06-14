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

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "route_pi.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new route_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    Calculator PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------
//route_pi *g_route_pi = NULL;

route_pi::route_pi(void *ppimgr)
      :opencpn_plugin_110(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
//      g_route_pi = this;
}

int route_pi::Init(void)
{
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
      LoadConfig();

        // Create the Context Menu Items

        //    In order to avoid an ASSERT on msw debug builds,
        //    we need to create a dummy menu to act as a surrogate parent of the created MenuItems
        //    The Items will be re-parented when added to the real context meenu

        wxMenu dummy_menu;

      wxMenuItem *pmi = new wxMenuItem(&dummy_menu, -1, _("Start Route_pi Here"));
      m_add_start = AddCanvasContextMenuItem(pmi, this );
      SetCanvasContextMenuItemViz(m_add_start, true);

      wxMenuItem *pmih = new wxMenuItem(&dummy_menu, -1, _("Finish Route_pi Here."));
      m_add_finish = AddCanvasContextMenuItem(pmih, this );
      SetCanvasContextMenuItemViz(m_add_finish, true);


      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_route_pi, _img_route_pi, wxITEM_NORMAL,
            _("Route"), _T(""), NULL,
             CALCULATOR_TOOL_POSITION, 0, this);

      m_pDialog = NULL;

      return (WANTS_TOOLBAR_CALLBACK   |
              INSTALLS_TOOLBAR_TOOL    |
              WANTS_PREFERENCES        |
              WANTS_CURSOR_LATLON      |
              WANTS_CONFIG
           );
}

bool route_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pDialog)
      {
            //Capture dialog position
            wxPoint p = m_pDialog->GetPosition();
            SetCalculatorDialogX(p.x);
            SetCalculatorDialogY(p.y);
            m_pDialog->Close();
            delete m_pDialog;
            m_pDialog = NULL;
      }
      SaveConfig();
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

int route_pi::GetToolbarToolCount(void)
{
      return 1;
}

void route_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pDialog)
            return;

      DimeWindow(m_pDialog);
}

void route_pi::OnToolbarToolCallback(int id)
{
      if(NULL == m_pDialog)
      {
            m_pDialog = new Dlg(m_parent_window);
            m_pDialog->plugin = this;
            m_pDialog->Move(wxPoint(m_route_dialog_x, m_route_dialog_y));
      }
 m_pDialog->Fit();
      m_pDialog->Show(!m_pDialog->IsShown());
}

bool route_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/Route_pi" ) );
            pConf->Read ( _T ( "Opacity" ),  &m_iOpacity, 255 );
           // pConf->Read       dialog->m_cpConnectorColor->SetColour(m_sConnectorColor);
            m_route_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_route_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );

            if((m_route_dialog_x < 0) || (m_route_dialog_x > m_display_width))
                  m_route_dialog_x = 5;
            if((m_route_dialog_y < 0) || (m_route_dialog_y > m_display_height))
                  m_route_dialog_y = 5;
            return true;
      }
      else
            return false;
}

bool route_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/Route_pi" ) );
            pConf->Write ( _T ( "Opacity" ), m_iOpacity );
            pConf->Write ( _T ( "DialogPosX" ),   m_route_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_route_dialog_y );
            return true;
      }
      else
            return false;
}

void route_pi::ShowPreferencesDialog( wxWindow* parent )
{
      CfgDlg *dialog = new CfgDlg( parent, wxID_ANY, _("Route Preferences"), wxPoint( m_route_dialog_x, m_route_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->Fit();
      wxColour cl;
      DimeWindow(dialog);
      dialog->m_sOpacity->SetValue(m_iOpacity);

      if(dialog->ShowModal() == wxID_OK)
      {
            m_iOpacity = dialog->m_sOpacity->GetValue();
            SaveConfig();
      }
      delete dialog;
}

void route_pi::OnContextMenuItemCallback(int id)
{
//Need to make sure that Route Dialog exits, otherwise we will get a Core Dump
      if(NULL == m_pDialog)
      {
         OnToolbarToolCallback(10);
         m_pDialog->Show(false);

      }

    if (id==m_add_start){
     //     printf("Take location as start of Route\n");
     //     printf("Lat: %g, Lon %g\n ",m_cursor_lat,m_cursor_lon);
        m_pDialog->SetStart(m_cursor_lat,m_cursor_lon);
    }

    if (id==m_add_finish){
    //      printf("Take Location as finish of Route\n");
    //     printf("Lat: %g, Lon %g\n ",m_cursor_lat,m_cursor_lon);
    m_pDialog->SetFinish(m_cursor_lat,m_cursor_lon);
    }

}

void route_pi::SetCursorLatLon(double lat, double lon)
{

        m_cursor_lat=lat;
        m_cursor_lon=lon;
    //std::cout<<"Cursor--> Lat: "<<m_cursor_lat<<" Lon: "<<m_cursor_lon<<std::endl;
}
