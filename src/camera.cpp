#include "../include/camera.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                      CCamera POSITION CAMERA
/////////////////////////////////////////////////////////////////////////////////////////////////
void CCamera::Position_Camera(float pos_x, float pos_y, float pos_z,
                              float view_x, float view_y, float view_z,
                              float up_x, float up_y, float up_z)
{
    mPos = tVector3(pos_x, pos_y, pos_z);     // Set position
    mView = tVector3(view_x, view_y, view_z); // Set view
    mUp = tVector3(up_x, up_y, up_z);         // Set the up vector
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                      CCamera MOVE CAMERA
/////////////////////////////////////////////////////////////////////////////////////////////////
void CCamera::Move_Camera(float speed)
{
    tVector3 vVector = mView - mPos; // Get the view vector

    // Move forward with positive cameraspeed and backward with negative cameraspeed
    mPos.x += vVector.x * speed;
    mPos.z += vVector.z * speed;
    mView.x += vVector.x * speed;
    mView.z += vVector.z * speed;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                      CCamera ROTATE VIEW
/////////////////////////////////////////////////////////////////////////////////////////////////
void CCamera::Rotate_View(float speed)
{
    tVector3 vVector = mView - mPos; // Get the view vector

    mView.z = static_cast<float>(mPos.z + sin(speed) * vVector.x + cos(speed) * vVector.z);
    mView.x = static_cast<float>(mPos.x + cos(speed) * vVector.x - sin(speed) * vVector.z);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                      CCamera STRAFE CAMERA
/////////////////////////////////////////////////////////////////////////////////////////////////
void CCamera::Strafe_Camera(float speed)
{
    tVector3 vVector = mView - mPos; // Get the view vector
    tVector3 vOrthoVector;           // Orthogonal vector for the view vector

    vOrthoVector.x = -vVector.z;
    vOrthoVector.z = vVector.x;

    // Move left with positive cameraspeed and right with negative cameraspeed
    mPos.x += vOrthoVector.x * speed;
    mPos.z += vOrthoVector.z * speed;
    mView.x += vOrthoVector.x * speed;
    mView.z += vOrthoVector.z * speed;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                      CCamera UP-DOWN CAMERA
/////////////////////////////////////////////////////////////////////////////////////////////////
void CCamera::UpDown_Camera(float speed)
{
    tVector3 vVector = mView - mPos; // Get the view vector
    tVector3 vOrthoVector;           // Orthogonal vector for the view vector

    vOrthoVector.y = 10;

    // Move up with positive cameraspeed and down with negative cameraspeed
    mPos.y += vOrthoVector.y * speed;
    mView.y += vOrthoVector.y * speed;
}
