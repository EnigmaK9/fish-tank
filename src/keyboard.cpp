#include <GL/glut.h>
#include "variables.h"
#include "keyboard.h"
#include <cmath>
#include "room.h"
#include "../include/glm/glm.hpp"  // Incluye la biblioteca glm
//#include "../include/camera.h"  // Incluye la biblioteca glm
#include <GLFW/glfw3.h>

//CCamera objCamera;	//Crea el objeto Camera



// Variables para el movimiento del personaje y la cámara
float characterPosX = 0.0f;
float characterPosY = 0.0f;
float cameraPosX = 0.0f;
float cameraPosY = 0.0f;

// Función de callback para el teclado
void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Movimiento del personaje
    float characterSpeed = 0.1f;

    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        characterPosY += characterSpeed;
    }

    if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        characterPosY -= characterSpeed;
    }

    if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        characterPosX -= characterSpeed;
    }

    if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        characterPosX += characterSpeed;
    }

    // Movimiento de la cámara
    float cameraSpeed = 0.1f;

    if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        cameraPosY += cameraSpeed;
    }

    if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        cameraPosY -= cameraSpeed;
    }

    if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        cameraPosX -= cameraSpeed;
    }

    if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        cameraPosX += cameraSpeed;
    }
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