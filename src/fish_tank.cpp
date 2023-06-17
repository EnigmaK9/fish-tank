#include <GL/glut.h>
#include "variables.h"
#include "fish_tank.h"
#include "fish.h"

void renderTankBody(float width, float height, float depth)
{
    glBegin(GL_QUADS);

    // Cara frontal
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);  // Color azul semi-transparente
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Cara trasera
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);  // Color azul semi-transparente
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);

    // Caras laterales
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);  // Color azul semi-transparente
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);

    // Cara inferior
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);  // Color azul semi-transparente
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);

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
    float width = 2.25f;   
    float height = 1.125f;   
    float depth = 1.125f;   

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
