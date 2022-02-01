#include <GL/glut.h>
#include <vector>
#include <cmath>
#include "transformacoes.hpp"
#include "matriz.hpp"

typedef GLfloat point4[4];

void aplicarTrans ( obj, GLfloat T[4][4])
{
	for(int i = 0; i < obj.size(); ++i)
	{
		point4 vet[1], res[1];

		for (int j = 0; j < 3; j++)
			vet[j][0] = obj[i][j];
		vet[4][0] = 1.0f;
		
		matriz::multiplicacao (res, T, vet);

		for (int j = 0; j < 3; j++)
			obj[i][j] = res[j][0];
	}
}

void escala(std::vector<GLfloat> obj, GLfloat sx, GLfloat sy, GLfloat sz)
{
	GLfloat T[4][4] = 
	{
		{sx, 0.0f, 0.0f, 0.0f},
		{0.0f, sy, 0.0f, 0.0f},
		{0.0f, 0.0f, sz, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	aplicarTrans (obj, T);
}

void translacao(std::vector<GLfloat> obj, GLfloat tx, GLfloat ty, GLfloat tz) 
{
	GLfloat T[4][4] = 
	{
		{1.0f, 0.0f, 0.0f, tx},
		{0.0f, 1.0f, 0.0f, ty},
		{0.0f, 0.0f, 1.0f, tz},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	aplicarTrans (obj, T);
}