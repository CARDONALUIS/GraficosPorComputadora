#ifndef TRASLACION_H
#define TRASLACION_H

#include "Vertex.h"
#include  <armadillo>

class Traslacion
{
public:
	Vertex V1;
	arma::fmat MT;
	arma::fcolvec VT;
	arma::fcolvec VR;

	Traslacion(float TX, float TY, float TZ, Vertex V1);
	void multiT(arma::fmat MT, arma::fcolvec VR);
	~Traslacion();
};

#endif // TRASLACION_H
