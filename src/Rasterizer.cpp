#include "../lib/Rasterizer.h"

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

Rasterizer::Rasterizer(int width, int height)
    : currentframe(0), sFrame(nullptr), rFrame(nullptr), width(width), height(height) {
    initializeRasterizer(width, height);
}

Rasterizer::~Rasterizer() {
    delete framebuffers[0];
    delete framebuffers[1];
}

void Rasterizer::initializeRasterizer(int width, int height) {
    framebuffers[0] = new Framebuffer(width, height);
    framebuffers[1] = new Framebuffer(width, height);
    swap();
}

void Rasterizer::show() {
    sFrame->show();
}

void Rasterizer::clear() {
    rFrame->clear(0);
}


void Rasterizer::drawTri(Vector2& v0, Vector2& v1, Vector2& v2) {
    int xmin = MAX(0, MIN(v0.x, MIN(v1.x, v2.x)));
    int ymin = MAX(0, MIN(v0.y, MIN(v1.y, v2.y)));
    int xmax = MIN(width, MAX(v0.x, MAX(v1.x, v2.x)));
    int ymax = MIN(height, MAX(v0.x, MAX(v1.x, v2.x)));

    for (int y = ymin; y < ymax; y++) {
        for (int x = xmin; x < xmax; x++) {
            rFrame->setPixel(x, y, 0, '#');
        }
    }
}
