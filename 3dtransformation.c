#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>

void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
glOrtho(-200,200,-200,200,-200,200);
glBegin(GL_LINES);
glColor3ub(0,255,0);
glVertex3f(-10,-10,-10);
glVertex3f(-10,-10,10);
glVertex3f(-10,-10,10);
glVertex3f(-10,10,-10);

glVertex3f(-10,10,-10);
glVertex3f(-10,10,10);
glVertex3f(10,10,-10);
glVertex3f(10,10,10);
glVertex3f(10,-10,-10);
glVertex3f(10,-10,10);
glEnd();
glFlush();
}

int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("3D Rotation");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
