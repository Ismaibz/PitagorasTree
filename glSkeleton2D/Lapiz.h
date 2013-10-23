//---------------------------------------------------------------------------

#ifndef LapizH
#define LapizH
//---------------------------------------------------------------------------

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "PV2D.h"
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
using namespace std;
class Lapiz{

public:
	PV2D* pos;
	GLdouble dir;

	Lapiz();
	Lapiz(PV2D * p, GLdouble d);
	~Lapiz();
	void moveTo(PV2D* p, bool draw);
	void turnTo(GLdouble a);
	void turn(GLdouble a);
	void forward(GLdouble dist, bool draw);


};


#endif
