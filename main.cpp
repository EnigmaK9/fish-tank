#include <GL/glut.h>
#include "fish_tank.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Fish Tank");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(displayFishTank);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
