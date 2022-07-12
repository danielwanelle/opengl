#include <GL/glut.h>
// #include <stdio.h>
// #include <string.h>

// GLfloat rotate;
// int shape, color, pressed, shapeName;
// char texto[50];

GLdouble angle, fAspect, eyex, eyey, eyez;

// void defineCor(void)
// {
//     switch (color)
//     {
//     case 0:
//         glColor3f(1.0, 0.0, 0.0);
//         break;
//     case 1:
//         glColor3f(0.0, 1.0, 0.0);
//         break;
//     case 2:
//         glColor3f(0.0, 0.0, 1.0);
//         break;
//     default:
//         glColor3f(1.0, 0.0, 0.0);
//         break;
//     }
// }

// void triangulo()
// {
//     glBegin(GL_TRIANGLES);
//     defineCor();
//     glVertex2i(-50, -50);
//     glVertex2i(0, 50);
//     glVertex2i(50, -50);
//     glEnd();
// }

// void quadrado()
// {
//     glBegin(GL_QUADS);
//     defineCor();
//     glVertex2i(-50, -50);
//     glVertex2i(-50, 50);
//     glVertex2i(50, 50);
//     glVertex2i(50, -50);
//     glEnd();
// }

// void losango()
// {
//     glBegin(GL_QUADS);
//     defineCor();
//     glVertex2i(0, -50);
//     glVertex2i(-50, 0);
//     glVertex2i(0, 50);
//     glVertex2i(50, 0);
//     glEnd();
// }

// void DesenhaTexto(char *texto)
// {
//     glPushMatrix();
//     glRasterPos2f(-320.0, 230.0);
//     while (*texto)
//         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *texto++);
//     glFlush();
//     glPopMatrix();
// }

// void Sub1(int op)
// {
//     glPushMatrix();
//     shapeName = op;
//     glutPostRedisplay();
//     glPopMatrix();
// }

// void Sub2(int op)
// {
//     color = op;
//     glutPostRedisplay();
// }

// void Sub3(int op)
// {
//     if (op == 0)
//     {
//         switch (shapeName)
//         {
//         case 0:
//             strcpy(texto, "Quadrado");
//             break;

//         case 1:
//             strcpy(texto, "Triangulo");
//             break;

//         case 2:
//             strcpy(texto, "Losango");
//             break;
//         }
//         glutPostRedisplay();
//     }
//     else if (op == 1)
//     {
//         glRotatef(36.0, 0.0, 0.0, 1.0);
//         glutPostRedisplay();
//     }
// }

// void MenuPrincipal(int op)
// {
//     return;
// }

// void CriaMenu()
// {
//     int menu, submenu1, submenu2, submenu3;
//     submenu1 = glutCreateMenu(Sub1);
//     glutAddMenuEntry("Quadrado", 0);
//     glutAddMenuEntry("Triangulo", 1);
//     glutAddMenuEntry("Losango", 2);
//     submenu2 = glutCreateMenu(Sub2);
//     glutAddMenuEntry("Vermelho", 0);
//     glutAddMenuEntry("Verde", 1);
//     glutAddMenuEntry("Azul", 2);
//     submenu3 = glutCreateMenu(Sub3);
//     glutAddMenuEntry("Exibir nome da figura", 0);
//     glutAddMenuEntry("Rotacionar", 1);
//     menu = glutCreateMenu(MenuPrincipal);
//     glutAddSubMenu("Tipo de Figura", submenu1);
//     glutAddSubMenu("Mudar Cor", submenu2);
//     glutAddSubMenu("Outros", submenu3);
//     glutAttachMenu(GLUT_RIGHT_BUTTON);
// }

// void MoverBotaoPressionado(int x, int y)
// {
//     if (pressed == 1)
//     {
//         sprintf(texto, "Mouse pressionado: (%d, %d)", x, y);
//         glutPostRedisplay();
//     }
// }

// void MovendoMouse(int x, int y)
// {
//     sprintf(texto, "Posicao Atual: (%d, %d)", x, y);
//     glutPostRedisplay();
// }

// void GerenciaMouse(int button, int state, int x, int y)
// {
//     if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//     {
//         CriaMenu();
//     }
//     else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//     {
//         pressed = 1;
//     }
//     else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//     {
//         pressed = 0;
//     }
// }

void Desenha(void)
{
    // glClear(GL_COLOR_BUFFER_BIT);
    // DesenhaTexto(texto);
    // if (shapeName == 0)
    // {
    //     quadrado();
    // }
    // else if (shapeName == 1)
    // {
    //     triangulo();
    // }
    // else if (shapeName == 2)
    // {
    //     losango();
    // }
    // glFlush();
}

voidEspecificaParametrosVisualizacao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, fAspect, 0.5, 500);
    PosicionaObservador();
}

voidPosicionaObservador(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
}

void Inicializa(void)
{
    // shape = 0;
    // color = 0;
    // pressed = 0;
    // shapeName = 0;
    // rotate = 0.0;
    // strcpy(texto, "");
    // gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
    // glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ex7");
    Inicializa();
    glutDisplayFunc(Desenha);
    // glutMouseFunc(GerenciaMouse);
    // glutPassiveMotionFunc(MovendoMouse);
    // glutMotionFunc(MoverBotaoPressionado);
    glutMainLoop();
}