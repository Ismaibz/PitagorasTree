//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH
//---------------------------------------------------------------------------
#include "Cuadrado.h"
#include "Lista.h"

class Escena{
	
	public:
		int xRight;
		int xLeft;
	  	Lista<Lista<Cuadrado>>* lista;

		Escena (Cuadrado primero);
		~Escena();



};



#endif
