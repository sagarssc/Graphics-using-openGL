#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
int gettbrl(int *,int *,int ,int ,int ,int ,int );
int dis(int *,int *);
int xl1=0,xl2=50,yl1=0,yl2=30,x[2],y[2],a[2],b[2],tbrl[2],t;
int i;
int gettbrl(int *x,int *y,int n,int xl1,int xl2,int yl1,int yl2){
int i,tbrl[2];
  for(i=0;i<2;i++){
  if(x[i]<=xl1 && y[i]<=yl2 || x[i]<=xl1 && y[i]>=yl1){
  tbrl[i]=1;
  }
  else if(x[i]<=xl1 && y[i]<yl1){
  tbrl[i]=5;
  }
  else if(x[i]<=xl1 && y[i]>yl2){
  tbrl[i]=9;
  }

  else if(y[i]>=yl2 && x[i]>=xl1 || x[i]<=xl2){
  tbrl[i]=8;
  }
  else if(x[i]>=xl2 && y[i]>=yl2){
  tbrl[i]=10;
  }
  else if(x[i]>=xl2 && y[i]<yl2 && y[i]>=yl1){
  tbrl[i]=2;
  }

  else if(x[i]>xl2 && y[i]<yl1){
  tbrl[i]=6;
  }
  else if(y[i]<yl1 && x[i]<xl2 && x[i]>xl1){
  tbrl[i]=4;
  }
  }
  return tbrl[n];
}
int dis(int *a,int *b){
int i;
for(i=0;i<2;i++){
printf("%d	%d\n",a[i],b[i]);}
}
void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-20,60,-20,60);
x[0]=-10;y[0]=0;x[1]=40;y[1]=50;
  for(i=0;i<2;i++){
  tbrl[i]=gettbrl(x,y,i,xl1,xl2,yl1,yl2);
   }
 t=(y[1]-y[0])/(x[1]-x[0]);
 
 for(i=0;i<2;i++){

  if(tbrl[i]==1){
  b[i]=t*(xl1-x[i])+y[i];
  a[i]=xl1;
  }

  else if(tbrl[i]==2){
  b[i]=t*(xl2-x[i])+y[i];
  a[i]=xl1;
  }

  else if(tbrl[i]==4){
  a[i]=x[i]+((yl1-y[i])/t);
  b[i]=yl1;
  }

  else if(tbrl[i]==5){
  b[i]=t*(xl1-x[i])+y[i];
  a[i]=xl1;
  if(b[i]<yl1){
  a[i]=x[i]+((yl1-y[i])/t);
  b[i]=yl1;}
  }

  else if(tbrl[i]==6){
  b[i]=t*(xl2-x[i])+y[i];
  a[i]=xl1;
  if(b[i]<yl1){
  a[i]=x[i]+((yl1-y[i])/t);
  b[i]=yl1;}
  }

  else if(tbrl[i]==8){
  a[i]=x[i]+((yl2-y[i])/t);
  b[i]=yl2;
  }

  if(tbrl[i]==9){
  b[i]=t*(xl1-x[i])+y[i];
  a[i]=xl1;
  if(b[i]>yl2){
  a[i]=x[i]+((yl2-y[i])/t);
  b[i]=yl2;}
  }

  else if(tbrl[i]==10){
  b[i]=t*(xl2-x[i])+y[i];
  a[i]=xl1;
  if(b[i]>yl2){
  a[i]=x[i]+((yl2-y[i])/t);
  b[i]=yl2;}
  }
 }

dis(a,b);
glBegin(GL_LINES);
glVertex2f(xl1,yl1);
glVertex2f(xl1,yl2);
glVertex2f(xl1,yl2);
glVertex2f(xl2,yl2);
glVertex2f(xl2,yl2);
glVertex2f(xl2,yl1);
glVertex2f(xl2,yl1);
glVertex2f(xl1,yl1);
glColor3f(1,0,8);
glVertex2f(a[0],b[0]);
glVertex2f(a[1],b[1]);
glColor3f(2,4,8);
glEnd();
glFlush();
}
int main(int argc,char **argv){/*
printf("enter the cliping windows lines equation\n");
printf("x1=");
scanf("%d",&xl1);
printf("\ny1=");
scanf("%d",&yl1);
printf("\nx2=");
scanf("%d",&xl2);
printf("\ny2=");
scanf("%d",&yl2);
printf("\n\nenter the line starting and ending pt.\n");
scanf("%d %d %d %d",&x[0],&y[0],&x[1],&y[1]);*/
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
glutInitWindowPosition(80,80);
glutInitWindowSize(600,600);
glutCreateWindow("Shubham");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
