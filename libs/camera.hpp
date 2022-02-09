#include <GL/glut.h>
#include "vetor.hpp"

class camera
{
public:

	camera() {}

	camera(
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

	ponto eye = {ex, ey, ez};
	ponto lat = {px, py, pz};
	ponto vupP = {vx, vy, vz};

	// determinando o eixo z
	vetor zeixo = eye - lat;
	vetor kunit = normalizar(zeixo);

	// determinando o eixo x
	vetor vup = vupP - eye;
	vetor xeixo = produtoVetorial(vup, kunit);
	vetor iunit = normalizar(xeixo);

	// determinando o eixo y
	vetor junit = produtoVetorial(kunit, iunit);

	// vetor da posicao da camera
	vetor E {ex, ey, ez};

	GLfloat mwtc[4][4] = 
	{
		{iunit.x, iunit.y, iunit.z, -(iunit*E)},
		{junit.x, junit.y, junit.z, -(junit*E)},
		{kunit.x, kunit.y, kunit.z, -(kunit*E)},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

public:

	// GLfloat **getMatriz()
	// {
	// 	return mwtc;
	// }
};