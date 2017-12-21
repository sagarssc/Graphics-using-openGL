#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
void cirlce(int ,int ,int );
void triangle(int a,int b,int c,int d,int e,int f);
void arrow(int a, int b,int c,int d,int e,int f,int g,int ,int ,int ,int ,int ,int ,int );
void circle(int r,int g,int h){

int a,b,x,y,p,ta,tb,i=0;
a=0,b=r;
x=a,y=b;
p=1-r;

glVertex2f(a+g,b+h);
while(a<b){
if(p<0){
ta=a;
tb=b;
a++;
glVertex2f(a+g,b+h);
glVertex2f(tb+g,ta+h);
glVertex2f(b+g,a+h);
glVertex2f(tb+g,-ta+h);
glVertex2f(b+g,-a+h);
glVertex2f(ta+g,-tb+h);
glVertex2f(a+g,-b+h);
glVertex2f(-ta+g,tb+h);
glVertex2f(-a+g,b+h);
glVertex2f(-tb+g,ta+h);
glVertex2f(-b+g,a+h);
glVertex2f(-tb+g,-ta+h);
glVertex2f(-b+g,-a+h);
glVertex2f(-ta+g,-tb+h);
glVertex2f(-a+g,-b+h);
glVertex2f(a+g,b+h);
p=p+2*a+1;
}
else if(p>0){
ta=a;
tb=b;
b--;
a++;
glVertex2f(a+g,b+h);
glVertex2f(tb+g,ta+h);
glVertex2f(b+g,a+h);
glVertex2f(tb+g,-ta+h);
glVertex2f(b+g,-a+h);
glVertex2f(ta+g,-tb+h);
glVertex2f(a+g,-b+h);
glVertex2f(-ta+g,tb+h);
glVertex2f(-a+g,b+h);
glVertex2f(-tb+g,ta+h);
glVertex2f(-b+g,a+h);
glVertex2f(-tb+g,-ta+h);
glVertex2f(-b+g,-a+h);
glVertex2f(-ta+g,-tb+h);
glVertex2f(-a+g,-b+h);
glVertex2f(a+g,b+h);
p=p+2*a+1-2*b;
}
}
glVertex2f(a+g,b+h);

}
void triangle(int a,int b,int c,int d,int e,int f){
glVertex2f(a,b);
glVertex2f(c,d);
glVertex2f(c,d);
glVertex2f(e,f);
glVertex2f(e,f);
glVertex2f(a,b);
}
void arrow(int a, int b,int c,int d,int e,int f,int g ,int h ,int i ,int j ,int k ,int l, int m, int n){
glVertex2f(a,b);glVertex2f(c,d);
glVertex2f(c,d);glVertex2f(e,f);
glVertex2f(e,f);glVertex2f(g,h);
glVertex2f(g,h);glVertex2f(i,j);
glVertex2f(i,j);glVertex2f(k,l);
glVertex2f(k,l);glVertex2f(m,n);
}

int j,i=0,x,y,r,a,b,p,ta,tb;
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-350,350,-350,350);
glBegin(GL_LINES);
glVertex2f(-200,200);glVertex2f(-200,-200);
glVertex2f(-200,200);glVertex2f(200,200);
glVertex2f(-200,-200);glVertex2f(200,-200);
glVertex2f(200,-200);glVertex2f(200,200);
circle(70,0,0);
arrow(15,120,15,90,25,90,0,75,-25,90,-15,90,-15,120);
arrow(-120,15,-90,15,-90,25,-75,0,-90,-25,-90,-15,-120,-15);
arrow(15,-120,15,-90,25,-90,0,-75,-25,-90,-15,-90,-15,-120);
arrow(120,15,90,15,90,25,75,0,90,-25,90,-15,120,-15);

triangle(-200,200,200,200,0,320);
triangle(-175,210,175,210,0,310);
triangle(-150,220,150,220,0,300);

triangle(-200,200,-200,-200,-320,0);
triangle(-210,175,-210,-175,-310,0);
triangle(-220,150,-220,-150,-300,0);

triangle(-200,-200,200,-200,0,-320);
triangle(-175,-210,175,-210,0,-310);
triangle(-150,-220,150,-220,0,-300);

triangle(200,200,200,-200,320,0);
triangle(210,175,210,-175,310,0);
triangle(220,150,220,-150,300,0);
circle(20,0,260);circle(20,-260,0);circle(20,0,-260);circle(20,260,0);

glColor3f(7,3,8);
glEnd();
glFlush();
}
int main(int argc,char **argv){

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(40,100);
glutInitWindowSize(500,500);
glutCreateWindow("Mt");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
