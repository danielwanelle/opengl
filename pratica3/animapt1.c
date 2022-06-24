#include<stdint.h>
// #include<GL/gl.h>
// #include<GL/glu.h>
#include<GL/glut.h>

int gira;
GLfloat tx, ty, angulo, win;

void Desenha(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(100.0f, 150.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2i(150.0f, 200.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(200.0f, 150.0f);
    glEnd();

    glFlush();
}

void Inicializa(void) {
    tx = 0; // movimentos cima, baixo, esquerda e direita
    ty = 0; // movimentos cima, baixo, esquerda e direita
    angulo = 0; // incrementar = efeito da rotação
    gira = 0; // 0 = parado e 1 = girando
    win = 1; //SRT começa com (-win,win,-win,win)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D (-win, win, -win, win);
    glMatrixMode(GL_MODELVIEW);
}

void Teclado(unsigned char key, int x, int y) {
    switch (key)
    {
        case 65: // Aumentar figura
            glScalef(win*1.5f, win*1.5f, 0.0);
            break;
        case 68: // Diminuir figura
            glScalef(win*0.5f, win*0.5f, 0.0);
            break;
        case 71: // Colocar figura para girar
            gira = 1;
            break;
        case 82: // Rotacionar figura manualmente
            glRotatef(36, 0, 0, 0);
            break;
        case 79: // Restaurar imagem original
            tx = 0;
            ty = 0;
            angulo = 0;
            gira = 0;
            win = 1;
            glScalef(win, win, 0.0);
        case 80: // Parar
            gira = 0;
            break;
        case 27: // Sair da aplicação
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y) {
    switch (key) // setas do teclado
    {
        case GLUT_KEY_UP:
            ty++;
            break;
        case GLUT_KEY_DOWN:
            ty--;
            break;
        case GLUT_KEY_LEFT:
            tx--;
            break;
        case GLUT_KEY_RIGHT:
            tx++;
            break;
    }
    glTranslatef(tx,ty,0);
    glutPostRedisplay();
}

void GerenciaMouse(int button, int state, int x, int y) {
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) win+=10;
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) win-=10;
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
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(TeclasEspeciais);
    glutMouseFunc(GerenciaMouse);
    Inicializa();
    glutMainLoop();
}