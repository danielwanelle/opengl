#include <GL/glut.h>
#include <stdio.h>
// #include <string.h>

int tipofigura;
GLint rings, nsides, slices, stacks;
GLdouble size, radius, height, innerRadius, outerRadius, eyex, eyey, eyez, angle, fAspect, eyex, eyey, eyez;

void PosicionaObservador(void)
{
    puts("Posiciona observador");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
}

void EspecificaParametrosVisualizacao(void)
{
    puts("Especifica parametros");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, fAspect, 0.5, 500);
    PosicionaObservador();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    puts("Altera o tamanho da janela");
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    EspecificaParametrosVisualizacao();
}

void Teclado(unsigned char key, int x, int y)
{
    printf("Key %d", key);
    if (tipofigura == 3 || tipofigura == 4)
    {
        switch (key)
        {
        case 117:
            slices += 1;
            break;

        case 105:
            slices -= 1;
            break;

        case 111:
            stacks += 1;
            break;

        case 112:
            stacks -= 1;
            break;
        }
    }
    else if (tipofigura == 5)
    {
        switch (key)
        {
        case 110:
            nsides += 1;
            break;

        case 109:
            nsides -= 1;
            break;

        case 114:
            rings += 1;
            break;

        case 121:
            rings -= 1;
            break;
        }
    }

    switch (key)
    {
    case 49:
        tipofigura = 1;
        break;

    case 50:
        tipofigura = 2;
        break;

    case 51:
        tipofigura = 3;
        break;

    case 52:
        tipofigura = 4;
        break;

    case 53:
        tipofigura = 5;
        break;

    case 102:
        eyez += 1;
        break;

    case 116:
        eyez -= 1;
        break;

    case 100:
        eyex += 1;
        break;

    case 101:
        eyex -= 1;
        break;

    case 99:
        eyey += 1;
        break;

    case 98:
        eyey -= 1;
        break;

    case 27:
        exit(0);
        break;
    }

    PosicionaObservador();
    glutPostRedisplay();
}

void Desenha(void)
{
    switch (tipofigura)
    {
    case 1:
        glutWireTeapot(size);
        break;

    case 2:
        glutWireCube(size);
        break;

    case 3:
        glutWireSphere(radius, slices, stacks);
        break;

    case 4:
        glutWireCone(size, height, slices, stacks);
        break;

    case 5:
        glutWireTorus(innerRadius, outerRadius, nsides, rings);
        break;
    }
}

void Inicializa(void)
{
    tipofigura = 1;
    angle = 35.0f;
    fAspect = 0.0f;
    rings = 6;
    nsides = 20;
    slices = 20;
    stacks = 10;
    size = 50.0f;
    radius = 25.0f;
    height = 50.0f;
    innerRadius = 25.0f;
    outerRadius = 25.0f;
    eyex = 0;
    eyey = 0;
    eyez = -200;
    AlteraTamanhoJanela(640, 480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ex7");
    Inicializa();
    glutIdleFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
}