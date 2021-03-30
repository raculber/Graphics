#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream> 
#include <time.h>

GLenum mode = GL_POLYGON;

void init() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glLoadIdentity();
}
void displayI(float rand1x, float rand1y) {
	//Drawing squares 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Draw outline
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.6, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.6, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	rand1x += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.6, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	rand1x += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();	

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.6, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

}
void displayJ(float rand1x, float rand1y) {
	//Drawing squares 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Drawing outline
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	rand1x += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1y += 0.1;
	rand1x -= 0.2;
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
}
void displayL(float rand1x, float rand1y) {
	//Drawing squares 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Drawing outline
	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.3, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.3, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	rand1x += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.3, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1y += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.3, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
}
void displayO(float rand1x, float rand1y) {
	//Drawing squares 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.1);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Drawing outline 
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.8, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.1);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.8, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1y += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.1);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.8, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1x -= 0.1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.1);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.8, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
}
void displayS(float rand1x, float rand1y) {
	//Drawing squares 
	glBegin(GL_POLYGON);
	glColor3f(0.2, 1.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Drawing outline
	glBegin(GL_LINE_LOOP);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(0.2, 1.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1y += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.2, 1.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1x += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.2, 1.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

}
void displayT(float rand1x, float rand1y) {
	//Drawing squares 
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Drawing outline 
	glBegin(GL_LINE_LOOP);
	glColor3f(0.5, 0.1, 0.5);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.5, 0.1, 0.5);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	rand1x += 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.5, 0.1, 0.5);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1y += 0.1;
	rand1x -= 0.1;
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.9);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.5, 0.1, 0.5);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
}
void displayZ(float rand1x, float rand1y) {
	//Drawing square 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Draw outline
	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	//Change center point	
	rand1x += 0.1; 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1y += 0.1;
	rand1x -= 0.1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
	rand1x -= 0.1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0.0, 0.0);
	glVertex2f(rand1x, rand1y);
	glVertex2f(rand1x+0.1, rand1y);
	glVertex2f(rand1x+0.1, rand1y-0.1);
	glVertex2f(rand1x, rand1y-0.1);
	glEnd();
	
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(NULL));
	//Draw Light Blue I shape
	float randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	float randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check 
	while (randomX + 0.4 > 1.0 || randomY - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayI(randomX, randomY);

	//Draw Dark Blue J shape
	randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check
	while (randomX + 0.3 > 1.0 || randomY + 0.1 > 1.0 || randomY - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayJ(randomX, randomY);

	//Draw Orange L shape 
	randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check
	while (randomX + 0.3 > 1.0 || randomY + 0.1 > 1.0 || randomY - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayL(randomX, randomY);

	//Draw Yellow O shape
	randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check
	while (randomX + 0.2 > 1.0 || randomY + 0.1 > 1.0 || randomY - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayO(randomX, randomY);

	//Draw Green S shape 
	randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check
	while (randomX + 0.3 > 1.0 || randomY + 0.1 > 1.0 || randomY - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayS(randomX, randomY);
	
	//Draw Purple T shape
	randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check
	while (randomX + 0.3 > 1.0 || randomY + 0.1 > 1.0 || randomY - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayT(randomX, randomY);

	//Draw Red Z Shape 
	randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
	randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	//Out of bounds check
	while (randomX + 0.2 > 1.0 || randomY + 0.1 > 1.0 || randomY - 0.1 < -1.0 
	|| randomX - 0.1 < -1.0) {
		randomX = 2*(((float) rand())/ (float) RAND_MAX)-1;
		randomY = 2*(((float) rand())/ (float) RAND_MAX)-1;
	}
	displayZ(randomX, randomY);
	glFlush();
}
int main(int argc, char *argv[]) 
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Tetris");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
