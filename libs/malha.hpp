#include <GL/glut.h>

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
		{1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f},
		{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}
	};

	int* edgeToPoints(int a[2], int b[2], int c[2])
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

	void triangulo(int a[2], int b[2], int c[2])
	{
		int *pontos;

		pontos = edgeToPoints(a, b, c);

		glBegin(GL_TRIANGLES);
			glColor3fv (colors[pontos[0]]);
			glVertex3fv(vertices[pontos[0]]);
			glColor3fv (colors[pontos[1]]);
			glVertex3fv(vertices[pontos[1]]);
			glColor3fv (colors[pontos[2]]);
			glVertex3fv(vertices[pontos[2]]);
		glEnd();
	}

	public:
	
	void colorCube()
	{
		triangulo(arestas[6], arestas[10], arestas[2]); // x+
		triangulo(arestas[12], arestas[2], arestas[11]); // x+
        triangulo(arestas[7], arestas[4], arestas[13]); // y+
        triangulo(arestas[13], arestas[5], arestas[6]); // y+
        triangulo(arestas[5], arestas[14], arestas[10]); // z+
        triangulo(arestas[9], arestas[1], arestas[14]); // z+
        triangulo(arestas[4], arestas[15], arestas[9]); // x-
		triangulo(arestas[8], arestas[0], arestas[15]); // x-
        triangulo(arestas[1], arestas[16], arestas[2]); // y-
        triangulo(arestas[3], arestas[16], arestas[10]); // y-
        triangulo(arestas[11], arestas[17], arestas[7]); // z-
        triangulo(arestas[3], arestas[8], arestas[17]); // z-
	}
};

int main(){

    return 0;
}