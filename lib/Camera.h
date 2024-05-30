#ifndef INCLUDE_CAMERA_H
#define INCLUDE_CAMERA_H

#include "defs.h"
#include "Matrix4x4.h"
#include "Vector3.h"

class Camera {
    public:
        
        Camera();
        ~Camera();

        inline Vector3& getPosition() { return position; }
        inline Vector3& getRotation() { return rotation; }

        inline void calculateViewMatrix() {
            viewMatrix = Matrix4x4(1);
            viewMatrix.rotate(Vector3(1, 0, 0), rotation.x);
            viewMatrix.rotate(Vector3(0, 1, 0), rotation.y);
            viewMatrix.rotate(Vector3(0, 0, 1), rotation.z);
            viewMatrix.translate(position);
        }

        void calculateProjMatrix(float fov, float aspect, float zNear, float zFar);

        inline Matrix4x4 getViewMat() { return viewMatrix; }
        inline Matrix4x4 getProjMat() { return projMatrix; }
        inline Matrix4x4 getPVMat() { return projMatrix * viewMatrix; }

        private:
            Vector3 position, rotation;
            Matrix4x4 viewMatrix, projMatrix;
};

Vector4 transformVertex(const Vector4& vec, const Matrix4x4& MPVMatrix);

#endif
