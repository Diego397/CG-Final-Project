#include <GL/glut.h>
#include "Vetor.hpp"

class Camera
{
public:

	Camera() {}

	Camera(
		GLfloat tex, GLfloat tey, GLfloat tez,
		GLfloat tpx, GLfloat tpy, GLfloat tpz,
		GLfloat tvx, GLfloat tvy, GLfloat tvz 
	) : ex(tex), ey(tey), ez(tez),
		px(tpx), py(tpy), pz(tpz),
		vx(tvx), vy(tvy), vz(tvz) 
	{}
	
private:

	GLfloat ex{0.0f}, ey{0.0f}, ez{0.0f}; // Eye
	GLfloat px{0.0f}, py{0.0f}, pz{0.0f}; // Point of interest (LookAt)
	GLfloat vx{0.0f}, vy{0.0f}, vz{0.0f}; // view up

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

	GLfloat mwtc[4][4] = 
	{
		{iunit.x, iunit.y, iunit.z, -(iunit*E)},
		{junit.x, junit.y, junit.z, -(junit*E)},
		{kunit.x, kunit.y, kunit.z, -(kunit*E)},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

public:

};