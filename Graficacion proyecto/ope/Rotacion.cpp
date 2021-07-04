#include "Rotacion.h"
#include "Vertex.h"
#include  <armadillo>



Rotacion::Rotacion(int tipoR, Vertex v1, float angulo)
{
	switch (tipoR)
	{
	case 1://x
		MX = {
		{1.0f,0.0f,0.0f,0.0f},
		{0.0f, (float)cos(angulo * 3.14159 / 180),-(float)sin(angulo * 3.14159 / 180),0.0f},
		{0.0f,(float)sin(angulo * 3.14159 / 180),(float)cos(angulo * 3.14159 / 180),0.0f},
		{0.0f, 0.0f, 0.0f,1.0f}
		};
	
		break;
	case 2://y
		MY = {
		{(float)cos(angulo * 3.14159 / 180),0.0f,(float)sin(angulo * 3.14159 / 180),0.0f},
		{0.0f, 1.0f,0.0f,0.0f},
		{-(float)sin(angulo * 3.14159 / 180),0.0f,(float)cos(angulo * 3.14159 / 180),0.0f},
		{0.0f, 0.0f, 0.0f,1.0f}
		};
		
	break;

	case 3://z
		MZ = {
		{(float)cos(angulo * 3.14159 / 180),-(float)sin(angulo * 3.14159 / 180),0.0f,0.0f},
		{(float)sin(angulo * 3.14159 / 180), (float)cos(angulo * 3.14159 / 180),0.0f,0.0f},
		{0.0f,0.0f,1.0f,0.0f},
		{0.0f, 0.0f, 0.0f,1.0f}
		};
	break;
	}

	V1.CX = v1.getVertexX();
	V1.CY = v1.getVertexY();
	V1.CZ = v1.getVertexZ();

	V = { {V1.CX},{V1.CY},{V1.CZ},{1.0f} };

   

	switch (tipoR)
	{
	case 1://x
		multiR(MX, V);

		break;
	case 2://y
		multiR(MY, V);
		break;
	case 3://z
		multiR(MZ, V);
		break;
	}
}


Rotacion::Rotacion(int tipoR, float angulo)
{
	int z;
	switch (tipoR)
	{
	case 1://x
		MX = {
		{1.0f,0.0f,0.0f,0.0f},
		{0.0f, (float)cos(angulo * 3.14159 / 180),-(float)sin(angulo * 3.14159 / 180),0.0f},
		{0.0f,(float)sin(angulo * 3.14159 / 180),(float)cos(angulo * 3.14159 / 180),0.0f},
		{0.0f, 0.0f, 0.0f,1.0f}
		};
		MA = MX;
		z = 0;
		break;
	case 2://y
		MY = {
		{(float)cos(angulo * 3.14159 / 180),0.0f,(float)sin(angulo * 3.14159 / 180),0.0f},
		{0.0f, 1.0f,0.0f,0.0f},
		{-(float)sin(angulo * 3.14159 / 180),0.0f,(float)cos(angulo * 3.14159 / 180),0.0f},
		{0.0f, 0.0f, 0.0f,1.0f}
		};
		
		MA = MY;
		break;
	case 3://z
		MZ = {
		{(float)cos(angulo * 3.14159 / 180),-(float)sin(angulo * 3.14159 / 180),0.0f,0.0f},
		{(float)sin(angulo * 3.14159 / 180), (float)cos(angulo * 3.14159 / 180),0.0f,0.0f},
		{0.0f,0.0f,1.0f,0.0f},
		{0.0f, 0.0f, 0.0f,1.0f}
		};
		MA = MZ;
		break;
	}
}


void Rotacion::multiR(arma::fmat mr, arma::fcolvec vr)
{
	VR = mr * vr;
}


Rotacion::~Rotacion()
{
}
