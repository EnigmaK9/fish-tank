#include <GL/glut.h>
#include "variables.h"
#include "fish_tank.h"
#include "fish.h"

void renderTankContents(float width, float height, float depth);

void renderTankBody(float width, float height, float depth)
{
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);

    // Front face - Blue
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f); // Blue semi-transparent
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Back face - Red
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Red semi-transparent
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);

    // Left face - Green
    glColor4f(0.0f, 1.0f, 0.0f, 0.5f); // Green semi-transparent
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Right face - Yellow
    glColor4f(1.0f, 1.0f, 0.0f, 0.5f); // Yellow semi-transparent
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);

    // Bottom face - Cyan
    glColor4f(0.0f, 1.0f, 1.0f, 0.5f); // Cyan semi-transparent
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);

    glEnd();

    // Render water surface (reflected)
    glEnable(GL_CLIP_PLANE0); // Enable clipping plane for reflection
    double planeCoefficients[] = {0.0, 1.0, 0.0, 0.0}; // Define reflection plane (y = 0)
    glClipPlane(GL_CLIP_PLANE0, planeCoefficients); // Set the clipping plane

    glPushMatrix();
    glScalef(1.0f, -1.0f, 1.0f); // Invert along the y-axis to reflect
    renderTankContents(width, height, depth); // Render the contents of the tank (fish, plants, etc.)
    glPopMatrix();

    glDisable(GL_CLIP_PLANE0); // Disable clipping plane

    // Disable blending
    glDisable(GL_BLEND);
}

void renderTankContents(float width, float height, float depth)
{
    // Render water surface
    glBegin(GL_QUADS);
    glColor4f(0.0f, 0.5f, 1.0f, 0.5f); // Light blue semi-transparent
    glVertex3f(-width / 2, 0.0f, depth / 2);
    glVertex3f(width / 2, 0.0f, depth / 2);
    glVertex3f(width / 2, 0.0f, -depth / 2);
    glVertex3f(-width / 2, 0.0f, -depth / 2);
    glEnd();

    // Cube on top
    glColor4f(1.0f, 1.0f, 0.0f, 0.5f); // Yellow semi-transparent
    float cubeWidth = width * 0.8f;
    float cubeHeight = height * 0.1f;
    float cubeDepth = depth * 0.8f;
    glBegin(GL_QUADS);
    glVertex3f(-cubeWidth / 2, height / 2, -cubeDepth / 2);
    glVertex3f(cubeWidth / 2, height / 2, -cubeDepth / 2);
    glVertex3f(cubeWidth / 2, height / 2 + cubeHeight, -cubeDepth / 2);
    glVertex3f(-cubeWidth / 2, height / 2 + cubeHeight, -cubeDepth / 2);
    glEnd();
}

void renderTankLeg(float width, float height, float depth)
{
    glPushMatrix();
    glScalef(0.1f, height, 0.1f);  // Dimensiones de la pata (ancho, alto, profundidad)
    glColor3f(0.6f, 0.4f, 0.2f);  // Color café
    glutSolidCube(1.0f);  // Renderizar la pata como un cubo sólido
    glPopMatrix();
}

void displayFishTank()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Apply rotations
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Dimensiones de la pecera en metros (dimensiones más pequeñas)
    float width = 18.0f;   // 9 metros de ancho
    float height = 9.0f;   // 4.5 metros de alto
    float depth = 9.0f;    // 4.5 metros de profundidad

    // Renderizar la pecera
    renderTankBody(width, height, depth);

    // Restaurar estado de la mezcla
    glDisable(GL_BLEND);

    // Renderizar las patas de la pecera
    glPushMatrix();
    glTranslatef(-width / 2, -height / 2, -depth / 2);  // Posición de la pata en la esquina inferior izquierda
    renderTankLeg(width, height, depth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-width / 2, -height / 2, depth / 2);  // Posición de la pata en la esquina superior izquierda
    renderTankLeg(width, height, depth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(width / 2, -height / 2, -depth / 2);  // Posición de la pata en la esquina inferior derecha
    renderTankLeg(width, height, depth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(width / 2, -height / 2, depth / 2);  // Posición de la pata en la esquina superior derecha
    renderTankLeg(width, height, depth);
    glPopMatrix();

    renderFish();

    glutSwapBuffers();
}
