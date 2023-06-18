#include <GL/glut.h>
#include <iostream>
#include "variables.h"
#include "fish_tank.h"
#include "keyboard.h"
#include "room.h"
#include "fish.h"
#include "skybox.h"

void displayRoom()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set up the camera
    if (currentCamera == CAMERA_FRONT) {
        gluLookAt(0.0f, 0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    } else if (currentCamera == CAMERA_TOP) {
        gluLookAt(0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
    } else if (currentCamera == CAMERA_OUTSIDE) {
        // Set up the camera to view from outside the fish tank
        gluLookAt(0.0f, 0.0f, 200.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    }

    // Render the room
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Dimensiones de la habitación en metros
    float roomWidth = 5.0f;
    float roomHeight = 3.0f;
    float roomDepth = 5.0f;

    // Renderizar la habitación
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);  // Color verde

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
    // Render the fish tank
    displayFishTank();
    // Render the skybox
    //renderSkybox(50.0f); // Tamaño de la skybox
    
    glutSwapBuffers();
}

