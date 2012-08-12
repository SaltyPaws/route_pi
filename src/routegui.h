///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
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
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/slider.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DlgDef
///////////////////////////////////////////////////////////////////////////////
class DlgDef : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxPanel* m_panel6;
		wxStaticText* m_staticText1511;
		wxStaticText* m_staticText3221;
		wxTextCtrl* m_IntervalNM;
		wxStaticText* m_staticText3321;
		wxButton* m_button11;
		wxStaticText* m_staticText32211;
		wxTextCtrl* m_distance_GC;
		wxStaticText* m_staticText33211;
		wxStaticText* m_statictext234;
		wxTextCtrl* m_distance_RH;
		wxStaticText* m_staticText332111;
		wxButton* m_button111;
		wxButton* m_button6;
		wxPanel* m_panel12;
		wxPanel* m_panel61;
		wxStaticText* m_staticText15111;
		wxStaticText* m_staticText32212;
		wxTextCtrl* m_IntervalNM1;
		wxStaticText* m_staticText33212;
		wxStaticText* m_staticText322121;
		wxTextCtrl* m_LatLimit;
		wxStaticText* m_staticText332121;
		wxButton* m_button112;
		wxStaticText* m_staticText322111;
		wxTextCtrl* m_distance_LC;
		wxStaticText* m_staticText332112;
		wxStaticText* m_statictext2341;
		wxTextCtrl* m_distance_GC1;
		wxStaticText* m_staticText3321111;
		wxStaticText* m_statictext23411;
		wxTextCtrl* m_distance_RH1;
		wxStaticText* m_staticText33211111;
		wxButton* m_button1111;
		wxNotebook* m_wxNotebook234;
		wxPanel* m_panel11;
		wxStaticText* m_staticText3231;
		wxTextCtrl* m_Lat1;
		wxStaticText* m_staticText3331;
		wxStaticText* m_staticText32311;
		wxTextCtrl* m_Lon1;
		wxStaticText* m_staticText33311;
		wxStaticText* m_staticText32312;
		wxTextCtrl* m_Lat2;
		wxStaticText* m_staticText33312;
		wxStaticText* m_staticText323111;
		wxTextCtrl* m_Lon2;
		wxStaticText* m_staticText333111;
		wxStaticText* m_staticText323122;
		wxTextCtrl* m_Route;
		wxStaticText* m_staticText3231112;
		wxTextCtrl* m_Start;
		wxStaticText* m_staticText32311121;
		wxTextCtrl* m_End;
		wxPanel* m_panel15;
		wxStaticText* m_staticText32313;
		wxTextCtrl* m_Lat1_d;
		wxStaticText* m_staticText33313;
		wxTextCtrl* m_Lat1_m;
		wxStaticText* m_staticText1143;
		wxTextCtrl* m_Lat1_s;
		wxStaticText* m_staticText1153;
		wxChoice* m_Lat1_NS;
		wxStaticText* m_staticText323112;
		wxTextCtrl* m_Lon1_d;
		wxStaticText* m_staticText333112;
		wxTextCtrl* m_Lon1_m;
		wxStaticText* m_staticText11412;
		wxTextCtrl* m_Lon1_s;
		wxStaticText* m_staticText11512;
		wxChoice* m_Lon1_EW;
		wxStaticText* m_staticText323121;
		wxTextCtrl* m_Lat2_d;
		wxStaticText* m_staticText333121;
		wxTextCtrl* m_Lat2_m;
		wxStaticText* m_staticText11421;
		wxTextCtrl* m_Lat2_s;
		wxStaticText* m_staticText11521;
		wxChoice* m_Lat2_NS;
		wxStaticText* m_staticText3231111;
		wxTextCtrl* m_Lon2_d;
		wxStaticText* m_staticText3331111;
		wxTextCtrl* m_Lon2_m;
		wxStaticText* m_staticText114111;
		wxTextCtrl* m_Lon2_s;
		wxStaticText* m_staticText115111;
		wxChoice* m_Lon2_EW;
		wxButton* m_button81;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnGCCalculate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportGC( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportRH( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGCLCalculate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportGCL( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNoteBookFit( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnConverttoDegree( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxBoxSizer* bSframe;
		
		DlgDef( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Menu"), const wxPoint& pos = wxPoint( 20,20 ), const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxTAB_TRAVERSAL ); 
		~DlgDef();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CfgDlgDef
///////////////////////////////////////////////////////////////////////////////
class CfgDlgDef : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText17;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
	
	public:
		wxSlider* m_sOpacity;
		
		CfgDlgDef( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CfgDlgDef();
	
};

#endif //__ROUTEGUI_H__
