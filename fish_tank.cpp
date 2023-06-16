#include <GL/glut.h>
#include "fish_tank.h"

// Variables for rotation
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

void displayFishTank()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Apply rotations
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    // Dimensiones de la pecera en metros (dimensiones más pequeñas)
    float width = 0.75f;
    float height = 0.375f;
    float depth = 0.375f;

    // Renderizar la pecera
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
    glColor4f(0.0f, 0.0f, 1.0f, 0.3f);  // Color azul con transparencia

    // Cara frontal
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Cara trasera
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);

    // Caras laterales (transparentes)
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);

    // Cara inferior
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);


    glEnd();

    glDisable(GL_BLEND);

    // Renderizar el pez (solo como ejemplo)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);  // Color amarillo para el pez
    glTranslatef(0.0f, 0.0f, 0.0f);  // Posición del pez en el centro de la pecera
    glutSolidSphere(0.1f, 20, 20);  // Representación del pez como una esfera
    glPopMatrix();

    glutSwapBuffers();
}

// Variables para el movimiento de la cámara
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 5.0f;

void specialKeys(int key, int x, int y)
{
    // Handle rotation based on arrow keys
    switch (key) {
        case GLUT_KEY_LEFT:
            angleY -= 5.0f;
            break;
        case GLUT_KEY_RIGHT:
            angleY += 5.0f;
            break;
        case GLUT_KEY_UP:
            angleX -= 5.0f;
            break;
        case GLUT_KEY_DOWN:
            angleX += 5.0f;
            break;
    }

    // Redraw the scene
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    // Handle rotation and movement based on WASD keys
    switch (key) {
        case 'w':
        case 'W':
            angleX -= 10.0f;
            break;
        case 's':
        case 'S':
            angleX += 10.0f;
            break;
        case 'a':
        case 'A':
            angleY -= 10.0f;
            break;
        case 'd':
        case 'D':
            angleY += 10.0f;
            break;
        case 'q':
        case 'Q':
            cameraZ -= 1.0f;
            break;
        case 'e':
        case 'E':
            cameraZ += 1.0f;
            break;
        case 'r':
        case 'R':
            cameraY += 1.0f;
            break;
        case 'f':
        case 'F':
            cameraY -= 1.0f;
            break;
        case 'x':
        case 'X':
            angleX = 0.0f;
            angleY = 0.0f;
            angleZ = 0.0f;
            cameraX = 0.0f;
            cameraY = 0.0f;
            cameraZ = 5.0f;
            break;
        case 'i':
        case 'I':
            cameraZ -= 1.0f;
            break;
        case 'o':
        case 'O':
            cameraZ += 1.0f;
            break;
        case 'j':
        case 'J':
            cameraX -= 1.0f;
            break;
        case 'l':
        case 'L':
            cameraX += 1.0f;
            break;
        case 'k':
        case 'K':
            cameraY -= 1.0f;
            break;
        case 'm':
        case 'M':
            cameraY += 1.0f;
            break;
    }

    // Redraw the scene
    glutPostRedisplay();
}



