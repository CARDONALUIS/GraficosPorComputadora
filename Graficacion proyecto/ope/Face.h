#ifndef FACE_H
#define FACE_H

#include <list>
#include <fstream>
#include <iostream>
#include <armadillo>


using namespace std;

class Face
{
public:
	int ver1, ver2, ver3;
	float A, AN, B, BN, C, CN, D;
	float magnitud,  magnitudL;
	arma::fvec veNor;
	arma::fvec vecL, vecLN;
	Face();
	Face(int v1, int v2, int v3);
	void setFace(int v1, int v2, int v3);
	void setNormales(float, float, float, float, float, float, float, arma::fvec);
	int getFace1();
	int getFace2();
	int getFace3();
	float getAN();
	float getBN();
	float getCN();
	arma::fvec getveNor();
	void print();
	~Face();
};

#endif // FACE_H
