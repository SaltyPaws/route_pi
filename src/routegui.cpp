///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "routegui.h"

///////////////////////////////////////////////////////////////////////////

DlgDef::DlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	bSframe = new wxBoxSizer( wxHORIZONTAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel6 = new wxPanel( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	
	m_staticText3221 = new wxStaticText( sbSizer22->GetStaticBox(), wxID_ANY, _("Waypoint\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3221->Wrap( -1 );
	bSizer93->Add( m_staticText3221, 0, wxALL, 5 );
	
	m_IntervalNM = new wxTextCtrl( sbSizer22->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer93->Add( m_IntervalNM, 0, wxALL, 5 );
	
	m_staticText3321 = new wxStaticText( sbSizer22->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3321->Wrap( -1 );
	bSizer93->Add( m_staticText3321, 0, wxALL, 5 );
	
	
	sbSizer22->Add( bSizer93, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button11 = new wxButton( sbSizer22->GetStaticBox(), wxID_ANY, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button11->SetToolTip( _("Show distances in result. Calculate is not required for route export.") );
	
	bSizer94->Add( m_button11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer22->Add( bSizer94, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer1421->Add( sbSizer22, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer221;
	sbSizer221 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, _("Result") ), wxVERTICAL );
	
	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32211 = new wxStaticText( sbSizer221->GetStaticBox(), wxID_ANY, _("Great Circle\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32211->Wrap( -1 );
	bSizer89->Add( m_staticText32211, 0, wxALL, 5 );
	
	m_distance_GC = new wxTextCtrl( sbSizer221->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer89->Add( m_distance_GC, 0, wxALL, 5 );
	
	m_staticText33211 = new wxStaticText( sbSizer221->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33211->Wrap( -1 );
	bSizer89->Add( m_staticText33211, 0, wxALL, 5 );
	
	
	sbSizer221->Add( bSizer89, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer891;
	bSizer891 = new wxBoxSizer( wxHORIZONTAL );
	
	m_statictext234 = new wxStaticText( sbSizer221->GetStaticBox(), wxID_ANY, _("Rhumb Line\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_statictext234->Wrap( -1 );
	bSizer891->Add( m_statictext234, 0, wxALL, 5 );
	
	m_distance_RH = new wxTextCtrl( sbSizer221->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer891->Add( m_distance_RH, 0, wxALL, 5 );
	
	m_staticText332111 = new wxStaticText( sbSizer221->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText332111->Wrap( -1 );
	bSizer891->Add( m_staticText332111, 0, wxALL, 5 );
	
	
	sbSizer221->Add( bSizer891, 1, wxEXPAND, 5 );
	
	
	bSizer1421->Add( sbSizer221, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, _("Export") ), wxVERTICAL );
	
	m_button111 = new wxButton( sbSizer11->GetStaticBox(), wxID_ANY, _("Great Circle (shortest) GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button111, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button6 = new wxButton( sbSizer11->GetStaticBox(), wxID_ANY, _("Rhumb Line (fixed heading) GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer1421->Add( sbSizer11, 1, wxEXPAND, 5 );
	
	
	bSizer1311->Add( bSizer1421, 0, 0, 5 );
	
	
	bSizer9111->Add( bSizer1311, 0, 0, 5 );
	
	
	m_panel6->SetSizer( bSizer9111 );
	m_panel6->Layout();
	bSizer9111->Fit( m_panel6 );
	bSizer3->Add( m_panel6, 0, wxALL, 5 );
	
	
	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("Great Circle"), true );
	m_panel12 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel61 = new wxPanel( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer91111;
	bSizer91111 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText15111 = new wxStaticText( m_panel61, wxID_ANY, _("Limited Circle\nRoute"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15111->Wrap( -1 );
	m_staticText15111->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer91111->Add( m_staticText15111, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer13111;
	bSizer13111 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14211;
	bSizer14211 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer222;
	sbSizer222 = new wxStaticBoxSizer( new wxStaticBox( m_panel61, wxID_ANY, _("Input") ), wxVERTICAL );
	
	wxBoxSizer* bSizer931;
	bSizer931 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32212 = new wxStaticText( sbSizer222->GetStaticBox(), wxID_ANY, _("Waypoint\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32212->Wrap( -1 );
	bSizer931->Add( m_staticText32212, 0, wxALL, 5 );
	
	m_IntervalNM1 = new wxTextCtrl( sbSizer222->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer931->Add( m_IntervalNM1, 0, wxALL, 5 );
	
	m_staticText33212 = new wxStaticText( sbSizer222->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33212->Wrap( -1 );
	bSizer931->Add( m_staticText33212, 0, wxALL, 5 );
	
	
	sbSizer222->Add( bSizer931, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9311;
	bSizer9311 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText322121 = new wxStaticText( sbSizer222->GetStaticBox(), wxID_ANY, _("Latitude  \nLimit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322121->Wrap( -1 );
	bSizer9311->Add( m_staticText322121, 0, wxALL, 5 );
	
	m_LatLimit = new wxTextCtrl( sbSizer222->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9311->Add( m_LatLimit, 0, wxALL, 5 );
	
	m_staticText3331112 = new wxStaticText( sbSizer222->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331112->Wrap( -1 );
	bSizer9311->Add( m_staticText3331112, 0, wxALL, 5 );
	
	
	sbSizer222->Add( bSizer9311, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer941;
	bSizer941 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button112 = new wxButton( sbSizer222->GetStaticBox(), wxID_ANY, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button112->SetToolTip( _("Show distances in result. Calculate is not required for route export.") );
	
	bSizer941->Add( m_button112, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer222->Add( bSizer941, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer14211->Add( sbSizer222, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2211;
	sbSizer2211 = new wxStaticBoxSizer( new wxStaticBox( m_panel61, wxID_ANY, _("Result") ), wxVERTICAL );
	
	wxBoxSizer* bSizer892;
	bSizer892 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText322111 = new wxStaticText( sbSizer2211->GetStaticBox(), wxID_ANY, _("Limited Circle\nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322111->Wrap( -1 );
	bSizer892->Add( m_staticText322111, 0, wxALL, 5 );
	
	m_distance_LC = new wxTextCtrl( sbSizer2211->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer892->Add( m_distance_LC, 0, wxALL, 5 );
	
	m_staticText332112 = new wxStaticText( sbSizer2211->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText332112->Wrap( -1 );
	bSizer892->Add( m_staticText332112, 0, wxALL, 5 );
	
	
	sbSizer2211->Add( bSizer892, 0, 0, 5 );
	
	wxBoxSizer* bSizer8911;
	bSizer8911 = new wxBoxSizer( wxHORIZONTAL );
	
	m_statictext2341 = new wxStaticText( sbSizer2211->GetStaticBox(), wxID_ANY, _("Great Circle     \nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_statictext2341->Wrap( -1 );
	bSizer8911->Add( m_statictext2341, 0, wxALL, 5 );
	
	m_distance_GC1 = new wxTextCtrl( sbSizer2211->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer8911->Add( m_distance_GC1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3321111 = new wxStaticText( sbSizer2211->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3321111->Wrap( -1 );
	bSizer8911->Add( m_staticText3321111, 0, wxALL, 5 );
	
	
	sbSizer2211->Add( bSizer8911, 0, 0, 5 );
	
	wxBoxSizer* bSizer89111;
	bSizer89111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_statictext23411 = new wxStaticText( sbSizer2211->GetStaticBox(), wxID_ANY, _("Rhumb Line     \nDistance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_statictext23411->Wrap( -1 );
	bSizer89111->Add( m_statictext23411, 0, wxALL, 5 );
	
	m_distance_RH1 = new wxTextCtrl( sbSizer2211->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer89111->Add( m_distance_RH1, 0, wxALL, 5 );
	
	m_staticText33211111 = new wxStaticText( sbSizer2211->GetStaticBox(), wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33211111->Wrap( -1 );
	bSizer89111->Add( m_staticText33211111, 0, wxALL, 5 );
	
	
	sbSizer2211->Add( bSizer89111, 0, 0, 5 );
	
	
	bSizer14211->Add( sbSizer2211, 0, 0, 5 );
	
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_panel61, wxID_ANY, _("Export") ), wxVERTICAL );
	
	m_button1111 = new wxButton( sbSizer12->GetStaticBox(), wxID_ANY, _("Limited Circle GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer12->Add( m_button1111, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer14211->Add( sbSizer12, 1, wxEXPAND, 5 );
	
	
	bSizer13111->Add( bSizer14211, 0, 0, 5 );
	
	
	bSizer91111->Add( bSizer13111, 0, 0, 5 );
	
	
	m_panel61->SetSizer( bSizer91111 );
	m_panel61->Layout();
	bSizer91111->Fit( m_panel61 );
	bSizer31->Add( m_panel61, 0, wxALL, 5 );
	
	
	m_panel12->SetSizer( bSizer31 );
	m_panel12->Layout();
	bSizer31->Fit( m_panel12 );
	m_notebook1->AddPage( m_panel12, _("Limited Circle"), false );
	
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
	
	m_staticText3231 = new wxStaticText( sbSizer7->GetStaticBox(), wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231->Wrap( -1 );
	bSizer1431->Add( m_staticText3231, 0, wxALL, 5 );
	
	m_Lat1 = new wxTextCtrl( sbSizer7->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431->Add( m_Lat1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3331 = new wxStaticText( sbSizer7->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331->Wrap( -1 );
	bSizer1431->Add( m_staticText3331, 0, wxALL, 5 );
	
	
	bSizer1321->Add( bSizer1431, 0, 0, 5 );
	
	wxBoxSizer* bSizer14311;
	bSizer14311 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32311 = new wxStaticText( sbSizer7->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32311->Wrap( -1 );
	bSizer14311->Add( m_staticText32311, 0, wxALL, 5 );
	
	m_Lon1 = new wxTextCtrl( sbSizer7->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311->Add( m_Lon1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33311 = new wxStaticText( sbSizer7->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33311->Wrap( -1 );
	bSizer14311->Add( m_staticText33311, 0, wxALL, 5 );
	
	
	bSizer1321->Add( bSizer14311, 0, 0, 5 );
	
	
	sbSizer7->Add( bSizer1321, 0, 0, 5 );
	
	
	bSizer40->Add( sbSizer7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer71;
	sbSizer71 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("End of Route") ), wxVERTICAL );
	
	wxBoxSizer* bSizer13211;
	bSizer13211 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14312;
	bSizer14312 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32312 = new wxStaticText( sbSizer71->GetStaticBox(), wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32312->Wrap( -1 );
	bSizer14312->Add( m_staticText32312, 0, wxALL, 5 );
	
	m_Lat2 = new wxTextCtrl( sbSizer71->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14312->Add( m_Lat2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33312 = new wxStaticText( sbSizer71->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33312->Wrap( -1 );
	bSizer14312->Add( m_staticText33312, 0, wxALL, 5 );
	
	
	bSizer13211->Add( bSizer14312, 0, 0, 5 );
	
	wxBoxSizer* bSizer143111;
	bSizer143111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323111 = new wxStaticText( sbSizer71->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323111->Wrap( -1 );
	bSizer143111->Add( m_staticText323111, 0, wxALL, 5 );
	
	m_Lon2 = new wxTextCtrl( sbSizer71->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143111->Add( m_Lon2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText333111 = new wxStaticText( sbSizer71->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333111->Wrap( -1 );
	bSizer143111->Add( m_staticText333111, 0, wxALL, 5 );
	
	
	bSizer13211->Add( bSizer143111, 0, 0, 5 );
	
	
	sbSizer71->Add( bSizer13211, 0, 0, 5 );
	
	
	bSizer40->Add( sbSizer71, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer712;
	sbSizer712 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("Naming") ), wxVERTICAL );
	
	wxBoxSizer* bSizer132112;
	bSizer132112 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer143122;
	bSizer143122 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323122 = new wxStaticText( sbSizer712->GetStaticBox(), wxID_ANY, _("Route"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323122->Wrap( -1 );
	bSizer143122->Add( m_staticText323122, 0, wxALL, 5 );
	
	m_Route = new wxTextCtrl( sbSizer712->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143122->Add( m_Route, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer132112->Add( bSizer143122, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1431112;
	bSizer1431112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3231112 = new wxStaticText( sbSizer712->GetStaticBox(), wxID_ANY, _("Start  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231112->Wrap( -1 );
	bSizer1431112->Add( m_staticText3231112, 0, wxALL, 5 );
	
	m_Start = new wxTextCtrl( sbSizer712->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431112->Add( m_Start, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer132112->Add( bSizer1431112, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14311121;
	bSizer14311121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32311121 = new wxStaticText( sbSizer712->GetStaticBox(), wxID_ANY, _("End     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32311121->Wrap( -1 );
	bSizer14311121->Add( m_staticText32311121, 0, wxALL, 5 );
	
	m_End = new wxTextCtrl( sbSizer712->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311121->Add( m_End, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer132112->Add( bSizer14311121, 0, wxEXPAND, 5 );
	
	
	sbSizer712->Add( bSizer132112, 0, wxEXPAND, 5 );
	
	
	bSizer40->Add( sbSizer712, 0, wxEXPAND, 5 );
	
	
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
	
	m_staticText32313 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("Lat "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32313->Wrap( -1 );
	bSizer14313->Add( m_staticText32313, 0, wxALL, 5 );
	
	m_Lat1_d = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer14313->Add( m_Lat1_d, 0, wxALL, 5 );
	
	m_staticText33313 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText33313->Wrap( -1 );
	bSizer14313->Add( m_staticText33313, 0, wxALL, 5 );
	
	m_Lat1_m = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer14313->Add( m_Lat1_m, 0, wxALL, 5 );
	
	m_staticText1143 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1143->Wrap( -1 );
	bSizer14313->Add( m_staticText1143, 0, wxALL, 5 );
	
	m_Lat1_s = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer14313->Add( m_Lat1_s, 0, wxALL, 5 );
	
	m_staticText1153 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1153->Wrap( -1 );
	bSizer14313->Add( m_staticText1153, 0, wxALL, 5 );
	
	wxString m_Lat1_NSChoices[] = { _("N"), _("S") };
	int m_Lat1_NSNChoices = sizeof( m_Lat1_NSChoices ) / sizeof( wxString );
	m_Lat1_NS = new wxChoice( sbSizer72->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lat1_NSNChoices, m_Lat1_NSChoices, 0 );
	m_Lat1_NS->SetSelection( 0 );
	bSizer14313->Add( m_Lat1_NS, 0, wxALL, 5 );
	
	
	bSizer13212->Add( bSizer14313, 0, 0, 5 );
	
	wxBoxSizer* bSizer143112;
	bSizer143112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323112 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("Lon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323112->Wrap( -1 );
	bSizer143112->Add( m_staticText323112, 0, wxALL, 5 );
	
	m_Lon1_d = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143112->Add( m_Lon1_d, 0, wxALL, 5 );
	
	m_staticText333112 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333112->Wrap( -1 );
	bSizer143112->Add( m_staticText333112, 0, wxALL, 5 );
	
	m_Lon1_m = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143112->Add( m_Lon1_m, 0, wxALL, 5 );
	
	m_staticText11412 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11412->Wrap( -1 );
	bSizer143112->Add( m_staticText11412, 0, wxALL, 5 );
	
	m_Lon1_s = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143112->Add( m_Lon1_s, 0, wxALL, 5 );
	
	m_staticText11512 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11512->Wrap( -1 );
	bSizer143112->Add( m_staticText11512, 0, wxALL, 5 );
	
	wxString m_Lon1_EWChoices[] = { _("E"), _("W") };
	int m_Lon1_EWNChoices = sizeof( m_Lon1_EWChoices ) / sizeof( wxString );
	m_Lon1_EW = new wxChoice( sbSizer72->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lon1_EWNChoices, m_Lon1_EWChoices, 0 );
	m_Lon1_EW->SetSelection( 0 );
	bSizer143112->Add( m_Lon1_EW, 0, wxALL, 5 );
	
	
	bSizer13212->Add( bSizer143112, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	sbSizer72->Add( bSizer13212, 0, 0, 5 );
	
	
	bSizer401->Add( sbSizer72, 0, 0, 5 );
	
	wxStaticBoxSizer* sbSizer711;
	sbSizer711 = new wxStaticBoxSizer( new wxStaticBox( m_panel15, wxID_ANY, _("End of Route") ), wxVERTICAL );
	
	wxBoxSizer* bSizer132111;
	bSizer132111 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer143121;
	bSizer143121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323121 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("Lat "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323121->Wrap( -1 );
	bSizer143121->Add( m_staticText323121, 0, wxALL, 5 );
	
	m_Lat2_d = new wxTextCtrl( sbSizer711->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143121->Add( m_Lat2_d, 0, wxALL, 5 );
	
	m_staticText333121 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333121->Wrap( -1 );
	bSizer143121->Add( m_staticText333121, 0, wxALL, 5 );
	
	m_Lat2_m = new wxTextCtrl( sbSizer711->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143121->Add( m_Lat2_m, 0, wxALL, 5 );
	
	m_staticText11421 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11421->Wrap( -1 );
	bSizer143121->Add( m_staticText11421, 0, wxALL, 5 );
	
	m_Lat2_s = new wxTextCtrl( sbSizer711->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143121->Add( m_Lat2_s, 0, wxALL, 5 );
	
	m_staticText11521 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11521->Wrap( -1 );
	bSizer143121->Add( m_staticText11521, 0, wxALL, 5 );
	
	wxString m_Lat2_NSChoices[] = { _("N"), _("S") };
	int m_Lat2_NSNChoices = sizeof( m_Lat2_NSChoices ) / sizeof( wxString );
	m_Lat2_NS = new wxChoice( sbSizer711->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lat2_NSNChoices, m_Lat2_NSChoices, 0 );
	m_Lat2_NS->SetSelection( 0 );
	bSizer143121->Add( m_Lat2_NS, 0, wxALL, 5 );
	
	
	bSizer132111->Add( bSizer143121, 0, 0, 5 );
	
	wxBoxSizer* bSizer1431111;
	bSizer1431111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3231111 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("Lon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231111->Wrap( -1 );
	bSizer1431111->Add( m_staticText3231111, 0, wxALL, 5 );
	
	m_Lon2_d = new wxTextCtrl( sbSizer711->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer1431111->Add( m_Lon2_d, 0, wxALL, 5 );
	
	m_staticText3331111 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331111->Wrap( -1 );
	bSizer1431111->Add( m_staticText3331111, 0, wxALL, 5 );
	
	m_Lon2_m = new wxTextCtrl( sbSizer711->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer1431111->Add( m_Lon2_m, 0, wxALL, 5 );
	
	m_staticText114111 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114111->Wrap( -1 );
	bSizer1431111->Add( m_staticText114111, 0, wxALL, 5 );
	
	m_Lon2_s = new wxTextCtrl( sbSizer711->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer1431111->Add( m_Lon2_s, 0, wxALL, 5 );
	
	m_staticText115111 = new wxStaticText( sbSizer711->GetStaticBox(), wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115111->Wrap( -1 );
	bSizer1431111->Add( m_staticText115111, 0, wxALL, 5 );
	
	wxString m_Lon2_EWChoices[] = { _("E"), _("W") };
	int m_Lon2_EWNChoices = sizeof( m_Lon2_EWChoices ) / sizeof( wxString );
	m_Lon2_EW = new wxChoice( sbSizer711->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lon2_EWNChoices, m_Lon2_EWChoices, 0 );
	m_Lon2_EW->SetSelection( 0 );
	bSizer1431111->Add( m_Lon2_EW, 0, wxALL, 5 );
	
	
	bSizer132111->Add( bSizer1431111, 0, 0, 5 );
	
	
	sbSizer711->Add( bSizer132111, 0, 0, 5 );
	
	
	bSizer401->Add( sbSizer711, 0, 0, 5 );
	
	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button81 = new wxButton( m_panel15, wxID_ANY, _("Convert to Degree"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button81->SetToolTip( _("Degrees, minutes and seconds can be entered as fraction or as decimal.") );
	
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
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportRH ), NULL, this );
	m_button112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnGCLCalculate ), NULL, this );
	m_button1111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportGCL ), NULL, this );
	m_wxNotebook234->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DlgDef::OnNoteBookFit ), NULL, this );
	m_button81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConverttoDegree ), NULL, this );
}

DlgDef::~DlgDef()
{
	// Disconnect Events
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnGCCalculate ), NULL, this );
	m_button111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportGC ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportRH ), NULL, this );
	m_button112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnGCLCalculate ), NULL, this );
	m_button1111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnExportGCL ), NULL, this );
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
	
	m_staticText17 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	sbSizer4->Add( m_staticText17, 0, wxALL, 5 );
	
	m_sOpacity = new wxSlider( sbSizer4->GetStaticBox(), wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
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
