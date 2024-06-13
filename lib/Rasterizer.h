#ifndef INCLUDE_RASTERIZER_H
#define INCLUDE_RASTERIZER_H

#include "Framebuffer.h"
#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector4.h"
#include "ModelFile.h"

class Rasterizer {
    public:
        Rasterizer(int width, int height);

        ~Rasterizer();
        
        void drawTri(const Vector2& v0, const Vector2& v1, const Vector2& v2);

        inline void setRenderCB(bool (*renderCBFunc)()) {
            renderCB = renderCBFunc;
        }

        inline void swap() {
            sFrame = framebuffers[currentframe ^= 1];
            rFrame = framebuffers[currentframe ^ 1];
        }

        void presentFrame();

        void clear();

    private:
        int width, height;
        bool (*renderCB)();
        Framebuffer *sFrame, *rFrame;
        int currentframe;
        Framebuffer *framebuffers[2];

        std::thread renderThread;

};

Vector4 transformVertex(const Vector4& vec, const Matrix4x4& MPVMatrix);

#endif
