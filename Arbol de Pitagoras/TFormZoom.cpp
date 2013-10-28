//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFormZoom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormZoom *FormZoom;
//---------------------------------------------------------------------------
__fastcall TFormZoom::TFormZoom(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormZoom::BotonAceptarClick(TObject *Sender)
{
        AnsiString tam = TextZoom->Text;
        int zoom = atoi(tam.c_str());
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------
