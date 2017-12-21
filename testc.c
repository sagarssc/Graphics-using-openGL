#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
void dis(int,int,int,int);
void dis(int i,int p,int a,int b){
printf("%d  %d  %d   %d\n",i,p,a,b);
}
int j,i=0,x,y,r,a,b,p,ta,tb;
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);

a=0,b=r;
x=a,y=b;
p=1-r;
glBegin(GL_LINES);
glVertex2f(-500,0);
glVertex2f(500,0);
glVertex2f(0,-500);
glVertex2f(0,500);
glVertex2f(a,b+95);
while(a<b){
if(p<0){
ta=a;
tb=b;
a++;
glVertex2f(a,b+95);
glVertex2f(tb,ta+95);
glVertex2f(b,a+95);
glVertex2f(tb,-ta+95);
glVertex2f(b,-a+95);
glVertex2f(ta,-tb+95);
glVertex2f(a,-b+95);
glVertex2f(-ta,tb+95);
glVertex2f(-a,b+95);
glVertex2f(-tb,ta+95);
glVertex2f(-b,a+95);
glVertex2f(-tb,-ta+95);
glVertex2f(-b,-a+95);
glVertex2f(-ta,-tb+95);
glVertex2f(-a,-b+95);
glVertex2f(a,b+95);
p=p+2*a+1;
}
else if(p>0){
ta=a;
tb=b;
b--;
a++;
glVertex2f(a,b+95);
glVertex2f(tb,ta+95);
glVertex2f(b,a+95);
glVertex2f(tb,-ta+95);
glVertex2f(b,-a+95);
glVertex2f(ta,-tb+95);
glVertex2f(a,-b+95);
glVertex2f(-ta,tb+95);
glVertex2f(-a,b+95);
glVertex2f(-tb,ta+95);
glVertex2f(-b,a+95);
glVertex2f(-tb,-ta+95);
glVertex2f(-b,-a+95);
glVertex2f(-ta,-tb+95);
glVertex2f(-a,-b+95);
glVertex2f(a,b+95);
p=p+2*a+1-2*b;
}
dis(i,p,a,b);
i++;
}

glColor3f(1,2,8);
glEnd();
glFlush();
}
int main(int argc,char **argv){
printf("Enter the radius\n==> ");
scanf("%d",&r);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(40,100);
glutInitWindowSize(500,500);
glutCreateWindow("Rohnit");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
