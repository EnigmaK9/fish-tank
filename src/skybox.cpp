#include <iostream>
#include <GL/glut.h>
#include "variables.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint skyboxTexture; // Variable to store the texture identifier

void loadSkyboxTexture()
{
    int width, height, channels;
    unsigned char *imageData = stbi_load("../images/aquarium.jpg", &width, &height, &channels, 0);
    if (!imageData)
    {
        std::cout << "Error loading skybox texture." << std::endl;
        return;
    }

    glGenTextures(1, &skyboxTexture);
    glBindTexture(GL_TEXTURE_2D, skyboxTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

void renderSkybox(float size)
{
    float halfSize = size / 2;

    // Enable texture mapping and bind the texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, skyboxTexture);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Disable writing to the depth buffer
    glDepthMask(GL_FALSE);

    // Save the current modelview matrix
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
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(halfSize, -halfSize, halfSize);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(halfSize, halfSize, halfSize);
    glTexCoord2f(0.0f, 1.0f);
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

    // Disable depth testing and texture mapping
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
}
