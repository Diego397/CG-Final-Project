#include <GL/glut.h>


class Cubo 
{
	typedef GLfloat point3[3];
	private:

	point3 vertices[8] = 
	{
		{-1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
		{1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0},
		{-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0},
		{1.0, -1.0, -1.0}, {-1.0, -1.0, -1.0}
	};

	GLfloat colors[8][3] =
	{
		{0.0, 1.0, 1.0}, {1.0, 1.0, 1.0,},
		{1.0, 1.0, 1.0}, {0.0, 1.0, 0.0,},
		{0.0, 0.0, 1.0}, {1.0, 0.0, 1.0,},
		{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0,}
	};

	void quad(int a, int b, int c, int d);

	public:
	
	void colorCube();
	
	point3 *getVertices();
};