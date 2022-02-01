#include <GL/glut.h>
#include <stdlib.h>
#include "libs/malha.hpp"
#include "libs/cubo.hpp"
#include "libs/func.hpp"

float angulo = 0.0f,rotX = 1.0,rotY = 0.0f,rotZ = 0.0f,velocidade = -1.00;
int w,h;

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

	glRotatef(angulo,rotX, rotY, rotZ);

	cubo.colorCube();

	angulo+=velocidade;

	glutSwapBuffers();
}

void Inicializa (void)
{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glEnable(GL_DEPTH_TEST);
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

void TeclaEspeciais(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
	{
		velocidade += 0.05;
		printf("Velocidade Rotação : %.2f\n",velocidade);
	}
	
	if(key == GLUT_KEY_DOWN) 
	{
		velocidade -=  0.05;
		printf("Velocidade Rotação : %.2f\n",velocidade);
	}

	if(key == GLUT_KEY_LEFT)
		if(velocidade < 0)velocidade *= -1;
	
	if(key == GLUT_KEY_RIGHT)
		if(velocidade > 0)velocidade *= -1;
}

void CliqueMouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		if(state == GLUT_DOWN)
			printf("Clicou com o botão esquerdo na Posição  X : %i Y : %i \n",x,y);
		
		else if (state == GLUT_UP)
			printf("Soltou Botão esquerdo\n");
	}
	else if(button == GLUT_RIGHT_BUTTON)
	{
		if(state == GLUT_DOWN)
			printf("Clicou com o botão direito na Posição  X : %i Y : %i \n",x,y);

		else if(state == GLUT_UP)
			printf("Soltou Botão direito\n");
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		if(state == GLUT_DOWN)
			printf("Clicou com o botão do meio na Posição  X : %i Y : %i \n",x,y);

		else if(state == GLUT_UP)
			printf("Soltou Botão do meio\n");
	}
}

void MovimentoMouse (int x,int y) 
{
	printf("Mouse na Posição  X : %i Y : %i \n",x,y);
}

void AlteraTamanhoTela(int w, int h) {

// Função é chamada caso a tela tenha tido alterada

	if (h == 0)
		h = 1;

	float proporsao =  w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, proporsao, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
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
	glutMouseFunc(CliqueMouse);
	glutPassiveMotionFunc(MovimentoMouse);
	glutKeyboardFunc( Teclado );
	glutSpecialFunc( TeclaEspeciais);
	glutMainLoop();
}