///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __UIDIALOG_H__
#define __UIDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/notebook.h>
#include <wx/statbox.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/slider.h>

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
		wxPanel* m_panel6;
		wxStaticText* m_staticText1511;
		wxStaticText* m_staticText3221;
		wxTextCtrl* m_textCtrl2521;
		wxStaticText* m_staticText3321;
		wxStaticText* m_staticText32112;
		wxTextCtrl* m_textCtrl25112;
		wxStaticText* m_staticText33112;
		wxStaticText* m_staticText321111;
		wxTextCtrl* m_textCtrl251111;
		wxStaticText* m_staticText331111;
		wxStaticText* m_staticText3211111;
		wxTextCtrl* m_textCtrl2511111;
		wxStaticText* m_staticText3311111;
		wxStaticText* m_staticText32111111;
		wxChoice* m_choice1;
		wxButton* m_button311;
		wxStaticBitmap* m_bitmap1;
		wxPanel* m_panel2;
		wxPanel* m_panel7;
		wxStaticText* m_staticText151;
		wxStaticText* m_staticText322;
		wxTextCtrl* m_textCtrl252;
		wxStaticText* m_staticText332;
		wxStaticText* m_staticText3211;
		wxTextCtrl* m_textCtrl2511;
		wxStaticText* m_staticText3311;
		wxStaticText* m_staticText32111;
		wxTextCtrl* m_textCtrl25111;
		wxStaticText* m_staticText33111;
		wxButton* m_button31;
		wxStaticBitmap* m_bitmap2;
		wxPanel* m_panel3;
		wxPanel* m_panel8;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_textCtrl25;
		wxStaticText* m_staticText33;
		wxStaticText* m_staticText321;
		wxTextCtrl* m_textCtrl251;
		wxStaticText* m_staticText331;
		wxButton* m_button3;
		wxStaticBitmap* m_bitmap3;
		wxPanel* m_panel4;
		wxPanel* m_panel10;
		wxStaticText* m_staticText152;
		wxStaticText* m_staticText323;
		wxTextCtrl* m_textCtrl253;
		wxStaticText* m_staticText333;
		wxStaticText* m_staticText3212;
		wxTextCtrl* m_textCtrl2512;
		wxStaticText* m_staticText3312;
		wxStaticText* m_staticText32121;
		wxTextCtrl* m_textCtrl25121;
		wxStaticText* m_staticText33121;
		wxButton* m_button32;
		wxStaticBitmap* m_bitmap4;
		wxPanel* m_panel11;
		wxStaticText* m_staticText3231;
		wxTextCtrl* m_textCtrl2531;
		wxStaticText* m_staticText3331;
		wxTextCtrl* m_textCtrl61;
		wxStaticText* m_staticText114;
		wxTextCtrl* m_textCtrl62;
		wxStaticText* m_staticText115;
		wxStaticText* m_staticText32311;
		wxTextCtrl* m_textCtrl25311;
		wxStaticText* m_staticText33311;
		wxTextCtrl* m_textCtrl611;
		wxStaticText* m_staticText1141;
		wxTextCtrl* m_textCtrl621;
		wxStaticText* m_staticText1151;
	
	public:
		wxBoxSizer* bSframe;
		
		WmmUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SAR & Route"), const wxPoint& pos = wxPoint( 20,20 ), const wxSize& size = wxSize( 626,506 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER|wxTAB_TRAVERSAL ); 
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

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog3
///////////////////////////////////////////////////////////////////////////////
class MyDialog3 : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel12;
		wxStaticText* m_staticText95;
		wxButton* m_button10;
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
		
		MyDialog3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog3();
	
};

#endif //__UIDIALOG_H__
