#include <GL/glut.h>
#include <iostream>
#include "variables.h"
#include "fish_tank.h"
#include "keyboard.h"
#include "room.h"
#include "fish.h"
#include "camera.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

// Variables para el movimiento del personaje y la cámara
float characterPosX = 0.0f;
float characterPosY = 0.0f;
float cameraPosX = 0.0f;
float cameraPosY = 0.0f;


int main() {
    // Inicializar GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Crear una ventana
    GLFWwindow* window = glfwCreateWindow(800, 600, "Escenario", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Establecer la ventana actual para las llamadas a GLFW
    glfwMakeContextCurrent(window);
    glutDisplayFunc(displayRoom);
    glutSpecialFunc(specialKeys);
    // Establecer la función de callback del teclado
    glfwSetKeyCallback(window, keyboardCallback);

    // Bucle principal de renderizado
    while (!glfwWindowShouldClose(window)) {
        // Procesar eventos de la ventana

        // ...

        // Renderizar el escenario, el personaje y la cámara usando las variables characterPosX, characterPosY, cameraPosX y cameraPosY

        // ...

        // Intercambiar los buffers de la ventana
        glfwSwapBuffers(window);

        // Comprobar si se han presionado teclas de escape u otros eventos de cierre
        glfwPollEvents();
    }

    // Liberar recursos y terminar GLFW
    glfwTerminate();

    return 0;
}
