
#include "Cuadrado.h"
#include "Lista.h"

class Escena{
	
	public:
		int xRight;
		int xLeft;
		Lista<Lista<Cuadrado>> *lista;

		Escena (Cuadrado primero)
		{
			xRight = 0;
			xLeft = 0;
			lista = new Lista<Lista<Cuadrado>>();
			Lista<Cuadrado> * listaAux = new Lista<Cuadrado>();
			listaAux->InsertarPrincipio(primero);
			lista->InsertarPrincipio(*listaAux);
		};

		~Escena()
		{
			xRight = 0;
			xLeft = 0;
			delete lista;
		}


};