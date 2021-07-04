#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
public:
	float CX;
	float CY;
	float CZ;
	Vertex();
	Vertex(float x, float y, float z);
	void setVertex(float x, float y, float z);
	float getVertexX();
	float getVertexY();
	float getVertexZ();
	void print();
	~Vertex();
};


#endif // VERTEX_H
