#include <GL/glut.h>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<tuple<float, float, float>> tuple_vec;

class Esfera
{
	private:

	float fmod_(float x, float y);

	tuple<float, float, float> toRgb(float h, float s, float v);

	tuple_vec vec;

	public:

	void desenha_esfera(float radius, int nEquatorPoints, int nPoints2);

	tuple_vec getVertices()
	{
		return vec;
	}
};