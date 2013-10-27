//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH
//---------------------------------------------------------------------------
#include "Cuadrado.h"
#include "Lista.h"
#include "Lapiz.h"


class Escena{

	public:
		int xRight;
		int xLeft;
                Lista< Lista<Cuadrado*> *> *lista;

		Escena (Cuadrado* primero);
		~Escena();
                void dibuja(TForm* form, Lapiz* lapiz, int lado);



};



#endif
