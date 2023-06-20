#include <GL/glut.h>
#include "variables.h"
#include "fish_tank.h"
#include "fish.h"

void renderTankContents(float width, float height, float depth);
void renderJellyfish();
void renderBox(float x, float y, float z, float width, float height, float depth, float red, float green, float blue, float alpha);

void renderTankBody(float width, float height, float depth)
{
    // Habilitar blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);

    // Cara frontal - Azul
    glColor4f(0.0f, 0.0f, 1.0f, 0.1f); // Azul semi-transparente
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Cara trasera - Rojo
    glColor4f(1.0f, 0.0f, 0.0f, 0.1f); // Rojo semi-transparente
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);

    // Cara izquierda - Verde
    glColor4f(0.0f, 1.0f, 0.0f, 0.1f); // Verde semi-transparente
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Cara derecha - Amarillo
    glColor4f(1.0f, 1.0f, 0.0f, 0.1f); // Amarillo semi-transparente
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);

    // Cara inferior - Cian
    glColor4f(0.0f, 1.0f, 1.0f, 0.1f); // Cian semi-transparente
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);

    glEnd();

    // Renderizar superficie del agua (reflejada)
    glEnable(GL_CLIP_PLANE0); // Habilitar plano de recorte para el reflejo
    double planeCoefficients[] = {0.0, 1.0, 0.0, 0.0}; // Definir el plano de reflejo (y = 0)
    glClipPlane(GL_CLIP_PLANE0, planeCoefficients); // Establecer el plano de recorte

    glPushMatrix();
    glScalef(1.0f, -1.0f, 1.0f); // Invertir a lo largo del eje y para reflejar
    renderTankContents(width, height, depth); // Renderizar el contenido del acuario (peces, plantas, etc.)
    glPopMatrix();

    glDisable(GL_CLIP_PLANE0); // Deshabilitar el plano de recorte

    // Deshabilitar blending
    glDisable(GL_BLEND);
}


void renderTankContents(float width, float height, float depth)
{
    // Renderizar superficie del agua
    glBegin(GL_QUADS);
    glColor4f(0.0f, 0.5f, 1.0f, 0.5f); // Azul claro semi-transparente
    glVertex3f(-width / 2, 0.0f, depth / 2);
    glVertex3f(width / 2, 0.0f, depth / 2);
    glVertex3f(width / 2, 0.0f, -depth / 2);
    glVertex3f(-width / 2, 0.0f, -depth / 2);
    glEnd();

    // Renderizar cajas
    float boxWidth = width * 0.1f;
    float boxHeight = height * 0.2f;
    float boxDepth = depth * 0.1f;

    // Caja en la parte superior con color - gris semi-transparente
    renderBox(-10.0f, -10.0f, -10.0f, 2.0f, 2.0f, 2.0f, 0.5f, 0.5f, 0.5f, 0.9f);

    // Caja en la parte inferior con color (1.0, 0.0, 0.0, 0.5) - Rojo semi-transparente
    renderBox(-10.0f, -2.0f, -10.0f, 2.0f, 2.0f, 2.0f, 0.6f, 0.4f, 0.2f, 0.9f);
}

void renderBox(float x, float y, float z, float width, float height, float depth, float red, float green, float blue, float alpha)
{
    glColor4f(red, green, blue, alpha);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, depth);
    glutSolidCube(1.0f);
    glPopMatrix();
}


void renderJellyfish()
{
    // Set jellyfish parameters
    float bodyRadius = 0.010f;
    float tentacleLength = 0.020f;
    float tentacleRadius = 0.002f;
    int numTentacles = 8;

    // Render jellyfish body
    glColor4f(1.0f, 0.0f, 1.0f, 0.5f); // Purple semi-transparent
    glutSolidSphere(bodyRadius, 32, 32);

    // Render jellyfish tentacles
    glColor4f(1.0f, 0.0f, 1.0f, 0.2f); // Purple semi-transparent
    for (int i = 0; i < numTentacles; i++)
    {
        glPushMatrix();
        glRotatef(360.0f * i / numTentacles, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, -bodyRadius, 0.0f);

        // Render tentacle as a cylinder
        GLUquadricObj *quadric = gluNewQuadric();
        gluCylinder(quadric, tentacleRadius, tentacleRadius, tentacleLength, 16, 16);

        // Render tentacle end as a sphere
        glTranslatef(0.0f, 0.0f, tentacleLength);
        gluSphere(quadric, tentacleRadius * 1.5f, 16, 16);

        gluDeleteQuadric(quadric);
        glPopMatrix();
    }

    // Displace the jellyfish by 2 units along the x, y, and z axes
    //glTranslatef(-2.0f, -2.0f, -2.0f);
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

    // Aplicar rotaciones
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    // Habilitar blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Dimensiones del acuario en metros (dimensiones más pequeñas)
    float width = 180.0f;   // 18 metros de ancho
    float height = 90.0f;   // 9 metros de alto
    float depth = 90.0f;    // 9 metros de profundidad

    // Renderizar el cuerpo del acuario
    renderTankBody(width, height, depth);

    // Restaurar estado de blending
    glDisable(GL_BLEND);

    // Renderizar las patas del acuario
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

    renderJellyfish();

    glutSwapBuffers();
}