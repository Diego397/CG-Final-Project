#include <GL/glut.h>
#include "Matriz.hpp"

void matriz::multiplicacao (GLfloat product[4][1], GLfloat aMatrix[4][4], GLfloat bMatrix[4][1]) 
{
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 1; col++){
            product[row][col] = 0.0f;
			for (int inner = 0; inner < 4; inner++) 
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
        }
}

void matriz::multiplicacao (GLfloat product[4][4], GLfloat aMatrix[4][4], GLfloat bMatrix[4][4]) 
{
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 4; col++){
            product[row][col] = 0.0f;
			for (int inner = 0; inner < 4; inner++) 
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
        }
}
void matriz::multiplicacao (GLfloat **product, GLfloat **aMatrix, int al, int ac, GLfloat **bMatrix, int bl, int bc) 
{
	for (int row = 0; row < al; row++) 
		for (int col = 0; col < bc; col++){
			product[row][col] = 0.0f;
			for (int inner = 0; inner < al; inner++) 
				product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
		}
}