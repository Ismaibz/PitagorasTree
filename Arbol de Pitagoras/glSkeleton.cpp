//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("glSkeleton.res");
USEFORM("UFP.cpp", GLForm2D);
USEUNIT("Cuadrado.cpp");
USEUNIT("Escena.cpp");
USEUNIT("Lapiz.cpp");
USEUNIT("Lista.cpp");
USEUNIT("PV2D.cpp");
USEFORM("FormPrimerCuadrado.cpp", FormLado);
USEFORM("TFormZoom.cpp", FormZoom);
USEFORM("TFormEmbaldosado.cpp", FormEmbaldosado);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm2D), &GLForm2D);
                 Application->CreateForm(__classid(TFormLado), &FormLado);
                 Application->CreateForm(__classid(TFormZoom), &FormZoom);
                 Application->CreateForm(__classid(TFormEmbaldosado), &FormEmbaldosado);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
