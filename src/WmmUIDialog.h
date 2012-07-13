///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WMMUIDIALOG_H__
#define __WMMUIDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/notebook.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/button.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WmmUIDialog
///////////////////////////////////////////////////////////////////////////////
class WmmUIDialog : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxStaticBitmap* m_bitmap1;
		wxPanel* m_panel2;
		wxStaticBitmap* m_bitmap2;
		wxPanel* m_panel3;
		wxStaticBitmap* m_bitmap3;
		wxPanel* m_panel4;
		wxStaticBitmap* m_bitmap4;
		wxPanel* m_panel5;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText81;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText101;
		wxStaticText* m_staticText111;
		wxStaticText* m_staticText121;
		wxStaticText* m_staticText141;
		wxStaticText* m_staticText131;
	
	public:
		wxBoxSizer* bSframe;
		wxBoxSizer* bSframe1;
		wxStaticBoxSizer* sbSboat;
		wxFlexGridSizer* gSboat;
		wxTextCtrl* m_tbF;
		wxTextCtrl* m_tbH;
		wxTextCtrl* m_tbX;
		wxTextCtrl* m_tbY;
		wxTextCtrl* m_tbZ;
		wxTextCtrl* m_tbI;
		wxTextCtrl* m_tbD;
		wxStaticBoxSizer* sbScursor;
		wxFlexGridSizer* gScursor;
		wxTextCtrl* m_tcF;
		wxTextCtrl* m_tcH;
		wxTextCtrl* m_tcX;
		wxTextCtrl* m_tcY;
		wxTextCtrl* m_tcZ;
		wxTextCtrl* m_tcI;
		wxTextCtrl* m_tcD;
		
		WmmUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SAR & Route"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 691,650 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxTAB_TRAVERSAL ); 
		~WmmUIDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WmmPrefsDialog
///////////////////////////////////////////////////////////////////////////////
class WmmPrefsDialog : public wxDialog 
{
	private:
	
	protected:
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
	
	public:
		wxRadioBox* m_rbViewType;
		wxCheckBox* m_cbShowAtCursor;
		wxCheckBox* m_cbLiveIcon;
		wxSlider* m_sOpacity;
		
		WmmPrefsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("WMM Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE ); 
		~WmmPrefsDialog();
	
};

#endif //__WMMUIDIALOG_H__
