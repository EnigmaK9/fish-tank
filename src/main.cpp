// 🌟✨ Programa creado por Carlos Ignacio Padilla Herrera ✨🌟



#include <GL/glut.h>
#include "variables.h"
#include "fish_tank.h"
#include "keyboard.h"
#include "room.h"
#include "fish.h"
#include <irrKlang.h>

using namespace irrklang;


int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fish Tank");

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
/*
    // Set up the view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Set up the light
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightPosition[] = {0.0f, 1.0f, 2.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Set up material properties
    GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat shininess[] = {128.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
*/
    // Register callback functions
    glutDisplayFunc(displayRoom);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);

    // Start the main loop
    glutMainLoop();

    
    // irrKlang
    ISoundEngine* engine = createIrrKlangDevice();

    if (!engine)
    {
        // No se pudo crear el dispositivo de irrKlang
        return 1;
    }

    // Cargar un archivo de sonido
    ISound* sound = engine->play2D("audios/pump-run.mp3", true);

    if (!sound)
    {
        // No se pudo cargar el archivo de sonido
        engine->drop();
        return 1;
    }

    // Reproducir el sonido
    sound->setVolume(0.5f);  // Establecer el volumen al 50%
    sound->setPlayPosition(1000);  // Establecer la posición de reproducción en milisegundos

    // Esperar hasta que el sonido termine de reproducirse
    while (sound->isFinished() == false)
    {
        // Puedes hacer otras operaciones aquí mientras el sonido se reproduce
    }

    // Liberar recursos
    sound->drop();
    engine->drop();

    return 0;
}