
#include <gl/GL.h>

class PV2D{

	public:
		GLdouble x;
		GLdouble y;

	PV2D()
	{
		x = 0;
		y = 0;
	}

	PV2D(GLdouble xn, GLdouble yn)
	{
		x = xn;
		y = yn;
	}

	PV2D(const PV2D &p)
	{
		x = p.x;
		y = p.y;
	}

	~PV2D()
	{
		x = 0;
		y = 0;
	}

};