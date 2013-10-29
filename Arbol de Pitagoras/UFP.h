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
#include "TFormZoom.h"
#include "TFormEmbaldosado.h"
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
        TMenuItem *Embaldosado;
        TMenuItem *Embaldosar;
        TMenuItem *Desembaldosar;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
        void __fastcall SalirClick(TObject *Sender);
        void __fastcall PrimerCuadradoClick(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall ZoomClick(TObject *Sender);
        void __fastcall EmbaldosarClick(TObject *Sender);
        void __fastcall DesembaldosarClick(TObject *Sender);
        void __fastcall SiguienteGeneracionClick(TObject *Sender);

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
 void aplicarZoom(GLdouble zoom);
 void embaldosar(int nCol);
 bool baldosas;
 void drawScene();
 int nCol;
 void desEmbaldosar();
 int generacion;

 public:
   		// User declarations
   float lado;
   __fastcall TGLForm2D(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
