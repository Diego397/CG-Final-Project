#include <GL/glut.h>
#include <vector>
#include <cmath>
#include "transformacoes.hpp"

void aplicarTrans ()
{
    
}

void escala(std::vector<GLfloat> obj, GLfloat sx, GLfloat sy, GLfloat sz)
{
    GLfloat T[4][4] = 
    {
        {sx, 0, 0, 0},
        {0, sy, 0, 0},
        {0, 0, sz, 0},
        {0, 0, 0, 1}
    };
}

void translacao(std::vector<GLfloat> obj, GLfloat tx, GLfloat ty, GLfloat tz) 
{
    GLfloat T[4][4] = 
    {
        {1, 0, 0, tx},
        {0, 1, 0, ty},
        {0, 0, 1, tz},
        {0, 0, 0, 1}

    };
}