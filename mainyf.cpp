#include <windows.h>
#include <GL/glut.h>

//ȫ�ֱ���
GLuint hand,foot,body,head,neck,robot;

//�ֲ�����
GLfloat bodyRotate= 0.0, LeftHandRotate = 15.0,RightHandRotate = 15.0, headRotate=0.0;

void init(void)
{
    glEnable(GL_LIGHTING);//ʹ�õƹ�
    glEnable(GL_LIGHT0);//ʹ��Ĭ�ϵ���ŵ�
    glEnable(GL_COLOR_MATERIAL);//������ɫ����

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);//���ú㶨��ɫ

    head = glGenLists(1);
    body = glGenLists(1);
    hand = glGenLists(1);
    foot = glGenLists(1);
    neck = glGenLists(1);
    robot = glGenLists(1);
    //�����б�



    //ͷ����list
    glNewList(head, GL_COMPILE);
    glShadeModel(GL_SMOOTH);
    //ѹ��ջ��
    glPushMatrix();//!!!!
    glScalef(1.8f, 1.8f, 1.8f);//����
    glutSolidSphere(0.75, 50, 50);//������

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glScalef(0.100f, 0.1009f, 0.100f);
    glTranslatef(-3.0f,0,0); //ƽ��
    glutSolidSphere(0.75, 50, 50);//������

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glScalef(0.10f, 0.10f, 0.10f);

    glTranslatef(50,0,0);
    glutSolidSphere(7, 50, 50);
    glPopMatrix();
    glEndList();

    //����
    glNewList(neck, GL_COMPILE);
    glPushMatrix();
    glScalef(2.0f, 2.0f, 2.0f);
    glTranslatef(0.01f,-2.25,0);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(2.0f, 1.5f, 0.5f);
    gluCylinder(quadratic,0.1f,0.1f,0.80f,32,32);
    glPopMatrix();
    glEndList();

    //��body����list
    glNewList(body, GL_COMPILE);
    glPushMatrix();
    glColor4f(0.0, 0.0, 1.0, 1.0);
    glScalef(2.5f, 5.5f, 1.0f);
    GLUquadricObj *quadratic2;
    quadratic2 = gluNewQuadric();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(2.0f, 1.5f, 0.5f);

    glBegin;

    gluCylinder(quadratic2,0.270f,0.270f,2.0f,50,50);
    glEnd();
    glPopMatrix();
    glEndList();

    //���ַ���list��
    glNewList(hand, GL_COMPILE);
    glPushMatrix();
    glTranslatef(0.0f, -1.5f, 0.0f);
    glScalef(1.0f, 2.0f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();
    glEndList();

    //�ѽŷ���list��
    glNewList(foot, GL_COMPILE);
    glPushMatrix();
    glTranslatef(0.0f, -1.975f, 0.0f);
    glScalef(1.0f, 5.0f, 1.0f);
    GLUquadricObj *quadratic3;
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.8f, 1.5f, 0.5f);
    glBegin;
    gluCylinder(quadratic2,0.270f,0.270f,2.0f,50,50);
    glEnd();
    glPopMatrix();
    glEndList();
}

void display(void)
{
    GLfloat position[] =
    {2.5, 2.5, 0.0, 0.0};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

//	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();  /*clear the matrix */

    /*viewing transformation*/
    gluLookAt(0.5,0, 10, 0.0, 3.0, 0.0, 0.0, 1.0, 0.0);


    glPushMatrix(); ///
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glRotatef(bodyRotate, 0.0, 1.0, 0.0);
    glEnable(GL_LIGHTING);
    // ��

    glColor3f(0.1, 0.7, 0.1);
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    //������ת���
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    //����callList����Ū�ҽ�
    glCallList(foot);
    glPopMatrix();

    //������ת�ҽ�
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.0f);

    //����callList����Ū�ҽ�
    glCallList(foot);
    glPopMatrix();
    glPopMatrix();

    //����
    glColor3f(0.45, 0.0, 1.0);

    glPushMatrix();
    glTranslatef(0.0f, 4.5f, 0.0f);
    //������ת����
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);
    //����callList����ȥŪ����
    glRotatef(LeftHandRotate, 1.0, 0.0, 0.0);
    glCallList(hand);
    glTranslatef(0.0f, -2.2f, 0.0f);
    glCallList(hand);
    glPopMatrix();
    //������ת����
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glRotatef(RightHandRotate, 1.0, 0.0, 0.0);
    //����callList����ȥŪ����
    glCallList(hand);
    glTranslatef(0.0f, -2.2f, 0.0f);
    glCallList(hand);
    glPopMatrix();
    glPopMatrix();

    //����
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0f, 4.70f, 0.0f);
    //����callList����ȥŪ����
    glCallList(body);
    glPopMatrix();

    //����
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, 0.0f);
    glCallList(neck);
    glPopMatrix();

    //ͷ
    glColor3f(0.9, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(0.0f, 6.75f, 0.0f);
    glRotatef(headRotate, 0.0, 1.0, 0.0);
    //����callList����ȥŪͷ
    glCallList(head);
    glPopMatrix();

    glPopMatrix(); ///
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
    if(key == 'd')
    {
        RightHandRotate = RightHandRotate + 20.0;
        if (RightHandRotate> 360.0)
            RightHandRotate = 0.5;
    }
    if(key == 'a')
    {
        LeftHandRotate += 20.0;
        if(LeftHandRotate > 360.0)
            LeftHandRotate = 0.5;
    }
    if(key == 'w')
    {
        bodyRotate += 20.0;
    }
    if(key == 's')
    {
        bodyRotate -= 20.0;
    }
    if(key == 'q')
    {
        headRotate += 20.0;
    }
    if(key == 'e')
    {
        headRotate -= 20.0;
    }
    glutPostRedisplay();
}//ָ��������������

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
