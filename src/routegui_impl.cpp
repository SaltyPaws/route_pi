/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
 * Author:   SaltyPaws
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

CfgDlg::CfgDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : CfgDlgDef( parent, id, title, pos, size, style )
{
}

Dlg::Dlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DlgDef( parent, id, title, pos, size, style )
{
    this->Fit();
}

void Dlg::OnToggle( wxCommandEvent& event )
{

}

void Dlg::OnCalculate( wxCommandEvent& event )
{

}
void Dlg::OnConverttoDegree( wxCommandEvent& event )
{
    //Lat1
    wxString Lat1 = this->m_Lat1_d->GetValue() + _T(" ")  + this->m_Lat1_m->GetValue() + _T(" ")  + this->m_Lat1_s->GetValue() + _T(" ");// + this->m_Lon1_EW->GetCurrentSelection();
    if(this->m_Lat1_NS->GetCurrentSelection()) //S=1
        Lat1=Lat1 + _T("S");
    else
        Lat1=Lat1 + _T("N");
    m_Lat1->SetValue(wxString::Format(wxT("%g"), fromDMStodouble((char*)Lat1.mb_str().data())));

    //Lon1
    wxString Lon1 = this->m_Lon1_d->GetValue() + _T(" ") + this->m_Lon1_m->GetValue() + _T(" ")  + this->m_Lon1_s->GetValue() + _T(" ") ;// + this->m_Lon1_EW->GetString();
    if(this->m_Lon1_EW->GetCurrentSelection()) //W=1
        Lon1=Lon1 + _T("W");
    else
        Lon1=Lon1 + _T("E");
    m_Lon1->SetValue(wxString::Format(wxT("%g"), fromDMStodouble((char*)Lon1.mb_str().data())));

    //Lat2
    wxString Lat2 = this->m_Lat2_d->GetValue() + _T(" ")  + this->m_Lat2_m->GetValue() + _T(" ")  + this->m_Lat2_s->GetValue() + _T(" ");//  + this->m_Lat2_NS->GetString();
    if(this->m_Lat2_NS->GetCurrentSelection()) //S=1
        Lat2=Lat2 + _T("S");
    else
        Lat2=Lat2 + _T("N");
    m_Lat2->SetValue(wxString::Format(wxT("%g"), fromDMStodouble((char*)Lat2.mb_str().data())));

    //Lon2
    wxString Lon2 = this->m_Lon2_d->GetValue() + _T(" ")  + this->m_Lon2_m->GetValue() + _T(" ")  + this->m_Lon2_s->GetValue() + _T(" ") ;// + _T(this->m_Lon2_EW->GetSelection());
    if(this->m_Lon2_EW->GetCurrentSelection()) //W=1
        Lon2=Lon2 + _T("W");
    else
        Lon2=Lon2 + _T("E");
    m_Lon2->SetValue(wxString::Format(wxT("%g"), fromDMStodouble((char*)Lon2.mb_str().data())));

}

void Dlg::OnNoteBookFit( wxCommandEvent& event )
{

        this->m_panel11->Layout();
    /*this->m_panel11->Fit();
    this->m_wxNotebook234->Layout();
    this->m_wxNotebook234->Fit();*/
    this->m_wxNotebook234->InvalidateBestSize();


    //this->Layout();
    this->Fit();
        printf("Resizing window \n");
}

void Dlg::OnGCCalculate( wxCommandEvent& event ){


    bool error_occured=false;
    double dist, fwdAz, revAz;

    double lat1,lon1,lat2,lon2;
    if(!this->m_Lat1->GetValue().ToDouble(&lat1)){ error_occured=true;}
    if(!this->m_Lon1->GetValue().ToDouble(&lon1)){ error_occured=true; }
    if(!this->m_Lat2->GetValue().ToDouble(&lat2)){ error_occured=true;}
    if(!this->m_Lon2->GetValue().ToDouble(&lon2)){ error_occured=true; }

    //Validate input ranges
    if (std::abs(lat1)>90){ error_occured=true; }
    if (std::abs(lat2)>90){ error_occured=true; }
    if (std::abs(lon1)>180){ error_occured=true; }
    if (std::abs(lon2)>180){ error_occured=true; }

    if(!distVincenty(lat1, lon1, lat2, lon2, &dist, &fwdAz, &revAz)){ error_occured=true; };
    this->m_distance_GC->SetValue(wxString::Format(wxT("%g"), dist));

    DistanceBearingMercator(lat1, lon1, lat2, lon2, &fwdAz, &dist);
    this->m_distance_RH->SetValue(wxString::Format(wxT("%g"), dist));

    if (error_occured==true)  {
        wxLogMessage(_("Error in calculation. Please check input!") );
        wxMessageBox(_("Error in calculation. Please check input!") );}


}

void Dlg::OnFit( wxCommandEvent& event )
{

     //   this->m_panel11->Layout();
    /*this->m_panel11->Fit();
    this->m_wxNotebook234->Layout();
    this->m_wxNotebook234->Fit();*/
    this->m_wxNotebook234->InvalidateBestSize();
    this->m_panel11->Fit();
        this->m_panel11->Layout();

    //this->Layout();
    this->Fit();
    this->Layout();
    printf("Resizing window \n");
        //  wxMessageBox(_("User entered text:\n") );
}

void Dlg::OnExportGC( wxCommandEvent& event )
{
    //printf("You should see a file dialiog \n");

      wxFileDialog dlg(this, _("Export G as"), wxEmptyString, wxEmptyString, _T("GPX files (*.gpx)|*.gpx|All files (*.*)|*.*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
      dlg.ShowModal();
      if (dlg.GetPath() != wxEmptyString){
            //wxMessageBox(_("User entered text:"), dlg.GetPath());


            bool error_occured=false;
            double dist, fwdAz, revAz;

            double lat1,lon1,lat2,lon2;
            if(!this->m_Lat1->GetValue().ToDouble(&lat1)){ error_occured=true;}
            if(!this->m_Lon1->GetValue().ToDouble(&lon1)){ error_occured=true; }
            if(!this->m_Lat2->GetValue().ToDouble(&lat2)){ error_occured=true;}
            if(!this->m_Lon2->GetValue().ToDouble(&lon2)){ error_occured=true; }

            //Validate input ranges
            if (std::abs(lat1)>90){ error_occured=true; }
            if (std::abs(lat2)>90){ error_occured=true; }
            if (std::abs(lon1)>180){ error_occured=true; }
            if (std::abs(lon2)>180){ error_occured=true; }

            if(!distVincenty(lat1, lon1, lat2, lon2, &dist, &fwdAz, &revAz)){ error_occured=true; };
            this->m_distance_GC->SetValue(wxString::Format(wxT("%g"), dist));

           /* DistanceBearingMercator(lat1, lon1, lat2, lon2, &fwdAz, &dist);
            this->m_distance_RH->SetValue(wxString::Format(wxT("%g"), dist));*/

            if (error_occured==true)  {
                wxLogMessage(_("Error in calculation. Please check input!") );
                wxMessageBox(_("Error in calculation. Please check input!") );}

            ////////////////////Start XML
            TiXmlDocument doc;
            TiXmlElement* msg;
            TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "utf-8", "" );
            doc.LinkEndChild( decl );

            TiXmlElement * root = new TiXmlElement( "gpx" );
            doc.LinkEndChild( root );

            root->SetAttribute("version", "1.1");
            root->SetAttribute("creator", "Route_pi by SaltyPaws");
            root->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
            root->SetAttribute("xmlns:gpxx","http://www.garmin.com/xmlschemas/GpxExtensions/v3" );
            root->SetAttribute("xsi:schemaLocation", "http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd");
            root->SetAttribute("xmlns:opencpn","http://www.opencpn.org");


            TiXmlElement * Route = new TiXmlElement( "rte" );

            TiXmlElement * RouteName = new TiXmlElement( "name" );
            TiXmlText * text4 = new TiXmlText( "Route01" );
            Route->LinkEndChild( RouteName );
            RouteName->LinkEndChild( text4 );


            //////////////////////Add Points HERE

            double step_size;
            if(!this->m_IntervalNM->GetValue().ToDouble(&step_size)){ error_occured=true;}
            if ((step_size>dist) || (step_size<dist*1/5000)){
                wxLogMessage(_("Route interval > Distance, 0 or negative") );
                wxMessageBox(_("Route interval > Distance, 0 or negative") );
                }

            //start
            Addpoint(Route,wxString::Format(wxT("%f"),lat1),wxString::Format(wxT("%f"),lon1),_T("Start"),_T("diamond"),_T("WPT"));
            double lati, loni;
            for(double in_distance=step_size;in_distance<dist;in_distance=in_distance+step_size)
                {
                destVincenty( lat1,  lon1,  fwdAz,  in_distance, &lati, &loni, &revAz);
                std::cout<<"Distance: "<<in_distance<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                Addpoint(Route,wxString::Format(wxT("%f"),lati),wxString::Format(wxT("%f"),loni), wxString::Format(wxT("%f"),in_distance) ,_T("diamond"),_T("WPT"));
                }
            //Addpoint(Route,(double)10,(double)11,(wxString)_T("NAAM"),(wxString)_T("SYMBOL"),(wxString)_T("TYPE"));

            //end
            Addpoint(Route,wxString::Format(wxT("%f"),lat2),wxString::Format(wxT("%f"),lon2),_T("Finish"),_T("SYMBOL"),_T("WPT"));
            //////////////////////////Close XML

            root->LinkEndChild( Route );
            //root->LinkEndChild(root );



            wxString s=dlg.GetPath() +  _T(".gpx");
            wxCharBuffer buffer=s.ToUTF8();
           // foo( buffer.data() );  // data() returns const char *
//bar( buffer.data(), strlen(buffer.data()) );  // in case you need the length of the data

            std::cout<< buffer.data()<<std::endl;
            doc.SaveFile( buffer.data() );
            }





//TiXmlDocument doc;
}

//void Dlg::Addpoint(TiXmlElement* Route, double ptlat, double ptlon, wxString ptname, wxString ptsym, wxString pttype){
void Dlg::Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype){
//add point
	TiXmlElement * RoutePoint = new TiXmlElement( "rtept" );
    RoutePoint->SetAttribute("lat", ptlat.mb_str());
    RoutePoint->SetAttribute("lon", ptlon.mb_str());


    TiXmlElement * Name = new TiXmlElement( "name" );
    TiXmlText * text = new TiXmlText( ptname.mb_str() );
    RoutePoint->LinkEndChild( Name );
    Name->LinkEndChild( text );

    TiXmlElement * Symbol = new TiXmlElement( "sym" );
    TiXmlText * text1 = new TiXmlText( ptsym.mb_str() );
    RoutePoint->LinkEndChild( Symbol );
    Symbol->LinkEndChild( text1 );

    TiXmlElement * Type = new TiXmlElement( "type" );
    TiXmlText * text2 = new TiXmlText( pttype.mb_str() );
    RoutePoint->LinkEndChild( Type );
    Type->LinkEndChild( text2 );
    Route->LinkEndChild( RoutePoint );
//done adding point
}
