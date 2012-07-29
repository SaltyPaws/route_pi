///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "routegui.h"

///////////////////////////////////////////////////////////////////////////

DlgDef::DlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( 2000,2000 ) );
	
	bSframe = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxSize( -1,345 ), 0 );
	m_notebook1->SetMinSize( wxSize( 615,345 ) );
	
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	m_panel1->SetMinSize( wxSize( 615,335 ) );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel6 = new wxPanel( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel6->SetMinSize( wxSize( 300,335 ) );
	
	wxBoxSizer* bSizer9111;
	bSizer9111 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1511 = new wxStaticText( m_panel6, wxID_ANY, _("Great Circle\nRoute"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1511->Wrap( -1 );
	m_staticText1511->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer9111->Add( m_staticText1511, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer1311;
	bSizer1311 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1421;
	bSizer1421 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer22;
	sbSizer22 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, _("Input") ), wxVERTICAL );
	
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3221 = new wxStaticText( m_panel6, wxID_ANY, _("Waypoint\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3221->Wrap( -1 );
	bSizer93->Add( m_staticText3221, 0, wxALL, 5 );
	
	m_IntervalNM = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer93->Add( m_IntervalNM, 0, wxALL, 5 );
	
	m_staticText3321 = new wxStaticText( m_panel6, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3321->Wrap( -1 );
	bSizer93->Add( m_staticText3321, 0, wxALL, 5 );
	
	
	sbSizer22->Add( bSizer93, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button11 = new wxButton( m_panel6, wxID_ANY, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer94->Add( m_button11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button111 = new wxButton( m_panel6, wxID_ANY, _("Export GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer94->Add( m_button111, 0, wxALL, 5 );
	
	
	sbSizer22->Add( bSizer94, 1, wxEXPAND, 5 );
	
	
	bSizer1421->Add( sbSizer22, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer221;
	sbSizer221 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, _("Result") ), wxVERTICAL );
	
	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32211 = new wxStaticText( m_panel6, wxID_ANY, _("Great Circle\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32211->Wrap( -1 );
	bSizer89->Add( m_staticText32211, 0, wxALL, 5 );
	
	m_distance_GC = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer89->Add( m_distance_GC, 0, wxALL, 5 );
	
	m_staticText33211 = new wxStaticText( m_panel6, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33211->Wrap( -1 );
	bSizer89->Add( m_staticText33211, 0, wxALL, 5 );
	
	
	sbSizer221->Add( bSizer89, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer891;
	bSizer891 = new wxBoxSizer( wxHORIZONTAL );
	
	m_statictext234 = new wxStaticText( m_panel6, wxID_ANY, _("Rhumb Line\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_statictext234->Wrap( -1 );
	bSizer891->Add( m_statictext234, 0, wxALL, 5 );
	
	m_distance_RH = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer891->Add( m_distance_RH, 0, wxALL, 5 );
	
	m_staticText332111 = new wxStaticText( m_panel6, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText332111->Wrap( -1 );
	bSizer891->Add( m_staticText332111, 0, wxALL, 5 );
	
	
	sbSizer221->Add( bSizer891, 1, wxEXPAND, 5 );
	
	
	bSizer1421->Add( sbSizer221, 1, wxEXPAND, 5 );
	
	
	bSizer1311->Add( bSizer1421, 0, 0, 5 );
	
	
	bSizer9111->Add( bSizer1311, 0, 0, 5 );
	
	
	m_panel6->SetSizer( bSizer9111 );
	m_panel6->Layout();
	bSizer9111->Fit( m_panel6 );
	bSizer3->Add( m_panel6, 0, wxALL, 5 );
	
	m_bitmap1 = new wxStaticBitmap( m_panel1, wxID_ANY, wxBitmap( wxT("bitmaps/trackln.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap1->SetMinSize( wxSize( 290,300 ) );
	
	bSizer3->Add( m_bitmap1, 0, wxALL, 5 );
	
	
	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("Great Circle"), true );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	m_panel2->SetMinSize( wxSize( -1,335 ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel7 = new wxPanel( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer911;
	bSizer911 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText151 = new wxStaticText( m_panel7, wxID_ANY, _("Expanding Square\n         Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	m_staticText151->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer911->Add( m_staticText151, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText322 = new wxStaticText( m_panel7, wxID_ANY, _("Approach course     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322->Wrap( -1 );
	bSizer142->Add( m_staticText322, 0, wxALL, 5 );
	
	m_textCtrl252 = new wxTextCtrl( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer142->Add( m_textCtrl252, 0, wxALL, 5 );
	
	m_staticText332 = new wxStaticText( m_panel7, wxID_ANY, _("Degrees"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText332->Wrap( -1 );
	bSizer142->Add( m_staticText332, 0, wxALL, 5 );
	
	
	bSizer131->Add( bSizer142, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer1411;
	bSizer1411 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3211 = new wxStaticText( m_panel7, wxID_ANY, _("Leg Distance               "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3211->Wrap( -1 );
	bSizer1411->Add( m_staticText3211, 0, wxALL, 5 );
	
	m_textCtrl2511 = new wxTextCtrl( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1411->Add( m_textCtrl2511, 0, wxALL, 5 );
	
	m_staticText3311 = new wxStaticText( m_panel7, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3311->Wrap( -1 );
	bSizer1411->Add( m_staticText3311, 0, wxALL, 5 );
	
	
	bSizer131->Add( bSizer1411, 0, 0, 5 );
	
	wxBoxSizer* bSizer14111;
	bSizer14111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32111 = new wxStaticText( m_panel7, wxID_ANY, _("Number of Squares"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32111->Wrap( -1 );
	bSizer14111->Add( m_staticText32111, 0, wxALL, 5 );
	
	m_textCtrl25111 = new wxTextCtrl( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14111->Add( m_textCtrl25111, 0, wxALL, 5 );
	
	m_staticText33111 = new wxStaticText( m_panel7, wxID_ANY, _("n"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33111->Wrap( -1 );
	bSizer14111->Add( m_staticText33111, 0, wxALL, 5 );
	
	
	bSizer131->Add( bSizer14111, 0, 0, 5 );
	
	
	bSizer911->Add( bSizer131, 0, 0, 5 );
	
	m_button31 = new wxButton( m_panel7, wxID_ANY, _("Generate &GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer911->Add( m_button31, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	m_panel7->SetSizer( bSizer911 );
	m_panel7->Layout();
	bSizer911->Fit( m_panel7 );
	bSizer4->Add( m_panel7, 0, wxALL, 5 );
	
	m_bitmap2 = new wxStaticBitmap( m_panel2, wxID_ANY, wxBitmap( wxT("bitmaps/exp_sq.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap2->SetMinSize( wxSize( 290,300 ) );
	
	bSizer4->Add( m_bitmap2, 0, wxALL, 5 );
	
	
	m_panel2->SetSizer( bSizer4 );
	m_panel2->Layout();
	bSizer4->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, _("SAR: Expanding Square"), false );
	
	bSframe->Add( m_notebook1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	m_wxNotebook234 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel11 = new wxPanel( m_wxNotebook234, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("Start of Route") ), wxVERTICAL );
	
	wxBoxSizer* bSizer1321;
	bSizer1321 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1431;
	bSizer1431 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3231 = new wxStaticText( m_panel11, wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231->Wrap( -1 );
	bSizer1431->Add( m_staticText3231, 0, wxALL, 5 );
	
	m_Lat1 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431->Add( m_Lat1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3331 = new wxStaticText( m_panel11, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331->Wrap( -1 );
	bSizer1431->Add( m_staticText3331, 0, wxALL, 5 );
	
	
	bSizer1321->Add( bSizer1431, 0, 0, 5 );
	
	wxBoxSizer* bSizer14311;
	bSizer14311 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32311 = new wxStaticText( m_panel11, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32311->Wrap( -1 );
	bSizer14311->Add( m_staticText32311, 0, wxALL, 5 );
	
	m_Lon1 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311->Add( m_Lon1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33311 = new wxStaticText( m_panel11, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33311->Wrap( -1 );
	bSizer14311->Add( m_staticText33311, 0, wxALL, 5 );
	
	
	bSizer1321->Add( bSizer14311, 0, 0, 5 );
	
	
	sbSizer7->Add( bSizer1321, 0, 0, 5 );
	
	
	bSizer40->Add( sbSizer7, 0, 0, 5 );
	
	wxStaticBoxSizer* sbSizer71;
	sbSizer71 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("End of Route") ), wxVERTICAL );
	
	wxBoxSizer* bSizer13211;
	bSizer13211 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14312;
	bSizer14312 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32312 = new wxStaticText( m_panel11, wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32312->Wrap( -1 );
	bSizer14312->Add( m_staticText32312, 0, wxALL, 5 );
	
	m_Lat2 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14312->Add( m_Lat2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33312 = new wxStaticText( m_panel11, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33312->Wrap( -1 );
	bSizer14312->Add( m_staticText33312, 0, wxALL, 5 );
	
	
	bSizer13211->Add( bSizer14312, 0, 0, 5 );
	
	wxBoxSizer* bSizer143111;
	bSizer143111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323111 = new wxStaticText( m_panel11, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323111->Wrap( -1 );
	bSizer143111->Add( m_staticText323111, 0, wxALL, 5 );
	
	m_Lon2 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143111->Add( m_Lon2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText333111 = new wxStaticText( m_panel11, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333111->Wrap( -1 );
	bSizer143111->Add( m_staticText333111, 0, wxALL, 5 );
	
	
	bSizer13211->Add( bSizer143111, 0, 0, 5 );
	
	
	sbSizer71->Add( bSizer13211, 0, 0, 5 );
	
	
	bSizer40->Add( sbSizer71, 0, 0, 5 );
	
	
	m_panel11->SetSizer( bSizer40 );
	m_panel11->Layout();
	bSizer40->Fit( m_panel11 );
	m_wxNotebook234->AddPage( m_panel11, _("Decimal Degree"), true );
	m_panel15 = new wxPanel( m_wxNotebook234, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer401;
	bSizer401 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer72;
	sbSizer72 = new wxStaticBoxSizer( new wxStaticBox( m_panel15, wxID_ANY, _("Start of Route") ), wxVERTICAL );
	
	wxBoxSizer* bSizer13212;
	bSizer13212 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14313;
	bSizer14313 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32313 = new wxStaticText( m_panel15, wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32313->Wrap( -1 );
	bSizer14313->Add( m_staticText32313, 0, wxALL, 5 );
	
	m_Lat1_d = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14313->Add( m_Lat1_d, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33313 = new wxStaticText( m_panel15, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33313->Wrap( -1 );
	bSizer14313->Add( m_staticText33313, 0, wxALL, 5 );
	
	m_Lat1_m = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14313->Add( m_Lat1_m, 0, wxALL, 5 );
	
	m_staticText1143 = new wxStaticText( m_panel15, wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1143->Wrap( -1 );
	bSizer14313->Add( m_staticText1143, 0, wxALL, 5 );
	
	m_Lat1_s = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14313->Add( m_Lat1_s, 0, wxALL, 5 );
	
	m_staticText1153 = new wxStaticText( m_panel15, wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1153->Wrap( -1 );
	bSizer14313->Add( m_staticText1153, 0, wxALL, 5 );
	
	wxString m_Lat1_NSChoices[] = { _("N"), _("S") };
	int m_Lat1_NSNChoices = sizeof( m_Lat1_NSChoices ) / sizeof( wxString );
	m_Lat1_NS = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lat1_NSNChoices, m_Lat1_NSChoices, 0 );
	m_Lat1_NS->SetSelection( 0 );
	bSizer14313->Add( m_Lat1_NS, 0, wxALL, 5 );
	
	
	bSizer13212->Add( bSizer14313, 0, 0, 5 );
	
	wxBoxSizer* bSizer143112;
	bSizer143112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323112 = new wxStaticText( m_panel15, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323112->Wrap( -1 );
	bSizer143112->Add( m_staticText323112, 0, wxALL, 5 );
	
	m_Lon1_d = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143112->Add( m_Lon1_d, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText333112 = new wxStaticText( m_panel15, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333112->Wrap( -1 );
	bSizer143112->Add( m_staticText333112, 0, wxALL, 5 );
	
	m_Lon1_m = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143112->Add( m_Lon1_m, 0, wxALL, 5 );
	
	m_staticText11412 = new wxStaticText( m_panel15, wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11412->Wrap( -1 );
	bSizer143112->Add( m_staticText11412, 0, wxALL, 5 );
	
	m_Lon1_s = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143112->Add( m_Lon1_s, 0, wxALL, 5 );
	
	m_staticText11512 = new wxStaticText( m_panel15, wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11512->Wrap( -1 );
	bSizer143112->Add( m_staticText11512, 0, wxALL, 5 );
	
	wxString m_Lon1_EWChoices[] = { _("E"), _("W") };
	int m_Lon1_EWNChoices = sizeof( m_Lon1_EWChoices ) / sizeof( wxString );
	m_Lon1_EW = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lon1_EWNChoices, m_Lon1_EWChoices, 0 );
	m_Lon1_EW->SetSelection( 0 );
	bSizer143112->Add( m_Lon1_EW, 0, wxALL, 5 );
	
	
	bSizer13212->Add( bSizer143112, 0, 0, 5 );
	
	
	sbSizer72->Add( bSizer13212, 0, 0, 5 );
	
	
	bSizer401->Add( sbSizer72, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer711;
	sbSizer711 = new wxStaticBoxSizer( new wxStaticBox( m_panel15, wxID_ANY, _("End of Route") ), wxVERTICAL );
	
	wxBoxSizer* bSizer132111;
	bSizer132111 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer143121;
	bSizer143121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323121 = new wxStaticText( m_panel15, wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323121->Wrap( -1 );
	bSizer143121->Add( m_staticText323121, 0, wxALL, 5 );
	
	m_Lat2_d = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143121->Add( m_Lat2_d, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText333121 = new wxStaticText( m_panel15, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333121->Wrap( -1 );
	bSizer143121->Add( m_staticText333121, 0, wxALL, 5 );
	
	m_Lat2_m = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143121->Add( m_Lat2_m, 0, wxALL, 5 );
	
	m_staticText11421 = new wxStaticText( m_panel15, wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11421->Wrap( -1 );
	bSizer143121->Add( m_staticText11421, 0, wxALL, 5 );
	
	m_Lat2_s = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143121->Add( m_Lat2_s, 0, wxALL, 5 );
	
	m_staticText11521 = new wxStaticText( m_panel15, wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11521->Wrap( -1 );
	bSizer143121->Add( m_staticText11521, 0, wxALL, 5 );
	
	wxString m_Lat2_NSChoices[] = { _("N"), _("S") };
	int m_Lat2_NSNChoices = sizeof( m_Lat2_NSChoices ) / sizeof( wxString );
	m_Lat2_NS = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lat2_NSNChoices, m_Lat2_NSChoices, 0 );
	m_Lat2_NS->SetSelection( 0 );
	bSizer143121->Add( m_Lat2_NS, 0, wxALL, 5 );
	
	
	bSizer132111->Add( bSizer143121, 0, 0, 5 );
	
	wxBoxSizer* bSizer1431111;
	bSizer1431111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3231111 = new wxStaticText( m_panel15, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231111->Wrap( -1 );
	bSizer1431111->Add( m_staticText3231111, 0, wxALL, 5 );
	
	m_Lon2_d = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431111->Add( m_Lon2_d, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3331111 = new wxStaticText( m_panel15, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331111->Wrap( -1 );
	bSizer1431111->Add( m_staticText3331111, 0, wxALL, 5 );
	
	m_Lon2_m = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431111->Add( m_Lon2_m, 0, wxALL, 5 );
	
	m_staticText114111 = new wxStaticText( m_panel15, wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114111->Wrap( -1 );
	bSizer1431111->Add( m_staticText114111, 0, wxALL, 5 );
	
	m_Lon2_s = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431111->Add( m_Lon2_s, 0, wxALL, 5 );
	
	m_staticText115111 = new wxStaticText( m_panel15, wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115111->Wrap( -1 );
	bSizer1431111->Add( m_staticText115111, 0, wxALL, 5 );
	
	wxString m_Lon2_EWChoices[] = { _("E"), _("W") };
	int m_Lon2_EWNChoices = sizeof( m_Lon2_EWChoices ) / sizeof( wxString );
	m_Lon2_EW = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lon2_EWNChoices, m_Lon2_EWChoices, 0 );
	m_Lon2_EW->SetSelection( 0 );
	bSizer1431111->Add( m_Lon2_EW, 0, wxALL, 5 );
	
	
	bSizer132111->Add( bSizer1431111, 0, 0, 5 );
	
	
	sbSizer711->Add( bSizer132111, 0, 0, 5 );
	
	
	bSizer401->Add( sbSizer711, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button81 = new wxButton( m_panel15, wxID_ANY, _("Convert to Degree"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer481->Add( m_button81, 0, wxALL, 5 );
	
	
	bSizer401->Add( bSizer481, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel15->SetSizer( bSizer401 );
	m_panel15->Layout();
	bSizer401->Fit( m_panel15 );
	m_wxNotebook234->AddPage( m_panel15, _("° ' \""), false );
	
	bSizer35->Add( m_wxNotebook234, 0, wxALL, 5 );
	
	
	bSframe->Add( bSizer35, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSframe );
	this->Layout();
	bSframe->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnGCCalculate ), NULL, this );
	m_button111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportGC ), NULL, this );
	m_wxNotebook234->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DlgDef::OnNoteBookFit ), NULL, this );
	m_button81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConverttoDegree ), NULL, this );
}

DlgDef::~DlgDef()
{
	// Disconnect Events
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnGCCalculate ), NULL, this );
	m_button111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportGC ), NULL, this );
	m_wxNotebook234->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DlgDef::OnNoteBookFit ), NULL, this );
	m_button81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConverttoDegree ), NULL, this );
	
}

CfgDlgDef::CfgDlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General settings") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	sbSizer4->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	sbSizer4->Add( m_staticText17, 0, wxALL, 5 );
	
	m_sOpacity = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer4->Add( m_sOpacity, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer1->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

CfgDlgDef::~CfgDlgDef()
{
}
