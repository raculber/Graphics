//Rachel Culbertson
//010854980
#include <math.h>
#include <stdio.h> 
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream> 
#include <fstream>
#include <vector>
using namespace std;
//Global variables
#define SIZE 64
#define maxLines 500
#define MIN_X_VIEW -1.0
#define MAX_X_VIEW 1.0
#define MIN_Y_VIEW -1.0
#define MAX_Y_VIEW 1.0
#define MIN_Z_VIEW -1.0
#define MAX_Z_VIEW 1.0
#define MIN_X_SCREEN 0
#define MAX_X_SCREEN 500
#define MIN_Y_SCREEN 0
#define MAX_Y_SCREEN 500
//Angles of rotation
int xangle = 0;
int yangle = 0;
int zangle = 0;
//Array holding lines
float lines[maxLines][4];
//Number of lines
int count = 0;
//mode = 0: startup
//mode = 1: drawing line
//mode = 2: drawing object of revolution; allow rotation
int mode = 0;
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(MIN_X_VIEW, MAX_X_VIEW, MIN_Y_VIEW, MAX_Y_VIEW, MIN_Z_VIEW, MAX_Z_VIEW);
	glEnable(GL_DEPTH_TEST);
}
void drawRevolution() {
	//Display original object of revolution 
	if (mode == 0) 
		count = 65;
	float xpos[count][count];
	float ypos[count][count];
	float zpos[count][count];
	if (mode == 2) {
		int i = 0;
		while (i < count) {
		        xpos[i][0] = lines[i][0];
	      		ypos[i][0] = lines[i][1];
	      		zpos[i][0] = 0.0;
			i++;
			if (i < count) {
				xpos[i][0] = lines[i][2];
			      	ypos[i][0] = lines[i][3];
				zpos[i][0] = 0.0;
				i++;
			}
	  	}
	}
	//Define object based on function
	else if (mode == 0) {
		for (int i = 0; i < count; i++) {
			//Range of function is 0 to 4pi
			float theta = i * 4 * M_PI / SIZE;
			//Function = -0.3cos(x) + 0.6
		        xpos[i][0] = (float) i / (float) SIZE - 0.5;
	      		ypos[i][0] = -0.3 * cos(theta) + 0.6;
	      		zpos[i][0] = 0.0;
	   	}

	}
	// Perform rotation around X axis
	for (int j = 1; j < count; j++) {
		float theta = j * 2 * M_PI / SIZE;
		float cos_theta = cos(theta);
		float sin_theta = sin(theta);
		for (int i = 0; i < count; i++) {
			xpos[i][j] = xpos[i][0];
			ypos[i][j] = ypos[i][0] * cos_theta - zpos[i][0] * sin_theta;
			zpos[i][j] = ypos[i][0] * sin_theta + zpos[i][0] * cos_theta;
		}
	}
	//Display polygons
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < count; i++) {
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < count; j++) {
				glVertex3f(xpos[i][j], ypos[i][j], zpos[i][j]);
		}
	        glEnd();
	}
	for (int j = 0; j < count; j++) {
		glBegin(GL_LINE_STRIP);
	        for (int i = 0; i < count; i++) {
			glVertex3f(xpos[i][j], ypos[i][j], zpos[i][j]);
		}
	        glEnd();
	
	}
	glFlush();
}
void smoothCurve() {
	for (int i = 1; i < count-1; i++) {
		lines[i][0] = (lines[i-1][0]+lines[i][0]+lines[i+1][0])/3;
		lines[i][1] = (lines[i-1][1]+lines[i][1]+lines[i+1][1])/3;
		lines[i][2] = (lines[i-1][2]+lines[i][2]+lines[i+1][2])/3;
		lines[i][3] = (lines[i-1][3]+lines[i][3]+lines[i+1][3])/3;
	}
	
}
//Display callback
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
   	glRotatef(xangle, 1.0, 0.0, 0.0);
   	glRotatef(yangle, 0.0, 1.0, 0.0);
	glRotatef(zangle, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	//Display line
	if (mode == 1) {
		for (int i=0; i < count; i++) {	
			if ((lines[i][0] != lines[i][2]) || (lines[i][1] != lines[i][3])) {		
				glBegin(GL_LINE_LOOP);
				float x1 = lines[i][0];
				float y1 = lines[i][1];
				float x2 = lines[i][2];
				float y2 = lines[i][3];
				glVertex3f(x1, y1, 0.0);
				glVertex3f(x2, y2, 0.0);
				glEnd();
			}
		}
	}
	//Display object of revolution
	if (mode == 2 || mode == 0) {
		drawRevolution();
	}
	glFlush();
}
//Keyboard callback
void keyboard(unsigned char key, int x, int y) {
   	// Update angles
	if (mode == 2 || mode == 0) {
	   	if (key == 'x')
	      		xangle -= 5;
		else if (key == 'y') 
	      		yangle -= 5;
		else if (key == 'z')
			zangle -= 5;
		else if (key == 'X')
	   		xangle += 5;
		else if (key == 'Y') 
	   		yangle += 5;
		else if (key == 'Z') 
			zangle += 5;
	}
	if (mode == 2) {
		if (key == 's')
			smoothCurve();
	}
	// Redraw objects
	glutPostRedisplay();
}

//Mouse callback
void mouse(int button, int state, int x, int y) {
	// Calculate scale factors
	float x_scale = (MAX_X_VIEW - MIN_X_VIEW) / (float)(MAX_X_SCREEN - MIN_X_SCREEN);
        float y_scale = (MIN_Y_VIEW - MAX_Y_VIEW) / (float)(MAX_Y_SCREEN - MIN_Y_SCREEN);

        // Handle mouse down
        if (state == GLUT_DOWN) {
		//Reset count
		count = 0;
		//Reset Angle
		xangle = 0;
		yangle = 0;
		zangle = 0;
   		float x2 = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
   		float y2 = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
        	mode = 1;
        	lines[count][0] = x2;
        	lines[count][1] = y2;
   	}

  	 // Handle mouse up
   	else if (state == GLUT_UP) 
   	{
	      	mode = 2;
	      	glutPostRedisplay();
   	}
}

//Motion callback
void motion(int x, int y) {
	// Calculate scale factors
   	float x_scale = (MAX_X_VIEW - MIN_X_VIEW) / (float)(MAX_X_SCREEN - MIN_X_SCREEN);
   	float y_scale = (MIN_Y_VIEW - MAX_Y_VIEW) / (float)(MAX_Y_SCREEN - MIN_Y_SCREEN);

   	// Handle mouse motion
   	float x2 = MIN_X_VIEW + (x - MIN_X_SCREEN) * x_scale;
   	float y2 = MAX_Y_VIEW + (y - MIN_Y_SCREEN) * y_scale;
   	if (count < maxLines) {  
		lines[count][2] = x2;
	  	lines[count][3] = y2;
	  	count++;
		if (count < maxLines) {
		   	lines[count][0] = x2;
		   	lines[count][1] = y2;
		}
	   	glutPostRedisplay();
   	}

}
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("Object of Revolution");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
   	glutMouseFunc(mouse);
   	glutMotionFunc(motion);
	cout << "Keyboard commands" << endl;
	cout << "x: Rotate -5 degrees around x axis" << endl;
	cout << "y: Rotate -5 degrees around y axis" << endl;
	cout << "z: Rotate -5 degrees around z axis" << endl;
	cout << "X: Rotate +5 degrees around x axis" << endl;
	cout << "Y: Rotate +5 degrees around y axis" << endl;
	cout << "Z: Rotate +5 degrees around z axis" << endl;
	cout << "s: Smooth curve" << endl;
	init();
	glutMainLoop();
	return 0;
}
