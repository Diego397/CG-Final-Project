#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#include <new>
#include <math.h>
#include <vector>

class Malha 
{
	private:

	typedef GLfloat point3[3];
	point3 vertices[8] = 
	{
		{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 2.0f},
		{2.0f, 0.0f, 2.0f}, {2.0f, 0.0f, 0.0f},
		{0.0f, 2.0f, 0.0f}, {0.0f, 2.0f, 2.0f},
		{2.0f, 2.0f, 2.0f}, {2.0f, 2.0f, 0.0f}
	};

	int arestas[18][2] = 
	{
		{0, 1}, {1, 2},
		{2, 3}, {3, 0},
		{4, 5}, {5, 6},
		{6, 7}, {7, 4},
		{0, 4}, {1, 5},
		{2, 6}, {3, 7},
		{2, 7}, {5, 7},
		{5, 2}, {1, 4},
		{1, 3}, {3, 4}       
		
	};

	GLfloat colors[8][3] =
	{
		{0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f},
		{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}
	};

	int* edgeToPoints(int a[2], int b[2], int c[2]) // 6 7    2 6     2 7
	{
		int *vertices = new int[3];
        int pa, pb, pc;
		pa = a[0]; pb = a[1];
		
		if (b[0] != pa and b[0] != pb) 
			pc = b[0];
		else 
			pc = b[1];

		vertices[0] = pa; vertices[1] = pb; vertices[2] = pc;
		return vertices;
	}

	void triangulo(int a[2], int b[2], int c[2], int cor)
	{
		int *pontos;

		pontos = edgeToPoints(a, b, c);

        std::cout << "pontos: " << pontos[0] << pontos[1] << pontos[2] << "\n";

		glBegin(GL_TRIANGLES);
			glColor3fv (colors[cor]);
			glVertex3fv(vertices[pontos[0]]);
			glColor3fv (colors[cor]);
			glVertex3fv(vertices[pontos[1]]);
			glColor3fv (colors[cor]);
			glVertex3fv(vertices[pontos[2]]);
		glEnd();
	}

	public:
	
	void colorCube()
	{
		triangulo(arestas[6], arestas[10], arestas[2], 0); // x+
		triangulo(arestas[12], arestas[2], arestas[11], 0); // x+
        // triangulo(arestas[7], arestas[4], arestas[13], 1); // y+
        // triangulo(arestas[13], arestas[5], arestas[6], 1); // y+
        // triangulo(arestas[5], arestas[14], arestas[10], 2); // z+
        // triangulo(arestas[9], arestas[1], arestas[14], 2); // z+
        // triangulo(arestas[4], arestas[15], arestas[9], 3); // x-
		// triangulo(arestas[8], arestas[0], arestas[15], 3); // x-
        // triangulo(arestas[1], arestas[16], arestas[2], 4); // y-
        // triangulo(arestas[3], arestas[16], arestas[10], 4); // y-
        // triangulo(arestas[11], arestas[17], arestas[7], 5); // z-
        // triangulo(arestas[3], arestas[8], arestas[17], 5); // z-
	}
};

float angulo = 0.0f,rotX = 1.0,rotY = 0.0f,rotZ = 0.0f,velocidade = -1.00;
int w,h;

GLuint texid1;

Malha cubo;

void DesenhaNaTela(void)
{

    //colocaImagem();

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT);

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
}

void Teclado(unsigned char key, int x, int y){
    if(key == 27) exit(0); // O Programa Fecha Caso o Esc seja apertado ...

    if((char)key == ' '){
        if(rotX == 1.0f){
        rotX = 0.0f;
        rotY = 1.0f;
        rotZ = 0.0f;
        }else if (rotY == 1.0f){
        rotX = 0.0f;
        rotY = 0.0f;
        rotZ = 1.0f;
        }else if(rotZ == 1.0f){
        rotX = 1.0f;
        rotY = 0.0f;
        rotZ = 0.0f;
        }

    }

}

void TeclaEspeciais(int key, int x, int y){

    if(key == GLUT_KEY_UP) {
    velocidade += 0.05;
    printf("Velocidade Rotação : %.2f\n",velocidade);
    }
    if(key == GLUT_KEY_DOWN) {
    velocidade -=  0.05;
    printf("Velocidade Rotação : %.2f\n",velocidade);
    }

    if(key == GLUT_KEY_LEFT)
        if(velocidade < 0)velocidade *= -1;
    if(key == GLUT_KEY_RIGHT)
        if(velocidade > 0)velocidade *= -1;
}

void CliqueMouse(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
        printf("Clicou com o botão esquerdo na Posição  X : %i Y : %i \n",x,y);
        }else if (state == GLUT_UP){
        printf("Soltou Botão esquerdo\n");
        }
    }else if(button == GLUT_RIGHT_BUTTON){
        if(state == GLUT_DOWN){
        printf("Clicou com o botão direito na Posição  X : %i Y : %i \n",x,y);
        }else if(state == GLUT_UP){
        printf("Soltou Botão direito\n");
        }
    }else if (button == GLUT_MIDDLE_BUTTON){
        if(state == GLUT_DOWN){
        printf("Clicou com o botão do meio na Posição  X : %i Y : %i \n",x,y);
        }else if(state == GLUT_UP){
        printf("Soltou Botão do meio\n");
        }
    }
}

void MovimentoMouse (int x,int y) {

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