#ifndef VARIABLES_H
#define VARIABLES_H

#include "glm/glm.hpp"

// Camera variables
extern glm::vec3 target;  // Camera target position
extern glm::vec3 position;  // Camera position
extern glm::vec3 up;  // Up vector for camera orientation

// Global variables
extern float angleX;  // Rotation angle around the X-axis
extern float angleY;  // Rotation angle around the Y-axis
extern float angleZ;  // Rotation angle around the Z-axis
extern float cameraX;  // Camera X-coordinate
extern float cameraY;  // Camera Y-coordinate
extern float cameraZ;  // Camera Z-coordinate
extern bool keyStates[256];  // Array to store the state of keyboard keys
extern float fishX;  // Fish X-coordinate (commented out)

// Variables for camera movement
extern float CAMERASPEED;  // Speed of camera movement

// Variables for camera movement with arrow keys
extern float angleStep;  // Step size for rotation angles

// Variables for jumping
extern float jumpHeight;  // Maximum height of the jump
extern float jumpSpeed;  // Speed of the jump
extern bool isJumping;  // Flag indicating if the camera is jumping
extern float jumpPosition;  // Current position in the jump animation

#endif  // VARIABLES_H
