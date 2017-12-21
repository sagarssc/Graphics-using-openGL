#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int a[8] = {0 ,0 ,0 ,300 ,300 ,300, 300, 0},c[8],b[2];

void rectangle(int a,int b,int c,int d,int e,int f,int g,int h){
glBegin(GL_POLYGON);
glColor3ub(0,100,200);
glVertex2f(a,b);
glVertex2f(c,d);
glVertex2f(e,f);
glVertex2f(g,h);
glEnd();
glFlush();
}


void translation(){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
c[0]=a[0]+b[0];c[4]=a[4]+b[0];
c[1]=a[1]+b[1];c[5]=a[5]+b[1];
c[2]=a[2]+b[0];c[6]=a[6]+b[0];
c[3]=a[3]+b[1];c[7]=a[7]+b[1];
glBegin(GL_POLYGON);
glColor3ub(0,255,0);
rectangle(c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7]);
glEnd();
glFlush();
}

void click(int button,int stack ,int x ,int y){
translation();
}

void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500);
glBegin(GL_POLYGON);
glColor3ub(0,100,200);
rectangle(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
glEnd();
glFlush();
}

int main(int argc,char **argv){
int i;
//printf("Enter the Rectangle coordinates :\n");
//for(i=0;i<8;i++){scanf("%d",&a[i]);}
printf("Enter Translation Matrix :\n");
for(i=0;i<2;i++){scanf("%d",&b[i]);}
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("500048459");
glutDisplayFunc(draw);
glutMouseFunc(click);
glutMainLoop();
return 0;
}
