//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

#include "FormPrimerCuadrado.h"
#include "Cuadrado.h"
#include "Escena.h"
#include "Lapiz.h"

//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Archivo;
        TMenuItem *Salir;
        TMenuItem *Programa;
        TMenuItem *PrimerCuadrado;
        TMenuItem *SiguienteGeneracion;
        TMenuItem *Zoom;
        TMenuItem *ZoomIn;
        TMenuItem *ZoomOut;
        TMenuItem *Embaldosado;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
        void __fastcall SalirClick(TObject *Sender);
        void __fastcall PrimerCuadradoClick(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tamaño del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 // métodos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();
 bool primerCuadrado;
 int xCuadrado;
 int yCuadrado;
 Escena* escena;
 Lapiz* lapiz;

 public:
   		// User declarations
   int lado;
   __fastcall TGLForm2D(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
