#include "../lib/Framebuffer.h"
#include <ncurses.h>

Framebuffer::Framebuffer(int width, int height)
    : width(width), height(height)
{
    depthbuffer = new depth_t[width * height];
    colorbuffer = new color_t[width * height];
}

Framebuffer::~Framebuffer() {
    delete[] depthbuffer;
    delete[] colorbuffer;
}

void Framebuffer::clear(color_t clearcolor) {
    memset(colorbuffer, clearcolor, sizeof(color_t) * width * height);
    memset(colorbuffer, MAX_DEPTH, sizeof(depth_t) * width * height);
}

void Framebuffer::setPixel(int x, int y, depth_t depth, color_t color) {
    int index = x + y * width;

    if (depth < depthbuffer[index]) {
        depthbuffer[index] = depth;
        colorbuffer[index] = color;
    }
}

void Framebuffer::show() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = x + y * width;

            if (!colorbuffer[index]) continue;

            mvprintw(x, y, "%c", (char)colorbuffer[index]);
        }
    }
}
