#include <GL/glut.h>
#include "Material.hpp"

void Material::setMaterial(int i)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient[i]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse[i]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular[i]);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess[i]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}