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

void Escena::dibuja(Lapiz* lapiz)
{
        lista->Ultimo();
        int generacion = 0;
        while (lista->Actual())
        {
                if ( generacion > 8)
                         glColor3f(0.0,0.6,0.0);
                else
                {
                        if (generacion > 4)

                              glColor3f(0.0,0.2,0.0);
                        else
                            glColor3f(0.4,0.2,0.0);   
                }
                generacion++;
                Lista<Cuadrado*>* listaAux = lista->ValorActual();
                listaAux->Primero();
                while (listaAux->Actual())
                {

                        Cuadrado* aux = listaAux->ValorActual();
                        glBegin(GL_QUADS);
                                glVertex2d(aux->v1->x,aux->v1->y);
                                glVertex2d(aux->v2->x,aux->v2->y);
                                glVertex2d(aux->v3->x,aux->v3->y);
                                glVertex2d(aux->v4->x,aux->v4->y);
                        glEnd();

                        listaAux->Siguiente();
                }
                lista->Anterior();
        }
};

void Escena::expande(Lapiz* lapiz, float lado)
{
        lista->Primero();
        Lista<Cuadrado*>* listaAux = lista->ValorActual();
        listaAux->Primero();
        Lista<Cuadrado*>* listaNueva = new Lista<Cuadrado*>();
                while (listaAux->Actual())
                {
                        Cuadrado* aux = listaAux->ValorActual();

                        //Cuadrado de la derecha (a partir del v3)
                        lapiz->moveTo(aux->v3,false);
                        lapiz->lookAt(aux->v4);
                        lapiz->turn(-0.75);
                        PV2D* p2 = new PV2D(*lapiz->pos);
                        lapiz->forward(lado,false);
                        PV2D* p3 = new PV2D(*lapiz->pos);
                        lapiz->turn(0.5);
                        lapiz->forward(lado,false);
                        PV2D* p4 = new PV2D(*lapiz->pos);
                        lapiz->turn(0.5);
                        lapiz->forward(lado,false);
                        PV2D* p1 = new PV2D(*lapiz->pos);
                        Cuadrado* nuevo1 = new Cuadrado(p1,p2,p3,p4);
                        listaNueva->InsertarPrincipio(nuevo1);

                        //Cuadrado de la izquierda (a partir del v4)
                        lapiz->moveTo(aux->v3,false);
                        lapiz->lookAt(aux->v4);
                        lapiz->moveTo(aux->v4,false);
                        lapiz->turn(-0.75);
                        PV2D* p12 = new PV2D(*lapiz->pos);
                        lapiz->forward(lado,false);
                        PV2D* p22 = new PV2D(*lapiz->pos);
                        lapiz->turn(0.5);
                        lapiz->forward(lado,false);
                        PV2D* p32 = new PV2D(*lapiz->pos);
                        lapiz->turn(0.5);
                        lapiz->forward(lado,false);
                        PV2D* p42 = new PV2D(*lapiz->pos);
                        Cuadrado* nuevo2 = new Cuadrado(p12,p22,p32,p42);
                        listaNueva->InsertarPrincipio(nuevo2);
                        listaAux->Siguiente();
                }
                lista->InsertarPrincipio(listaNueva);
};



#pragma package(smart_init)
