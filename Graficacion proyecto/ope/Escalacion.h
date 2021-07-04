#ifndef ESCALACION_H
#define ESCALACION_H

#include "Vertex.h"
#include  <armadillo>

class Escalacion
{
public:
	Vertex V1;
	arma::fmat ME;
	arma::fcolvec VE;
	arma::fcolvec VR;

	Escalacion(float ESC, Vertex V1);
	void multi(arma::fmat ME, arma::fcolvec VE);
	~Escalacion();
};


#endif // ESCALACION_H
