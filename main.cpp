// #include <GL/glut.h>
// #include <stdlib.h>
// #include "libs/malha.hpp"
// #include "libs/cubo.hpp"
// #include "libs/func.hpp"

// float angulo = 0.0f,rotX = 1.0,rotY = 0.0f,rotZ = 0.0f,velocidade = -1.00;
// int w,h;

// GLuint texid1;

// malha cubo;

// void DesenhaNaTela(void)
// {

// 	//colocaImagem();

// 	// Clear Color and Depth Buffers
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// 	// Reset transformations
// 	glLoadIdentity();

// 	gluLookAt(  0.0f, 0.0f, 10.0f,
// 				0.0f, 0.0f,  0.0f,
// 				0.0f, 1.0f,  0.0f);

// 	glRotatef(angulo,rotX, rotY, rotZ);

// 	cubo.colorCube();

// 	angulo+=velocidade;

// 	glutSwapBuffers();
// }

// void Inicializa (void)
// {
// 		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// 		glEnable(GL_DEPTH_TEST);
// }

// void Teclado(unsigned char key, int x, int y)
// {
// 	if(key == 27) exit(0); // O Programa Fecha Caso o Esc seja apertado ...

// 	if((char)key == ' ')
// 	{
// 		if(rotX == 1.0f)
// 		{
// 			rotX = 0.0f;
// 			rotY = 1.0f;
// 			rotZ = 0.0f;
// 		}
// 		else if (rotY == 1.0f)
// 		{
// 			rotX = 0.0f;
// 			rotY = 0.0f;
// 			rotZ = 1.0f;
// 		}
// 		else if(rotZ == 1.0f)
// 		{
// 			rotX = 1.0f;
// 			rotY = 0.0f;
// 			rotZ = 0.0f;
// 		}
// 	}
// }

// void TeclaEspeciais(int key, int x, int y)
// {
// 	if(key == GLUT_KEY_UP)
// 	{
// 		velocidade += 0.05;
// 		printf("Velocidade Rotação : %.2f\n",velocidade);
// 	}
	
// 	if(key == GLUT_KEY_DOWN) 
// 	{
// 		velocidade -=  0.05;
// 		printf("Velocidade Rotação : %.2f\n",velocidade);
// 	}

// 	if(key == GLUT_KEY_LEFT)
// 		if(velocidade < 0)velocidade *= -1;
	
// 	if(key == GLUT_KEY_RIGHT)
// 		if(velocidade > 0)velocidade *= -1;
// }

// void CliqueMouse(int button, int state, int x, int y)
// {
// 	if(button == GLUT_LEFT_BUTTON)
// 	{
// 		if(state == GLUT_DOWN)
// 			printf("Clicou com o botão esquerdo na Posição  X : %i Y : %i \n",x,y);
		
// 		else if (state == GLUT_UP)
// 			printf("Soltou Botão esquerdo\n");
// 	}
// 	else if(button == GLUT_RIGHT_BUTTON)
// 	{
// 		if(state == GLUT_DOWN)
// 			printf("Clicou com o botão direito na Posição  X : %i Y : %i \n",x,y);

// 		else if(state == GLUT_UP)
// 			printf("Soltou Botão direito\n");
// 	}
// 	else if (button == GLUT_MIDDLE_BUTTON)
// 	{
// 		if(state == GLUT_DOWN)
// 			printf("Clicou com o botão do meio na Posição  X : %i Y : %i \n",x,y);

// 		else if(state == GLUT_UP)
// 			printf("Soltou Botão do meio\n");
// 	}
// }

// void MovimentoMouse (int x,int y) 
// {
// 	printf("Mouse na Posição  X : %i Y : %i \n",x,y);
// }

// void AlteraTamanhoTela(int w, int h) {

// // Função é chamada caso a tela tenha tido alterada

// 	if (h == 0)
// 		h = 1;

// 	float proporsao =  w * 1.0 / h;

// 	glMatrixMode(GL_PROJECTION);

// 	glLoadIdentity();

// 	glViewport(0, 0, w, h);

// 	gluPerspective(45.0f, proporsao, 0.1f, 100.0f);

// 	glMatrixMode(GL_MODELVIEW);
// }

// int main(int argc, char** argv)
// {
// 	glutInit(&argc,argv);
// 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
// 	glutInitWindowSize(320*3,240*3);
// 	glutInitWindowPosition(100*3,100*3);
// 	glutCreateWindow("Cubo 3D");
// 	Inicializa();
// 	glutDisplayFunc(DesenhaNaTela);
// 	glutIdleFunc(DesenhaNaTela);
// 	glutReshapeFunc(AlteraTamanhoTela);
// 	glutMouseFunc(CliqueMouse);
// 	glutPassiveMotionFunc(MovimentoMouse);
// 	glutKeyboardFunc( Teclado );
// 	glutSpecialFunc( TeclaEspeciais);
// 	glutMainLoop();
// }

/*
 * OGL02Animation.cpp: 3D Shapes with animation
 */
// #include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Global variables */
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 15;        // refresh interval in milliseconds [NEW]
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
   glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
 
   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
 
      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube
 
   // Render a pyramid consists of 4 triangles
   glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen
   glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f);  // Rotate about the (1,1,0)-axis [NEW]
 
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
 
   // Update the rotational angle after each refresh [NEW]
   anglePyramid += 0.2f;
   angleCube -= 0.15f;
}
 
/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}