//---------------------------------------------------------------------------

#ifndef TFormZoomH
#define TFormZoomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormZoom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *TextZoom;
        TLabel *Label2;
        TButton *BotonAceptar;
        void __fastcall BotonAceptarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormZoom(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormZoom *FormZoom;
//---------------------------------------------------------------------------
#endif
