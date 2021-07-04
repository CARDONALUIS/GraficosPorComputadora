#include "Traslacion.h"
#include "Vertex.h"
#include  <armadillo>


Traslacion::Traslacion(float tx, float ty, float tz, Vertex v1)
{
	MT = {
		{1.0f,0.0f,0.0f,tx},
		{0.0f,1.0f,0.0f,ty},
		{0.0f,0.0f,1.0f,tz},
		{0.0f,0.0f,0.0f,1.0f}
	};

	V1.CX = v1.getVertexX();
	V1.CY = v1.getVertexY();
	V1.CZ = v1.getVertexZ();

	VT = { {V1.CX},{V1.CY},{V1.CZ},{1.0f}};

	multiT(MT, VT);

}


void Traslacion::multiT(arma::fmat mt, arma::fcolvec vt)
{
	VR = mt * vt;
}


Traslacion::~Traslacion()
{
}