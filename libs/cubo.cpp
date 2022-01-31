#include <GL/glut.h>
#include "cubo.hpp"

void cubo::quad(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glColor3fv (colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv (colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv (colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv (colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void cubo::colorCube()
{
    quad(6, 2, 1, 5); // x+
    quad(3, 0, 1, 2); // y+
    quad(5, 1, 0, 4); // z+
    quad(4, 0, 3, 7); // x-
    quad(6, 5, 4, 7); // y-
    quad(7, 3, 2, 6); // z-
}