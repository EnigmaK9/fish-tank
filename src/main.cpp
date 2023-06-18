#include <GL/glut.h>
#include <iostream>
#include "variables.h"
#include "fish_tank.h"
#include "keyboard.h"
#include "room.h"
#include "fish.h"
#include "camera.h"
#include <stdio.h>
#include "../include/irrKlang.h"

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

//#pragma comment(lib, "irrKlang.lib")

CameraMode currentCamera = CAMERA_FRONT;

int main(int argc, char** argv)
{
    /*ISoundEngine* engine = createIrrKlangDevice();
    
    if (!engine)
    {
        printf("Could not startup engine\n");
        return 0;
    }
    
    engine->play2D("../media/getout.ogg", true);
    
    do
    {
        printf("Press any key to play some sound, press 'q' to quit.\n");
        engine->play2D("../media/bell.wav");
    } while (getch() != 'q');
    */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fish Tank");
    
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(displayRoom);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    // engine->drop(); //irrklang

    return 0;
}
