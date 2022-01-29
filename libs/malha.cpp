#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <new>
#include <math.h>
#include <vector>
#include "malha.hpp"

int* malha::edgeToPoints(int a[2], int b[2], int c[2])
{
	int *vertices = new int[3];
	int pa, pb, pc;
	pa = a[0]; pb = a[1];
	
	if (b[0] != pa and b[0] != pb) 
		pc = b[0];
	else 
		pc = b[1];

	vertices[0] = pa; vertices[1] = pb; vertices[2] = pc;
	return vertices;
}

void malha::triangulo(int a[2], int b[2], int c[2], int cor)
{
	int *pontos;

	pontos = edgeToPoints(a, b, c);

	glBegin(GL_TRIANGLES);
	glColor3fv (colors[cor]);
	glVertex3fv(vertices[pontos[0]]);
	glColor3fv (colors[cor]);
	glVertex3fv(vertices[pontos[1]]);
	glColor3fv (colors[cor]);
	glVertex3fv(vertices[pontos[2]]);
	glEnd();
}

void malha::colorCube()
{
	triangulo(arestas[6], arestas[10], arestas[2], 0); // x+
	triangulo(arestas[12], arestas[2], arestas[11], 0); // x+

	triangulo(arestas[7], arestas[4], arestas[13], 1); // y+
	triangulo(arestas[13], arestas[5], arestas[6], 1); // y+

	triangulo(arestas[5], arestas[14], arestas[10], 2); // z+
	triangulo(arestas[9], arestas[1], arestas[14], 2); // z+

	triangulo(arestas[4], arestas[15], arestas[9], 3); // x-
	triangulo(arestas[8], arestas[0], arestas[15], 3); // x-

	triangulo(arestas[1], arestas[16], arestas[2], 4); // y-
	triangulo(arestas[3], arestas[16], arestas[10], 4); // y-

	triangulo(arestas[11], arestas[17], arestas[7], 5); // z-
	triangulo(arestas[3], arestas[8], arestas[17], 5); // z-
}