//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cuadrado.h"

//---------------------------------------------------------------------------

Cuadrado::Cuadrado(PV2D *v1n,PV2D *v2n,PV2D *v3n,PV2D *v4n)
{
        v1 = new PV2D(*v1n);
        v2 = new PV2D(*v2n);
        v3 = new PV2D(*v3n);
        v4 = new PV2D(*v4n);
       /* delete v1n;
        delete v2n;
        delete v3n;
        delete v4n;    */
};

Cuadrado::~Cuadrado()
{
        delete v1;
        delete v2;
        delete v3;
        delete v4;
};




#pragma package(smart_init)
