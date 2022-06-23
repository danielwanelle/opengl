#include<stdint.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<GL/glut.h>

int h, v;
GLfloat x, y, passox, passoy;
GLsizei d;

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1,1,1,0);
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

void Inicializa(void) {
    x = 100.0f;
    y = 150.0f;
    d = 50;
    passox = 1.0f;
    passoy = 1.0f;
    h = 1;
    v = -1;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0.0f, 800, 0.0f, 600);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int value)
{
    // Muda (x,y) movendo o desenho
    // Cuidado para não ultrapassar os limites da janela
    if (h > 0 && x+2*d < 800.0f) {
        x += passox;
    } else if (h > 0 && x+2*d >= 800.0f) {
        x -= passox;
        h *= -1;
    } else {
        x -= passox;
    }

    if (v > 0 && y+d < 600.0f) {
        y += passoy;
    } else if (v > 0 && x+2*d >= 800.0f) {
        y -= passoy;
        v *= -1;
    } else {
        y -= passoy;
    }
    
    glutPostRedisplay(); //Redesenha
    glutTimerFunc(33,Timer, 1); //Aguarda 33 ms e volta
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(350, 100);
    glutCreateWindow("Ex3");
    glutIdleFunc(Desenha);
    Inicializa();
    glutMainLoop();
}