#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
int fact(int i){
if(i==0){return 1;}
else if(i==1){return 1;}
else {return i*fact(i-1);}
}

int i,n,j[4],x[4],b[4][2]={{1,1},{20,3},{4,30},{3,1}},q;

float p[200],t,w[200];
void draw(void){
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-10,100,-10,100);
printf("1  Running\n");
for(i=0;i<4;i++){
x[i]=fact(3)/(fact(i)*fact(3-i));
printf("x[i]  =   %d\n",x[i]);
}
printf("\n\n\n");
q=0;
for(t=0;t<1;){
p[q]=0;
for(i=0;i<4;i++){
p[q]=p[q]+b[i][0]*x[i]*pow(t,i)*pow(i-t,3-i);
//printf("   p[q]=%d, x[i]=%d ,b[i][0]=%d ,ti=%f ,tin = %f\n",p[q],x[i],b[i][0],pow(t,i),pow(i-t,3-i));
}
printf("p[t]  =   %f\n",p[q]);

w[q]=0;
for(i=0;i<4;i++){
w[q]=w[q]+b[i][1]*x[i]*pow(t,i)*pow(i-t,3-i);
//printf("   p[q]=%d, x[i]=%d ,b[i][0]=%d ,ti=%f ,tin = %f\n",p[q],x[i],b[i][0],pow(t,i),pow(i-t,3-i));
}
printf("w[t]  =   %f\n",w[q]);

q++;
t=t+0.005;
}
glBegin(GL_POINTS);
glColor3ub(0,0,255);
for(i=0;i<199;i++){
glVertex2f(p[i],w[i]);
glVertex2f(p[i+1],w[i+1]);
}
glEnd();
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("500048459");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
