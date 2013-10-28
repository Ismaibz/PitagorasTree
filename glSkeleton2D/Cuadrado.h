//---------------------------------------------------------------------------

#ifndef CuadradoH
#define CuadradoH
//---------------------------------------------------------------------------

#include "PV2D.h"

class Cuadrado{

public:

	PV2D *v1;
	PV2D *v2;
	PV2D *v3;
	PV2D *v4;

	Cuadrado(PV2D v1n,PV2D v2n,PV2D v3n,PV2D v4n);
	~Cuadrado();

};


#endif
