#include<GL/glut.h>

int h, v;
GLfloat x, y, passox, passoy;
GLsizei d;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(x,y);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2i(x+d,y+d);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(x+d+d,y);
    glEnd();
    glutSwapBuffers();
}

void Timer(int value)
{
    if (h == 1 && x+2*d < 800.0f) {
        x += passox;
    } else if (h == 1 && x+2*d >= 800.0f) {
        x -= passox;
        h = 0;
    } else if (h == 0 && x <= 0.0f) {
        x += passox;
        h = 1;
    } else {
        x -= passox;
    }

    if (v == 1 && y+d < 600.0f) {
        y += passoy;
    } else if (v == 1 && y+d >= 600.0f) {
        y -= passoy;
        v = 0;
    } else if (v == 0 && y <= 0.0f) {
        y += passoy;
        v = 1;
    } else {
        y -= passoy;
    }
    
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}

void Inicializa(void) {
    x = 100.0f;
    y = 150.0f;
    d = 50;
    passox = 1.0f;
    passoy = 1.0f;
    h = 1;
    v = 0;
    gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(350, 100);
    glutCreateWindow("Ex4");
    Inicializa();
    glutIdleFunc(Desenha);
    glutTimerFunc(33,Timer, 1);
    glutMainLoop();
}