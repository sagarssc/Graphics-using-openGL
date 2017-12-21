#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int n,i,a[4][2]={{-40,70},{40,70},{40,150},{-40,150}},b[2][2],c[4][2];

void Shear(){
if(n==1){
b[0][0]=1;
b[0][1]=0;
b[1][0]=1;
b[1][1]=1;
}
else if(n==2){
b[0][0]=1;
b[0][1]=1;
b[1][0]=0;
b[1][1]=1;
}
else if(n==3){
b[0][0]=1;
b[0][1]=0;
b[1][0]=-1;
b[1][1]=1;
}
else if(n==4){
b[0][0]=1;
b[0][1]=-1;
b[1][0]=0;
b[1][1]=1;
}
for(i=0;i<4;i++){
c[i][0]=a[i][0]*b[0][0]+a[i][1]*b[1][0];
c[i][1]=a[i][0]*b[0][1]+a[i][1]*b[1][1];
//printf("%d   %d\n",c[i][0],c[i][1]);
}
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);
glColor3ub(0,0,255);
for(i=0;i<4;i++){
glVertex2f(c[i][0],c[i][1]);}
glEnd();

}
void onclick(){
Shear();
glFlush();
}

void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-200,200,-200,200);
glBegin(GL_POLYGON);
glColor3ub(255,0,0);
for(i=0;i<4;i++){
glVertex2f(a[i][0],a[i][1]);}
glEnd();
glFlush();
}

int main(int argc,char **argv){
printf("\n\n===>1:x-Shear\n    2:Y-Shear\n    3:-X-Shear\n    4:-Y-Shear\n");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("500048459");
glutDisplayFunc(draw);
glutMouseFunc(onclick);
glutMainLoop();
return 0;
}
