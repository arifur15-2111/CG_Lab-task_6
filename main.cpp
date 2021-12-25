#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
}


void Draw()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 0.1 ,0.1, 0.1);



   double x0=0, y0=0+70, r=70;
   glBegin(GL_POLYGON);
   glVertex2d(x0,y0);

   double dp0=1-r;
   double dp_new;

   while(1){
    if(dp0<0){
        x0++;
        dp_new=dp0+2*x0+1;
    }
    else if(dp0>=0){
        x0++;
        y0--;
        dp_new=dp0+2*x0-2*y0+1;
    }
    dp0=dp_new;
    glVertex2d(x0,y0);
    glVertex2d(-x0,y0);
    glVertex2d(x0,-y0);
    glVertex2d(-x0,-y0);

    glVertex2d(y0,x0);
    glVertex2d(-y0,x0);
    glVertex2d(y0,-x0);
    glVertex2d(-y0,-x0);

    if(x0>=y0){
        break;
    }
   }

   glEnd();
   glFlush();


glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Task: 6, ID : 182-15-2111");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
