#include <GL/glut.h>
#include "Vetor.hpp"

class Camera
{
public:

	typedef float point3[3];

	explicit Camera( float ex, float ey, float ez, float px, float py, float pz, float vx, float vy, float vz);
	
private:

	float ex{0.0f}, ey{0.0f}, ez{0.0f}; // Eye
	float px{0.0f}, py{0.0f}, pz{0.0f}; // Point of interest (LookAt)
	float vx{0.0f}, vy{0.0f}, vz{0.0f}; // view up
	float mwtc[4][4];

	void aplicarTrans (point3 *obj, int tam, GLfloat T[4][4]);

public:

	void mudaCamera(point3 *obj, int tam);
};
