#include <GL/glut.h>
#include "variables.h"
#include "fish_tank.h"
#include <cmath>

void renderFish()
{
    // Renderizar el pez (solo como ejemplo)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);  // Color amarillo para el pez
    glTranslatef(0.0f, 0.0f, 0.0f);  // Posición del pez en el centro de la pecera
    glutSolidSphere(0.1f, 20, 20);  // Representación del pez como una esfera
    
    // Renderizar la cola de pescado
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);  // Color azul para la cola
    
    // Calcular la posición y tamaño de la cola
    float tailLength = 0.2f;  // Longitud de la cola (negativa para ubicarla en la parte trasera)
    float tailWidth = 0.05f;  // Anchura de la cola
    
    // Posicionar y rotar la cola con respecto al pez
    glTranslatef(tailLength, 0.0f, 0.0f);  // Desplazar la cola hacia atrás
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);  // Invertir la orientación de la cola
    
    // Dibujar la cola de pescado como un prisma rectangular
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, tailWidth, 0.0f);
    glVertex3f(tailLength, tailWidth, 0.0f);
    glVertex3f(tailLength, 0.0f, 0.0f);
    glEnd();
    
    glPopMatrix();  // Finalizar transformación de la cola
    
    // Renderizar la linterna
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);  // Color rojo para la linterna
    
    // Calcular la posición del cilindro y la esfera
    float angle = 60.0f;  // Ángulo de desplazamiento
    float radius = 0.005f;  // Radio del cilindro (ajustar este valor para reducir el ancho del cilindro)
    float height = 0.2f;  // Altura del cilindro
    float sphereRadius = 0.01f;  // Radio de la esfera
    
    glTranslatef(0.0f, 0.1f, 0.0f);  // Desplazar el origen a la posición del cilindro y la esfera
    
    // Rotar el cilindro y la esfera con respecto al pez
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    
    // Dibujar el cilindro simulado con un cono y un disco
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);  // Orientar el cono hacia arriba
    
    // Ajustar los vértices del cono para crear la forma de campana
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= 10; ++i)
    {
        float y = i * height / 10.0f;
        float radiusOffset = sin(i * M_PI / 10.0f) * radius;  // Ajustar el radio según una función sinusoidal
        glVertex3f(radius + radiusOffset, y, 0.0f);
        glVertex3f(-radius + radiusOffset, y, 0.0f);
    }
    glEnd();
    
    glTranslatef(0.0f, height, 0.0f);  // Posicionar el disco en la parte superior del cono
    glColor3f(1.0f, 1.0f, 1.0f);  // Color blanco para la esfera final
    glutSolidSphere(sphereRadius, 10, 10);
    glPopMatrix();
    
    glPopMatrix();  // Finalizar transformación de la linterna
    
    glPopMatrix();  // Finalizar transformación del pez
    
    // Resto del código...
}

// Resto del código...
