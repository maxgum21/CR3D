#include "../lib/Rasterizer.h"
#include <ncurses.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

Rasterizer::Rasterizer(int width, int height)
    : currentframe(0), sFrame(nullptr), rFrame(nullptr), width(width), height(height) {
    framebuffers[0] = new Framebuffer(width, height);
    framebuffers[1] = new Framebuffer(width, height);
    swap();
}

Rasterizer::~Rasterizer() {
    delete framebuffers[1];
    delete framebuffers[0];
}

void Rasterizer::show() {
    sFrame->show();
}

void Rasterizer::clear() {
    rFrame->clear(0);
}

float edgeCross(const Vector2& a, const Vector2& b, Vector2& p) {
    Vector2 ab = b - a;// Vector2(b.x - a.x, b.y - a.y);
    Vector2 ap = p - a;

    return ap % ab;
}

void Rasterizer::drawTri(const Vector2& v0, const Vector2& v1, const Vector2& v2) {
    int xmin = MAX(0, MIN(v0.x, MIN(v1.x, v2.x)));
    int ymin = MAX(0, MIN(v0.y, MIN(v1.y, v2.y)));
    int xmax = MIN(width, MAX(v0.x, MAX(v1.x, v2.x)));
    int ymax = MIN(height, MAX(v0.y, MAX(v1.y, v2.y)));

    float area = Vector2(v1.x - v2.x, v1.y - v2.y) % Vector2(v0.x - v2.x, v0.y - v2.y);

    for (int y = ymin; y <= ymax; y++) {
        for (int x = xmin; x <= xmax; x++) {
            float w0 = (Vector2(x - v1.x, y - v1.y) % Vector2(v2.x - v1.x, v2.y - v1.y)) / area;
            float w1 = (Vector2(x - v2.x, y - v2.y) % Vector2(v0.x - v2.x, v0.y - v2.y)) / area;
            float w2 = 1.0 - w0 - w1;

            bool cond1 = (w0 < -0.01);
            bool cond2 = (w1 < -0.01);
            bool cond3 = (w2 < -0.01);

            if ((cond1 == cond2) && (cond1 == cond3)) {
                rFrame->setPixel(x, y, 0, '#');
            }
        }
    }
}


            /*float w0 = ((x - v0.x)*(v2.y - v0.y) - (v2.x - v0.x)*(y - v0.y)) /
                ((v1.x - v0.x)*(v2.y - v0.y) - (v1.y - v0.y)*(v2.x - v0.x));

            float w1 = (y - v0.y - w0*(v1.y - v0.y)) / (v2.y - v0.y);

            if (w0 >= 0 && w1 >= 0 && (w0 + w1) <= 1) {
                rFrame->setPixel(x, y, 0, '#');
            }*/
