#include<GL/glut.h>

GLfloat scale, position;
int side;

void triangulo(GLfloat red, GLfloat green, GLfloat blue, GLint x, GLint y, GLint d) {
    glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);
        glVertex2i(x, y);
        glVertex2i(x+d, y+d);
        glVertex2i(x+2*d, y);
    glEnd();
}

void Desenha1(void) {
    glTranslatef(0,position,0);
    triangulo(1.0, 0.0, 0.0, 100, 0, 50);
    glFlush();
}

void Desenha2(void) {
    glScalef(scale, scale, 0.0);
    triangulo(0.0, 0.0, 1.0, -200, 0, 50);
    glFlush();
}

void Inicializa(void) {
    glMatrixMode(GL_MODELVIEW);
    scale = 1.0;
    side = 0;
    position = 0.0;
    gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
}

void Teclado(unsigned char key, int x, int y) {
    glPushMatrix();
    
    switch (key)
    {
        case 'a':
        case 'A':
            scale += 0.1;
            side = -1;
            break;
        case 'd':
        case 'D':
            scale -= 0.1;
            side = -1;
            break;
        case 'b':
        case 'B':
            position -= 1.0;
            side = 1;
            break;
        case 'c':
        case 'C':
            position += 1.0;
            side = 1;
            break;
        case 'o':
        case 'O':
            scale = 1.0;
            side = 0;
            position = 0.0;
            break;
        case 27:
            exit(0);
            break;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    if (side > 0) {
        Desenha1();
        glPopMatrix();
        glPushMatrix();
        Desenha2();
    } else if (side < 0) {
        Desenha2();
        glPopMatrix();
        glPushMatrix();
        Desenha1();
    } else {
        glPushMatrix();
        Desenha1();
        Desenha2();
        glLoadIdentity();
    }

        glPopMatrix();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(350, 100);
    glutCreateWindow("Ex5");
    Inicializa();
    Desenha1();
    Desenha2();
    glutKeyboardFunc(Teclado);
    glutMainLoop();
}