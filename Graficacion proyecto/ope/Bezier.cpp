#include "Bezier.h"
#include "VertexC.h"
#include <GLFW/glfw3.h>
#include "Vertex.h"
#include "Face.h"
#include "Escalacion.h"
#include "Traslacion.h"
#include <armadillo>

using namespace std;
float consColor2 = 0.003915686;

Bezier::Bezier()
{
}

Bezier::Bezier(VertexC pb1, VertexC pb2, VertexC pb3, VertexC pb4)
{
	MHB = {
			{-1.0f, 3.0f, -3.0f, 1.0f},
			{3.0f, -6.0f, 3.0f, 0.0f},
			{-3.0f, 3.0f, 0.0f, 0.0f},
			{1.0f, 0.0f, 0.0f, 0.0f}
	};
	Pb1.set_value(pb1.get_value());
	Pb2.set_value(pb2.get_value());
	Pb3.set_value(pb3.get_value());
	Pb4.set_value(pb4.get_value());
	calc_curve();
}

Bezier::~Bezier()
{
}

void Bezier::calc_curve()
{
	arma::frowvec pb1 = Pb1.get_value();
	arma::frowvec pb2 = Pb2.get_value();
	arma::fmat GHB(4, 3);

	GHB.row(0) = Pb1.get_value();
	GHB.row(1) = Pb2.get_value();
	GHB.row(2) = Pb3.get_value();
	GHB.row(3) = Pb4.get_value();

	for (float t = 0.0f; t <= 1.0f; t += dt) {
		arma::frowvec Tb = { powf(t,3.0f), powf(t,2.0f), t, 1.0f };
		arma::frowvec Qtb = Tb * MHB * GHB;
		VertexC vcb;
		vcb.set_value(Qtb);
		vcurveB.push_back(vcb);

	}
}

void Bezier::print()
{
	for (unsigned int j = 0; j < vcurveB.size(); j++)
	{
		//vcurveB[j].print();
		/*cout << "XFP = ";
		cout << vcurveB[j].get_value().at(0, 0) << endl;
		cout << "YFP = ";
		cout << vcurveB[j].get_value().at(0, 1) << endl;
		cout << "ZFP = ";
		cout << vcurveB[j].get_value().at(0, 2) << endl;
		cout << endl;*/
		
		//Pinta puntos
		//glBegin(GL_POINTS);
		//glVertex3f(vcurveB[j].get_value().at(0, 0), vcurveB[j].get_value().at(0, 1), vcurveB[j].get_value().at(0, 2));
		glEnd();

	}


}

void Bezier::printGrap(vector <Vertex> lisVer, vector <Face> lisFac, float cx, float cy, float cz, arma::fvec foco,arma::fvec camera,arma::fvec eye,float Ia ,float Ka,float Ip , float Kd)
{

           float I;
           
           float color[3] = {255,255,255};


            for (unsigned int i = 0; i < lisFac.size(); i++)
            {
                arma::fvec veCam = arma::normalise(camera - eye);
                
                if (arma::dot(veCam, lisFac[i].veNor) < 0)
                {
                    I = Ia * Ka + Ip * Kd * arma::dot(lisFac[i].veNor, lisFac[i].vecLN);
                    
                    glColor3f(consColor2*color[0] * ((I * 100 / 2))/100 , consColor2*color[1] * ((I * 100 / 2)/100), consColor2*color[2] * ((I * 100 / 2)/100));
                    
                    glBegin(GL_TRIANGLES);//1
                    for (unsigned int j = 0; j < lisVer.size(); j++)
                    {
                        if (lisFac[i].getFace1() == j + 1)
                        {
                            Escalacion es(0.05f, lisVer[j]);
                            Vertex vp((float)es.VR.at(0, 0), (float)es.VR.at(1, 0), (float)es.VR.at(2, 0));
                            Traslacion ta(cx, cy, cz, vp);


                            glVertex3f(ta.VR.at(0, 0), ta.VR.at(1, 0), ta.VR.at(2, 0));

                        }
                        if (lisFac[i].getFace2() == j + 1)
                        {
                            Escalacion es(0.05f, lisVer[j]);
                            Vertex vp((float)es.VR.at(0, 0), (float)es.VR.at(1, 0), (float)es.VR.at(2, 0));
                            Traslacion ta(cx, cy, cz, vp);

                            glVertex3f(ta.VR.at(0, 0), ta.VR.at(1, 0), ta.VR.at(2, 0));
                        }
                        if (lisFac[i].getFace3() == j + 1)
                        {
                            Escalacion es(0.05f, lisVer[j]);
                            Vertex vp((float)es.VR.at(0, 0), (float)es.VR.at(1, 0), (float)es.VR.at(2, 0));
                            Traslacion ta(cx, cy, cz, vp);

                            glVertex3f(ta.VR.at(0, 0), ta.VR.at(1, 0), ta.VR.at(2, 0));
                        }
                    }


                    glEnd();
                }
        }

}

