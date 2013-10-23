//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------



       Escena::Escena(Cuadrado primero)
       {
                xRight = 0;
                xLeft = 0;
                lista = new Lista<Lista<Cuadrado>>();
                Lista<Cuadrado> * listaAux = new Lista<Cuadrado>();
                listaAux->InsertarPrincipio(primero);
                lista->InsertarPrincipio(*listaAux);
       };

       Escena::~Escena()
       {
                xRight = 0;
                xLeft = 0;
                delete lista;
       };



#pragma package(smart_init)
