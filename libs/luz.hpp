#include <GL/glut.h>
class luz
{
private:

	float LightAmbient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float LightDiffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float LightSpecular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float LightPosition[4] = {200.0f, 300.0f, 100.0f, 0.0f};


public:
	void setLuz();
};