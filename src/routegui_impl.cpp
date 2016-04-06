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
    dbg=false; //for debug output set to true
}

void Dlg::OnToggle( wxCommandEvent& event )
{

}

void Dlg::OnCalculate( wxCommandEvent& event )
{

}
void Dlg::OnConverttoDegree( wxCommandEvent& event )
{
    //set cell values to 0 if they are empty. This ensures conversion goes ok.
    double test_value;
    if(!this->m_Lat1_d->GetValue().ToDouble(&test_value)){m_Lat1_d->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lat1_m->GetValue().ToDouble(&test_value)){m_Lat1_m->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lat1_s->GetValue().ToDouble(&test_value)){m_Lat1_s->SetValue(wxString::Format(wxT("%i"),0 ));}

    if(!this->m_Lat2_d->GetValue().ToDouble(&test_value)){m_Lat2_d->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lat2_m->GetValue().ToDouble(&test_value)){m_Lat2_m->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lat2_s->GetValue().ToDouble(&test_value)){m_Lat2_s->SetValue(wxString::Format(wxT("%i"),0 ));}

    if(!this->m_Lon1_d->GetValue().ToDouble(&test_value)){m_Lon1_d->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lon1_m->GetValue().ToDouble(&test_value)){m_Lon1_m->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lon1_s->GetValue().ToDouble(&test_value)){m_Lon1_s->SetValue(wxString::Format(wxT("%i"),0 ));}

    if(!this->m_Lon2_d->GetValue().ToDouble(&test_value)){m_Lon2_d->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lon2_m->GetValue().ToDouble(&test_value)){m_Lon2_m->SetValue(wxString::Format(wxT("%i"),0 ));}
    if(!this->m_Lon2_s->GetValue().ToDouble(&test_value)){m_Lon2_s->SetValue(wxString::Format(wxT("%i"),0 ));}


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
    this->m_wxNotebook234->InvalidateBestSize();
    this->Fit();
    if (dbg) printf("Resizing window \n");
}

void Dlg::OnGCCalculate( wxCommandEvent& event ){

    bool error_occured=false;
    double dist, fwdAz, revAz;

    double lat1,lon1,lat2,lon2;
    //set value to 0
    if(!this->m_Lat1->GetValue().ToDouble(&lat1)){ lat1=0.0;}
    if(!this->m_Lon1->GetValue().ToDouble(&lon1)){ lon1=0.0;}
    if(!this->m_Lat2->GetValue().ToDouble(&lat2)){ lat2=0.0;}
    if(!this->m_Lon2->GetValue().ToDouble(&lon2)){ lon2=0.0;}

    //Validate input ranges
    if (std::abs(lat1)>90){ error_occured=true; }
    if (std::abs(lat2)>90){ error_occured=true; }
    if (std::abs(lon1)>180){ error_occured=true; }
    if (std::abs(lon2)>180){ error_occured=true; }

    if(!DistVincenty(lat1, lon1, lat2, lon2, &dist, &fwdAz, &revAz)){ error_occured=true; };
    this->m_distance_GC->SetValue(wxString::Format(wxT("%g"), dist));

    DistanceBearingMercator(lat1, lon1, lat2, lon2, &fwdAz, &dist);
    this->m_distance_RH->SetValue(wxString::Format(wxT("%g"), dist));

    if (error_occured==true)  {
        wxLogMessage(_("Error in calculation. Please check input!") );
        wxMessageBox(_("Error in calculation. Please check input!") );}
}

void Dlg::OnFit( wxCommandEvent& event )
{
    this->m_wxNotebook234->InvalidateBestSize();
    this->m_panel11->Fit();
    this->m_panel11->Layout();
    this->Fit();
    this->Layout();
    if (dbg) printf("Resizing window \n");
}

void Dlg::OnExportGC( wxCommandEvent& event )
{
      bool error_occured=false;
      bool user_canceled=false;
      wxFileDialog dlg(this, _("Export GPX file as"), wxEmptyString, wxEmptyString, _T("GPX files (*.gpx)|*.gpx|All files (*.*)|*.*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
      if (dlg.ShowModal() == wxID_CANCEL)
        user_canceled=true;     // the user changed idea...
      if (!user_canceled && !dlg.GetPath().IsEmpty()){
            //wxMessageBox(_("User entered text:"), dlg.GetPath());

            double dist, fwdAz, revAz;

            double lat1,lon1,lat2,lon2;
            //set value to 0
            if(!this->m_Lat1->GetValue().ToDouble(&lat1)){ lat1=0.0;}
            if(!this->m_Lon1->GetValue().ToDouble(&lon1)){ lon1=0.0;}
            if(!this->m_Lat2->GetValue().ToDouble(&lat2)){ lat2=0.0;}
            if(!this->m_Lon2->GetValue().ToDouble(&lon2)){ lon2=0.0;}
            //Validate input ranges
            if (std::abs(lat1)>90){ error_occured=true; }
            if (std::abs(lat2)>90){ error_occured=true; }
            if (std::abs(lon1)>180){ error_occured=true; }
            if (std::abs(lon2)>180){ error_occured=true; }

            if(!DistVincenty(lat1, lon1, lat2, lon2, &dist, &fwdAz, &revAz)){ error_occured=true; };
            this->m_distance_GC->SetValue(wxString::Format(wxT("%g"), dist));

           /* DistanceBearingMercator(lat1, lon1, lat2, lon2, &fwdAz, &dist);
            this->m_distance_RH->SetValue(wxString::Format(wxT("%g"), dist));*/

            if (error_occured==true)  {
                wxLogMessage(_("Error in calculation. Please check input!") );
                wxMessageBox(_("Error in calculation. Please check input!") );}

            ////////////////////Start XML
            TiXmlDocument doc;
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
            TiXmlText * text4 = new TiXmlText( this->m_Route->GetValue().ToUTF8() );
            Route->LinkEndChild( RouteName );
            RouteName->LinkEndChild( text4 );

            TiXmlElement * Extensions = new TiXmlElement( "extensions" );

            TiXmlElement * StartN = new TiXmlElement( "opencpn:start" );
            TiXmlText * text5 = new TiXmlText( this->m_Start->GetValue().ToUTF8() );
            Extensions->LinkEndChild( StartN );
            StartN->LinkEndChild( text5 );

            TiXmlElement * EndN = new TiXmlElement( "opencpn:end" );
            TiXmlText * text6 = new TiXmlText( this->m_End->GetValue().ToUTF8() );
            Extensions->LinkEndChild( EndN );
            EndN->LinkEndChild( text6 );

            Route->LinkEndChild( Extensions );
            //////////////////////Add Points HERE

            double step_size;
            bool m_IntervalNM_test=false;
            if(!this->m_IntervalNM->GetValue().ToDouble(&step_size)){ m_IntervalNM_test=true;}
            if ((step_size>dist) || (step_size<dist*1/5000) || (m_IntervalNM_test)){
                m_IntervalNM->SetValue(wxString::Format(wxT("%g"), dist/100));
                step_size=dist/100;
                if (step_size<0.05) step_size=1; //prevent infinite loop
                }

            //start
            Addpoint(Route,wxString::Format(wxT("%f"),lat1),wxString::Format(wxT("%f"),lon1),_T("Start"),_T("diamond"),_T("WPT"));
            double lati, loni;
            for(double in_distance=step_size;in_distance<dist;in_distance=in_distance+step_size)
                {
                DestVincenty( lat1,  lon1,  fwdAz,  in_distance, &lati, &loni, &revAz);
                if (dbg) std::cout<<"Distance: "<<in_distance<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                Addpoint(Route,wxString::Format(wxT("%f"),lati),wxString::Format(wxT("%f"),loni), wxString::Format(wxT("%d"),(int)in_distance) ,_T("diamond"),_T("WPT"));
                }
            //end
            Addpoint(Route,wxString::Format(wxT("%f"),lat2),wxString::Format(wxT("%f"),lon2),_T("Finish"),_T("SYMBOL"),_T("WPT"));
            //////////////////////////Close XML

            root->LinkEndChild( Route );
            wxString s=dlg.GetPath();

            if (!wxFileExists(dlg.GetPath())) {
                 s = s + _T(".gpx");
            }
            wxCharBuffer buffer=s.ToUTF8();
            if (dbg) std::cout<< buffer.data()<<std::endl;
            doc.SaveFile( buffer.data() );

        }
}

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

void Dlg::OnGCLCalculate( wxCommandEvent& event ){
    OnGCLCalculate (event, false);
    }

void Dlg::OnGCLCalculate( wxCommandEvent& event, bool write_file ){

    //-40,80,20, 20, -80 is a problem
    //20, 80, -40, -80 is a problem

    bool error_occured=false;
    bool user_canceled=false;
    double dist, fwdAz, revAz;


    double lat1,lon1,lat2,lon2,limit;
    //set value to 0
    if(!this->m_Lat1->GetValue().ToDouble(&lat1)){ lat1=0.0;}
    if(!this->m_Lon1->GetValue().ToDouble(&lon1)){ lon1=0.0;}
    if(!this->m_Lat2->GetValue().ToDouble(&lat2)){ lat2=0.0;}
    if(!this->m_Lon2->GetValue().ToDouble(&lon2)){ lon2=0.0;}
    if (error_occured) wxMessageBox(_T("error in conversion of input coordinates"));
    if(!error_occured && (!this->m_LatLimit->GetValue().ToDouble(&limit))){ error_occured=true; wxMessageBox(_("No Lat Limit!") ); }

    //error_occured=false;

    wxString s;
    if (write_file){
        wxFileDialog dlg(this, _("Export Great Circle GPX file as"), wxEmptyString, wxEmptyString, _T("GPX files (*.gpx)|*.gpx|All files (*.*)|*.*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
        if (dlg.ShowModal() == wxID_CANCEL)
            user_canceled=true;     // the user changed idea...
        //dlg.ShowModal();
        s=dlg.GetPath();
        //  std::cout<<s<< std::endl;
        if (!user_canceled && s.IsEmpty()) { error_occured=true; if (dbg) printf("Empty Path\n");}
    }

    //Validate input ranges
    if (!user_canceled && !error_occured){
        if (std::abs(lat1)>90){ error_occured=true; }
        if (std::abs(lat2)>90){ error_occured=true; }
        if (std::abs(lon1)>180){ error_occured=true; }
        if (std::abs(lon2)>180){ error_occured=true; }
        if (error_occured) wxMessageBox(_("error in input range validation"));
    }

    if ((!user_canceled && !error_occured) && (lat1>0) && (lat1>std::abs(limit))){ //North
        error_occured=true;
        wxMessageBox(_("Start Latitude>Limit!") );
    }
    if ((!user_canceled && !error_occured) && (lat1<0) && (std::abs(lat1)>std::abs(limit))){ //south
        error_occured=true;
        wxMessageBox(_("Start Latitude>Limit!") );
    }
    if ((!user_canceled && !error_occured) && (lat2>0) && (lat2>std::abs(limit))){ //North
        error_occured=true;
        wxMessageBox(_("Start Latitude>Limit!") );
    }
    if ((!user_canceled && !error_occured) && (lat2<0) && (std::abs(lat2)>std::abs(limit))){ //south
        error_occured=true;
        wxMessageBox(_("Start Latitude>Limit!") );
    }
    //Calculate RH dist
    DistanceBearingMercator(lat1, lon1, lat2, lon2, &fwdAz, &dist);
    this->m_distance_RH1->SetValue(wxString::Format(wxT("%g"), dist));

    //Calculate GC
    if(!DistVincenty(lat1, lon1, lat2, lon2, &dist, &fwdAz, &revAz)){ error_occured=true;    if (dbg) printf("error in DistVincenty\n"); };
    this->m_distance_GC1->SetValue(wxString::Format(wxT("%g"), dist));
    TiXmlDocument doc;
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "utf-8", "" );
    doc.LinkEndChild( decl );
    TiXmlElement * root = new TiXmlElement( "gpx" );
    TiXmlElement * Route = new TiXmlElement( "rte" );
    TiXmlElement * RouteName = new TiXmlElement( "name" );
    TiXmlText * text4 = new TiXmlText( this->m_Route->GetValue().ToUTF8() );

    if (write_file){
        doc.LinkEndChild( root );
        root->SetAttribute("version", "1.1");
        root->SetAttribute("creator", "Route_pi by SaltyPaws");
        root->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
        root->SetAttribute("xmlns:gpxx","http://www.garmin.com/xmlschemas/GpxExtensions/v3" );
        root->SetAttribute("xsi:schemaLocation", "http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd");
        root->SetAttribute("xmlns:opencpn","http://www.opencpn.org");
        Route->LinkEndChild( RouteName );
        RouteName->LinkEndChild( text4 );

        TiXmlElement * Extensions = new TiXmlElement( "extensions" );

        TiXmlElement * StartN = new TiXmlElement( "opencpn:start" );
        TiXmlText * text5 = new TiXmlText( this->m_Start->GetValue().ToUTF8() );
        Extensions->LinkEndChild( StartN );
        StartN->LinkEndChild( text5 );

        TiXmlElement * EndN = new TiXmlElement( "opencpn:end" );
        TiXmlText * text6 = new TiXmlText( this->m_End->GetValue().ToUTF8() );
        Extensions->LinkEndChild( EndN );
        EndN->LinkEndChild( text6 );

        Route->LinkEndChild( Extensions );
    }

    //Calculate GCL
    double step_size=dist/100;
    if (step_size<0.05) step_size=1; //prevent infinite loop

    if (!user_canceled && !error_occured){
        wxLogMessage(_("Error occured, aborting GCL calc!") );
        //wxMessageBox(_("Route interval > Distance, 0 or negative") );
        }
    if (!user_canceled && !error_occured){
        //start
        double lati=0, loni=0,latold=lat1,lonold=lon1,segment_distance=0,fwdAz_dummy=0,revAz_dummy=0;
        double GCL_dist=0;
        bool Lat_limit_found=false;
        double Lat_int1=0, Lat_int2=999999, Lon_int1=0, Lon_int2=0;

        for(double in_distance=0;in_distance<(dist+Tol());in_distance=in_distance+step_size)
            {
            DestVincenty( lat1,  lon1,  fwdAz,  in_distance, &lati, &loni, &revAz);

            if ((lati>0) && (lati>std::abs(limit))){ //North
                if (!Lat_limit_found){
                    if (dbg) std::cout<<"First intersection point"<< std::endl;
                    if (dbg) std::cout<<"------------->"<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                    Lat_int1=lati;
                    Lon_int1=loni;
                    Lat_limit_found=true;
                    lati=limit;
                    if (dbg) std::cout<<"------>N"<< std::endl;
                }

            }
            else if ((lati<0) && (std::abs(lati)>std::abs(limit))){ //south
                if (!Lat_limit_found){
                    if (dbg) std::cout<<"First intersection point"<< std::endl;
                    if (dbg) std::cout<<"------------->"<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                    Lat_int1=lati;
                    Lon_int1=loni;
                    Lat_limit_found=true;
                    lati=-(std::abs(limit));
                    if (dbg) std::cout<<"------>S"<< std::endl;
                }
            }
            else{
                if(Lat_limit_found && (Lat_int2 >99999)){
                    if (dbg) std::cout<<"Second intersection point"<< std::endl;
                    if (dbg) std::cout<<"------------->"<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                    Lat_int2=lati;
                    Lon_int2=loni;
                }
            }

            if(!DistVincenty(latold, lonold, lati, loni, &segment_distance, &fwdAz_dummy, &revAz_dummy)){ error_occured=true; if (dbg) printf("error in 2nd Vncenty\n"); };
                GCL_dist += segment_distance;
                //std::cout<<"Distance: "<<GCL_dist<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                latold=lati;
                lonold=loni;
            }

            //if Lat_limit_found we will do a limited circle calc, otherwise revert to great circle FIXME
            //first GC: (lat1 ,lat2, Lat_int1,x (>Lat_int1&&<Lat_int2) )
            if (Lat_limit_found){
                if (Lat_int1>0){
                    Lat_int1=std::abs(limit);
                    Lat_int2=std::abs(limit);
                }
                else if (Lat_int1<0){
                    Lat_int1=-std::abs(limit);
                    Lat_int2=-std::abs(limit);
                }
                else
                    error_occured=true; //intersecting limit cannot be 0


                int target_az=0;
                if (fwdAz>0 && fwdAz<90) target_az = 270;
                else if (fwdAz>90 && fwdAz<180) target_az = 270;
                else if (fwdAz>180 && fwdAz<270) target_az = 90;
                else if (fwdAz>270 && fwdAz<360) target_az = 90;
                else {error_occured=1; if (dbg) std::cout<<"impossible course for GC!!! "<<fwdAz<<std::endl;}

                //Find position of first section
                this->lat1=lat1;
                this->lon1=lon1;
                this->lat2=Lat_int1;
                //this->lon2=20;
                this->targetAz=target_az;
                {
                    double low_Limit = Lon_int2 > Lon_int1 ? Lon_int1 : Lon_int2;
                    double high_Limit = Lon_int2 > Lon_int1 ? Lon_int2 : Lon_int1;
                    double difference=high_Limit-low_Limit;
                    if (difference>180){
                        double tmp=high_Limit;
                        high_Limit=low_Limit+360;
                        low_Limit=tmp;
                        }

                    Lon_int1=BrentsMethodSolve(low_Limit,high_Limit,1e-13);
                    if (Lon_int1>180)
                        Lon_int1=Lon_int1-360;
                }

                //Second section
                if (target_az==90)
                    target_az=270;
                else if (target_az==270)
                    target_az=90;
                else
                    error_occured=true;

                this->lat1=lat2;
                this->lon1=lon2;
                this->lat2=Lat_int2;
                //this->lon2=20;
                this->targetAz=target_az;
               {
                    double low_Limit = Lon_int2 > Lon_int1 ? Lon_int1 : Lon_int2;
                    double high_Limit = Lon_int2 > Lon_int1 ? Lon_int2 : Lon_int1;

                    double difference=high_Limit-low_Limit;
                    if (difference>180){
                        double tmp=high_Limit;
                        high_Limit=low_Limit+360;
                        low_Limit=tmp;
                        }
                    Lon_int2=BrentsMethodSolve(low_Limit,high_Limit,1e-13);
                    if (Lon_int2>180)
                        Lon_int2=Lon_int2-360;
                }
        //Section 1
        DistVincenty(lat1, lon1, Lat_int1, Lon_int1, &segment_distance, &fwdAz_dummy, &revAz_dummy);
        if (dbg) std::cout<<"Section 1: lat1 "<<lat1<<" lon1: "<<lon1<<" lat2: "<<Lat_int1<<" Lon2: "<<Lon_int1<< std::endl;
        double LC_distance=segment_distance;
        int WPT_counter=0;
        if (write_file){
            //Start
            Addpoint(Route,wxString::Format(wxT("%f"),lat1),wxString::Format(wxT("%f"),lon1), _T("Start") ,_T("diamond"),_T("WPT"));
            //First arc to interception
            //retrieve step-size
            double step_size;
            bool m_IntervalNM_test=false;
            if(!this->m_IntervalNM1->GetValue().ToDouble(&step_size)){ m_IntervalNM_test=true;}
            if ((step_size>dist) || (step_size<dist*1/5000) || (m_IntervalNM_test)){
                m_IntervalNM1->SetValue(wxString::Format(wxT("%g"), dist/100));
                step_size=dist/100;
                if (step_size<0.05) step_size=1; //prevent infinite loop
                }

            for(double in_distance=step_size;in_distance<segment_distance;in_distance=in_distance+step_size)
                {
                DestVincenty( lat1,  lon1,  fwdAz_dummy,  in_distance, &lati, &loni, &revAz);
                if (dbg) std::cout<<"GCL Distance: "<<in_distance<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                Addpoint(Route,wxString::Format(wxT("%f"),lati),wxString::Format(wxT("%f"),loni), wxString::Format(wxT("%d"),++WPT_counter) ,_T("diamond"),_T("WPT"));
            }
            //Interception
            Addpoint(Route, wxString::Format(wxT("%f"),Lat_int1), wxString::Format(wxT("%f"),Lon_int1), _T("Lat Limit1") ,_T("diamond"),_T("WPT"));
       }

       //Parallell sailing
       //DistVincenty(Lat_int1, Lon_int1, Lat_int2, Lon_int2, &segment_distance, &fwdAz_dummy, &revAz_dummy);
       DistanceBearingMercator(Lat_int2, Lon_int2, Lat_int1, Lon_int1, &fwdAz_dummy, &segment_distance);
       LC_distance+=segment_distance;
       //FIXME add wwaypoint writing
       if (write_file){
            for(double in_distance=step_size;in_distance<(segment_distance+Tol());in_distance=in_distance+step_size)
                {
                //DestVincenty( Lat_int2,  Lon_int2,  fwdAz_dummy,  in_distance, &lati, &loni, &revAz);
                destLoxodrome(Lat_int1,  Lon_int1,  fwdAz_dummy,  in_distance, &lati, &loni);
                if (dbg) std::cout<<"GCL Distance: "<<in_distance<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                Addpoint(Route,wxString::Format(wxT("%f"),lati),wxString::Format(wxT("%f"),loni), wxString::Format(wxT("%d"),++WPT_counter) ,_T("diamond"),_T("WPT"));
            }
       }

        //Final section
       DistVincenty(Lat_int2, Lon_int2, lat2, lon2, &segment_distance, &fwdAz_dummy, &revAz_dummy);
       if (dbg) std::cout<<"Section 2: lat1 "<<Lat_int2<<" lon1: "<<Lon_int2<<" lat2: "<<lat2<<" Lon2: "<<lon2<< std::endl;
       LC_distance+=segment_distance;

       if (write_file){
            //Add last point on intersecting limit
            Addpoint(Route, wxString::Format(wxT("%f"),Lat_int2), wxString::Format(wxT("%f"),Lon_int2), _T("Lat_limit2") ,_T("diamond"),_T("WPT"));
            for(double in_distance=step_size;in_distance<segment_distance;in_distance=in_distance+step_size)
                {
                DestVincenty( Lat_int2,  Lon_int2,  fwdAz_dummy,  in_distance, &lati, &loni, &revAz);
                if (dbg) std::cout<<"GCL Distance: "<<in_distance<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                Addpoint(Route,wxString::Format(wxT("%f"),lati),wxString::Format(wxT("%f"),loni), wxString::Format(wxT("%d"),++WPT_counter) ,_T("diamond"),_T("WPT"));
            }
            //Add finish
            Addpoint(Route, wxString::Format(wxT("%f"),lat2), wxString::Format(wxT("%f"),lon2), _T("Finish") ,_T("diamond"),_T("WPT"));
       }

       //Write out distance to dialog box
       this->m_distance_LC->SetValue(wxString::Format(wxT("%g"), LC_distance));

       }
       if (!Lat_limit_found) {
            //no intersection, do normal GC
            //this->m_distance_GC1->SetValue(wxString::Format(wxT("%g"), dist));
            this->m_distance_LC->SetValue(this->m_distance_GC1->GetValue());
            //write file (call to GC function)
            if (write_file){
                if (dbg) std::cout<<"Calling GC function, nothing to limit."<< std::endl;
                this->m_IntervalNM->SetValue(this->m_IntervalNM1->GetValue()); //Make sure right step-sizze is used
                OnExportGC( event );
            }
       }

       if (write_file){
            root->LinkEndChild( Route );
            // check if string ends with .gpx or .GPX
            if (!wxFileExists(s)){
                 s = s + _T(".gpx");
            }
            wxCharBuffer buffer=s.ToUTF8();
            if (dbg) std::cout<< buffer.data()<<std::endl;
            doc.SaveFile( buffer.data() );}
    } //end of if no error occured

    if (error_occured==true)  {
        wxLogMessage(_("Error in calculation. Please check input!") );
        wxMessageBox(_("Error in calculation. Please check input!") );
    }

}

void Dlg::OnExportGCL( wxCommandEvent& event ){

    OnGCLCalculate (event, true);
}

double Dlg::F(double lonx)
{
   //std::cout<<"lat1 "<<lat1<<" lon1: " <<lon1<<"lat2 "<<lat2<<" lonx: " <<lonx<<" targetaz: "<<targetAz<< std::endl;
   double segment_distance_dummy, fwdAz_dummy, revAz_dummy;
   DistVincenty(lat1, lon1, lat2, lonx, &segment_distance_dummy, &fwdAz_dummy, &revAz_dummy);
   return revAz_dummy-targetAz;
}

double Dlg::BrentsMethodSolve(double lowerLimit, double upperLimit, double errorTol)
{
    if (dbg) std::cout<<"-------------------------------------------------------------"<< std::endl;
    double a = lowerLimit;
    double b = upperLimit;

    if (dbg) std::cout<<"lowerLimit: "<<lowerLimit<<" upperLimit: "<< upperLimit<< std::endl;
    double c = 0;
    double d = 0;

    double fa = F(a);
    double fb = F(b);
    if (dbg) std::cout<<"fa: "<<fa<<" fb: " <<fb<< std::endl;

    double fc = 0;
    double s = 0;
    double fs = 0;

    // if f(a) f(b) >= 0 then error-exit
    if (fa * fb >= 0)
    {
        if (fa < fb)
            return a;
        else
            return b;
    }

    // if |f(a)| < |f(b)| then swap (a,b) end if
    if (fabs(fa) < fabs(fb))
    { double tmp = a; a = b; b = tmp; tmp = fa; fa = fb; fb = tmp; }

    c = a;
    fc = fa;
    bool mflag = true;
    int i = 0;

    while (!(fb==0) && (fabs(a-b) > errorTol)&&(i<50))
    {
        if ((fa != fc) && (fb != fc))
            // Inverse quadratic interpolation
            s = a * fb * fc / (fa - fb) / (fa - fc) + b * fa * fc / (fb - fa) / (fb - fc) + c * fa * fb / (fc - fa) / (fc - fb);
        else
            // Secant Rule
            s = b - fb * (b - a) / (fb - fa);

        double tmp2 = (3 * a + b) / 4;
        if ((!(((s > tmp2) && (s < b)) || ((s < tmp2) && (s > b)))) || (mflag && (fabs(s - b) >= (fabs(b - c) / 2))) || (!mflag && (fabs(s - b) >= (fabs(c - d) / 2))))
        {
            s = (a + b) / 2;
            mflag = true;
        }
        else
        {
            if ((mflag && (fabs(b - c) < errorTol)) || (!mflag && (fabs(c - d) < errorTol)))
            {
                s = (a + b) / 2;
                mflag = true;
            }
            else
                mflag = false;
        }
        fs = F(s);
        d = c;
        c = b;
        fc = fb;
        if (fa * fs < 0) { b = s; fb = fs; }
        else { a = s; fa = fs; }

        // if |f(a)| < |f(b)| then swap (a,b) end if
        if (fabs(fa) < fabs(fb))
        { double tmp = a; a = b; b = tmp; tmp = fa; fa = fb; fb = tmp; }

        if (dbg) std::cout<<"Iteration: "<<i<<" lon: " <<b<<" target: "<<fs<< std::endl;
        i++;
    }
    if ((i > 999) || (fs>Tol()))
        wxMessageBox(_("Brent's method not converging, check result") );
    return b;
}

void Dlg::OnExportRH( wxCommandEvent& event )
{
    bool error_occured=false;
    bool user_canceled=false;
    wxFileDialog dlg(this, _("Export Rhumb Line GPX file as"), wxEmptyString, wxEmptyString, _T("GPX files (*.gpx)|*.gpx|All files (*.*)|*.*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (dlg.ShowModal() == wxID_CANCEL)
        user_canceled=true;     // the user changed idea...
    if (!user_canceled && !dlg.GetPath().IsEmpty()){
            double dist, fwdAz;//, revAz;

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

            DistanceBearingMercator(lat2, lon2, lat1, lon1, &fwdAz, &dist);

            if (error_occured==true)  {
                wxLogMessage(_("Error in calculation. Please check input!") );
                wxMessageBox(_("Error in calculation. Please check input!") );}

            ////////////////////Start XML
            TiXmlDocument doc;
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
            TiXmlText * text4 = new TiXmlText( this->m_Route->GetValue().ToUTF8() );
            Route->LinkEndChild( RouteName );
            RouteName->LinkEndChild( text4 );

            TiXmlElement * Extensions = new TiXmlElement( "extensions" );

            TiXmlElement * StartN = new TiXmlElement( "opencpn:start" );
            TiXmlText * text5 = new TiXmlText( this->m_Start->GetValue().ToUTF8() );
            Extensions->LinkEndChild( StartN );
            StartN->LinkEndChild( text5 );

            TiXmlElement * EndN = new TiXmlElement( "opencpn:end" );
            TiXmlText * text6 = new TiXmlText( this->m_End->GetValue().ToUTF8() );
            Extensions->LinkEndChild( EndN );
            EndN->LinkEndChild( text6 );

            Route->LinkEndChild( Extensions );
            //////////////////////Add Points HERE

            double step_size;
            bool m_IntervalNM_test=false;
            if(!this->m_IntervalNM->GetValue().ToDouble(&step_size)){ m_IntervalNM_test=true;}
            //check step size distance
            if ((step_size>dist) || (step_size<dist*1/5000) || (m_IntervalNM_test)){
                m_IntervalNM->SetValue(wxString::Format(wxT("%g"), dist/100));
                step_size=dist/100;
                if (step_size<0.05) step_size=1; //prevent infinite loop
            }
            //start
            Addpoint(Route,wxString::Format(wxT("%f"),lat1),wxString::Format(wxT("%f"),lon1),_T("Start"),_T("diamond"),_T("WPT"));
            double lati, loni;
            for(double in_distance=step_size;in_distance<dist;in_distance=in_distance+step_size)
                {
                //DestVincenty( lat1,  lon1,  fwdAz,  in_distance, &lati, &loni, &revAz);
                if (dbg) std::cout<<"RH lat1 "<<lat1<<" lon1: " <<lon1<<"fwdAZ "<<fwdAz<<" dist " <<in_distance<< std::endl;
                destLoxodrome(lat1,  lon1,  fwdAz,  in_distance, &lati, &loni);
                //destRhumb(lat1, lon1, fwdAz,in_distance, &lati, &loni);
                if (dbg) std::cout<<"Distance: "<<in_distance<<"lat: "<<lati<<" lon: "<<loni<< std::endl;
                Addpoint(Route,wxString::Format(wxT("%f"),lati),wxString::Format(wxT("%f"),loni), wxString::Format(wxT("%d"),(int)in_distance) ,_T("diamond"),_T("WPT"));
                }
            //end
            Addpoint(Route,wxString::Format(wxT("%f"),lat2),wxString::Format(wxT("%f"),lon2),_T("Finish"),_T("SYMBOL"),_T("WPT"));
            //////////////////////////Close XML

            root->LinkEndChild( Route );
            wxString s=dlg.GetPath();

            if (!wxFileExists(dlg.GetPath())) {
                 s = s + _T(".gpx");
            }
            wxCharBuffer buffer=s.ToUTF8();
            if (dbg) std::cout<< buffer.data()<<std::endl;
            doc.SaveFile( buffer.data() );
        }
}


