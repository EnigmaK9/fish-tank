#include "SOIL.h"
#include <iostream>
#include <GL/glut.h>
#include "variables.h"

GLuint skyboxTexture;  // Variable para almacenar el identificador de la textura

void loadSkyboxTexture()
{
    // Cargar la imagen de textura usando SOIL
    skyboxTexture = SOIL_load_OGL_texture(
        "../images/aquarium.jpg",  // Ruta de la imagen de textura
        SOIL_LOAD_AUTO,  // Opciones de carga de la imagen
        SOIL_CREATE_NEW_ID,  // Generar un nuevo identificador de textura
        SOIL_FLAG_INVERT_Y  // Opciones adicionales de carga de la imagen
    );

    if (skyboxTexture == 0)
    {
        std::cout << "Error cargando la textura de la skybox." << std::endl;
    }
}

void renderSkybox(float size)
{
    float halfSize = size / 2;

    // Habilitar el mapeo de textura y cargar la textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, skyboxTexture);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Disable writing to the depth buffer
    glDepthMask(GL_FALSE);

    // Save the current matrix mode
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Reset the modelview matrix
    glLoadIdentity();

    // Translate the skybox to the camera position
    // Note: Replace 'cameraX', 'cameraY', 'cameraZ' with the actual camera position
    glTranslatef(cameraX, cameraY, cameraZ);

    // Render the skybox
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);  // Coordenadas de textura del vértice inferior izquierdo
    glVertex3f(-halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 0.0f);  // Coordenadas de textura del vértice inferior derecho
    glVertex3f(halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 1.0f);  // Coordenadas de textura del vértice superior derecho
    glVertex3f(halfSize, halfSize, halfSize);
    glTexCoord2f(0.0f, 1.0f);  // Coordenadas de textura del vértice superior izquierdo
    glVertex3f(-halfSize, halfSize, halfSize);

    // Back face
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(halfSize, halfSize, -halfSize);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-halfSize, halfSize, -halfSize);

    // Left face
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-halfSize, halfSize, -halfSize);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-halfSize, halfSize, halfSize);

    // Right face
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(halfSize, halfSize, -halfSize);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(halfSize, halfSize, halfSize);

    // Top face
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-halfSize, halfSize, halfSize);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(halfSize, halfSize, halfSize);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(halfSize, halfSize, -halfSize);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-halfSize, halfSize, -halfSize);

    // Bottom face
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-halfSize, -halfSize, -halfSize);

    glEnd();

    // Restore the previous modelview matrix
    glPopMatrix();

    // Enable writing to the depth buffer
    glDepthMask(GL_TRUE);

    // Disable depth testing and mapeo de textura
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
}
