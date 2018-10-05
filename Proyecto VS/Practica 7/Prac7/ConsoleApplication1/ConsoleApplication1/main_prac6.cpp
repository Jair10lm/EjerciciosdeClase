//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno:Ramirez Hernandez Jose Angel Jair*****//
//*************	 Visual Studio 2015						******//
//*************  Grupo: 6								******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int lunaTierra = 0;
int marte = 0;
int lunaMarte1 = 0;
int lunaMarte2 = 0;
int jupiter = 0;
int lunaJupiter1 = 0;
int lunaJupiter2 = 0;
int lunaJupiter3 = 0;
int saturno = 0;
int anilloSaturno1 = 0;
int anilloSaturno2 = 0;
int urano = 0;
int lunaUrano1 = 0;
int lunaUrano2 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;

GLfloat LuzAmbientalSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LuzEspecularSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position


GLfloat MercurioDiffuse[] =  { 0.55f,0.55f,0.55f,1.0f };		// Mercurio whitw plastic
GLfloat MercurioSpecular[] = { 0.70f,0.70f,0.70f,1.0f };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };;// Venus gold	
GLfloat VenusSpecular[] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };
GLfloat VenusShininess[] = { 40.0 };

GLfloat EarthDiffuse[]= { 0.0f,0.50980392f,0.50980392f,1.0f };	// Tierra blue plastic	
GLfloat EarthSpecular[] = { 0.50196078f,0.50196078f,0.50196078f,1.0f };
GLfloat EarthShininess[] = { 60.0 };

GLfloat LunaTierraDiffuse[] = { 0.5f,0.5f,0.5f,1.0f };		    // Luna Tierra
GLfloat LunaTierraSpecular[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat LunaTierraShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.61424f, 0.04136f, 0.04136f, 0.55f };// Marte Ruby		
GLfloat MarsSpecular[] = { 0.727811f, 0.626959f, 0.626959f, 0.55f };
GLfloat MarsShininess[] = { 78.125 };


GLfloat LunaMarteDiffuse[] = { 0.5f,0.5f,0.5f,1.0f };		    // Luna Marte
GLfloat LunaMarteMoonSpecular[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat LunaMarteMoonShininess[] = { 50.0 };

GLfloat Luna2MarteDiffuse[] = { 0.5f,0.5f,0.5f,1.0f };		    // Luna2 Marte
GLfloat Luna2MarteMoonSpecular[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat Luna2MarteMoonShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 1.0f, 0.5f, 0.31f };				//Jupiter Yellow rubber
GLfloat jupiterSpecular[] = { 0.5f, 0.5f, 0.5f };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat LunaJupiterDiffuse[] = { 0.5f,0.5f,0.5f,1.0f };		    // Luna Jupier
GLfloat LunaJupiterMoonSpecular[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat LunaJupiterMoonShininess[] = { 50.0 };

GLfloat Luna2JupiterDiffuse[] = { 0.5f,0.5f,0.5f,1.0f };		// Luna2 Jupiter
GLfloat Luna2JupiterMoonSpecular[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat Luna2JupiterMoonShininess[] = { 50.0 };

GLfloat Luna3JupiterDiffuse[] = { 0.5f,0.5f,0.5f,1.0f };		// Luna3 Jupiter
GLfloat Luna3JupiterMoonSpecular[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat Luna3JupiterMoonShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };	// Saturno Brass
GLfloat SaturnoSpecular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat AnilloSaturnoDiffuse[] = { 0.7038f, 0.27048f, 0.0828f, 1.0f };	// Anillo1 Saturno
GLfloat AnilloSaturnoSpecular[] = { 0.256777f, 0.137622f, 0.086014f, 1.0f };
GLfloat AnilloSaturnoShininess[] = { 50.0 };

GLfloat Anillo2SaturnoDiffuse[] = { 0.427451f, 0.470588f, 0.541176f, 1.0f };	// Anillo2 Saturno
GLfloat Anillo2SaturnoSpecular[] = { 0.333333f, 0.333333f, 0.521569f, 1.0f };
GLfloat Anillo2SaturnoShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.54f, 0.89f, 0.63f, 0.95f };			// Urano Jade
GLfloat UranoSpecular[] = { 0.316228f, 0.316228f, 0.316228f, 0.95f };
GLfloat UranoShininess[] = { 50.0 };



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LuzAmbientalSol);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LuzDifusaSol);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LuzEspecularSol);				// Setup The Diffuse Light
																	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
																	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

																	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
													//glEnable(GL_LIGHT0);
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	
	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol);

	glEnable(GL_LIGHTING);

	glPushMatrix(); //Sistema solar

		

		glPushMatrix();//Dibujar el sol
			
			glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
			glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
			glEnable(GL_LIGHTING);
			
			glPushMatrix();//dibujar a mercurio
			
				glRotatef(mercurio, 0.0, 1.0, 0.0);	//Traslacion 

				glTranslatef(3.2, 0, 0);
				glRotatef(mercurio, 0, 1, 0);   //Rotacion
				glColor3f(0.5, 0.5, 0.5);	//mercurio gris
				
				glMaterialfv(GL_FRONT, GL_AMBIENT, MercurioDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
				
				glutSolidSphere(0.3, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

			
			glPopMatrix();

			
			glPushMatrix();//dibujar a venus

				glRotatef(venus, 0.0, 1.0, 0.0);	//Traslacion 
				glTranslatef(5, 0, 0);
				glRotatef(venus, 0, 1, 0);   //Rotacion
				glColor3f(1, 0.5, 0);	//venus naranja
				
				glMaterialfv(GL_FRONT, GL_AMBIENT, VenusDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
				
				glutSolidSphere(0.5, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
					

			glPopMatrix();

			glPushMatrix();//dibujar a tierra

				glRotatef(tierra, 0.0, 1.0, 0.0);	//Traslacion 
				glTranslatef(8.2, 0, 0);
				glRotatef(tierra, 0, 1, 0);   //Rotacion
				glColor3f(0, 0, 1);	//tierra azul
				
				glMaterialfv(GL_FRONT, GL_AMBIENT, EarthDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);

				glutSolidSphere(0.7, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPushMatrix();
					
					glRotatef(tierra, 0.0, 1.0, 0.0);	//Traslacion 
					glTranslatef(1.5, 0, 0);
					glRotatef(tierra, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca

					glMaterialfv(GL_FRONT, GL_AMBIENT, LunaTierraDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, LunaTierraSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, LunaTierraShininess);

					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPopMatrix();

			glPopMatrix();


			glPushMatrix();//dibujar a marte

				glRotatef(marte, 0.0, 1.0, 0.0);	//Traslacion 
				glTranslatef(11.3, 0, 0);
				glRotatef(marte, 0, 1, 0);   //Rotacion
				glColor3f(1, 0, 0);	//tierra azul
				
				glMaterialfv(GL_FRONT, GL_AMBIENT, MarsDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);

				glutSolidSphere(0.4, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPushMatrix();
					
					glRotatef(marte, 0.0, 1.0, 0.0);	//Traslacion 
					glTranslatef(1.2, 0, 0);
					glRotatef(marte, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca

					glMaterialfv(GL_FRONT, GL_AMBIENT, LunaMarteDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, LunaMarteMoonSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, LunaMarteMoonShininess);

					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPopMatrix();

				glPushMatrix();

					glRotatef(marte, 0.0, 1.0, 0.0);	//Traslacion 
					glTranslatef(-1.2, 0, 0);
					glRotatef(marte, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca

					glMaterialfv(GL_FRONT, GL_AMBIENT, Luna2MarteDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, Luna2MarteMoonSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, Luna2MarteMoonShininess);

					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//dibujar a Jupiter

				glRotatef(jupiter, 0.0, 1.0, 0.0);	//Traslacion 
				glTranslatef(15.7, 0, 0);
				glRotatef(jupiter, 0, 1, 0);   //Rotacion
				glColor3f(0.76, 0.3, 0.1);	//jupiter cafe 

				glMaterialfv(GL_FRONT, GL_AMBIENT, JupiterDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, jupiterSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);

				glutSolidSphere(1, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPushMatrix();

					glRotatef(venus, 0.0, 1.0, 0.0);	//Traslacion 
					glTranslatef(-2, 0, 0);
					glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca

					glMaterialfv(GL_FRONT, GL_AMBIENT, LunaJupiterDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, LunaJupiterMoonSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, LunaJupiterMoonShininess);

					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPopMatrix();

				glPushMatrix();

					glRotatef(venus, 0.0, 1.0, 0.0);	//Traslacion 
					glTranslatef(2, 0, 0);
					glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca
					
					glMaterialfv(GL_FRONT, GL_AMBIENT, Luna2JupiterDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, Luna2JupiterMoonSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, Luna2JupiterMoonShininess);
					
					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
	
				glPopMatrix();


				glPushMatrix();

					glRotatef(venus, 0.0, 1.0, 0.0);	//Traslacion 
					glTranslatef(0, 0, 2);
					glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca

					glMaterialfv(GL_FRONT, GL_AMBIENT, Luna3JupiterDiffuse);
					glMaterialfv(GL_FRONT, GL_SPECULAR, Luna3JupiterMoonSpecular);
					glMaterialfv(GL_FRONT, GL_SHININESS, Luna3JupiterMoonShininess);

					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//dibujar a Saturno

				glRotatef(saturno, 0.0, 1.0, 0.0);	//Traslacion 
				glTranslatef(19.7, 0, 0);
				glRotatef(saturno, 0, 1, 0);   //Rotacion
				glColor3f(0.4, 0.4, 0);	//Saturno cafe 

				glMaterialfv(GL_FRONT, GL_AMBIENT, SaturnoDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);

				glutSolidSphere(0.9, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
				

				glRotatef(45, 1, 0, 0);   //Rotacion
				glColor3f(0.5, 0.6, 0.7);	//Anillo Cafe

				glMaterialfv(GL_FRONT, GL_AMBIENT, AnilloSaturnoDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, AnilloSaturnoSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, AnilloSaturnoShininess);

				glutSolidTorus(0.2, 2.8, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
				glColor3f(0.5, 0.3, 0.1);	//Anillo gris 

				glMaterialfv(GL_FRONT, GL_AMBIENT, Anillo2SaturnoDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, Anillo2SaturnoSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, Anillo2SaturnoShininess);

				glutSolidTorus(0.2, 2.3, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);


			glPopMatrix();

			glPushMatrix();//dibujar a urano

				glRotatef(urano, 0.0, 1.0, 0.0);	//Traslacion 
				glTranslatef(21.4, 0, 0);
				glRotatef(urano, 0, 1, 0);   //Rotacion
				glColor3f(0.5, 0.6, 0.7);	//urano blanco

				glMaterialfv(GL_FRONT, GL_AMBIENT, UranoDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);

				glutSolidSphere(0.8, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
				
			glPopMatrix();

		glPopMatrix();
		
	glPopMatrix();



	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360; //nunca va a llenarse la variable por lo cual al llegar a 360 se vuelve a inicar haciendo que gire 
		// sol - velocidad de despalzamiento

		mercurio = (mercurio - 1) % 360;

		venus = (venus - 2) % 360;

		tierra = (tierra - 3) % 360;

		marte = (marte - 4) % 360;

		jupiter = (jupiter - 5) % 360;

		saturno = (saturno - 6) % 360;

		urano = (urano - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (1000, 1000);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion ); //indicamos que el programa se siga ejecutando hasta que sea presionada alguna tecla
  glutMainLoop        ( );          // 

  return 0;
}