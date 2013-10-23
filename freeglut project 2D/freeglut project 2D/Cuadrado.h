
#include "PV2D.h"

class Cuadrado{

public:

	PV2D *v1;
	PV2D *v2;
	PV2D *v3;
	PV2D *v4;

	Cuadrado(PV2D v1n,PV2D v2n,PV2D v3n,PV2D v4n)
	{
		v1 = new PV2D(v1n);
		v2 = new PV2D(v2n);
		v3 = new PV2D(v3n);
		v4 = new PV2D(v4n);
	}

	~Cuadrado()
	{
		delete v1;
		delete v2;
		delete v3;
		delete v4;
	}

};