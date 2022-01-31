#include <GL/glut.h>
#include <stdlib.h>
#include "libs/malha.hpp"
#include "libs/cubo.hpp"
#include "libs/func.hpp"

int w, h;
// float rotX = 1.0, rotY = 0.0f, rotZ = 0.0f, angulo = 0.0f, velocidade = -1.00;

GLfloat angle, fAspect;
GLfloat rotX,rotY,rotZ;
GLfloat rotX_ini,rotY_ini,rotZ_ini;
GLfloat obsx,obsy,obsz;
GLfloat obsx_ini,obsy_ini,obsz_ini;
GLfloat x_ini,y_ini;
GLfloat bot;

GLuint texid1;

malha cubo;

void DesenhaNaTela(void)
{

	//colocaImagem();

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	gluLookAt(  0.0f, 0.0f, 10.0f,
				0.0f, 0.0f,  0.0f,
				0.0f, 1.0f,  0.0f);

	// Sem perspectiva
	// glRotatef(angulo,rotX, rotY, rotZ);
	// angulo += velocidade;
	
	// Com perspectiva
	glTranslatef(0.0f, 0.0f, -7.0f);

	cubo.colorCube();

	glutSwapBuffers();
}

void Inicializa (void)
{
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	
	// Cor
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};
    
    // Brilho
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
    
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

    // Capacidade de Brilho do Material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

	// Cor do fundo da janela
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);

    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);

    angle = 45;
}

//função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
    //especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    
    //inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    
    //posiciona e orienta o observador
    glTranslatef(-obsx,-obsy,-obsz);
    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);

    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();

    // Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.4,500);

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);

    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();

    // Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
    PosicionaObservador();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button,int state, int x, int y)
{
    if(state == GLUT_DOWN){
        //salva os parametros atuais
        x_ini = x;
        y_ini = y;
        obsx_ini = obsx;
        obsy_ini = obsy;
        obsz_ini = obsz;
        rotX_ini = rotX;
        rotY_ini = rotY;
        rotZ_ini = rotZ;
        bot = button;
    }
    else
        bot = -1;
}
// Define callback para eventos de movimento do mouse
#define SENS_ROT 5.0
#define SENS_OBS 15.0
#define SENS_TRANSL 30.0

void GerenciaMovim(int x, int y)
{
    //caso botão esquerdo
    if (bot == GLUT_LEFT_BUTTON){
        //Calcula diferenças
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        //e depois modifica os ângulos
        rotY = rotY_ini - deltax/SENS_ROT;
        rotX = rotX_ini - deltay/SENS_ROT;
    }
   	//caso botão direito
    else if (bot == GLUT_RIGHT_BUTTON){
        //calcula diferença
        int deltaz = y_ini - y;
        //e modifica a distancia do observador
        obsz = obsz_ini + deltaz/SENS_OBS;
    }

    //caso botão do meio
    else if(bot == GLUT_MIDDLE_BUTTON){
        //calcula as diferenças
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        //E modifica posições
        obsx = obsx_ini + deltax/SENS_TRANSL;
        obsy = obsy_ini + deltay/SENS_TRANSL;
    }

    PosicionaObservador();
    glutPostRedisplay();

}

void Teclado(unsigned char key, int x, int y)
{
	if(key == 27) exit(0); // O Programa Fecha Caso o Esc seja apertado ...

	if((char)key == ' ')
	{
		if(rotX == 1.0f)
		{
			rotX = 0.0f;
			rotY = 1.0f;
			rotZ = 0.0f;
		}
		else if (rotY == 1.0f)
		{
			rotX = 0.0f;
			rotY = 0.0f;
			rotZ = 1.0f;
		}
		else if(rotZ == 1.0f)
		{
			rotX = 1.0f;
			rotY = 0.0f;
			rotZ = 0.0f;
		}
	}
}

/*void TeclaEspeciais(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
	{
		velocidade += 0.05;
		printf("Velocidade Rotação : %.2f\n",velocidade);
	}
	
	if(key == GLUT_KEY_DOWN) 
	{
		velocidade -= 0.05;
		printf("Velocidade Rotação : %.2f\n",velocidade);
	}

	if(key == GLUT_KEY_LEFT)
		if(velocidade < 0)velocidade *= -1;
	
	if(key == GLUT_KEY_RIGHT)
		if(velocidade > 0)velocidade *= -1;
}
*/

void TeclasEspeciais (int tecla, int x, int y)
{
    switch (tecla) {
        case GLUT_KEY_HOME: if(angle >= 10) angle -=5;
                            break;
    case GLUT_KEY_END: if(angle <= 150) angle +=5;
                        break;
    }

   EspecificaParametrosVisualizacao();
    glutPostRedisplay();

}
void AlteraTamanhoTela(int w, int h) {
	if (h == 0)
		h = 1;

	float proporcao =  w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, proporcao, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

/*int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(320*3,240*3);
	glutInitWindowPosition(100*3,100*3);
	glutCreateWindow("Cubo 3D");
	Inicializa();
	glutDisplayFunc(DesenhaNaTela);
	glutIdleFunc(DesenhaNaTela);
	glutReshapeFunc(AlteraTamanhoTela);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(TeclaEspeciais);
	glutMainLoop();
}*/

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(864,486);
    glutCreateWindow("Chaleira");
    glutDisplayFunc(DesenhaNaTela);
    glutReshapeFunc(AlteraTamanhoTela);
    glutMouseFunc(GerenciaMouse);
    glutMotionFunc(GerenciaMovim);
    Inicializa();
    glutMainLoop();
}