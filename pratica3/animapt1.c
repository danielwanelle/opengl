#include<GL/glut.h>

int gira;
GLfloat tx, ty, angulo, win;

void Desenha(void) {
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(100.0f, 150.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2i(150.0f, 200.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(200.0f, 150.0f);
    glEnd();
    if (gira == 1) {
        angulo += 0.1f;
        glRotatef(angulo, tx, ty, 1.0f);
    }

    glFlush();
}

void Inicializa(void) {
    tx = 0;
    ty = 0;
    angulo = 0;
    gira = 0;
    win = 1;
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void Teclado(unsigned char key, int x, int y) {
    switch (key)
    {
        case 'a':
        case 'A':
            glScalef(1.5f, 1.5f, 0.0f);
            break;
        case 'd':
        case 'D':
            glScalef(0.5, 0.5, 0.0);
            break;
        case 'g':
        case 'G':
            gira = 1;
            break;
        case 'r':
        case 'R':
            glRotatef(36, 0, 0, 0);
            break;
        case 'o':
        case 'O':
            tx = 0;
            ty = 0;
            angulo = 0;
            gira = 0;
            win = 1;
            glLoadIdentity();
        case 'p':
        case 'P':
            gira = 0;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y) {
    switch (key)
    {
        case GLUT_KEY_UP:
            ty = 1;
            tx = 0;
            break;
        case GLUT_KEY_DOWN:
            ty = -1;
            tx = 0;
            break;
        case GLUT_KEY_LEFT:
            tx = -1;
            ty = 0;
            break;
        case GLUT_KEY_RIGHT:
            tx = 1;
            ty = 0;
            break;
    }
    glTranslatef(tx,ty,0);
    glutPostRedisplay();
}

void GerenciaMouse(int button, int state, int x, int y) {
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) glScalef(1.5f, 1.5f, 0.0f);
            break;;
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) glScalef(0.5f, 0.5f, 0.0f);
            break;;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(350, 100);
    glutCreateWindow("Ex3");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(TeclasEspeciais);
    glutMouseFunc(GerenciaMouse);
    glutMainLoop();
}