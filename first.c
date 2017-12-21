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
gluOrtho2D(0,500,0,500);
glBegin(GL_LINES);
glVertex2f(200,1);
glVertex2f(50,240);
glColor3f(1,0,0);
glEnd();
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(60,35);
glutInitWindowSize(200,400);
glutCreateWindow("sagar");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
