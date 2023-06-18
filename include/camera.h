#include "main.h"

#define CAMERASPEED 0.07f // Camera Speed

// 3D vector struct
typedef struct tVector3
{			
    tVector3() {} // Constructor
    tVector3(float new_x, float new_y, float new_z)
    {
        x = new_x;
        y = new_y;
        z = new_z;
    }

    // Operator overloading for vector addition
    tVector3 operator+(tVector3 vVector)
    {
        return tVector3(vVector.x + x, vVector.y + y, vVector.z + z);
    }

    // Operator overloading for vector subtraction
    tVector3 operator-(tVector3 vVector)
    {
        return tVector3(x - vVector.x, y - vVector.y, z - vVector.z);
    }

    // Operator overloading for scalar multiplication
    tVector3 operator*(float number)
    {
        return tVector3(x * number, y * number, z * number);
    }

    // Operator overloading for scalar division
    tVector3 operator/(float number)
    {
        return tVector3(x / number, y / number, z / number);
    }

    float x, y, z; // 3D vector coordinates
} tVector3;

// Camera class
class CCamera 
{
public:
    tVector3 mPos;	
    tVector3 mView;		
    tVector3 mUp;			

    // Move the camera sideways
    void Strafe_Camera(float speed);

    // Move the camera forward/backward
    void Move_Camera(float speed);

    // Rotate the camera view
    void Rotate_View(float speed);

    // Move the camera up/down
    void UpDown_Camera(float speed);

    // Set the position and view of the camera
    void Position_Camera(float pos_x, float pos_y, float pos_z,
                         float view_x, float view_y, float view_z,
                         float up_x, float up_y, float up_z);
};
