#include <GL/glut.h>

class material
{
private:
	/*
	0 = RUBY
	1 = WHITE
	*/
    
    float MatAmbient[2][4] = {
    							{0.1745f, 0.01175f, 0.01175f, 0.55f}, 
    							{0.05f, 0.05f, 0.05f, 1.0f}
    						 };

    float MatDiffuse[2][4] = {
    							{0.61424f, 0.04136f, 0.04136f, 0.55f},
    							{0.5f, 0.5f, 0.5f, 1.0f}
    						 };

    float MatSpecular[2][4] = {
    							{0.727811f, 0.626959f, 0.626959f, 0.55f},
    							{0.7f, 0.7f, 0.7f, 1.0f}
    						  };
    
    float MatShininess[2] = {
    							76.8f,
    							10.0f
    };

    float black[4] = {0.0f,0.0f,0.0f,1.0f};

public:
	void setMaterial(int i);
};