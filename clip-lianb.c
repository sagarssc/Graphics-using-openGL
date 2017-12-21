#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
int i;
float x1=-15,x2=30,yz=-30,y2=60,xmn=0,xmx=15,ymn=0,ymx=20,p[4],q[4],u[4],a=0,b=1,xn1,xn2,yn1,yn2;
void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-10,50,-10,50);
p[0]=-1*(x2-x1);
p[1]=x2-x1;
p[2]=-1*(y2-yz);
p[3]=y2-yz;
q[0]=x1-xmn;
q[1]=xmx-x1;
q[2]=yz-ymn;
q[3]=ymx-yz;
for(i=0;i<4;i++){
u[i]=q[i]/p[i];
}
for(i=1;i<=4;i++){
if(p[i]<0){
if(u[i]>a){
a=u[i];}}
if(p[i]>0){
if(u[i]<b){
b=u[i];}}
}
xn1=x1+p[1]*a;
yn1=yz+p[3]*a;
xn2=x1+p[1]*b;
yn2=yz+p[3]*b;
glBegin(GL_LINES);
glVertex2f(xmn,ymn);
glVertex2f(xmn,ymx);
glVertex2f(xmn,ymx);
glVertex2f(xmx,ymx);
glVertex2f(xmx,ymx);
glVertex2f(xmx,ymn);
glVertex2f(xmx,ymn);
glVertex2f(xmn,ymn);
glColor3f(1,0,1);
glVertex2f(xn1,yn1);
glVertex2f(xn2,yn2);
glColor3f(1,5,8);
glEnd();
glFlush();
}
int main(int argc,char **argv){
/*printf("Enter the line coordinates\n");
scanf("%f  %f   %f    %f",&x1,&yz,&x2,&y2);
printf("Enter the clipping coordinates\n");
scanf("%f  %f   %f    %f",&xmn,&ymn,&xmx,&ymx);*/
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(60,35);
glutInitWindowSize(400,400);
glutCreateWindow("Shubham");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
