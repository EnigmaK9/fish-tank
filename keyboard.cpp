void keyboard(unsigned char key, int x, int y)
{
    // Handle rotation and movement based on WASD keys
    switch (key) {
        case 'w':
        case 'W':
            angleX -= 10.0f;
            break;
        case 's':
        case 'S':
            angleX += 10.0f;
            break;
        case 'a':
        case 'A':
            angleY -= 10.0f;
            break;
        case 'd':
        case 'D':
            angleY += 10.0f;
            break;
        case 'q':
        case 'Q':
            cameraZ -= 1.0f;
            break;
        case 'e':
        case 'E':
            cameraZ += 1.0f;
            break;
        case 'r':
        case 'R':
            cameraY += 1.0f;
            break;
        case 'f':
        case 'F':
            cameraY -= 1.0f;
            break;
        case 'x':
        case 'X':
            angleX = 0.0f;
            angleY = 0.0f;
            angleZ = 0.0f;
            cameraX = 0.0f;
            cameraY = 0.0f;
            cameraZ = 5.0f;
            break;
        case 'i':
        case 'I':
            cameraZ -= 1.0f;
            break;
        case 'o':
        case 'O':
            cameraZ += 1.0f;
            break;
        case 'j':
        case 'J':
            cameraX -= 1.0f;
            break;
        case 'l':
        case 'L':
            cameraX += 1.0f;
            break;
        case 'k':
        case 'K':
            cameraY -= 1.0f;
            break;
        case 'm':
        case 'M':
            cameraY += 1.0f;
            break;
    }

    // Redraw the scene
    glutPostRedisplay();
}



