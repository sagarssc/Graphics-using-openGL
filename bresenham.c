#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
void display(float,float);
void display(float q,float w){
printf("%f   %f\n",q,w);
}
int SCREEN_WIDTH=500;
int SCREEN_HEIGHT=500;
float a,b,c,d,dx,dy,l,e;
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500);
dx=c-a;
dy=d-b;
l=abs(dx)>abs(dy)?abs(dx):abs(dy);
e=2*abs(dy)-abs(dx);
glBegin(GL_LINES);

glVertex2f(a,b);
int i;
for(i=0;i<=dx;i++){
display(a,b);
glColor3f(1,8,1);
glVertex2f(a,b);
glColor3f(1,4,1);
glVertex2f(a,b);
glColor3f(1,1,8);
while(e>=0){
b=b+1;e=e-2*dx;
}
a=a+1;e=e+2*dy;
}
glEnd();
glFlush();
}
int main(int argc,char **argv){
printf("Enter Starting point\n");
scanf("%f %f",&a,&b);
printf("Enter End Points\n");
scanf("%f %f",&c,&d);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(60,56);
glutInitWindowSize(400,400);
glutCreateWindow("garima.c");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
