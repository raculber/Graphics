#include <stdio.h> 
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream> 
#include <fstream>
#include <vector>
using namespace std;
class tetrisShape {
	private:
		float x, y;
		string type;
		bool frozen;
		int angle;
	public:
		float getX() { return x; }
		float getY() { return y; }
		string getType() { return type; }
		bool getFrozen() { return frozen; }
		int getAngle() { return angle; }
		void setX(float x2) { x = x2; }
		void setY(float y2) { y = y2; }
		void setType(string type2) { type = type2; }
		void setFrozen(bool frozen2) { frozen = frozen2; } 
		void setAngle(int angle2) { angle = angle2; }
};
vector<tetrisShape> shapes;
ofstream file;
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Sets 10x20 coordinates
	glOrtho(-5.0, 5.0, -10.0, 10.0, -1.0, 1.0);
}
//---------------------------------------
// Draw one square
//---------------------------------------
void draw_square(float x, float y, float w, float R, float G, float B)
{
   glBegin(GL_POLYGON);
   glColor3f(R, G, B);
   glVertex2f(x-w/2, y-w/2);
   glVertex2f(x-w/2, y+w/2);
   glVertex2f(x+w/2, y+w/2);
   glVertex2f(x+w/2, y-w/2);
   glEnd();

   glLineWidth(3);
   glBegin(GL_LINE_LOOP);
   glColor3f(R/2, G/2, B/2);
   glVertex2f(x-w/2, y-w/2);
   glVertex2f(x-w/2, y+w/2);
   glVertex2f(x+w/2, y+w/2);
   glVertex2f(x+w/2, y-w/2);
   glEnd();
}

//---------------------------------------
// Draw I piece
//---------------------------------------
void draw_I(float x, float y)
{
   float R=0.65, G=0.85, B=1;
   draw_square(x,y,1, R,G,B);
   draw_square(x-1,y,1, R,G,B);
   draw_square(x+1,y,1, R,G,B);
   draw_square(x+2,y,1, R,G,B);
}

//---------------------------------------
// Draw J piece
//---------------------------------------
void draw_J(float x, float y)
{
   float R=0, G=0, B=1;
   draw_square(x,y,1, R,G,B);
   draw_square(x-1,y,1, R,G,B);
   draw_square(x+1,y,1, R,G,B);
   draw_square(x-1,y+1,1, R,G,B);
}

//---------------------------------------
// Draw L piece
//---------------------------------------
void draw_L(float x, float y)
{
   float R=1, G=0.65, B=0;
   draw_square(x,y,1, R,G,B);
   draw_square(x-1,y,1, R,G,B);
   draw_square(x+1,y,1, R,G,B);
   draw_square(x+1,y+1,1, R,G,B);
}

//---------------------------------------
// Draw O piece
//---------------------------------------
void draw_O(float x, float y)
{
   float R=1, G=1, B=0;
   draw_square(x,y,1, R,G,B);
   draw_square(x+1,y,1, R,G,B);
   draw_square(x,y+1,1, R,G,B);
   draw_square(x+1,y+1,1, R,G,B);
}

//---------------------------------------
// Draw T piece
//---------------------------------------
void draw_T(float x, float y)
{
   float R=1, G=0, B=1;
   draw_square(x,y,1, R,G,B);
   draw_square(x-1,y,1, R,G,B);
   draw_square(x+1,y,1, R,G,B);
   draw_square(x,y+1,1, R,G,B);
}

//---------------------------------------
// Draw S piece
//---------------------------------------
void draw_S(float x, float y)
{
   float R=0, G=1, B=0;
   draw_square(x,y,1, R,G,B);
   draw_square(x-1,y,1, R,G,B);
   draw_square(x,y+1,1, R,G,B);
   draw_square(x+1,y+1,1, R,G,B);
}

//---------------------------------------
// Draw Z piece
//---------------------------------------
void draw_Z(float x, float y)
{
   float R=1, G=0, B=0;
   draw_square(x,y,1, R,G,B);
   draw_square(x+1,y,1, R,G,B);
   draw_square(x,y+1,1, R,G,B);
   draw_square(x-1,y+1,1, R,G,B);
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//Display grid of gray squares
	for (float i = -4.5; i <= 5.0; i++) {
		for (float j = -9.5; j < 11.0; j++) {
			draw_square(i, j, 1, 0.6, 0.6, 0.6);
		}
	}
	for (unsigned int i = 0; i < shapes.size(); i++) {
		float x = shapes.at(i).getX();
		float y = shapes.at(i).getY();
		string type = shapes.at(i).getType();
		int angle = shapes.at(i).getAngle();
		if (type == "I") {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			glTranslatef(-x, -y, 0.0);
			draw_I(x, y);
			glPopMatrix();
		}
		else if (type == "J") {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			glTranslatef(-x, -y, 0.0);
			draw_J(x, y);
			glPopMatrix();
		}
		else if (type == "L") {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			glTranslatef(-x, -y, 0.0);
			draw_L(x, y);
			glPopMatrix();
		}
		else if (type == "O") {
			draw_O(x, y);
		}
		else if (type == "S") {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			glTranslatef(-x, -y, 0.0);
			draw_S(x, y);
			glPopMatrix();
		}
		else if (type == "T") {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			glTranslatef(-x, -y, 0.0);
			draw_T(x, y);
			glPopMatrix();
		}
		else if (type == "Z") {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			glTranslatef(-x, -y, 0.0);
			draw_Z(x, y);
			glPopMatrix();
		}

	}
	
	glFlush();
}
void keyboard(unsigned char key, int x, int y) {
	//Add I shape 
	if (key == 'i' || key == 'I') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(9.5);
		s.setType("I");
		s.setFrozen(false);
		s.setAngle(0);
		shapes.push_back(s);
		//Automatically freeze previous shape
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	//Add J shape 
	else if (key == 'j' || key == 'J') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(8.5);
		s.setType("J");
		s.setFrozen(false);
		s.setAngle(0);
		shapes.push_back(s);
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	//Add L shape
	else if (key == 'l' || key == 'L') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(8.5);
		s.setType("L");
		s.setFrozen(false);
		s.setAngle(0);
		shapes.push_back(s);
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	//Add O shape
	else if (key == 'o' || key == 'O') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(8.5);
		s.setType("O");
		s.setFrozen(false);
		shapes.push_back(s);
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	else if (key == 's' || key == 'S') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(8.5);
		s.setType("S");
		s.setFrozen(false);
		s.setAngle(0);
		shapes.push_back(s);
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	else if (key == 't' || key == 'T') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(8.5);
		s.setType("T");
		s.setFrozen(false);
		s.setAngle(0);
		shapes.push_back(s);
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	else if (key == 'z' || key == 'Z') {
		tetrisShape s;
		s.setX(-0.5);
		s.setY(8.5);
		s.setType("Z");
		s.setFrozen(false);
		s.setAngle(0);
		shapes.push_back(s);
		if (shapes.size() > 1)
			shapes.at(shapes.size() - 2).setFrozen(true);
	}
	//Space: freeze shape
	else if (key == 32) {
		int last = shapes.size() -1;
		if (last >= 0) {
			shapes.at(last).setFrozen(true);			
		}
	} 
	glutPostRedisplay();
}
void special(int key, int x, int y) {
	int last = shapes.size()-1;
	if (last >= 0) {
		float y  = shapes.at(last).getY();
		float x  = shapes.at(last).getX();
		bool frozen = shapes.at(last).getFrozen();
		int angle = shapes.at(last).getAngle();
		//Move left
		if (key == GLUT_KEY_LEFT && !frozen) {
			if (x > -4.5)	
				shapes.at(last).setX(x-1);
		}
		//Move right
		else if (key == GLUT_KEY_RIGHT && !frozen) {
			if (x < 4.5)
				shapes.at(last).setX(x+1);
		}
		//Move down
		else if (key == GLUT_KEY_DOWN && !frozen) {
			if (y > -9.5)
				shapes.at(last).setY(y-1);
		}
		//Rotate 90 degrees
		else if (key == GLUT_KEY_UP && !frozen) {
			shapes.at(last).setAngle(angle+90);
		}
	}
	glutPostRedisplay();		
}
int main(int argc, char *argv[]) {	
	glutInit(&argc, argv);
	glutInitWindowSize(400, 800);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Tetris");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	init();
	glutMainLoop();
	return 0;
}
