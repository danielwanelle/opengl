#include <GL/glut.h>
#include <stdio.h>
// #include <string.h>

int tipofigura, rotate;
GLint rings, nsides, slices, stacks;
GLdouble size, radius, height, innerRadius, outerRadius, eyex, eyey, eyez, red, green, blue, angle, fAspect, zNear, zFar, scale;

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
    gluPerspective(angle, fAspect, zNear, zFar);
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

    case 54:
        red = 1;
        green = 0;
        blue = 0;
        break;

    case 55:
        red = 0;
        green = 1;
        blue = 0;
        break;

    case 56:
        red = 0;
        green = 0;
        blue = 1;
        break;

    case 57:
        scale = 1.5;
        break;

    case 48:
        scale = 0.5;
        break;

    case 103:
        rotate = 1;
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
}

void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(red, green, blue);
    glScalef(scale, scale, scale);
    if (rotate == 1)
    {
        glRotatef(3.6, 0.0, 1.0, 0.0);
    }

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
    glutSwapBuffers();
    scale = 1.0;
}

void Inicializa(void)
{
    tipofigura = 1;
    angle = 35.0f;
    fAspect = 0.0f;
    zNear = 0.5;
    zFar = 500;
    scale = 1.0;
    rotate = 0;
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
    red = 0;
    green = 0;
    blue = 1;
    glClearColor(1, 1, 1, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ex7");
    Inicializa();
    glutReshapeFunc(AlteraTamanhoJanela);
    glutIdleFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
}