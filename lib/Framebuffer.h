#ifndef INCLUDE_FRAMEBUFFER_H
#define INCLUDE_FRAMEBUFFER_H

#include <sys/types.h>
#include "defs.h"

#define MAX_DEPTH 0xFF

typedef u_int8_t depth_t;
typedef u_int8_t color_t;

class Framebuffer {
    public:
        Framebuffer(int width, int height);
        ~Framebuffer();
        Framebuffer(const Framebuffer& fb);

        Framebuffer& operator=(const Framebuffer& fb);

        void setPixel(int x, int y, depth_t depth, color_t color);

        inline color_t getColor(int x, int y) { return colorbuffer[x + y * width]; }

        void clear(color_t clearcolor);

        void show();

    private:
        int width, height;
        depth_t *depthbuffer;
        color_t *colorbuffer;
        
};

#endif
