#include "CameraInterface.h"
#include "IpcCamera.h"
#include "camera.h"

CameraInterface* CameraInterface::get_camera(CameraType camera_type) {
    switch (camera_type) {
    case TypeUVCcamera:
        return Camera::instance();
        break;
    case TypeIpcCamera:
        return IpcCamera::instance();
        break;
    default:
        return Camera::instance();
        break;
    }
}

