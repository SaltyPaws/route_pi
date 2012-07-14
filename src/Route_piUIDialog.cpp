#include "Route_piUIDialog.h"

Route_piUIDialog::Route_piUIDialog( wxWindow* parent )
:
UIDialog( parent )
{

}

void Route_piUIDialog::OnParallelSearchClick( wxCommandEvent& event ){
      PrefsDialog *dialog = new PrefsDialog( parent, wxID_ANY, _("Route & SAR Preferences"), wxPoint( m_route_dialog_x, m_route_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->Fit();
      wxColour cl;
      GetGlobalColor(_T("DILG1"), &cl);
      dialog->SetBackgroundColour(cl);

      /*dialog->m_rbViewType->SetSelection(m_iViewType);
      dialog->m_cbShowAtCursor->SetValue(m_bShowAtCursor);
      dialog->m_cbLiveIcon->SetValue(m_bShowLiveIcon);
      dialog->m_sOpacity->SetValue(m_iOpacity);*/

      if(dialog->ShowModal() == wxID_OK)
      {
            /*m_iViewType = dialog->m_rbViewType->GetSelection();
            m_bShowAtCursor = dialog->m_cbShowAtCursor->GetValue();
            m_bShowLiveIcon = dialog->m_cbLiveIcon->GetValue();
            m_iOpacity = dialog->m_sOpacity->GetValue();

            RearangeWindow();

            SaveConfig();*/
      }
      delete dialog;
}
