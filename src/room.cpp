#include <GL/glut.h>
#include "variables.h"
#include "fish_tank.h"
#include "fish.h"
#include "room.h"

void displayRoom()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Dimensiones de la habitación en metros
    float roomWidth = 5.0f;
    float roomHeight = 3.0f;
    float roomDepth = 5.0f;
    
    // Renderizar la habitación
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);  // Color gris claro
 
    // Pared frontal
    glVertex3f(-roomWidth / 2, -roomHeight / 2, roomDepth / 2);
    glVertex3f(roomWidth / 2, -roomHeight / 2, roomDepth / 2);
    glVertex3f(roomWidth / 2, roomHeight / 2, roomDepth / 2);
    glVertex3f(-roomWidth / 2, roomHeight / 2, roomDepth / 2);

    // Pared trasera
    glVertex3f(-roomWidth / 2, -roomHeight / 2, -roomDepth / 2);
    glVertex3f(roomWidth / 2, -roomHeight / 2, -roomDepth / 2);
    glVertex3f(roomWidth / 2, roomHeight / 2, -roomDepth / 2);
    glVertex3f(-roomWidth / 2, roomHeight / 2, -roomDepth / 2);

    // Pared izquierda
    glVertex3f(-roomWidth / 2, -roomHeight / 2, roomDepth / 2);
    glVertex3f(-roomWidth / 2, -roomHeight / 2, -roomDepth / 2);
    glVertex3f(-roomWidth / 2, roomHeight / 2, -roomDepth / 2);
    glVertex3f(-roomWidth / 2, roomHeight / 2, roomDepth / 2);

    // Pared derecha
    glVertex3f(roomWidth / 2, -roomHeight / 2, roomDepth / 2);
    glVertex3f(roomWidth / 2, -roomHeight / 2, -roomDepth / 2);
    glVertex3f(roomWidth / 2, roomHeight / 2, -roomDepth / 2);
    glVertex3f(roomWidth / 2, roomHeight / 2, roomDepth / 2);
    
    // Piso
    glVertex3f(-roomWidth / 2, -roomHeight / 2, roomDepth / 2);
    glVertex3f(-roomWidth / 2, -roomHeight / 2, -roomDepth / 2);
    glVertex3f(roomWidth / 2, -roomHeight / 2, -roomDepth / 2);
    glVertex3f(roomWidth / 2, -roomHeight / 2, roomDepth / 2);

    glEnd();

    displayFishTank();

    glutSwapBuffers();
}
