#include "../lib/Camera.h"

Camera::Camera() :
    position(0.0, 0.0, 0.0),
    rotation(0.0, 0.0, 0.0),
    viewMatrix(),
    projMatrix() 
{
    calculateViewMatrix();
}

Camera::~Camera() {}

void Camera::calculateProjMatrix(float fov, float aspect, float zNear, float zFar){
    projMatrix = Matrix4x4();

    float tanhfov = (float)tanf(fov / 2);

    projMatrix.m00 = 1/(aspect * tanhfov);
    projMatrix.m11 = 1/tanhfov;
    projMatrix.m22 = -(zNear + zFar) / (zFar - zNear);
    projMatrix.m32 = -(2 * zFar * zNear) / (zFar - zNear);
    projMatrix.m23 = -1;

    projMatrix.transpose();
}

Vector4 transformVertex(const Vector4& vec, const Matrix4x4& MPVMatrix) {
    Vector4 res = MPVMatrix * vec;

    res.x /= res.w;
    res.y /= res.w;
    res.z /= res.w;

    return res;
}
