#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14

GLfloat armstep = 0.0f;
GLfloat colorstep = 0.0f;
GLfloat udstep = 0.08f;
GLfloat lrstep = 0.73f;

int n =200;
void display()
{
    GLfloat tran[]=
    {
        cos(armstep), -sin(armstep), 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        sin(armstep), cos(armstep), 0.0f, 0.0f,
        lrstep, udstep, 0.0f, 1.0f
    };
    glClear( GL_COLOR_BUFFER_BIT );


//glTranslated(step, udstep, 0.0f);
//glMultMatrixf(tran);
//glScalef(step,step,1.0f);
//glRotatef(step*180/PI,1.0f,0.0f,0.0f);
//glRotatef(step*55/PI,0.0f,0.0f,1.0f);

  //  glTranslatef(0.2f,0.2f,0.0f);
   // glRotatef(step*180/PI, 0.0f, 0.0f, 1.0f);
//glTranslatef(0.2f,0.2f,0.0f);

    glPushMatrix();

    glTranslatef(lrstep-0.73,udstep-0.08,0);

    glColor3f(1.0f,1.0f,0);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.25*cos(2*i*PI/n)-0.5,0.07*sin(2*i*PI/n)+0.08);//上左手臂

    }
    glEnd();

    glColor3f(1.0f,1.0f,0);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.25*cos(2*i*PI/n)+0.5,0.07*sin(2*i*PI/n)+0.08);//上右手臂

    }
    glEnd();

    glColor3f(0.1f,0.5f,0.9f);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.3*cos(2*i*PI/n),0.5*sin(2*i*PI/n)-0.15);

    }
    glEnd();




    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.2,0.6);
    glVertex2f(-0.2,0.6);
    glEnd();

    glColor3f(colorstep,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.15,0.45);
    glVertex2f(-0.05,0.45);
    glVertex2f(-0.05,0.52);
    glVertex2f(-0.15,0.52);
    glEnd();

    glColor3f(colorstep,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.15,0.45);
    glVertex2f(0.05,0.45);
    glVertex2f(0.05,0.52);
    glVertex2f(0.15,0.52);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.13,0.37);
    glVertex2f(0.13,0.37);
    glVertex2f(0,0.39);
    glEnd();

    glPushMatrix();
    glTranslatef(-lrstep,udstep,0);
    glRotatef(armstep*180/PI, 0.0f, 0.0f, 1.0f);//test
    glTranslatef(lrstep,-udstep,0);
    glColor3f(1,0,1);
    glBegin(GL_TRIANGLES);//左手爪子
    glVertex2f(0-0.75,0+0.45);
    glVertex2f(-0.1-0.75,0.05+0.45);
    glVertex2f(-0.1-0.75,0.2+0.45);
    glVertex2f(0-0.75,0+0.45);
    glVertex2f(0.1-0.75,0.05+0.45);
    glVertex2f(0.1-0.75,0.2+0.45);
    glEnd();

    glColor3f(1.0f,1.0f,0);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.07*cos(2*i*PI/n)-0.75,0.2*sin(2*i*PI/n)+0.28);//下左手臂

    }
    glEnd();



     glColor3f(0.98f,0.625f,0.12f);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.07*cos(2*i*PI/n)-0.73,0.07*sin(2*i*PI/n)+0.08);//上左手肘

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lrstep,udstep,0);
    glRotatef(-armstep*180/PI, 0.0f, 0.0f, 1.0f);//test
    glTranslatef(-lrstep,-udstep,0);

    glColor3f(1,0,1);
    glBegin(GL_TRIANGLES);//右手爪子
    glVertex2f(0+0.75,0+0.45);
    glVertex2f(-0.1+0.75,0.05+0.45);
    glVertex2f(-0.1+0.75,0.2+0.45);
    glVertex2f(0+0.75,0+0.45);
    glVertex2f(0.1+0.75,0.05+0.45);
    glVertex2f(0.1+0.75,0.2+0.45);
    glEnd();

    glColor3f(1.0f,1.0f,0);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.07*cos(2*i*PI/n)+0.75,0.2*sin(2*i*PI/n)+0.28);//下右手臂

    }
    glEnd();

    glColor3f(0.98f,0.625f,0.12f);
    glBegin( GL_TRIANGLE_FAN );
    for(int i = 0; i<n; i++){
       glVertex2f(0.07*cos(2*i*PI/n)+0.73,0.07*sin(2*i*PI/n)+0.08);//上右手肘

    }
    glEnd();
    glPopMatrix();

    glColor3f(colorstep,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);

	//以下ABCDE分别是五角星的5个顶点
	glVertex2f(0.25*cos(90*2*PI/360),0.25*sin(90*2*PI/360));
	glVertex2f(0.25*cos(306*2*PI/360),0.25*sin(306*2*PI/360));
	glVertex2f(0.25*cos(162*2*PI/360),0.25*sin(162*2*PI/360));
	glVertex2f(0.25*cos(18*2*PI/360),0.25*sin(18*2*PI/360));
	glVertex2f(0.25*cos(234*2*PI/360),0.25*sin(234*2*PI/360));
	glEnd();

	glBegin(GL_LINE_LOOP);
	for(int i = 0; i<n; i++){
       glVertex2f(0.25*cos(2*i*PI/n),0.25*sin(2*i*PI/n));//下右手臂

    }
    glEnd();


    glPopMatrix();

    glFlush();
}
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT)
        lrstep -= 0.1f;
    if(key == GLUT_KEY_RIGHT)
        lrstep += 0.1f;

    if(key == GLUT_KEY_UP)
        udstep += 0.1f;
    if(key == GLUT_KEY_DOWN)
        udstep -= 0.1f;


    glutPostRedisplay();
}
void NormalKeys(unsigned char key, int x, int y)
{
    if(key == 'w')
        colorstep += 0.2f;
    if(key == 's')
        colorstep -= 0.2f;
    if(key == 'a')
        armstep -= 0.1f;
    if(key == 'd')
        armstep += 0.1f;
    glutPostRedisplay();
}



int main( int argc, char ** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition( 150, 150 );
    glutInitWindowSize( 400, 400 );
    glutCreateWindow( "OpenGL Examples!" );
    glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(NormalKeys);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
