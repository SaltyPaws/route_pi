///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 11 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WmmUIDialog.h"

///////////////////////////////////////////////////////////////////////////

WmmUIDialog::WmmUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	bSframe = new wxBoxSizer( wxVERTICAL );
	
	bSframe->SetMinSize( wxSize( 200,-1 ) ); 
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap1 = new wxStaticBitmap( m_panel1, wxID_ANY, wxBitmap( wxT("bitmaps/trackln.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_bitmap1, 0, wxALL, 5 );
	
	
	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("SAR: Trackline"), false );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap2 = new wxStaticBitmap( m_panel2, wxID_ANY, wxBitmap( wxT("bitmaps/exp_sq.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_bitmap2, 0, wxALL, 5 );
	
	
	m_panel2->SetSizer( bSizer4 );
	m_panel2->Layout();
	bSizer4->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, _("SAR: Expanding Square"), false );
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap3 = new wxStaticBitmap( m_panel3, wxID_ANY, wxBitmap( wxT("bitmaps/sector.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_bitmap3, 0, wxALL, 5 );
	
	
	m_panel3->SetSizer( bSizer5 );
	m_panel3->Layout();
	bSizer5->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("SAR: Sector Search"), false );
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap4 = new wxStaticBitmap( m_panel4, wxID_ANY, wxBitmap( wxT("bitmaps/oil_rig.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_bitmap4, 0, wxALL, 5 );
	
	
	m_panel4->SetSizer( bSizer6 );
	m_panel4->Layout();
	bSizer6->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, _("SAR: Oil Rig"), true );
	m_panel5 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	m_notebook1->AddPage( m_panel5, _("a page"), false );
	
	bSframe->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	
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
