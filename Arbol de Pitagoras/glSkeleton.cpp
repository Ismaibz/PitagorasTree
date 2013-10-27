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
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm2D), &GLForm2D);
                 Application->CreateForm(__classid(TFormLado), &FormLado);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
