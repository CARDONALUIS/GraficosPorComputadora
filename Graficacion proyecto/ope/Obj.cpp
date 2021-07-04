#include "Obj.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <stdio.h>
#include <cstdio>
#include <limits>
#include <vector>
#include <math.h>
#include <string>
#include <armadillo>

using namespace std;

Obj::Obj(char *archiNom)
{
	nomArchi = archiNom;
}

Obj::~Obj()
{

}

string Obj::leeArchivo(char *tipo)
{
	ifstream archivo;
	string texto;
	string prueba, numeros;
	string cx, cy, cz;
	

	char separador = ' ';


	archivo.open(nomArchi, ios::in);//Abrimos el archivo en modo lectura
	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	while (!archivo.eof())//Mientras no sea el final del archivo
	{
		getline(archivo, texto);
		prueba = texto.substr(0, 2);

		if (prueba == tipo)
		{
			for (size_t p = 0, q = 0; p != texto.npos; p = q)
			{
				numeros += (texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0)));
				numeros += ' ';
			}
		}
	}

	archivo.close();
	return numeros;
}

vector <Vertex> Obj::llenaListaVer(string numeros)
{
	int i = 0;
	int conCor = 0;
	string cx, cy, cz;
	Vertex v1;

	while (numeros[i] != '\0')
	{
		switch (conCor)
		{
		case 0:
			if (numeros[i] == '.')
			{
				cx += numeros[i];
			}
			if (numeros[i] == '-')
			{
				cx += numeros[i];
			}
			if (isdigit(numeros[i]))
			{
				if (numeros[i + 1] == ' ')
				{
					cx += numeros[i];
					conCor = 1;
				}
				else
				{
					cx += numeros[i];
				}
			}
			break;
		case 1:
			if (numeros[i] == '.')
			{
				cy += numeros[i];
			}

			if (numeros[i] == '-')
			{
				cy += numeros[i];
			}

			if (isdigit(numeros[i]))
			{
				if (numeros[i + 1] == ' ')
				{
					cy += numeros[i];
					conCor = 2;
				}
				else
				{
					cy += numeros[i];
				}
			}
			break;
		case 2:
			if (numeros[i] == '.')
			{
				cz += numeros[i];
			}

			if (numeros[i] == '-')
			{
				cz += numeros[i];
			}

			if (isdigit(numeros[i]))
			{
				if (numeros[i + 1] == ' ')
				{
					cz += numeros[i];
					Vertex v(strtod(cx.c_str(), NULL), strtod(cy.c_str(), NULL), strtod(cz.c_str(), NULL));
					v1.setVertex(v.getVertexX(), v.getVertexY(), v.getVertexZ());
					verVec.push_back(v1);
					conCor = 0;
					cx = "";
					cy = "";
					cz = "";
				}
				else
				{
					cz += numeros[i];
				}
			}
			break;
		}
		i++;

	}

	return verVec;
}


vector <Face> Obj::llenaListaFac(string numeros, vector <Vertex> liVe, arma::fvec foco)
{
	int i = 0;
	int conCor = 0, conInt = 0;
	int tipo = 1;
	string v1, v2, v3;
	Face f;
	string pro;

	while (numeros[i] != '\0' && tipo == 1)
	{
		if (numeros[i] == '/')
		{
			tipo = 0;
		}
		i++;
	}
	i = 0;

	if (tipo == 0)
	{
		while (numeros[i] != '\0')
		{
			switch (conCor)
			{
			case 0:
				if (isdigit(numeros[i]))
				{

					if (numeros[i - 1] == '/')
					{
						if (numeros[i - 2] == '/' || conInt == 1)
						{
							while (isdigit(numeros[i]))
								i++;

							conCor = 1;
							conInt = 0;
						}
						else
						{
							while (numeros[i] != '/')
							{
								i++;
							}
							conInt = 1;
						}
					}
					else
					{
						v1 += numeros[i];
					}
				}
				break;
			case 1:
				if (isdigit(numeros[i]))
				{
					if (numeros[i - 1] == '/')
					{
						if (numeros[i - 2] == '/' || conInt == 1)
						{
							while (isdigit(numeros[i]))
								i++;

							conCor = 2;
							conInt = 0;
						}
						else
						{
							while (numeros[i] != '/')
							{
								i++;
							}
							conInt = 1;
						}
					}
					else
					{
						v2 += numeros[i];
					}
				}
				break;
			case 2:

				if (isdigit(numeros[i]))
				{
					if (numeros[i - 1] == '/')
					{
						while (numeros[i] != ' ' || numeros[i] == '/')
						{
							i++;
						}
						conCor = 0;
					}
					else
					{
						while (numeros[i] != '/')
						{
							v3 += numeros[i];
							i++;
						}
						Face fa(strtod(v1.c_str(), NULL), strtod(v2.c_str(), NULL), strtod(v3.c_str(), NULL));
						f.setFace(fa.getFace1(), fa.getFace2(), fa.getFace3());
						facVer.push_back(f);
						v1 = "";
						v2 = "";
						v3 = "";
					}
				}
				break;
			}
			i++;

		}
	}
	else
	{
		while (numeros[i] != '\0')
		{
			switch (conCor)
			{
			case 0:
				if (isdigit(numeros[i]))
				{
					while (isdigit(numeros[i]))
					{
						v1 += numeros[i];
						i++;
					}
					conCor = 1;
				}
				break;
			case 1:
				if (isdigit(numeros[i]))
				{
					while (isdigit(numeros[i]))
					{
						v2 += numeros[i];
						i++;
					}
					conCor = 2;
				}
				break;
			case 2:

				if (isdigit(numeros[i]))
				{
					while (isdigit(numeros[i]))
					{
						v3 += numeros[i];
						i++;
					}
					conCor = 0;
					Face fa(strtod(v1.c_str(), NULL), strtod(v2.c_str(), NULL), strtod(v3.c_str(), NULL));
					f.setFace(fa.getFace1(), fa.getFace2(), fa.getFace3());
					facVer.push_back(f);
					v1 = "";
					v2 = "";
					v3 = "";
				}
				break;
			}
			i++;
		}
	}
     
	facVer = calNormal(liVe, facVer, foco);

	return facVer;

}


void Obj::relaciona(vector <Vertex> lisVer, vector <Face> lisFac)
{
	cout << endl << "Vertices: " << endl << endl;
	for (unsigned int j = 0; j < lisVer.size(); j++)
	{
		lisVer[j].print();
	}

	cout << endl << "Caras: " << endl << endl;
	for (unsigned int j = 0; j < lisFac.size(); j++)
	{
		lisFac[j].print();
	}
}


vector <Face> Obj::calNormal(vector <Vertex> lisVer, vector <Face> lisFac, arma::fvec foco)
{	
	arma::fvec A;
	arma::fvec B;
	arma::fvec C;

	for (unsigned int i = 0; i < lisFac.size(); i++)
	{
		for (unsigned int j = 0; j < lisVer.size(); j++)
		{		
			if (lisFac[i].getFace1() == j + 1)
			{
				A = { lisVer[j].getVertexX(), lisVer[j].getVertexY(), lisVer[j].getVertexZ() };
			}

			if (lisFac[i].getFace2() == j + 1)
			{
				B = { lisVer[j].getVertexX(), lisVer[j].getVertexY(), lisVer[j].getVertexZ() };
			}

			if (lisFac[i].getFace3() == j + 1)
			{
				C = { lisVer[j].getVertexX(), lisVer[j].getVertexY(), lisVer[j].getVertexZ() };
			}
		}
		
		arma::fvec vec1 = { A[0], B[0], C[0] };

		
		arma::fvec R1 = { B-A };
		arma::fvec R2 = { C-A };

		lisFac[i].vecL = foco - A;

		lisFac[i].vecLN = arma::normalise(lisFac[i].vecL);
		arma::fvec c = cross(R2, R1);
		lisFac[i].A = c.at(0, 0);
		lisFac[i].B = c.at(1, 0);
		lisFac[i].C = c.at(2, 0);
        lisFac[i].magnitud = sqrtf((powf(lisFac[i].A, 2) + powf(lisFac[i].B, 2) + powf(lisFac[i].C, 2)));
		lisFac[i].AN = -lisFac[i].A / lisFac[i].magnitud;
		lisFac[i].BN = -lisFac[i].B / lisFac[i].magnitud;
		lisFac[i].CN = -lisFac[i].C / lisFac[i].magnitud;
        lisFac[i].veNor = { lisFac[i].AN,lisFac[i].BN, lisFac[i].CN};
        lisFac[i].D = -(lisFac[i].A*A[0] + lisFac[i].B*A[1] + lisFac[i].C * A[2]);
	}
	return lisFac;
}


