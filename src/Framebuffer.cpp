#include "../lib/Framebuffer.h"
#include <cstring>

Framebuffer::Framebuffer(int width, int height)
    : width(width), height(height)
{
    depthbuffer = new depth_t[width * height];
    colorbuffer = new color_t[width * height];
}

Framebuffer::~Framebuffer() {
    delete[] colorbuffer;
    delete[] depthbuffer;
}

Framebuffer::Framebuffer(const Framebuffer& fb) : width(fb.width), height(fb.height)
{
    depthbuffer = new depth_t[width * height];
    memcpy(depthbuffer, fb.depthbuffer, sizeof(depth_t) * width * height);
    colorbuffer = new color_t[width * height];
    memcpy(colorbuffer, fb.colorbuffer, sizeof(color_t) * width * height);
}

Framebuffer& Framebuffer::operator=(const Framebuffer& fb) {
    depthbuffer = new depth_t[width * height];
    memcpy(depthbuffer, fb.depthbuffer, sizeof(depth_t) * width * height);
    colorbuffer = new color_t[width * height];
    memcpy(colorbuffer, fb.colorbuffer, sizeof(color_t) * width * height);
    return *this;
}

void Framebuffer::clear(color_t clearcolor) {
    memset(colorbuffer, clearcolor, sizeof(color_t) * width * height);
    memset(depthbuffer, MAX_DEPTH, sizeof(depth_t) * width * height);
}

void Framebuffer::setPixel(int x, int y, depth_t depth, color_t color) {

    if (x < 0 || x >= width || y < 0 || y >= height) return;

    int index = x + y * width;

    if (depth <= depthbuffer[index]) {
        depthbuffer[index] = depth;
        colorbuffer[index] = color;
    }
}

void Framebuffer::show() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = x + (y * width);

            if (!colorbuffer[index]) continue;

            mvprintw(y, x, "%c", (char)colorbuffer[index]);
        }
    }
}
