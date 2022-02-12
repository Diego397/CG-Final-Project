#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#include <new>
#include <math.h>
#include <vector>

class Malha 
{
	private:

	typedef GLfloat point3[3];
	point3 vertices[8] = 
	{
		{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 2.0f},
		{2.0f, 0.0f, 2.0f}, {2.0f, 0.0f, 0.0f},
		{0.0f, 2.0f, 0.0f}, {0.0f, 2.0f, 2.0f},
		{2.0f, 2.0f, 2.0f}, {2.0f, 2.0f, 0.0f}
	};

	int arestas[18][2] = 
	{
		{0, 1}, {1, 2},
		{2, 3}, {3, 0},
		{4, 5}, {5, 6},
		{6, 7}, {7, 4},
		{0, 4}, {1, 5},
		{2, 6}, {3, 7},
		{2, 7}, {5, 7},
		{5, 2}, {1, 4},
		{1, 3}, {3, 4}
		
	};

	GLfloat colors[8][3] =
	{
		{0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f},
		{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}
	};

	int* edgeToPoints(int a[2], int b[2], int c[2]);

	void triangulo(int a[2], int b[2], int c[2], int cor);

	public:
	
	void colorCube();
	point3 *getVertices();
};