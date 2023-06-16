// 🌟✨ Programa creado por Carlos Ignacio Padilla Herrera ✨🌟

#include <GL/glut.h>
#include "fish_tank.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Configura el modo de visualización
    glutInitWindowSize(500, 500); // Establece el tamaño de la ventana
    glutCreateWindow("OpenGL Fish Tank"); // Crea una ventana con el título especificado

    glEnable(GL_DEPTH_TEST); // Habilita el test de profundidad para la representación en 3D

    glutDisplayFunc(displayFishTank); // Registra la función de visualización del tanque de peces
    glutSpecialFunc(specialKeys); // Registra la función para manejar las teclas especiales
    glutKeyboardFunc(keyboard); // Registra la función para manejar las teclas normales del teclado
    glutMainLoop(); // Inicia el bucle principal de GLUT

    return 0;
}
