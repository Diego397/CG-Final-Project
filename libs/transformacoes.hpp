#include <GL/glut.h>
#include <string>
#include <cmath>

class Transformacoes 
{
	public:
	
	typedef GLfloat point4[4];
	typedef GLfloat point3[3];

	void aplicarTrans (point3 *obj, int tam, GLfloat T[4][4]);

	void escala(point3 *obj, int tam, GLfloat sx, GLfloat sy, GLfloat sz);

	void translacao(point3 *obj, int tam, GLfloat tx, GLfloat ty, GLfloat tz);

	void rotacao(point3 *obj, int tam, float angulo, char tipo);

	void rotacao(point3 *obj, int tam, double angulo, char tipo);

	void cisalhamento(point3 *obj, int tam, float tg, char tipo, std::string plano);
	
	void reflexao(point3 *obj, int tam, std::string tipo);

    void reflexao(point3 *obj, int tam, GLfloat* vetUni, GLfloat* pontos);

};

