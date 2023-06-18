#ifndef SKYBOX_H
#define SKYBOX_H

#include <GL/glut.h>
#include <SOIL.h> // Librería SOIL para cargar imágenes de textura

extern GLuint skyboxTexture; // Variable para almacenar el identificador de la textura

void loadSkyboxTexture();
void renderSkybox(float size);

#endif // SKYBOX_H
