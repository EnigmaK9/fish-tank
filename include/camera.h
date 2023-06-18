#include "main.h"

#define CAMERASPEED 0.07f // The Camera Speed

//////////////////////////////////////
// The tVector3 Struct
//////////////////////////////////////
typedef struct tVector3 // Expanded 3D vector struct
{			
    tVector3() {} // Constructor
    tVector3(float new_x, float new_y, float new_z) // Initialize constructor	 
    {
        x = new_x;
        y = new_y;
        z = new_z;
    }

    // Overload + operator to facilitate vector addition
    tVector3 operator+(tVector3 vVector)
    {
        return tVector3(vVector.x + x, vVector.y + y, vVector.z + z);
    }

    // Overload - operator to facilitate vector subtraction
    tVector3 operator-(tVector3 vVector)
    {
        return tVector3(x - vVector.x, y - vVector.y, z - vVector.z);
    }

    // Overload * operator to facilitate multiplication by scalars
    tVector3 operator*(float number)
    {
        return tVector3(x * number, y * number, z * number);
    }

    // Overload / operator to facilitate division by a scalar
    tVector3 operator/(float number)
    {
        return tVector3(x / number, y / number, z / number);
    }

    float x, y, z; // 3D vector coordinates
} tVector3;

//////////////////////////////////////
// The CCamera Class
//////////////////////////////////////
class CCamera 
{
public:
    tVector3 mPos;	
    tVector3 mView;		
    tVector3 mUp;			

    void Strafe_Camera(float speed); // Move the camera sideways
    void Move_Camera(float speed); // Move the camera forward/backward
    void Rotate_View(float speed); // Rotate the camera view
    void UpDown_Camera(float speed); // Move the camera up/down
    void Position_Camera(float pos_x, float pos_y, float pos_z,
                         float view_x, float view_y, float view_z,
                         float up_x, float up_y, float up_z);
};
