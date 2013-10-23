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

	Lapiz()
	{
		pos = new PV2D();
		dir = 0;
	};

	Lapiz(PV2D * p, GLdouble d)
	{
		pos = new PV2D(*p);
		dir = d;
	};

	~Lapiz()
	{
		delete pos;
	};

	void moveTo(PV2D* p, bool draw)
	{
		if (draw)
		{
			glBegin (GL_LINES);
				glVertex2d(pos->x,pos->y);
				glVertex2d(p->x,p->y);
			glEnd();
		}
		delete pos;
		pos  = new PV2D(*p);
		// borrar p si no se borra en otro sitio		
	};

	void turnTo(GLdouble a)
	{
		dir = a;
	};

	void turn(GLdouble a)
	{
		dir += a;
	};

	void forward(GLdouble dist, bool draw)
	{
		PV2D *p = new PV2D(pos->x + dist*cos(dir),pos->y + dist*sin(dir));
		if (draw)
		{
			glBegin (GL_LINES);
				glVertex2d(pos->x,pos->y);
				glVertex2d(p->x,p->y);
			glEnd();
		}
		delete pos;
		pos  = new PV2D(*p);
		delete p;
	};


};

 