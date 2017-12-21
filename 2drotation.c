#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int d;
double x,a=300,b=200;

void line(float a,float b){
glBegin(GL_LINES);
glVertex2f(0,0);
glVertex2f(a,b);
glEnd();
glFlush();
}

void rotation(){
double m,n,xn,yn;
x=d*0.0174533;
m=cos(x);n=sin(x);
xn=a*m-b*n;
yn=a*n+b*m;
glBegin(GL_LINES);
glColor3ub(255,0,0);
line(xn,yn);
glEnd();
glFlush();
}

void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);
glBegin(GL_LINES);
glColor3ub(0,100,200);
line(a,b);
glEnd();
glFlush();
rotation();
glEnd();
glFlush();
}

int main(int argc,char **argv){
int i;
printf("Enter Angle:\n");
scanf("%d",&d);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("500048459");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
