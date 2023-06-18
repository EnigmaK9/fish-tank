#include <GL/glut.h>
#include "variables.h"
#include "keyboard.h"
#include <cmath>
#include "room.h"
// Variables para el movimiento de la cámara
float cameraSpeed = 0.1f;
float cameraDefaultX = 0.0f;
float cameraDefaultY = 0.0f;
float cameraDefaultZ = 5.0f;

// Variables para el desplazamiento lateral
float cameraSideSpeed = 0.1f;
float cameraSideAngle = 0.0f;

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
        case 'z':
        case 'Z':
            cameraZ += cameraSpeed;
            break;
        case 'x':
        case 'X':
            cameraZ -= cameraSpeed;
            break;
        case 'r':
        case 'R':
            angleX = cameraDefaultX;
            angleY = cameraDefaultY;
            cameraZ = cameraDefaultZ;
            break;
        case 'q':
        case 'Q':
            cameraSideAngle -= 5.0f;
            break;
        case 'e':
        case 'E':
            cameraSideAngle += 5.0f;
            break;
        case GLUT_KEY_F1:
            currentCamera = CAMERA_FRONT;
            break;
        case GLUT_KEY_F2:
            currentCamera = CAMERA_TOP;
            break;
        case GLUT_KEY_F3:
            currentCamera = CAMERA_OUTSIDE;
            break;
        default:
            break;
    }
    // Redraw the scene
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    // Handle rotation and movement based on arrow keys
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
        case GLUT_KEY_PAGE_UP:
            cameraZ += cameraSpeed;
            break;
        case GLUT_KEY_PAGE_DOWN:
            cameraZ -= cameraSpeed;
            break;
        case GLUT_KEY_HOME:
            angleX = cameraDefaultX;
            angleY = cameraDefaultY;
            cameraZ = cameraDefaultZ;
            break;
        case GLUT_KEY_F1:
            angleX = cameraDefaultX;
            angleY = cameraDefaultY;
            cameraZ = cameraDefaultZ;
            break;
    }

    // Redraw the scene
    glutPostRedisplay();
}

void update(int value)
{
    // Move the camera based on the side angle
    float sideX = sin(cameraSideAngle * 3.14159f / 180.0f);
    float sideZ = cos(cameraSideAngle * 3.14159f / 180.0f);

    // Handle movement based on arrow keys
    if (keyStates[GLUT_KEY_UP]) {
        float angleRad = angleY * 3.14159f / 180.0f;
        cameraX += sin(angleRad) * cameraSpeed;
        cameraZ -= cos(angleRad) * cameraSpeed;
    }
    if (keyStates[GLUT_KEY_DOWN]) {
        float angleRad = angleY * 3.14159f / 180.0f;
        cameraX -= sin(angleRad) * cameraSpeed;
        cameraZ += cos(angleRad) * cameraSpeed;
    }
    if (keyStates[GLUT_KEY_LEFT]) {
        float angleRad = angleY * 3.14159f / 180.0f;
        cameraX += cos(angleRad) * cameraSideSpeed * sideX;
        cameraZ += sin(angleRad) * cameraSideSpeed * sideZ;
    }
    if (keyStates[GLUT_KEY_RIGHT]) {
        float angleRad = angleY * 3.14159f / 180.0f;
        cameraX -= cos(angleRad) * cameraSideSpeed * sideX;
        cameraZ -= sin(angleRad) * cameraSideSpeed * sideZ;
    }

    // Redraw the scene
    glutPostRedisplay();

    // Call update() again after 16 milliseconds
    glutTimerFunc(16, update, 0);
}
