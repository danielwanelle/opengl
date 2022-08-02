#include <GL/glut.h>
#include <stdio.h>
// #include <string.h>

int rotate, rightLight, leftLight;
GLfloat luzAmbiente[4], luzDifusa[4], luzEspecular[4], posicaoLuz0[4], posicaoLuz1[4];
GLdouble size, eyex, eyey, eyez, angle, fAspect, zNear, zFar, alpha;

void PosicionaObservador(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
}

void EspecificaParametrosVisualizacao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, fAspect, 0.5, 500);
    PosicionaObservador();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    EspecificaParametrosVisualizacao();
}

void Teclado(unsigned char key, int x, int y)
{
    rotate = 0;

    switch (key)
    {
    case 103:
        rotate = 1;
        break;

    case 115:
        eyez += 10;
        break;

    case 119:
        eyez -= 10;
        break;

    case 100:
        eyex += 10;
        break;

    case 97:
        eyex -= 10;
        break;

    case 91:
        eyey += 10;
        break;

    case 93:
        eyey -= 10;
        break;

    case 61:
        alpha += 0.1;
        break;

    case 45:
        alpha -= 0.1;
        break;

    case 101:
        if (leftLight == 1)
        {
            leftLight = 0;
        }
        else
        {
            leftLight = 1;
        }
        break;

    case 113:
        if (rightLight == 1)
        {
            rightLight = 0;
        }
        else
        {
            rightLight = 1;
        }
        break;

    case 27:
        exit(0);
        break;
    }

    PosicionaObservador();
}

void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (leftLight == 1)
    {
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHT0);
    }
    if (rightLight == 1)
    {
        glEnable(GL_LIGHT1);
    }
    else
    {
        glDisable(GL_LIGHT1);
    }

    glColor4f(0.0, 0.0, 1.0, alpha);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (rotate == 1)
    {
        glRotatef(3.6, 0.0, 1.0, 0.0);
    }

    glutSolidTeapot(size);
    glutSwapBuffers();
}

void Inicializa(void)
{
    angle = 35.0f;
    fAspect = 0.0f;
    zNear = 1;
    zFar = 225;
    rotate = 0;
    size = 50.0f;
    eyex = 0;
    eyey = 80;
    eyez = 200;
    alpha = 1.0;
    rightLight = 1;
    leftLight = 1;
    GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
    GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
    GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat posicaoLuz0[4] = {250.0, 50.0, 50.0, 1.0};
    GLfloat posicaoLuz1[4] = {-250.0, 50.0, 50.0, 1.0};
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_SPECULAR, luzEspecular);
    glMateriali(GL_FRONT, GL_SHININESS, 60);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0);
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1);
    // glClearColor(0.5, 0.5, 0.5, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ex8");
    Inicializa();
    glutReshapeFunc(AlteraTamanhoJanela);
    glutIdleFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
}