//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
__fastcall TGLForm2D::TGLForm2D(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    //Cor de fondo de la ventana
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //inicialización del volumen de vista
    xRight=200.0; xLeft=-xRight;
    yTop=xRight; yBot=-yTop;
    //Radio del volumen de vista == 1

    //inicialización del puerto de vista
    //ClientWidth=400;
    //ClientHeight=400;
    RatioViewPort=1.0;
    primerCuadrado = false;
    lapiz = new Lapiz();
    // inicialización de las variables del programa
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
    int PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------
void __fastcall TGLForm2D::FormResize(TObject *Sender)
{

 //se actualiza puerto de vista y su radio
  if ((ClientWidth<=1)||(ClientHeight<=1)){
     ClientWidth=400;
     ClientHeight=400;
     RatioViewPort=1.0;
     }
  else RatioViewPort= (float)ClientWidth/(float)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  // se actualiza el volumen de vista
  // para que su radio coincida con ratioViewPort
  GLfloat WidthVolVista = xRight-xLeft;
  GLfloat HeightVolVista = yTop-yBot;
  GLfloat RatioVolVista = (xRight-xLeft)/(yTop-yBot);

  if (RatioVolVista>=RatioViewPort){
     //Aumentamos yTop-yBot
     GLfloat newHeight = WidthVolVista/RatioViewPort;
     GLfloat yMiddle = (yTop+yBot)/2.0;
     yTop= yMiddle+newHeight/2.0;
     yBot= yMiddle-newHeight/2.0;
     }
  else{
     //Aumentamos xRight-xLeft
     GLfloat newWidth = HeightVolVista*RatioViewPort;
     GLfloat xMiddle = (xLeft+xRight)/2.0;
     xRight= xMiddle+newWidth/2.0;
     xLeft= xMiddle-newWidth/2.0;
     }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight, yBot,yTop);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  GLScene();

}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::GLScene()
{
//glClear(GL_COLOR_BUFFER_BIT);



//glFlush();
SwapBuffers(hdc);
}

//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormPaint(TObject *Sender)
{
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormDestroy(TObject *Sender)
{
    ReleaseDC(Handle,hdc);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
    // eliminar objetos creados
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::SalirClick(TObject *Sender)
{
        exit(-1);        
}
//---------------------------------------------------------------------------


void __fastcall TGLForm2D::PrimerCuadradoClick(TObject *Sender)
{

       TFormLado* FormLado;
       FormLado = new TFormLado(NULL);
       FormLado->ShowModal();
       AnsiString tam = FormLado->TamanoLado->Text;
       lado = atoi(tam.c_str());
       ShowMessage("Presione un punto para colocar el primer cuadrado");
       primerCuadrado = true;

}

//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormClick(TObject *Sender)
{
          if (primerCuadrado == true)
          {
                GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                TPoint p;
                GetCursorPos(&p);
                xCuadrado = p.x - this->Left;
                yCuadrado = this->Height - (p.y - this->Top);
                primerCuadrado = false;
                GLfloat xAbs =  (xCuadrado / escalaAncho) + xLeft;
                GLfloat yAbs =  (yCuadrado / escalaAlto) + yBot;
                PV2D *p1 = new PV2D(xAbs - (lado / 2.0), yAbs - (lado / 2.0));
                PV2D *p2 = new PV2D(xAbs + (lado / 2.0), yAbs - (lado / 2.0));
                PV2D *p3 = new PV2D(xAbs + (lado / 2.0), yAbs + (lado / 2.0));
                PV2D *p4 = new PV2D(xAbs - (lado / 2.0), yAbs + (lado / 2.0));
                Cuadrado* primero = new Cuadrado(p1,p2,p3,p4);
                escena = new Escena(primero);
                escena->dibuja(this,lapiz,lado);
                Repaint();
          }
}
//---------------------------------------------------------------------------

