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

    // Dimensiones de la pecera en metros (dimensiones normales mexicanas)
    float width = 1.5f;
    float height = 0.75f;
    float depth = 0.75f;

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
    glColor4f(0.0f, 0.0f, 1.0f, 0.1f);  // Color azul más transparente

    // Lado izquierdo
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Lado derecho
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);

    // Cara inferior
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);

    // Cara superior
    //glVertex3f(-width / 2, height / 2, depth / 2);
    //glVertex3f(-width / 2, height / 2, -depth / 2);
    //glVertex3f(width / 2, height / 2, -depth / 2);
    //glVertex3f(width / 2, height / 2, depth / 2);

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
            angleX -= 5.0f;
            break;
        case 's':
            angleX += 5.0f;
            break;
        case 'a':
            angleY -= 5.0f;
            break;
        case 'd':
            angleY += 5.0f;
            break;
        case 'q':
            cameraZ -= 0.1f;
            break;
        case 'e':
            cameraZ += 0.1f;
            break;
        case 'r':
            cameraY += 0.1f;
            break;
        case 'f':
            cameraY -= 0.1f;
            break;
    }

    // Redraw the scene
    glutPostRedisplay();
}

