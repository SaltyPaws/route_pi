///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UIDialog.h"

///////////////////////////////////////////////////////////////////////////

WmmUIDialog::WmmUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	m_staticText1511 = new wxStaticText( m_panel6, wxID_ANY, _("Paralell Search\n     Pattern"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1511->Wrap( -1 );
	m_staticText1511->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer9111->Add( m_staticText1511, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer1311;
	bSizer1311 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1421;
	bSizer1421 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3221 = new wxStaticText( m_panel6, wxID_ANY, _("Approach course     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3221->Wrap( -1 );
	bSizer1421->Add( m_staticText3221, 0, wxALL, 5 );
	
	m_textCtrl2521 = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1421->Add( m_textCtrl2521, 0, wxALL, 5 );
	
	m_staticText3321 = new wxStaticText( m_panel6, wxID_ANY, _("Degrees"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3321->Wrap( -1 );
	bSizer1421->Add( m_staticText3321, 0, wxALL, 5 );
	
	
	bSizer1311->Add( bSizer1421, 0, 0, 5 );
	
	wxBoxSizer* bSizer14112;
	bSizer14112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32112 = new wxStaticText( m_panel6, wxID_ANY, _("Leg Distance x           "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32112->Wrap( -1 );
	bSizer14112->Add( m_staticText32112, 0, wxALL, 5 );
	
	m_textCtrl25112 = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14112->Add( m_textCtrl25112, 0, wxALL, 5 );
	
	m_staticText33112 = new wxStaticText( m_panel6, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33112->Wrap( -1 );
	bSizer14112->Add( m_staticText33112, 0, wxALL, 5 );
	
	
	bSizer1311->Add( bSizer14112, 0, 0, 5 );
	
	wxBoxSizer* bSizer141111;
	bSizer141111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText321111 = new wxStaticText( m_panel6, wxID_ANY, _("Leg Distance y           "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321111->Wrap( -1 );
	bSizer141111->Add( m_staticText321111, 0, wxALL, 5 );
	
	m_textCtrl251111 = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer141111->Add( m_textCtrl251111, 0, wxALL, 5 );
	
	m_staticText331111 = new wxStaticText( m_panel6, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText331111->Wrap( -1 );
	bSizer141111->Add( m_staticText331111, 0, wxALL, 5 );
	
	
	bSizer1311->Add( bSizer141111, 0, 0, 5 );
	
	wxBoxSizer* bSizer1411111;
	bSizer1411111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3211111 = new wxStaticText( m_panel6, wxID_ANY, _("Number of Legs       "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3211111->Wrap( -1 );
	bSizer1411111->Add( m_staticText3211111, 0, wxALL, 5 );
	
	m_textCtrl2511111 = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1411111->Add( m_textCtrl2511111, 0, wxALL, 5 );
	
	m_staticText3311111 = new wxStaticText( m_panel6, wxID_ANY, _("n"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3311111->Wrap( -1 );
	bSizer1411111->Add( m_staticText3311111, 0, wxALL, 5 );
	
	
	bSizer1311->Add( bSizer1411111, 0, 0, 5 );
	
	wxBoxSizer* bSizer14111111;
	bSizer14111111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32111111 = new wxStaticText( m_panel6, wxID_ANY, _("Number of Ships      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32111111->Wrap( -1 );
	bSizer14111111->Add( m_staticText32111111, 0, wxALL, 5 );
	
	wxString m_choice1Choices[] = { _("1"), _("2") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( m_panel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer14111111->Add( m_choice1, 0, wxALL, 5 );
	
	
	bSizer1311->Add( bSizer14111111, 0, 0, 5 );
	
	
	bSizer9111->Add( bSizer1311, 0, 0, 5 );
	
	m_button311 = new wxButton( m_panel6, wxID_ANY, _("Generate &GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_button311, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
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
	m_notebook1->AddPage( m_panel1, _("SAR: Trackline"), false );
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
	m_notebook1->AddPage( m_panel2, _("SAR: Expanding Square"), true );
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel8 = new wxPanel( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText15 = new wxStaticText( m_panel8, wxID_ANY, _("Sector Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer91->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( m_panel8, wxID_ANY, _("Approach course"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer14->Add( m_staticText32, 0, wxALL, 5 );
	
	m_textCtrl25 = new wxTextCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_textCtrl25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33 = new wxStaticText( m_panel8, wxID_ANY, _("Degrees"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer14->Add( m_staticText33, 0, wxALL, 5 );
	
	
	bSizer13->Add( bSizer14, 0, 0, 5 );
	
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText321 = new wxStaticText( m_panel8, wxID_ANY, _("Leg Distance          "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer141->Add( m_staticText321, 0, wxALL, 5 );
	
	m_textCtrl251 = new wxTextCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer141->Add( m_textCtrl251, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText331 = new wxStaticText( m_panel8, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText331->Wrap( -1 );
	bSizer141->Add( m_staticText331, 0, wxALL, 5 );
	
	
	bSizer13->Add( bSizer141, 0, 0, 5 );
	
	
	bSizer91->Add( bSizer13, 0, 0, 5 );
	
	m_button3 = new wxButton( m_panel8, wxID_ANY, _("Generate &GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer91->Add( m_button3, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	m_panel8->SetSizer( bSizer91 );
	m_panel8->Layout();
	bSizer91->Fit( m_panel8 );
	bSizer5->Add( m_panel8, 0, wxALL, 5 );
	
	m_bitmap3 = new wxStaticBitmap( m_panel3, wxID_ANY, wxBitmap( wxT("bitmaps/sector.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap3->SetMinSize( wxSize( 280,300 ) );
	
	bSizer5->Add( m_bitmap3, 0, wxALL, 5 );
	
	
	m_panel3->SetSizer( bSizer5 );
	m_panel3->Layout();
	bSizer5->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("SAR: Sector Search"), false );
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel4->SetMinSize( wxSize( 300,200 ) );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel10 = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer912;
	bSizer912 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText152 = new wxStaticText( m_panel10, wxID_ANY, _("Oil Rig Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText152->Wrap( -1 );
	m_staticText152->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer912->Add( m_staticText152, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText323 = new wxStaticText( m_panel10, wxID_ANY, _("Approach course"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323->Wrap( -1 );
	bSizer143->Add( m_staticText323, 0, wxALL, 5 );
	
	m_textCtrl253 = new wxTextCtrl( m_panel10, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer143->Add( m_textCtrl253, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText333 = new wxStaticText( m_panel10, wxID_ANY, _("Degrees"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333->Wrap( -1 );
	bSizer143->Add( m_staticText333, 0, wxALL, 5 );
	
	
	bSizer132->Add( bSizer143, 1, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer1412;
	bSizer1412 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3212 = new wxStaticText( m_panel10, wxID_ANY, _("Leg Distance          "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3212->Wrap( -1 );
	bSizer1412->Add( m_staticText3212, 0, wxALL, 5 );
	
	m_textCtrl2512 = new wxTextCtrl( m_panel10, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1412->Add( m_textCtrl2512, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3312 = new wxStaticText( m_panel10, wxID_ANY, _("NM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3312->Wrap( -1 );
	bSizer1412->Add( m_staticText3312, 0, wxALL, 5 );
	
	
	bSizer132->Add( bSizer1412, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14121;
	bSizer14121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32121 = new wxStaticText( m_panel10, wxID_ANY, _("Sector Angle          "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32121->Wrap( -1 );
	bSizer14121->Add( m_staticText32121, 0, wxALL, 5 );
	
	m_textCtrl25121 = new wxTextCtrl( m_panel10, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14121->Add( m_textCtrl25121, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33121 = new wxStaticText( m_panel10, wxID_ANY, _("Degrees"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33121->Wrap( -1 );
	bSizer14121->Add( m_staticText33121, 0, wxALL, 5 );
	
	
	bSizer132->Add( bSizer14121, 1, wxEXPAND, 5 );
	
	
	bSizer912->Add( bSizer132, 1, wxEXPAND, 5 );
	
	m_button32 = new wxButton( m_panel10, wxID_ANY, _("Generate &GPX"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer912->Add( m_button32, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	m_panel10->SetSizer( bSizer912 );
	m_panel10->Layout();
	bSizer912->Fit( m_panel10 );
	bSizer6->Add( m_panel10, 0, wxALL, 5 );
	
	m_bitmap4 = new wxStaticBitmap( m_panel4, wxID_ANY, wxBitmap( wxT("bitmaps/oil_rig.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap4->SetMinSize( wxSize( 300,300 ) );
	
	bSizer6->Add( m_bitmap4, 0, wxALL, 5 );
	
	
	m_panel4->SetSizer( bSizer6 );
	m_panel4->Layout();
	bSizer6->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, _("SAR: Oil Rig"), false );
	
	bSframe->Add( m_notebook1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	m_panel11 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("Start of Search") ), wxVERTICAL );
	
	wxBoxSizer* bSizer1321;
	bSizer1321 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1431;
	bSizer1431 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3231 = new wxStaticText( m_panel11, wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231->Wrap( -1 );
	bSizer1431->Add( m_staticText3231, 0, wxALL, 5 );
	
	m_textCtrl2531 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431->Add( m_textCtrl2531, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3331 = new wxStaticText( m_panel11, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331->Wrap( -1 );
	bSizer1431->Add( m_staticText3331, 0, wxALL, 5 );
	
	m_textCtrl61 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431->Add( m_textCtrl61, 0, wxALL, 5 );
	
	m_staticText114 = new wxStaticText( m_panel11, wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	bSizer1431->Add( m_staticText114, 0, wxALL, 5 );
	
	m_textCtrl62 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431->Add( m_textCtrl62, 0, wxALL, 5 );
	
	m_staticText115 = new wxStaticText( m_panel11, wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	bSizer1431->Add( m_staticText115, 0, wxALL, 5 );
	
	
	bSizer1321->Add( bSizer1431, 0, 0, 5 );
	
	wxBoxSizer* bSizer14311;
	bSizer14311 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32311 = new wxStaticText( m_panel11, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32311->Wrap( -1 );
	bSizer14311->Add( m_staticText32311, 0, wxALL, 5 );
	
	m_textCtrl25311 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311->Add( m_textCtrl25311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33311 = new wxStaticText( m_panel11, wxID_ANY, _("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33311->Wrap( -1 );
	bSizer14311->Add( m_staticText33311, 0, wxALL, 5 );
	
	m_textCtrl611 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311->Add( m_textCtrl611, 0, wxALL, 5 );
	
	m_staticText1141 = new wxStaticText( m_panel11, wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1141->Wrap( -1 );
	bSizer14311->Add( m_staticText1141, 0, wxALL, 5 );
	
	m_textCtrl621 = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311->Add( m_textCtrl621, 0, wxALL, 5 );
	
	m_staticText1151 = new wxStaticText( m_panel11, wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1151->Wrap( -1 );
	bSizer14311->Add( m_staticText1151, 0, wxALL, 5 );
	
	
	bSizer1321->Add( bSizer14311, 0, 0, 5 );
	
	
	sbSizer7->Add( bSizer1321, 0, 0, 5 );
	
	
	m_panel11->SetSizer( sbSizer7 );
	m_panel11->Layout();
	sbSizer7->Fit( m_panel11 );
	bSizer35->Add( m_panel11, 1, wxEXPAND | wxALL, 5 );
	
	
	bSframe->Add( bSizer35, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSframe );
	this->Layout();
	
	this->Centre( wxBOTH );
}

WmmUIDialog::~WmmUIDialog()
{
}

WmmPrefsDialog::WmmPrefsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_rbViewTypeChoices[] = { _("Extended"), _("Variation only") };
	int m_rbViewTypeNChoices = sizeof( m_rbViewTypeChoices ) / sizeof( wxString );
	m_rbViewType = new wxRadioBox( this, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, m_rbViewTypeNChoices, m_rbViewTypeChoices, 2, wxRA_SPECIFY_COLS );
	m_rbViewType->SetSelection( 1 );
	bSizer2->Add( m_rbViewType, 0, wxALL|wxEXPAND, 5 );
	
	m_cbShowAtCursor = new wxCheckBox( this, wxID_ANY, _("Show also data at cursor position"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_cbShowAtCursor, 0, wxALL, 5 );
	
	m_cbLiveIcon = new wxCheckBox( this, wxID_ANY, _("Show data in toolbar icon"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_cbLiveIcon, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Window transparency") ), wxVERTICAL );
	
	m_sOpacity = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_INVERSE );
	sbSizer4->Add( m_sOpacity, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	bSizer2->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer2->Add( m_sdbSizer1, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
}

WmmPrefsDialog::~WmmPrefsDialog()
{
}

MyDialog3::MyDialog3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	m_panel12 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText95 = new wxStaticText( m_panel12, wxID_ANY, _("Hello World!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	bSizer62->Add( m_staticText95, 0, wxALL, 5 );
	
	m_button10 = new wxButton( m_panel12, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer62->Add( m_button10, 0, wxALL, 5 );
	
	
	m_panel12->SetSizer( bSizer62 );
	m_panel12->Layout();
	bSizer62->Fit( m_panel12 );
	bSizer61->Add( m_panel12, 1, wxEXPAND | wxALL, 5 );
	
	m_panel5 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	bSframe1 = new wxBoxSizer( wxVERTICAL );
	
	bSframe1->SetMinSize( wxSize( 200,-1 ) ); 
	sbSboat = new wxStaticBoxSizer( new wxStaticBox( m_panel5, wxID_ANY, _("Boat") ), wxVERTICAL );
	
	gSboat = new wxFlexGridSizer( 6, 2, 0, 0 );
	gSboat->AddGrowableCol( 1 );
	gSboat->SetFlexibleDirection( wxBOTH );
	gSboat->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText8 = new wxStaticText( m_panel5, wxID_ANY, _("F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	m_staticText8->SetToolTip( _("Total Intensity") );
	
	gSboat->Add( m_staticText8, 0, wxALL, 5 );
	
	m_tbF = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbF, 1, wxEXPAND, 5 );
	
	m_staticText9 = new wxStaticText( m_panel5, wxID_ANY, _("H"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetToolTip( _("Horizontal Intensity") );
	
	gSboat->Add( m_staticText9, 0, wxALL, 5 );
	
	m_tbH = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbH, 1, wxEXPAND, 5 );
	
	m_staticText10 = new wxStaticText( m_panel5, wxID_ANY, _("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetToolTip( _("North Component") );
	
	gSboat->Add( m_staticText10, 0, wxALL, 5 );
	
	m_tbX = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbX, 1, wxEXPAND, 5 );
	
	m_staticText11 = new wxStaticText( m_panel5, wxID_ANY, _("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	m_staticText11->SetToolTip( _("East Component") );
	
	gSboat->Add( m_staticText11, 0, wxALL, 5 );
	
	m_tbY = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbY, 1, wxEXPAND, 5 );
	
	m_staticText12 = new wxStaticText( m_panel5, wxID_ANY, _("Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetToolTip( _("Vertical Component") );
	
	gSboat->Add( m_staticText12, 0, wxALL, 5 );
	
	m_tbZ = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbZ, 1, wxEXPAND, 5 );
	
	m_staticText14 = new wxStaticText( m_panel5, wxID_ANY, _("Incl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetToolTip( _("(DIP) - Geomagnetic Inclination ") );
	m_staticText14->SetMinSize( wxSize( 50,-1 ) );
	
	gSboat->Add( m_staticText14, 0, wxALL, 5 );
	
	m_tbI = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbI, 1, wxEXPAND, 0 );
	
	
	sbSboat->Add( gSboat, 1, wxEXPAND, 0 );
	
	wxFlexGridSizer* gSizer3;
	gSizer3 = new wxFlexGridSizer( 1, 2, 0, 0 );
	gSizer3->AddGrowableCol( 1 );
	gSizer3->SetFlexibleDirection( wxBOTH );
	gSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText13 = new wxStaticText( m_panel5, wxID_ANY, _("Vari"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetToolTip( _("Magnetic Variation") );
	m_staticText13->SetMinSize( wxSize( 50,-1 ) );
	
	gSizer3->Add( m_staticText13, 0, wxALL, 5 );
	
	m_tbD = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	m_tbD->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer3->Add( m_tbD, 1, wxEXPAND, 5 );
	
	
	sbSboat->Add( gSizer3, 0, wxEXPAND, 0 );
	
	
	bSframe1->Add( sbSboat, 1, wxEXPAND|wxFIXED_MINSIZE, 0 );
	
	sbScursor = new wxStaticBoxSizer( new wxStaticBox( m_panel5, wxID_ANY, _("Cursor") ), wxVERTICAL );
	
	gScursor = new wxFlexGridSizer( 6, 2, 0, 0 );
	gScursor->AddGrowableCol( 1 );
	gScursor->SetFlexibleDirection( wxBOTH );
	gScursor->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText81 = new wxStaticText( m_panel5, wxID_ANY, _("F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	m_staticText81->SetToolTip( _("Total Intensity") );
	
	gScursor->Add( m_staticText81, 0, wxALL, 5 );
	
	m_tcF = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcF, 0, wxEXPAND, 5 );
	
	m_staticText91 = new wxStaticText( m_panel5, wxID_ANY, _("H"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	m_staticText91->SetToolTip( _("Horizontal Intensity") );
	
	gScursor->Add( m_staticText91, 0, wxALL, 5 );
	
	m_tcH = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcH, 0, wxEXPAND, 5 );
	
	m_staticText101 = new wxStaticText( m_panel5, wxID_ANY, _("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	m_staticText101->SetToolTip( _("North Component") );
	
	gScursor->Add( m_staticText101, 0, wxALL, 5 );
	
	m_tcX = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcX, 0, wxEXPAND, 5 );
	
	m_staticText111 = new wxStaticText( m_panel5, wxID_ANY, _("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	m_staticText111->SetToolTip( _("East Component") );
	
	gScursor->Add( m_staticText111, 0, wxALL, 5 );
	
	m_tcY = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcY, 0, wxEXPAND, 5 );
	
	m_staticText121 = new wxStaticText( m_panel5, wxID_ANY, _("Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText121->Wrap( -1 );
	m_staticText121->SetToolTip( _("Vertical Component") );
	
	gScursor->Add( m_staticText121, 0, wxALL, 5 );
	
	m_tcZ = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcZ, 0, wxEXPAND, 5 );
	
	m_staticText141 = new wxStaticText( m_panel5, wxID_ANY, _("Incl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	m_staticText141->SetToolTip( _("(DIP) - Geomagnetic Inclination ") );
	m_staticText141->SetMinSize( wxSize( 50,-1 ) );
	
	gScursor->Add( m_staticText141, 0, wxALL, 5 );
	
	m_tcI = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcI, 0, wxEXPAND, 5 );
	
	
	sbScursor->Add( gScursor, 1, wxEXPAND|wxFIXED_MINSIZE, 0 );
	
	wxFlexGridSizer* gSizer4;
	gSizer4 = new wxFlexGridSizer( 2, 2, 0, 0 );
	gSizer4->AddGrowableCol( 1 );
	gSizer4->SetFlexibleDirection( wxBOTH );
	gSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText131 = new wxStaticText( m_panel5, wxID_ANY, _("Vari"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	m_staticText131->SetToolTip( _("Magnetic Variation") );
	m_staticText131->SetMinSize( wxSize( 50,-1 ) );
	
	gSizer4->Add( m_staticText131, 0, wxALL, 5 );
	
	m_tcD = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	m_tcD->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer4->Add( m_tcD, 0, wxEXPAND, 5 );
	
	
	sbScursor->Add( gSizer4, 0, wxEXPAND, 0 );
	
	
	bSframe1->Add( sbScursor, 1, wxEXPAND|wxFIXED_MINSIZE, 0 );
	
	
	bSizer9->Add( bSframe1, 1, wxEXPAND, 5 );
	
	
	m_panel5->SetSizer( bSizer9 );
	m_panel5->Layout();
	bSizer9->Fit( m_panel5 );
	bSizer61->Add( m_panel5, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer61 );
	this->Layout();
	bSizer61->Fit( this );
	
	this->Centre( wxBOTH );
}

MyDialog3::~MyDialog3()
{
}
