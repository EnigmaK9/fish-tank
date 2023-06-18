// Programa creado por Carlos Ignacio Padilla Herrera

#include <GL/glut.h>
#include <iostream>
#include "variables.h"
#include "fish_tank.h"
#include "keyboard.h"
#include "room.h"
#include "fish.h"

CameraMode currentCamera = CAMERA_FRONT;

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fish Tank");

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Register callback functions
    glutDisplayFunc(displayRoom);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);

    // Start the main loop
    glutMainLoop();

    return 0;
}
