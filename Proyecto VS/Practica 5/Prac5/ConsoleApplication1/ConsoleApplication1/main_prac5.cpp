//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno: Ramirez Hernandez Jose Angel Jair ***//
//*************	 Visual Studio 2015						******//
//*************	 Grupo:6								******//
//************************************************************//

//con la tecla H se mueve el Hombro
//con la tecla J se mueve el Antebrazo
//con la tecla K se mueve la Palma
//con la tecla Y se mueven los Dedos
//con la tecla U se mueve el Pulgar

#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0;
float angAntebrazo = 0.0;
float angPalma = 0.0;
float angIndice = 0.0;
float angPulgar = 0.0;
float angNada = 0.0;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
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
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
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

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí. estamos en (0, 0, 0)
	
glPushMatrix(); //Dibujar el Brazo
	
		glTranslatef(-5, 3, 0); //estamos en (-2.5, 1.25, 0)
		glRotatef(angHombro, 0, 0, 1);
	
	glPushMatrix();

		glTranslatef(5, -3, 0); // ahora estamos en (0, 0, 0) 
		glScalef(10, 6, 5);
		prisma();

	glPopMatrix();

	//Dibujar el antebrazo

	glTranslatef(10, -3, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angAntebrazo, 0, 1, 0);

	glPushMatrix();

		glTranslatef(6, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(12, 5, 4);
		prisma();

	glPopMatrix();

	
	//Dibujar la Palma

	glTranslatef(12, 0, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angPalma, 0, 1, 0);

	glPushMatrix();
		
		glTranslatef(2, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(4, 4, 3);
		prisma();

	glPopMatrix();

	//dibujar el dedo indice
	glTranslatef(4, 1.6, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angIndice, 0, 1, 0);

	glPushMatrix();

		glTranslatef(1.2, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2.4, 0.8, 3);
		prisma();

	glPopMatrix();

	//Dibujar dedo grosero xD
	glTranslatef(0, -1.2, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(1.2, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2.4, 0.8, 3);
		prisma();

	glPopMatrix();

	//DIbujar dedo anular
	glTranslatef(0, -1.2, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(1.2, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2.4, 0.8, 3);
		prisma();

	glPopMatrix();

	//Dibujar meñique
	glTranslatef(0, -1.00, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(1, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2, 0.40, 3);
		prisma();

	glPopMatrix();

	//Segunda Falange del dedo meeñique
	glTranslatef(2, 0, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angIndice, 0, 0.5, 0);

	glPushMatrix();

		glTranslatef(0.8, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(1.6, 0.40, 3);
		prisma();

	glPopMatrix();

	//Segunda falange del dedo anular
	glTranslatef(0.4, 1.0, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(1, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2, 0.8, 3);
		prisma();

	glPopMatrix();

	//Segunda falange del dedo grosero
	glTranslatef(0, 1.2, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angIndice, 0, 0.5, 0);

	glPushMatrix();

		glTranslatef(1, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2, 0.8, 3);
		prisma();

	glPopMatrix();

	//segunda falange del dedo indice

	glTranslatef(0, 1.2, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(1, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(2, 0.8, 3);
		prisma();
	
	glPopMatrix();
	
	//tercer falange del dedo indice
	
	glTranslatef(2, 0, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(0.4, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(0.8, 0.8, 3);
		prisma();

	glPopMatrix();

	//tercer falange del dedo grosero
	glTranslatef(0, -1.2, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angIndice, 0, 1, 0);

	glPushMatrix();

		glTranslatef(0.8, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(1.6, 0.8, 3);
		prisma();

	glPopMatrix();

	//tercer falange del dedo anular
	glTranslatef(0, -1.2, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(0.6, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(1.2, 0.8, 3);
		prisma();

	glPopMatrix();

	//tercer falange del dedo meñique
	glTranslatef(-0.8, -1.0, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angNada, 0, 0, 0);

	glPushMatrix();

		glTranslatef(0.6, 0, 0); // ahora estamos en (0, 0, 0) 
		glScalef(1.2, 0.4, 3);
		prisma();

	glPopMatrix();

	//dibujar el pulgar
	glTranslatef(-6, 3.8, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angPulgar, 1, 0, 0);
	
	glPushMatrix();

		glTranslatef(0, 1.2, 0); // ahora estamos en (0, 0, 0) 
		glScalef(1.2, 2.4, 3);
		prisma();

	glPopMatrix();

	glTranslatef(0, 2.4, 0); //estamos en (-2.5, 1.25, 0)
	glRotatef(angPulgar, 1, 0, 0);

	glPushMatrix();

		glTranslatef(0, 0.8, 0); // ahora estamos en (0, 0, 0) 
		glScalef(1.2, 1.8, 3);
		prisma();

	glPopMatrix();



glPopMatrix();
											
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
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'h': //Rota el hombro en z hacia arriba con limite de 90 grados	
			if (angHombro < 90) {
				angHombro += 0.5f;
				printf("%f ", angHombro);
			}
			break;
		case 'H': //Rota el hombro en z hacia abajo con limite de 90 grados
			if (angHombro > -90) {
				angHombro -= 0.5f;
				printf("%f ", angHombro);
			}
			break;

		case 'j': //Rota el Antebrazo en y hacia delante con limite de 90 grados	
			if (angAntebrazo < 0) {
				angAntebrazo += 0.5f;
				printf("%f ", angAntebrazo);
			}
			break;
		case 'J': //Rota el Antebrazo en y hacia atraz con limite de 90 grados
			if (angAntebrazo > -90) {
				angAntebrazo -= 0.5f;
				printf("%f ", angAntebrazo);
			}
			break;

		case 'k': //Rota la palma en y hacia delante con limite de 90 grados	
			if (angPalma < 90) {
				angPalma += 0.5f;
				printf("%f ", angPalma);
			}
			break;
		case 'K': //Rota la palma en y hacia atraz con limite de 90 grados
			if (angPalma > -90) {
				angPalma -= 0.5f;
				printf("%f ", angPalma);
			}
			break;
		case 'y': //Rota los dedos en x hacia delante con limite de 0 grados	
			if (angIndice < 0) {
				angIndice += 0.5f;
				printf("%f ", angIndice);
			}
			break;
		case 'Y': //Rota el Pulgar en x hacia atraz con limite de 90 grados
			if (angIndice > -35) {
				angIndice -= 0.5f;
				printf("%f ", angIndice);
			}
			break;

		case 'u': //Rota el pulgar en x hacia delante con limite de 45 grados	
			if (angPulgar < 45) {
				angPulgar += 0.5f;
				printf("%f ", angPulgar);
			}
			break;
		case 'U': //Rota el Pulgar en x hacia atraz con limite de 0 grados
			if (angPulgar > -0) {
				angPulgar -= 0.5f;
				printf("%f ", angPulgar);
			}
			break;
		case 'N': //Rota el pulgar en x hacia delante con limite de 90 grados	
			if (angNada < 90) {
				angNada += 0.5f;
				printf("%f ", angNada);
			}
			break;
		case 'n': //Rota el Pulgar en x hacia atraz con limite de 90 grados
			if (angNada > -90) {
				angNada -= 0.5f;
				printf("%f ", angNada);
			}
			break;

		
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
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



