#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
void dis(int,int,int,int);
void dis(int i,int p,int a,int b){
printf("%d  %d  %d   %d\n",i,p,a,b);
}
int j,i=0,x,y,r=90,a,b,p,ta,tb;
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-200,200,-200,200);

a=0,b=r;
x=a,y=b;
p=1-r;
glBegin(GL_LINES);
while(a<b){
if(p<0){
ta=a;
tb=b;
a++;
glVertex2f(ta,tb+50);
glVertex2f(a,b+50);
glVertex2f(tb,ta+50);
glVertex2f(b,a+50);
glVertex2f(tb,-ta-50);
glVertex2f(b,-a-50);
glVertex2f(ta,-tb-50);
glVertex2f(a,-b-50);
glVertex2f(-ta,tb+50);
glVertex2f(-a,b+50);
glVertex2f(-tb,ta+50);
glVertex2f(-b,a+50);
glVertex2f(-tb,-ta-50);
glVertex2f(-b,-a-50);
glVertex2f(-ta,-tb-50);
glVertex2f(-a,-b-50);
p=p+2*a+1;
}
else if(p>0){
ta=a;
tb=b;
b--;
a++;
glVertex2f(ta,tb+50);
glVertex2f(a,b+50);
glVertex2f(tb,ta+50);
glVertex2f(b,a+50);
glVertex2f(tb,-ta-50);
glVertex2f(b,-a-50);
glVertex2f(ta,-tb-50);
glVertex2f(a,-b-50);
glVertex2f(-ta,tb+50);
glVertex2f(-a,b+50);
glVertex2f(-tb,ta+50);
glVertex2f(-b,a+50);
glVertex2f(-tb,-ta-50);
glVertex2f(-b,-a-50);
glVertex2f(-ta,-tb-50);
glVertex2f(-a,-b-50);
p=p+2*a+1-2*b;
}
}
glVertex2f(-90,50);glVertex2f(90,-50);
glVertex2f(90,150);glVertex2f(-90,-150);
glColor3f(1,2,8);
glEnd();
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(40,100);
glutInitWindowSize(500,500);
glutCreateWindow("Shikhar");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
