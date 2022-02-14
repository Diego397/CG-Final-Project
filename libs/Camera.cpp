#include <GL/glut.h>
#include "Vetor.hpp"
#include "Camera.hpp"
#include "Matriz.hpp"

matriz *objeto;

Camera::Camera( float ex, float ey, float ez, float px, float py, float pz, float vx, float vy, float vz) 
    : ex(ex), ey(ey), ez(ez),
	  px(px), py(py), pz(pz),
	  vx(vx), vy(vy), vz(vz) 
{
	Ponto eye = {ex, ey, ez};
	Ponto lat = {px, py, pz};
	Ponto vupP = {vx, vy, vz};

	// determinando o eixo z
	Vetor zeixo = eye - lat;
	Vetor kunit = normalizar(zeixo);

	// determinando o eixo x
	Vetor vup = vupP - eye;
	Vetor xeixo = produtoVetorial(vup, kunit);
	Vetor iunit = normalizar(xeixo);

	// determinando o eixo y
	Vetor junit = produtoVetorial(kunit, iunit);

	// Vetor da posicao da Camera
	Vetor E {ex, ey, ez};

	mwtc[0][0] = iunit.x; mwtc[0][1] = iunit.y; mwtc[0][2] = iunit.z; mwtc[0][3] = -(iunit*E);
    mwtc[1][0] = junit.x; mwtc[1][1] = junit.y; mwtc[1][2] = junit.z; mwtc[1][3] = -(junit*E);
    mwtc[2][0] = kunit.x; mwtc[2][1] = kunit.y; mwtc[2][2] = kunit.z; mwtc[2][3] = -(kunit*E);
    mwtc[3][0] = 0.0f;    mwtc[3][1] = 0.0f;    mwtc[3][2] = 0.0f;    mwtc[3][3] = 1.0f;

	// {
	// 	{iunit.x, iunit.y, iunit.z, -(iunit*E)},
	// 	{junit.x, junit.y, junit.z, -(junit*E)},
	// 	{kunit.x, kunit.y, kunit.z, -(kunit*E)},
	// 	{0.0f, 0.0f, 0.0f, 1.0f}
	// };
}

void Camera::aplicarTrans (point3 *obj, int tam, GLfloat T[4][4])
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

void Camera::mudaCamera(point3 *obj, int tam)
{
    Camera::aplicarTrans(obj, tam, mwtc);
}