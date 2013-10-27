//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormPrimerCuadrado.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLado *FormLado;
//---------------------------------------------------------------------------
__fastcall TFormLado::TFormLado(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormLado::BotonAceptarClick(TObject *Sender)
{
        AnsiString tam = TamanoLado->Text;
        int tama = atoi(tam.c_str());
        if (tama < 1) ShowMessage("Elija un tamaño mayor que 0");
        else ModalResult = mrOk;
}
//---------------------------------------------------------------------------


