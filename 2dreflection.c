#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int i,a[4][2]={{-40,70},{40,70},{40,150},{-40,150}},b[2][2]={{0,1},{1,0}},c[4][2];

void reflection(){
for(i=0;i<4;i++){
c[i][0]=a[i][0]*b[0][0]+a[i][1]*b[1][0];
c[i][1]=a[i][0]*b[0][1]+a[i][1]*b[1][1];
//printf("%d   %d\n",c[i][0],c[i][1]);
}

glBegin(GL_POLYGON);
glColor3ub(0,0,255);
for(i=0;i<4;i++){
glVertex2f(c[i][0],c[i][1]);}
glEnd();

}
void onclick(){
reflection();
glFlush();
}

void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);
glBegin(GL_POLYGON);
glColor3ub(255,0,0);
for(i=0;i<4;i++){
glVertex2f(a[i][0],a[i][1]);}
glEnd();
glBegin(GL_LINES);
glColor3ub(0,255,0);
glVertex2f(-450,-450);
glVertex2f(450,450);
glEnd();
glFlush();
}

int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("50048459");
glutDisplayFunc(draw);
glutMouseFunc(onclick);
glutMainLoop();
return 0;
}
