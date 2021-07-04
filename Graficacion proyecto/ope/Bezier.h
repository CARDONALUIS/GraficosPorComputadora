#ifndef BEZIER_H
#define BEZIER_H
#include <armadillo>
#include "VertexC.h"
#include "Vertex.h"
#include "Face.h"

class Bezier
{
public:
	float dt = 0.02f;
	arma::fmat MHB;
	VertexC Pb1, Pb2, Pb3, Pb4;
	std::vector< VertexC > vcurveB;

	Bezier();
	Bezier(VertexC , VertexC , VertexC , VertexC );
	void calc_curve();
	void print();
	void printGrap(vector <Vertex>, vector <Face>, float , float, float, arma::fvec ,arma::fvec ,arma::fvec ,float  ,float ,float  , float );
	~Bezier();
};

#endif // BEZIER_H
