#ifndef INCLUDE_RASTERIZER_H
#define INCLUDE_RASTERIZER_H

#include "defs.h"
#include "Framebuffer.h"
#include "Vector2.h"

class Rasterizer {
    public:
        Rasterizer(int width, int height);
        void initializeRasterizer(int width, int height);

        ~Rasterizer();
        
        void drawTri(Vector2& v0, Vector2& v1, Vector2& v2);

        inline void swap() {
            sFrame = framebuffers[currentframe ^= 1];
            rFrame = framebuffers[currentframe ^ 1];
        }

        void show();

        void clear();

    private:
        int width, height;
        Framebuffer *sFrame, *rFrame;
        int currentframe;
        Framebuffer *framebuffers[2];
};

#endif
