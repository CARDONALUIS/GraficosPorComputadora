#ifndef OBJ_H
#define OBJ_H
#include "Vertex.h"
#include "Face.h"
#include <list>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <armadillo>

using namespace std;

class Obj
{
public:
	vector <Face> facVer;
	vector <Vertex> verVec;
	char *nomArchi;
	Obj(char *archiNom);
	string leeArchivo(char *tipo);
	vector <Vertex> llenaListaVer(string numeros);
	vector <Face> llenaListaFac(string numerosf, vector <Vertex> lsVe, arma ::fvec foco);
	void relaciona(vector <Vertex> lisVer, vector <Face> lisFac);
	vector <Face> calNormal(vector <Vertex> lisVer, vector <Face> lisFac,arma::fvec foco);
	~Obj();

};

#endif // OBJ_H
