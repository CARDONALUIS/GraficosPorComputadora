#ifndef VERTEXC_H
#define VERTEXC_H
#include <armadillo>

class VertexC
{
public:
	arma::frowvec v;
	VertexC();
	VertexC(float X, float Y, float Z);
	void set_value(arma::frowvec VAL);
	arma::frowvec get_value();
    void print();
	~VertexC();
};

#endif // VERTEXC_H
