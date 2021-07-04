#include "Vertex.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;


Vertex::Vertex()
{
	CX = 0;
	CY = 0;
	CZ = 0;
}

Vertex::Vertex(float vx, float vy, float vz)
{
	CX = vx;
	CY = vy;
	CZ = vz;
}

Vertex::~Vertex()
{
}


void Vertex::setVertex(float x1, float y1, float z1)
{
	CX = x1;
	CY = y1;
	CZ = z1;
}

float Vertex::getVertexX()
{
	return CX;
}

float Vertex::getVertexY()
{
	return CY;
}

float Vertex::getVertexZ()
{
	return CZ;
}

void Vertex::print()
{
	printf("[%f, %f, %f]\n", CX, CY, CZ);
}
