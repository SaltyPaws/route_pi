///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ROUTEGUI_H__
#define __ROUTEGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/clrpicker.h>
#include <wx/fontpicker.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/tglbtn.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/notebook.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class RouteCfgDlgDef
///////////////////////////////////////////////////////////////////////////////
class RouteCfgDlgDef : public wxDialog
{
	private:

	protected:

	public:

		RouteCfgDlgDef( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Route preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 496,587 ), long style = wxDEFAULT_DIALOG_STYLE );
		~RouteCfgDlgDef();

};

///////////////////////////////////////////////////////////////////////////////
/// Class RouteDlgDef
///////////////////////////////////////////////////////////////////////////////
class RouteDlgDef : public wxDialog
{
	private:

	protected:

		// Virtual event handlers, overide them in your derived class
		virtual void OnRouteProperties( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRouteCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRouteOkClick( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxChoice* m_chSurvey;

		RouteDlgDef( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("OpenSeaMap"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,550 ), long style = wxDEFAULT_DIALOG_STYLE );
		~RouteDlgDef();

};


#endif //__ROUTEGUI_H__
