#include "variables.h"
#include "../include/glm/glm.hpp"

glm::vec3 target;  // Camera target position
glm::vec3 position;  // Camera position
glm::vec3 up;  // Up vector for camera orientation

// Global variables

float CAMERASPEED = 5.0f;  // Velocidad de movimiento de la cámara

// Variables for camera movement with arrow keys
float angleX = 0.0f;  // Rotation angle around the X-axis
float angleY = 0.0f;  // Rotation angle around the Y-axis
float angleZ = 0.0f;  // Rotation angle around the Z-axis
float angleStep = 5.0f;  // Step size for rotation angles

// Variables for camera movement
float cameraX = 0.0f;  // Camera X-coordinate
float cameraY = 0.0f;  // Camera Y-coordinate
float cameraZ = 0.0f;  // Camera Z-coordinate
float cameraSpeed = 5.0f;  // Speed of camera movement

// Variables for jumping
float jumpHeight = 100.0f;  // Maximum height of the jump
float jumpSpeed = 100.0f;  // Speed of the jump
bool isJumping = false;  // Flag indicating if the camera is jumping
float jumpPosition = 0.0f;  // Current position in the jump animation

bool keyStates[256] = { false };  // Array to store the state of keyboard keys

// Other variables

//float fishX = 0.0f;
//float fishY = 0.0f;
//float fishZ = 0.0f;
