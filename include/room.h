#ifndef ROOM_H
#define ROOM_H

enum CameraMode {
    CAMERA_FRONT,
    CAMERA_TOP,
    CAMERA_OUTSIDE
};

extern CameraMode currentCamera;

void displayRoom();

#endif
