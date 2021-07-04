
#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include "Obj.h"
#include <string.h>
#include "Vertex.h"
#include "Face.h"
#include <vector>
#include <string>
#include <armadillo>
#include "VertexC.h"
#include "Bezier.h"

using namespace std;

int perspective = 0;
float consColor = 0.003915686;
arma::fvec eye = { 0.0, 0.0, 2.0 };
arma::fvec camera = { 0.0, 0.0, 0.0 };
float valFoco[3] = {0.0, 0.95, 0.5};//{0.0, 0.5, 0.95};


void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );

int main(void)
{
	GLFWwindow* window;
	Obj fi((char*)"Circulo2.obj");
	Obj Por((char *)"Porteria2.obj");
	

	string nomObj = fi.leeArchivo((char *)"o ");

	cout << "Nombre de Objeto: ";
	if (nomObj != "")
		std::cout << nomObj.substr(2, nomObj.size()) << endl;
	else
		cout << "No posee identificador de nombre(g) su archivo obj" << endl;
		
	string nomPor = Por.leeArchivo((char *)"o ");
		
    //Bezier
    VertexC pb1_0(0.0, 0.0, 0.8);//Si funcionan
	VertexC pb2_0(0.85, 0.1, 0.2);
	VertexC pb3_0(0.98, 0.15, -0.5);
	VertexC pb4_0(0.4, 0.38, -0.75);
	Bezier curvaV(pb1_0, pb2_0, pb3_0, pb4_0);

	VertexC pb1_1(0.4, 0.38, -0.75);
	VertexC pb2_1(-0.1, 0.5, -0.9);
	VertexC pb3_1(-0.6, 0.5, -0.9);
	VertexC pb4_1(-0.6, 0.4, 0.1);
	Bezier curvaV2(pb1_1, pb2_1, pb3_1, pb4_1);

	VertexC pb1_2(-0.6, 0.4, 0.1);
	VertexC pb2_2(-0.5, 0.3, 0.95);
	VertexC pb3_2(0.06, 0.3, 0.4);
	VertexC pb4_2(0.3, 0.35, 0.1);
	Bezier curvaV3(pb1_2, pb2_2, pb3_2, pb4_2);


	  
	arma::fvec foco = { valFoco[0], valFoco[1], valFoco[2]};
	
	
	//Balon
	string datosv = fi.leeArchivo((char*)"v ");
	string datosf = fi.leeArchivo((char*)"f ");
	vector <Vertex> lsVe = fi.llenaListaVer(datosv);
	vector <Face> lsFe = fi.llenaListaFac(datosf, lsVe,foco);
	//Porteria
	string datosvP = Por.leeArchivo((char*)"v ");
	string datosfP = Por.leeArchivo((char*)"f ");
	vector <Vertex> lsVeP = Por.llenaListaVer(datosvP);
	vector <Face> lsFeP = Por.llenaListaFac(datosfP, lsVeP,foco);
	
	
	
	arma::fvec veCam = arma::normalise(camera - eye);

	float Ia = 0.95;
	float Ka = 0.85;
	float Ip = 0.8;
	float Kd = 0.75;	
	float I;

	float color[3] = { 255,0,0 };//Color de la porteria
		
    
	if (!glfwInit())
	{
		fprintf(stderr, "Fallo al inicializar GLFW\n");
		getchar();
		return -1;
	}

	window = glfwCreateWindow(1024, 768, "Ejemplo OpenGL", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Fallo al abrir la ventana de GLFW.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	glfwSetKeyCallback( window, keyCallback );
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	
	glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	bool bandC1 = true, bandC2 = true, bandC3 = true;
	unsigned int k = 0, l = 0, m = 0;
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	//Proyeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	float ar = width / height;
	
	//Proyeccion en paralelo
	glViewport(0, 0, width, height);
	glOrtho(-ar, ar, -1.0, 1.0, 1.0, 10.0);

	//Proyeccion en perspectiva
	//glFrustum(-ar, ar, -ar, ar, 1.0, 8.0);// va a  alcanzar hasta una distancia 10, osea con 10-2 = 8.

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	do {
		
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		
		
		if(perspective == 1) //Superior
		{
			gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], 0.0, 1.0, 0.0);
			arma::fvec veCam = arma::normalise(camera - eye);
		}
		else if(perspective == 2) //Normal
			{
				gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], 0.0, 1.0, 0.0);
				arma::fvec veCam = arma::normalise(camera - eye);
			}
			else if(perspective == 3) //Derecha
				{
					gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], 0.0, 1.0, 0.0);
					arma::fvec veCam = arma::normalise(camera - eye);
				}
				else if(perspective == 4) //Izquierda
				{
					gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], 0.0, 1.0, 0.0);
					arma::fvec veCam = arma::normalise(camera - eye);
				}
				else				//Normal, para tener una vista por default
					{
						gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], 0.0, 1.0, 0.0);
						arma::fvec veCam = arma::normalise(camera - eye);
					}
			

			
             glColor3f(1.0, 1.0, 1.0);//Dibujamos un pixel representando el foco
			 glBegin(GL_POINTS);
		     glVertex3f(valFoco[0], valFoco[1], valFoco[2]);

			for (unsigned int i = 0; i < lsFeP.size(); i++)//Aqui es para pintar la porteria
			{
				arma::fvec veCam = arma::normalise(camera - eye);

				if (arma::dot(veCam, lsFeP[i].veNor) < 0)
				{
					I = Ia * Ka + Ip * Kd * arma::dot(lsFeP[i].veNor, lsFeP[i].vecLN);
					
					glColor3f(consColor*color[0] * ((I * 100 / 2))/100 , consColor*color[1] * ((I * 100 / 2)/100), consColor*color[2] * ((I * 100 / 2)/100));
					
					glBegin(GL_TRIANGLES);//1
					
					for (unsigned int j = 0; j < lsVeP.size(); j++)
					{
						if (lsFeP[i].getFace1() == j + 1)
						{
							glVertex3f(lsVeP[j].getVertexX(), lsVeP[j].getVertexY(), lsVeP[j].getVertexZ());
						}

						if (lsFeP[i].getFace2() == j + 1)
						{
							glVertex3f(lsVeP[j].getVertexX(), lsVeP[j].getVertexY(), lsVeP[j].getVertexZ());
						}	

						if (lsFeP[i].getFace3() == j + 1)
						{
							glVertex3f(lsVeP[j].getVertexX(), lsVeP[j].getVertexY(), lsVeP[j].getVertexZ());
						}
					}
					
					glEnd();
					
				} 
			
			}
        //getchar();
		curvaV.print();
		curvaV2.print();
		curvaV3.print();
		
		if (bandC1 == true)
			{
				curvaV.printGrap(lsVe, lsFe, curvaV.vcurveB[k].get_value().at(0,0), curvaV.vcurveB[k].get_value().at(0,1), curvaV.vcurveB[k].get_value().at(0,2),foco, camera, eye ,Ia , Ka , Ip , Kd);
			}
			else
				if (bandC2 == true)
				{
					curvaV2.printGrap(lsVe, lsFe, curvaV2.vcurveB[l].get_value().at(0,0), curvaV2.vcurveB[l].get_value().at(0,1), curvaV2.vcurveB[l].get_value().at(0,2),foco, camera, eye ,Ia , Ka , Ip , Kd);
				}
				else
				{
					if (bandC3 == true)
					{
						curvaV3.printGrap(lsVe, lsFe, curvaV3.vcurveB[m].get_value().at(0, 0), curvaV3.vcurveB[m].get_value().at(0, 1), curvaV3.vcurveB[m].get_value().at(0, 2),foco, camera, eye ,Ia , Ka , Ip , Kd);
					}
				}
				
		glfwSwapBuffers(window);
		glfwPollEvents();
		
		if (k + 1 < curvaV2.vcurveB.size())
			{
				k++;
			}
			else
			{				
				bandC1 = false;
				if (l + 1 < curvaV2.vcurveB.size())
				{
					l++;
				}
				else
				{
					bandC2 = false;
					if (m + 1 < curvaV3.vcurveB.size())
					{
						m++;
					}
					else
					{
						k = 0;
						l = 0;
						m = 0;
						bandC1 = true;
						bandC2 = true;
						bandC3 = true;
					}
					
				}

			}

			usleep(10000);

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
	glfwTerminate();
    
	return 0;
}
void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{
    if(key == 265&& action == GLFW_PRESS)
	{			//up
			
		eye = { 0.0, 2.0, 0.0 };
		camera = { -0.05, 0.0, 0.0 };
		perspective = 1;//superior
	}
	if(key == 264&& action == GLFW_PRESS)
	{			//down
		
		eye = { 0.0, 0.0, 2.0 };//(-2.0,0.0,0.0)
		camera = { 0.0, 0.0, 0.0 };
		perspective = 2;	//normal
	}
	if(key == 262&& action == GLFW_PRESS)			//right
	{
		
		eye = { 2.0, 0.0, 0.0 };
		camera = { 0.0, 0.0, 0.0 };
		perspective = 3;	//derecha
	}
	if(key == 263&& action == GLFW_PRESS)			//left
	{
		
		eye = { -2.0, 0.0, 0.0 };
		camera = { 0.0, 0.0, 0.0 };
		perspective = 4;    //izquierda
	}
}
