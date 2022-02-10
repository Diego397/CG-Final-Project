#include <GL/glut.h>
#include <tuple>
#include <math.h>
#include "esfera.hpp"

using namespace std;

const float PI = 3.14159265358979323846264338;
const float deg60 = PI / 3.0;

float esfera::fmod_(float x, float y)
{
    float temp = floor(x / y);
    return x - temp * y;
}

tuple<float, float, float> esfera::toRgb(float h, float s, float v)
{
    float c = v * s;
    float m = v - c;
    float x = c * (1.0 - abs(fmod_(h / deg60, 2.0) - 1.0));
    
    tuple<float, float, float> temp;
    if(0.0 <= h && h < deg60)
        temp = make_tuple(c, x, 0.0f);
    else if(deg60 <= h && h < 2.0 * deg60)
        temp = make_tuple(x, c, 0.0f);
    else if(deg60 * 2.0 <= h && h <= 3.0 * deg60)
        temp = make_tuple(0.0f, c, x);
    else if(deg60 * 3.0 <= h && h <= 4.0 * deg60)
        temp = make_tuple(0.0f, x, c);
    else if(deg60 * 4.0 <= h && h <= 5.0 * deg60)
        temp = make_tuple(x, 0.0f, c);
    else if(deg60 * 5.0 <= h && h <= 6.0 * deg60)
        temp = make_tuple(c, 0.0f, x);
       
    get<0>(temp) += m;
    get<1>(temp) += m;
    get<2>(temp) += m;

    return temp;
}

void esfera::desenha_esfera(float radius, int nEquatorPoints, int nPoints2)
{
	float equatorAng = 2 * PI / nEquatorPoints;
	float ang2 = PI / (nPoints2 + 2);

	for(int i = 0; i < nEquatorPoints; ++i)
	{
		float theta = equatorAng * i;
		float phi = (-PI/2) + ang2;

		float cosTheta = cos(theta);
		float sinTheta = sin(theta);

		float cosThetaNxt = cos(theta + equatorAng);
		float sinThetaNxt = sin(theta + equatorAng);

		float xCover = cosTheta * cos(phi) * radius;
		float yCover = sin(phi) * radius;
		float zCover = sinTheta * cos(phi) * radius;		

		float xNxtCover = cosThetaNxt * cos(phi) * radius;
		float yNxtCover = sin(phi) * radius;
		float zNxtCover = sinThetaNxt * cos(phi) * radius;

		float r, g, b;

		glBegin(GL_TRIANGLES);
		//Cor da tampa de baixo
		// tie(r, g, b) = toRgb(1.0, 1.0, 1.0);
		// glColor3f(r, g, b);
		glVertex3f(xCover, yCover, zCover);
		glVertex3f(xNxtCover, yNxtCover, zNxtCover);
		glVertex3f(0, -radius, 0);
		//Cod da tampa de cima
		// tie(r, g, b) = toRgb(1.0, 1.0, 1.0);
		// glColor3f(r, g, b);
		glVertex3f(xCover, -yCover, zCover);
		glVertex3f(xNxtCover, -yNxtCover, zNxtCover);
		glVertex3f(0, radius, 0);
		glEnd();

		for(int j = 0; j < nPoints2; ++j)
		{
			float phi = (-PI/2) + ang2 * (j + 1);

			float cosPhi = cos(phi);
			float cosPhiNxt = cos(phi + ang2);
			float sinPhi = sin(phi);

			float xCur = cosTheta * cosPhi * radius;
			float yCur = sinPhi * radius;
			float zCur = sinTheta * cosPhi * radius;

			float xNxt1 = cosThetaNxt * cosPhi * radius;
			float yNxt1 = sinPhi * radius;
			float zNxt1 = sinThetaNxt * cosPhi * radius;

			float xNxt2 = cosTheta * cosPhiNxt * radius;
			float yNxt2 = sin(phi + ang2) * radius;
			float zNxt2 = sinTheta * cosPhiNxt * radius;

			float xNxt3 = cosThetaNxt * cosPhiNxt * radius;
			float yNxt3 = sin(phi + ang2) * radius;
			float zNxt3 = sinThetaNxt * cosPhiNxt * radius;

			glBegin(GL_TRIANGLES);
			//cor do meio
			// tie(r, g, b) = toRgb(fmod(theta + phi + 2 * PI, 2 * PI), 1.0, 1.0);
			// glColor3f(r, g, b);

			glVertex3f(xCur, yCur, zCur);
			glVertex3f(xNxt1, yNxt1, zNxt1);
			glVertex3f(xNxt2, yNxt2, zNxt2);

			glVertex3f(xNxt1, yNxt1, zNxt1);
			glVertex3f(xNxt3, yNxt3, zNxt3);
			glVertex3f(xNxt2, yNxt2, zNxt2);

			glEnd();
		}
	}
}