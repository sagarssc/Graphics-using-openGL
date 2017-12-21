#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
int SCREEN_WIDTH=500;
int SCREEN_HEIGHT=500;
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-50,50,-50,50);
glBegin(GL_LINES);
glVertex2f(11,43);
glVertex2f(12,42);
glVertex2f(13,42);
glVertex2f(14,42);
glVertex2f(15,41);
glVertex2f(16,41);
glVertex2f(17,41);
glVertex2f(18,40);
glVertex2f(19,40);
glVertex2f(20,39);
glVertex2f(21,39);
glVertex2f(22,38);
glVertex2f(23,38);
glVertex2f(24,37);
glVertex2f(25,36);
glVertex2f(-11,43);
glVertex2f(-12,42);
glVertex2f(-13,42);
glVertex2f(-14,42);
glVertex2f(-15,41);
glVertex2f(-16,41);
glVertex2f(-17,41);
glVertex2f(-18,40);
glVertex2f(-19,40);
glVertex2f(-20,39);
glVertex2f(-21,39);
glVertex2f(-22,38);
glVertex2f(-23,38);
glVertex2f(-24,37);
glVertex2f(-25,36);
glColor3f(1,0,0);
glEnd();
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(60,35);
glutInitWindowSize(200,400);
glutCreateWindow("garima");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
