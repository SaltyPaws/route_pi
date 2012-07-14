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

#include "routegui_impl.h"

RouteCfgDlg::RouteCfgDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : RouteCfgDlgDef( parent, id, title, pos, size, style )
{
}

RouteDlg::RouteDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : RouteDlgDef( parent, id, title, pos, size, style )
{
}

void RouteDlg::OnRouteProperties( wxCommandEvent& event )
{
      wxMessageBox(_("Sorry, this function is not yet implemented..."));
      event.Skip();
}

void RouteDlg::OnRouteCancelClick( wxCommandEvent& event ) { event.Skip(); }

void RouteDlg::OnRouteOkClick( wxCommandEvent& event ) { event.Skip(); }
