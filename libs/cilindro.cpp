#include <GL/glut.h>
#include "cilindro.hpp"
#include <math.h>

#define PI 3.1415927

void cilindro::desenha_cilindro(GLfloat raio,
                   GLfloat altura,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x               = 0.0;
    GLfloat y               = 0.0;
    GLfloat angulo          = 0.0;
    GLfloat angulo_step     = 0.1;

    /** Desenha o tronco do cilindro */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angulo = 0.0;
    while( angulo < 2*PI ) {
        x = raio * cos(angulo);
        y = raio * sin(angulo);
        glVertex3f(x, y , altura);
        glVertex3f(x, y , 0.0);
        angulo = angulo + angulo_step;
    }
    glVertex3f(raio, 0.0, altura);
    glVertex3f(raio, 0.0, 0.0);
    glEnd();

    /** Desenha a base do cilindro */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angulo = 0.0;
    while( angulo < 2*PI ) {
        x = raio * cos(angulo);
        y = raio * sin(angulo);
        glVertex3f(x, y , altura);
        angulo = angulo + angulo_step;
    }
    glVertex3f(raio, 0.0, altura);

    /** Desenha embaixo do cilindro */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angulo = 0.0;
    while( angulo < 2*PI ) {
        x = raio * cos(angulo);
        y = raio * sin(angulo);
        glVertex3f(x, y , 0.0);
        angulo = angulo + angulo_step;
    }
    glVertex3f(raio, 0.0, 0.0);
    glEnd();
}