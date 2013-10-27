//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------

Escena::Escena(Cuadrado* primero)
{
        xRight = 0;
        xLeft = 0;
        Lista<Cuadrado*>* listaAux = new Lista<Cuadrado*>();
        listaAux->InsertarPrincipio(primero);
        lista = new Lista< Lista<Cuadrado*> *>();
        lista->InsertarPrincipio(listaAux);

};

Escena::~Escena()
{
        xRight = 0;
        xLeft = 0;
        delete lista;
};

void Escena::dibuja(TForm* form, Lapiz* lapiz, int lado)
{
        lista->Primero();
        Lista<Cuadrado*>* listaAux = lista->ValorActual();
        listaAux->Primero();
        while (listaAux->Actual())
        {
                Cuadrado* aux = listaAux->ValorActual();
                lapiz->moveTo(aux->v1,false);
                lapiz->forward((GLdouble)lado,true);
                lapiz->turn((GLdouble)0.5);
                lapiz->forward((GLdouble)lado,true);
                lapiz->turn((GLdouble)0.5);
                lapiz->forward((GLdouble)lado,true);
                lapiz->turn((GLdouble)0.5);
                lapiz->forward((GLdouble)lado,true);
                listaAux->Siguiente();
        }
};



#pragma package(smart_init)
