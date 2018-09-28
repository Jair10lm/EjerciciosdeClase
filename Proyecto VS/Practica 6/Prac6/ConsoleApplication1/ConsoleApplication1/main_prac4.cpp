//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno: Ramirez Hernandez Jose Angel Jair ***//
//*************	 Grupo: 06								******//
//*************	 Visual Studio 2015						******//
//************************************************************//
#include "Main.h"

float transZ = -7.0f;
int screenW = 0.0;
int screenH = 0.0;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0, 1, 0);

	//Torso
	glPushMatrix();
	
		glScalef(10, 10, 5);
		prisma();
	
	glPopMatrix();

	//Cuello
	glPushMatrix();

	glTranslatef(0,5.5,0);
	glScalef(4, 1, 5);
	prisma();

	glPopMatrix();

	//Cabeza
	glPushMatrix();

	glTranslatef(0, 8, 0);
	glScalef(5, 4, 5);
	prisma();

	glPopMatrix();

	//Hombro Izquierdo
	glPushMatrix();

	glTranslatef(6, 4, 0);
	glScalef(2, 2, 5);
	prisma();

	glPopMatrix();

	//Hombro Derecho
	glPushMatrix();

	glTranslatef(-6, 4, 0);
	glScalef(2, 2, 5);
	prisma();

	glPopMatrix();

	//Biscep Derecho
	glPushMatrix();

	glTranslatef(9, 4, 0);
	glScalef(4, 2, 5);
	prisma();

	glPopMatrix();

	//Codo Derecho
	glPushMatrix();

	glTranslatef(11.5, 4, 0);
	glScalef(1, 2, 5);
	prisma();

	glPopMatrix();

	//Biscep izquierdo
	glPushMatrix();

	glTranslatef(-9, 4, 0);
	glScalef(4, 2, 5);
	prisma();

	glPopMatrix();

	//Codo Izquierdo
	glPushMatrix();

	glTranslatef(-11.5, 4, 0);
	glScalef(1, 2, 5);
	prisma();

	glPopMatrix();

	//Antebrazo Derecho
	glPushMatrix();

	glTranslatef(13.5, 4, 0);
	glScalef(3, 2, 5);
	prisma();

	glPopMatrix();

	//Antebrazo Izquierdo
	glPushMatrix();

	glTranslatef(-13.5, 4, 0);
	glScalef(3, 2, 5);
	prisma();

	glPopMatrix();

	//Mano/Muñeca Derecha
	glPushMatrix();

	glTranslatef(16, 4, 0);
	glScalef(2, 2, 5);
	prisma();

	glPopMatrix();
	
	//Mano/Muñeca Izquierda
	glPushMatrix();

	glTranslatef(-16, 4, 0);
	glScalef(2, 2, 5);
	prisma();

	glPopMatrix();
	
	//Muslo Derecho
	glPushMatrix();

	glTranslatef(2.5, -7.5, 0);
	glScalef(3, 5, 5);
	prisma();

	glPopMatrix();

	//Muslo Izquierda
	glPushMatrix();

	glTranslatef(-2.5, -7.5, 0);
	glScalef(3, 5, 5);
	prisma();

	glPopMatrix();

	//Rodilla Derecha
	glPushMatrix();

	glTranslatef(2.5, -10.5, 0);
	glScalef(3, 1, 5);
	prisma();

	glPopMatrix();

	//Rodilla izquierda
	glPushMatrix();

	glTranslatef(-2.5, -10.5, 0);
	glScalef(3, 1, 5);
	prisma();

	glPopMatrix();

	//tibia izquierda
	glPushMatrix();

	glTranslatef(-2.5, -14, 0);
	glScalef(3, 6, 5);
	prisma();

	glPopMatrix();

	//tibia Derecha
	glPushMatrix();

	glTranslatef(2.5, -14, 0);
	glScalef(3, 6, 5);
	prisma();

	glPopMatrix();

	//Pie Derech0
	glPushMatrix();

	glTranslatef(3, -18, 0);
	glScalef(5, 2, 5);
	prisma();

	glPopMatrix();

	//Pie Izquierdo
	glPushMatrix();

	glTranslatef(-3, -18, 0);
	glScalef(5, 2, 5);
	prisma();

	glPopMatrix();

	//glScalef();
	

  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-8, 8,-8, 8, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch (key) {
	case 'w': //te metes hacia el cubo
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;

	case 's': //te sales del cubo
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;

	case 'a': //se mueve a izquierda
	case 'A':
		transX -= 0.2f;
		break;

	case 'd': //Se mueve a la derecha
	case 'D':
		transX += 0.2f;
		break;

	case 'q': //se mueve hacia arriba
	case 'Q':
		transY += 0.2f;
		break;

	case 'e': // se mueve hacia abajo
	case 'E':
		transY -= 0.2f;
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



