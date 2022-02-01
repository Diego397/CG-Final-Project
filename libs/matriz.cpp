#include <GL/glut.h>
#include "matriz.hpp"

void matriz::multiplicacao (GLfloat product[4][1], GLfloat aMatrix[4][4], GLfloat bMatrix[4][1]) 
{
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 1; col++) 
			for (int inner = 0; inner < 4; inner++) 
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
}

void matriz::multiplicacao (GLfloat product[4][4], GLfloat aMatrix[4][4], GLfloat bMatrix[4][4]) 
{
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 4; col++) 
			for (int inner = 0; inner < 4; inner++) 
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
}
void matriz::multiplicacao (GLfloat **product, GLfloat **aMatrix, int al, int ac, GLfloat **bMatrix, int bl, int bc) 
{
	for (int row = 0; row < al; row++) 
		for (int col = 0; col < bc; col++) 
			for (int inner = 0; inner < al; inner++) 
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
}
/*
int main()
{
	GLfloat product[4][1];

	GLfloat aMatrix[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	GLfloat bMatrix[4][1] = 
	{
		{3.0f},
		{2.0f},
		{1.0f},
		{4.0f}
	};

	multiplicacao(product, aMatrix, bMatrix);

	for (int i = 0; i < 4; i ++)
		std::cout << product[i][0] << "\n";
}
*/