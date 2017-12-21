#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>

typedef struct pixel {GLubyte red,green,blue; }pixel;

void flood(float x,float y,pixel oldcolor,pixel fill){
pixel c;
glReadPixels(x ,y ,1 ,1 ,GL_RGB ,GL_UNSIGNED_BYTE, &c);
//printf("c = %d ,%d ,%d\n",(int)c.red,(int)c.green,(int)c.blue);
//printf("fill = %d ,%d ,%d\n",(int)fill.red,(int)fill.green,(int)fill.blue);
if(c.red == oldcolor.red && c.green == oldcolor.green && c.blue==oldcolor.blue){
glBegin(GL_POINTS);
glColor3ub(fill.red,fill.green,fill.blue);
glVertex2f(x,y);
//glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
glEnd();
glFlush();

flood(x+1,y,oldcolor,fill);
flood(x-1,y,oldcolor,fill);
flood(x,y+1,oldcolor,fill);
flood(x,y-1,oldcolor,fill);
}

}

void click(int button, int stack ,int x ,int y){

pixel fill,oldcolor;
 glReadPixels(250, 250, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &oldcolor);
 //printf("old %d,%d,%d\n",(int)oldcolor.red,(int)oldcolor.green,(int)oldcolor.blue);
 fill.red=0;
 fill.green=0;
 fill.blue=255;
 flood(250,250,oldcolor,fill);
glEnd();
glFlush();


}

void draw(void){
glClearColor(0,0,0,0);
glClear (GL_COLOR_BUFFER_BIT);

glLoadIdentity();
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500);
glBegin(GL_POLYGON);
glColor3ub(100,40,30);
glVertex2f(100,100);
glVertex2f(100,400);
glVertex2f(400,400);
glVertex2f(400,100);
glEnd();
glFlush();
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(40,110);
glutInitWindowSize(500,500);
glutCreateWindow("flood");
glutDisplayFunc(draw);
glutMouseFunc(click);
glutMainLoop();
return 0;
}
