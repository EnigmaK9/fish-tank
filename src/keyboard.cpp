#include <GL/glut.h>
#include "variables.h"
#include "keyboard.h"
#include <cmath>
#include "room.h"
#include "../include/glm/glm.hpp"  // Incluye la biblioteca glm
#include "../include/camera.h"  // Incluye la biblioteca glm

CCamera objCamera;	//Crea el objeto Camera

   

void keyboard ( unsigned char key, int x, int y )
{
	switch ( key ) {

		case 'w':   // Movimientos de la cámara
		case 'W':
			objCamera.Move_Camera(CAMERA_SPEED + 0.2f);
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERA_SPEED + 0.2f));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERA_SPEED + 0.4f));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera(CAMERA_SPEED + 0.4f);
			break;

		case 27:        // Cuando Esc es presionado...
			exit(0);   // Salimos del programa
			break;        
		default:        // Cualquier otra
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