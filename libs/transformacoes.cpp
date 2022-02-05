#include <GL/glut.h>
#include <cmath>
#include <string>
#include "transformacoes.hpp"
#include "matriz.hpp"

matriz *objeto;

void transformacoes::aplicarTrans (point3 *obj, int tam, GLfloat T[4][4])
{
	for(int i = 0; i < tam; ++i)
	{
		GLfloat vet[4][1], res[4][1];

		for (int j = 0; j < 3; j++)
			vet[j][0] = obj[i][j];
		vet[3][0] = 1.0f;
		
		objeto->multiplicacao (res, T, vet);

		for (int j = 0; j < 3; j++)
			obj[i][j] = res[j][0];
	}
}

void transformacoes::escala(point3 *obj, int tam, GLfloat sx, GLfloat sy, GLfloat sz)
{
	GLfloat T[4][4] = 
	{
		{sx, 0.0f, 0.0f, 0.0f},
		{0.0f, sy, 0.0f, 0.0f},
		{0.0f, 0.0f, sz, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	aplicarTrans (obj, tam, T);
}

void transformacoes::translacao(point3 *obj, int tam, GLfloat tx, GLfloat ty, GLfloat tz) 
{
	GLfloat T[4][4] = 
	{
		{1.0f, 0.0f, 0.0f, tx},
		{0.0f, 1.0f, 0.0f, ty},
		{0.0f, 0.0f, 1.0f, tz},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	aplicarTrans (obj, tam, T);
}

void transformacoes::rotacao(point3 *obj, int tam, double angulo, char tipo)
{
	float C = cos(angulo);
	float S = sin(angulo);

	if (tipo == 'X')
	{
		GLfloat Rx[4][4] = 
		{
			{1.0f, 	0.0f,	0.0f, 	0.0f},
			{0.0f,	C,		-S, 	0.0f},
			{0.0f, 	S, 		C, 		0.0f},
			{0.0f, 	0.0f, 	0.0f, 	1.0f}
		};
		aplicarTrans (obj, tam, Rx);
	}
	else if (tipo == 'Y')
	{
		GLfloat Ry[4][4] = 
		{
			{C, 	0.0f, 	S, 		0.0f},
			{0.0f, 	1.0f,	0.0f, 	0.0f},
			{-S, 	0.0f, 	C, 		0.0f},
			{0.0f, 	0.0f, 	0.0f, 	1.0f}
		};
		aplicarTrans (obj, tam, Ry);
	}
	else if (tipo == 'Z')
	{
		GLfloat Rz[4][4] = 
		{
			{C, 	-S, 	0.0f, 	0.0f},
			{S, 	C, 		0.0f, 	0.0f},
			{0.0f, 	0.0f, 	1.0f, 	0.0f},
			{0.0f, 	0.0f, 	0.0f, 	1.0f}
		};
		aplicarTrans (obj, tam, Rz);
	}
	// else if (tipo == 'G') //Falta definir Ixl, Iyl, Izl ...
	// {
	// 	GLfloat Mxxl[4][4] = 
	// 	{
	// 		{Ixl, 	Iyl, 	Izl, 	-P * Il},
	// 		{Jxl, 	Jyl, 	Jzl, 	-P * Jl},
	// 		{Kxl, 	Kyl, 	Kzl, 	-P * Kl},
	// 		{0.0f, 	0.0f, 	0.0f, 	1.0f}
	// 	};
		
	// 	GLfloat Mxlx[4][4] = 
	// 	{
	// 		{Ixl, 	Jxl, 	Kxl, 	Px},
	// 		{Iyl, 	Jyl, 	Kyl, 	Py},
	// 		{Izl, 	Jzl, 	Kzl, 	Pz},
	// 		{0.0f, 	0.0f, 	0.0f, 	1.0f}
	// 	};

	// 	GLfloat Ru[4][4];
		
	// 	Ru = Mxlx * Rzl * Mxxl;

	// 	aplicarTrans (obj, tam, Ru);
	// }
}

void transformacoes::cisalhamento(point3 *obj, int tam, float tg, char tipo, std::string plano)
{	
	if(plano == "XZ"){
		if(tipo == 'X'){
			GLfloat T[4][4] = 
			{
				{1.0f,	tg,		0.0f,	0.0f},
				{0.0f, 	1.0f,	0.0f,	0.0f},
				{0.0f, 	0.0f,	1.0f, 	0.0f},
				{0.0f, 	0.0f,	0.0f, 	1.0f}
			};
			aplicarTrans (obj, tam, T);
		}
		else if(tipo == 'Y'){
			GLfloat T[4][4] = 
			{
				{1.0f, 	0.0f, 	0.0f, 	0.0f},
				{tg, 	1.0f, 	0.0f, 	0.0f},
				{0.0f, 	0.0f, 	1.0f, 	0.0f},
				{0.0f,	0.0f, 	0.0f, 	1.0f}
			};
		}
		else
		{
			GLfloat T[4][4] = 
			{
				{1.0f,	0.0f,	0.0f,	0.0f},
				{0.0f, 	1.0f,	0.0f,	0.0f},
				{0.0f, 	tg,	    1.0f,   0.0f},
				{0.0f, 	0.0f,	0.0f, 	1.0f}
			};
		}
	}
	else if(plano == "XY"){
		if(tipo == 'X'){
			// GLfloat T[4][4] = 
			// {
			// 	{1.0f,	tg,		0.0f,	0.0f},
			// 	{0.0f, 	1.0f,	0.0f,	0.0f},
			// 	{0.0f, 	0.0f,	1.0f, 	0.0f},
			// 	{0.0f, 	0.0f,	0.0f, 	1.0f}
			// };
		}
		else if(tipo == 'Y'){
			GLfloat T[4][4] = 
			{
				{1.0f, 	0.0f, 	0.0f, 	0.0f},
				{0.0f, 	1.0f, 	tg, 	0.0f},
				{0.0f, 	0.0f, 	1.0f, 	0.0f},
				{0.0f,	0.0f, 	0.0f, 	1.0f}
			};
		}
		else
		{
			GLfloat T[4][4] = 
			{
				{1.0f,	0.0f,	0.0f,	0.0f},
				{0.0f, 	1.0f,	0.0f,	0.0f},
				{0.0f, 	tg,	    1.0f,   0.0f},
				{0.0f, 	0.0f,	0.0f, 	1.0f}
			};
		}
	}
}

void transformacoes::reflexao(point3 *obj, int tam, std::string tipo)
{
	if (tipo == "XY")
	{
		GLfloat Exy[4][4] = 
		{
			{1.0f,	0.0f,	0.0f,	0.0f},
			{0.0f, 	1.0f,	0.0f,	0.0f},
			{0.0f, 	0.0f,	-1.0f,   0.0f},
			{0.0f, 	0.0f,	0.0f, 	1.0f}
		};
	}

	else if (tipo == "XZ")
	{
		GLfloat Exz[4][4] = 
		{
			{1.0f,	0.0f,	0.0f,	0.0f},
			{0.0f, 	-1.0f,	0.0f,	0.0f},
			{0.0f, 	0.0f,	1.0f,   0.0f},
			{0.0f, 	0.0f,	0.0f, 	1.0f}
		};
	}
	else if (tipo == "YZ")
	{
		GLfloat Eyz[4][4] = 
		{
			{-1.0f,	0.0f,	0.0f,	0.0f},
			{0.0f, 	1.0f,	0.0f,	0.0f},
			{0.0f, 	0.0f,	1.0f,   0.0f},
			{0.0f, 	0.0f,	0.0f, 	1.0f}
		};
	}
}

void transformacoes::reflexao(point3 *obj, int tam, GLfloat* vetUni, GLfloat* pontos)
{
    GLfloat H[4][4] = 
    {
        {vetUni[0]*vetUni[0], vetUni[0]*vetUni[1], vetUni[0]*vetUni[2], 0.0f},
        {vetUni[1]*vetUni[0], vetUni[1]*vetUni[1], vetUni[1]*vetUni[2], 0.0f},
        {vetUni[2]*vetUni[0], vetUni[2]*vetUni[1], vetUni[2]*vetUni[2], 0.0f},
        {0.0f,   0.0f,    0.0f,    0.0f}
    };

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            H[i][j] = -2*H[i][j];

    GLfloat matInd[4][4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (j == i) matInd[i][j] = 1.0f;
            else matInd[i][j] = 0.0f;
        }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            H[i][j] += matInd[i][j];
    
	// matriz de translação
    GLfloat tpio[4][4] = 
    {
        {1.0f, 0.0f, 0.0f, -pontos[0]},
        {0.0f, 1.0f, 0.0f, -pontos[1]},
        {0.0f, 0.0f, 1.0f, -pontos[2]},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };
    
	// matriz de translação reversa
    GLfloat topi[4][4] =
    {
        {1.0f, 0.0f, 0.0f, pontos[0]},
        {0.0f, 1.0f, 0.0f, pontos[1]},
        {0.0f, 0.0f, 1.0f, pontos[2]},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

	aplicarTrans (obj, tam, tpio);
    aplicarTrans (obj, tam, H);
	aplicarTrans (obj, tam, topi);
}