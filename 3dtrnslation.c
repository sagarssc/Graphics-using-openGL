#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>

void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
glTranslatef(1.5f, 0.0f, -7.0f);
//glOrtho(-200,200,-200,200,-200,200);
glBegin(GL_QUADS);

      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
/*glColor3ub(255,255,255);
glVertex3f(-30,30,-30);
glVertex3f(30,30,-30);
glVertex3f(30,30,30);
glVertex3f(-30,30,30);

glColor3ub(255,0,0);
glVertex3f(-30,-30,-30);
glVertex3f(-30,-30,30);
glVertex3f(30,-30,30);
glVertex3f(30,-30,-30);

glColor3ub(0,255,0);
glVertex3f(-30,30,-30);
glVertex3f(30,30,-30);
glVertex3f(30,-30,-30);
glVertex3f(-30,-30,-30);

glColor3ub(0,0,255);
glVertex3f(-30,30,-30);
glVertex3f(-30,30,30);
glVertex3f(-30,-30,30);
glVertex3f(-30,-30,-30);

glColor3ub(100,150,255);
glVertex3f(30,30,-30);
glVertex3f(30,30,30);
glVertex3f(30,-30,30);
glVertex3f(30,-30,-30);

glColor3ub(255,0,255);
glVertex3f(-30,30,30);
glVertex3f(30,30,30);
glVertex3f(30,-30,30);
glVertex3f(-30,-30,30);*/
glEnd();
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowPosition(40,100);
glutInitWindowSize(500,500);
glutCreateWindow("translation");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
