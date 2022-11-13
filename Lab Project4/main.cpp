#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

float windowHeight = 500;
float windowWidth = 600;
float x = 0;
bool ysl = false;


void hill(){ //hill
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3f(0.0,0.5,0.0);
    glVertex2f(0,30);
    glVertex2f(5,40);
    glVertex2f(10,30);
glEnd();
glPopMatrix();
}

void large_hill(){ //large hill
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3f(0.0,0.5,0.0);
    glVertex2f(8,30);
    glVertex2f(15,42);
    glVertex2f(22,30);
glEnd();
glPopMatrix();
}

void house(){
glPushMatrix();//House
glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.0);
    glVertex2f(2,5);
    glVertex2f(2,12);
    glVertex2f(8,12);
    glVertex2f(8,5);
glEnd();
glPopMatrix();

glPushMatrix();//Door
glBegin(GL_QUADS);
    glColor3f(0.6,0.0,0.0);
    glVertex2f(4,5.1);
    glVertex2f(4,9);
    glVertex2f(6,9);
    glVertex2f(6,5.1);
glEnd();
glPopMatrix();

glPushMatrix(); //shed
glBegin(GL_TRIANGLES);
glColor3f(0.3,0.1,0.1);
    glVertex2f(0.1,12);
    glVertex2f(5,16);
    glVertex2f(10,12);
glEnd();
glPopMatrix();
}

void tree(){
glPushMatrix();//Tree
glBegin(GL_QUADS);
    glColor3f(0.5,0.0,0.0);
    glVertex2f(35,5);
    glVertex2f(35,10);
    glVertex2f(36,10);
    glVertex2f(36,5);
glEnd();
glPopMatrix();

glPushMatrix();//Tree leaf quad
glBegin(GL_QUADS);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(33,10);
    glVertex2f(34,12);
    glVertex2f(37,12);
    glVertex2f(38,10);
glEnd();
glPopMatrix();

glPushMatrix(); //Tree leaf triangle
glBegin(GL_TRIANGLES);
glColor3f(0.0,0.5,0.0);
    glVertex2f(33,12);
    glVertex2f(35.5,15);
    glVertex2f(38,12);
glEnd();
glPopMatrix();
}

void nouka(){

glPushMatrix();//Boat Quad
glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(20 - x,25);
    glVertex2f(20 - x,28);
    glVertex2f(28 - x,28);
    glVertex2f(28 - x,25);
glEnd();
glPopMatrix();


glPushMatrix(); //boat triangle1
glBegin(GL_TRIANGLES);
glColor3f(0.4,0.4,0.4);
    glVertex2f(15 - x,29);
    glVertex2f(20 - x,27);
    glVertex2f(20 - x,25);
glEnd();
glPopMatrix();

glPushMatrix(); //boat triangle2
glBegin(GL_TRIANGLES);
glColor3f(0.4,0.4,0.4);
    glVertex2f(28 - x,25);
    glVertex2f(28 - x,27);
    glVertex2f(33 - x,29);
glEnd();
glPopMatrix();

}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluOrtho2D(0, 45 , 0, 45);
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();

glPushMatrix(); //River
glBegin(GL_QUADS);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(0,0);
    glVertex2f(0,30);
    glVertex2f(50,30);
    glVertex2f(50,0);
glEnd();
glPopMatrix();

glPushMatrix(); //House Space
glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(0,0);
    glVertex2f(0,23);
    glVertex2f(20,20);
    glVertex2f(20,0);
glEnd();
glPopMatrix();


glPushMatrix(); //Tree Space
glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(30,0);
    glVertex2f(32,20);
    glVertex2f(50,25);
    glVertex2f(50,0);
glEnd();
glPopMatrix();


glPushMatrix(); //Hill-1
    glTranslatef(0,0,0);
    hill();
glPopMatrix();

glPushMatrix(); //Large Hill-1
    glTranslatef(0,0,0);
    large_hill();
glPopMatrix();

glPushMatrix(); //Hill-2
    glTranslatef(20,0,0);
    hill();
glPopMatrix();

glPushMatrix(); //Large Hill-2
    glTranslatef(18,0,0);
    large_hill();
glPopMatrix();

glPushMatrix(); //Hill-3
    glTranslatef(35,0,0);
    hill();
glPopMatrix();

glPushMatrix(); //House-1
    glTranslatef(0,0,0);
    house();
glPopMatrix();

glPushMatrix(); //House-2
    glTranslatef(8,2,0);
    glScalef(.80,.80,0);
    house();
glPopMatrix();

glPushMatrix(); //House-2
    glTranslatef(40,14,0);
    glScalef(.70,.70,0);
    house();
glPopMatrix();

glPushMatrix(); //Tree-1
    glTranslatef(0,0,0);
    tree();
glPopMatrix();

glPushMatrix(); //Tree-2
    glTranslatef(6,2,0);
    tree();
glPopMatrix();

glPushMatrix(); //Tree-3
    glTranslatef(3,7,0);
    tree();
glPopMatrix();

glPushMatrix(); //Tree-4
    glTranslatef(-33,10,0);
    tree();
glPopMatrix();

glPushMatrix(); //Tree-5
    glTranslatef(-27,11,0);
    tree();
glPopMatrix();

glPushMatrix(); //nouka
    glTranslatef(10,0,0);
    nouka();
    glPopMatrix();

glFlush();
glutSwapBuffers();
}

void key( unsigned char key, int x, int y ){
    switch ( key )
    {
    case 'b':
         ysl = true;
         glutPostRedisplay();
        break;
    case 'r':
         ysl = false;
         glutPostRedisplay();
        break;
    }
}

void boat(){
    if(ysl == true){
		x += 0.005;
		if(x > 70)
			x = -30;
    }
    else if (ysl == false)
	{
		x = 1;

	}
   glutPostRedisplay();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(500,100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Village");
    glClearColor(0.0f, 0.8f, 1.0f, 1.5f);
    glutKeyboardFunc(key);
      glutIdleFunc(boat);
    glutDisplayFunc(display);
    glutMainLoop();
return 0;
}
