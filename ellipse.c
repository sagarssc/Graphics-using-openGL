#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
int a,b,j,k,u,v,x,y,p1,p2,tx,ty;
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250,250,-250,250);
x=0;y=b;
p1=b*b-a*a*b+((a*a)/4);
j=2*(b*b)*x;
k=2*(a*a)*y;
glBegin(GL_LINES);
glVertex2f(-250,0);
glVertex2f(250,0);
glVertex2f(0,-250);
glVertex2f(0,250);
glVertex2f(x,y);
while(k >= j)
{
tx=x;
ty=y;
if(p1<0){
x++;
glVertex2f(x,y);
glVertex2f(-tx,ty);
glVertex2f(-x,y);
glVertex2f(-tx,-ty);
glVertex2f(-x,-y);
glVertex2f(tx,-ty);
glVertex2f(x,-y);
glVertex2f(x,y);
p1=p1+2*(b*b)*x+b*b;
}
else{
x++;
y--;
glVertex2f(x,y);
glVertex2f(-tx,ty);
glVertex2f(-x,y);
glVertex2f(-tx,-ty);
glVertex2f(-x,-y);
glVertex2f(tx,-ty);
glVertex2f(x,-y);
glVertex2f(x,y);
p1=p1+2*(b*b)*x-2*(a*a)*y+b*b;
}
j=2*(b*b)*x;
k=2*(a*a)*y;
}
p2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
u=2*(b*b)*x;
v=2*(a*a)*y;
while(y!=0)
{
tx=x;
ty=y;
if(p2>0){
y--;
glVertex2f(x,y);
glVertex2f(-tx,ty);
glVertex2f(-x,y);
glVertex2f(-tx,-ty);
glVertex2f(-x,-y);
glVertex2f(tx,-ty);
glVertex2f(x,-y);
glVertex2f(x,y);
p2=p2-2*a*a*y+a*a;
}
else{
x++;
y--;
glVertex2f(x,y);
glVertex2f(-tx,ty);
glVertex2f(-x,y);
glVertex2f(-tx,-ty);
glVertex2f(-x,-y);
glVertex2f(tx,-ty);
glVertex2f(x,-y);
glVertex2f(x,y);
p2=p2+2*(b*b)*x-2*(a*a)*y+a*a;
}
u=2*(b*b)*x;
v=2*(a*a)*y;
}
glColor3f(1,0,9);
glEnd();
glFlush();
}
int main(int argc,char **argv){
printf("Enter the Eclipese parameters\na==>");
scanf("%d",&a);
printf("\nb==>");
scanf("%d",&b);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(60,35);
glutInitWindowSize(200,400);
glutCreateWindow("Rohnit");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
