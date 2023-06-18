#include <GL/glut.h>
#include "variables.h"
#include "keyboard.h"
#include <cmath>
#include "room.h"
#include "/home/enigma/Documents/repos/fish-tank/include/glm/glm.hpp"  // Incluye la biblioteca glm


void Move_Camera(float speed)
{
    glm::vec3 cameraDirection = glm::normalize(target - position);
    glm::vec3 displacement = cameraDirection * speed;

    position += displacement;
    target += displacement;
}

void Strafe_Camera(float speed)
{
    glm::vec3 cameraDirection = glm::normalize(target - position);
    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraDirection, up));
    glm::vec3 displacement = cameraRight * speed;

    position += displacement;
    target += displacement;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'w':
        case 'W':
            Move_Camera(CAMERASPEED + 5.0f);
            break;
        case 's':
        case 'S':
            Move_Camera(-(CAMERASPEED + 5.0f));
            break;
        case 'a':
        case 'A':
            Strafe_Camera(-(CAMERASPEED + 5.0f));
            break;
        case 'd':
        case 'D':
            Strafe_Camera(CAMERASPEED + 5.0f);
            break;
        default:
            break;
    }

    glutPostRedisplay();
}



void specialKeys(int key, int x, int y)
{
    // Handle camera movement based on arrow keys
    switch (key) {
        case GLUT_KEY_LEFT:
            angleY -= angleStep;  // Rotar hacia la izquierda en el eje Y
            break;
        case GLUT_KEY_RIGHT:
            angleY += angleStep;  // Rotar hacia la derecha en el eje Y
            break;
        case GLUT_KEY_UP:
            angleX -= angleStep;  // Rotar hacia arriba en el eje X
            break;
        case GLUT_KEY_DOWN:
            angleX += angleStep;  // Rotar hacia abajo en el eje X
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

void update(int value)
{
    // Simular el salto de la cámara
    if (isJumping) {
        cameraY = jumpPosition + jumpHeight * sin(jumpSpeed * jumpPosition);
        jumpPosition += jumpSpeed;
        if (jumpPosition >= 180.0f) {
            isJumping = false;
            cameraY = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}