#include <GL/glut.h>

class matriz
{
	public:
	void multiplicacao (GLfloat product[4][1], GLfloat aMatrix[4][4], GLfloat bMatrix[4][1]);
	void multiplicacao (GLfloat product[4][4], GLfloat aMatrix[4][4], GLfloat bMatrix[4][4]);
	void multiplicacao (GLfloat **product, GLfloat **aMatrix, int al, int ac, GLfloat **bMatrix, int bl, int bc);
};
