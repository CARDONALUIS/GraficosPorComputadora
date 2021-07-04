#include "VertexC.h"
#include <armadillo>

VertexC::VertexC()
{
	v = { 0.0, 0.0, 0.0 };
}

VertexC::VertexC(float x, float y, float z)
{
	v = { x, y, z };
}

void VertexC::set_value(arma::frowvec val) {
	v = val;
}

arma::frowvec VertexC::get_value()
{
	return(v);
}

void VertexC::print()
{
	v.print();
}

VertexC::~VertexC()
{
}