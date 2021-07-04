#ifndef ROTACION_H
#define ROTACION_H
#include "Vertex.h"
#include  <armadillo>


class Rotacion
{
public:
	
	Vertex V1;
	float ANGULO;
	arma::fmat MX;
	arma::fmat MY;
	arma::fmat MZ;
	arma::fmat MA;

	arma::fcolvec V;
	arma::fcolvec VR, VRL;

	Rotacion(int TIPOR, Vertex V1, float ANGULO);
	Rotacion(int TIPOR, float ANGULO);
	void multiR(arma::fmat M, arma::fcolvec V);
	~Rotacion();
};


#endif // ROTACION_H
