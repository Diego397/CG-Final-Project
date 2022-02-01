#include <GL/glut.h>

void multiplicacao (GLfloat product[4][1], GLfloat aMatrix[4][4], GLfloat bMatrix[4][1]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 1; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 4; inner++) {
                product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
            }
        }
    }
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