#include <GL/glut.h>
#include <tuple>

using namespace std;

class esfera
{
	private:

	float fmod_(float x, float y);

	tuple<float, float, float> toRgb(float h, float s, float v);

	public:

	void desenha_esfera(float radius, int nEquatorPoints, int nPoints2);
};