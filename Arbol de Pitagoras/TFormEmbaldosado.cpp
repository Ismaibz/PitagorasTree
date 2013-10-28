//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFormEmbaldosado.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEmbaldosado *FormEmbaldosado;
//---------------------------------------------------------------------------
__fastcall TFormEmbaldosado::TFormEmbaldosado(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEmbaldosado::BotonAceptarClick(TObject *Sender)
{
        ModalResult = mrOk;        
}
//---------------------------------------------------------------------------
