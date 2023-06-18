#ifndef ROOM_H
#define ROOM_H

enum CameraMode {
    CAMERA_FRONT,
    CAMERA_TOP
};

extern CameraMode currentCamera;

void displayRoom();

#endif
