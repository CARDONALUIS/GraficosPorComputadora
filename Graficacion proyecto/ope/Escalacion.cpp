#include "Escalacion.h"
#include "Vertex.h"
#include <armadillo>


Escalacion::Escalacion(float esc, Vertex v1)
{
	ME = { {esc, 0.0f, 0.0f, 0.0f},
		{0.0f, esc, 0.0f, 0.0f},
		{0.0f, 0.0f, esc, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f} };

	V1.CX= v1.getVertexX();
	V1.CY = v1.getVertexY();
	V1.CZ = v1.getVertexZ();

	VE = { {V1.CX},{V1.CY},{V1.CZ},{1.0f}};

	multi(ME, VE);
}


Escalacion::~Escalacion()
{
    
}


void Escalacion::multi(arma::fmat me, arma::fcolvec ve)
{
	VR = me * ve;
}

