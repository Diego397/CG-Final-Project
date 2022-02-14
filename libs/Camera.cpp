#include <GL/glut.h>
#include "Vetor.hpp"
#include "Transformacoes.hpp"
#include "Camera.hpp"

void Camera::mudaCamera(point3 *obj, int tam)
{
    Transformacoes::aplicarTrans(obj, tam, mwtc);
}