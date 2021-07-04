#include "Face.h"
#include "Vertex.h"
#include <armadillo>

using namespace std;

Face::Face()
{
	ver1 = 0;
	ver2 = 0;
	ver3 = 0;
}

Face::Face(int v1, int v2, int v3)
{
	ver1 = v1;
	ver2 = v2;
	ver3 = v3;
}

Face::~Face()
{
}

void Face::setFace(int v1, int v2, int v3)//
{
	ver1 = v1;
	ver2 = v2;
	ver3 = v3;
}

void Face::setNormales(float a, float b, float c, float d, float an, float bn, float cn, arma::fvec vN)
{
	A = a;
	B = b;
	C = c; 
	D = d;
	AN = an;
	BN = bn;
	CN = cn;
	veNor = vN;	
}

int Face::getFace1()
{
	return ver1;
}

int Face::getFace2()
{
	return ver2;
}

int Face::getFace3()
{
	return ver3;
}

void Face::print()
{
	printf("[%d, %d, %d]\n", ver1, ver2, ver3);
}


float Face::getAN()
{
	return AN;
}


float Face::getBN()
{
	return BN;
}

float Face::getCN()
{
	return CN;
}

arma::fvec Face::getveNor()
{
	return veNor;
}