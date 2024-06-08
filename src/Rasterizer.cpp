#include "../lib/Rasterizer.h"
#include "../lib/Vector4.h"

#include <ncurses.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

bool renderStart, renderFinished, programRunning;

void renderThreadF(bool(**renderCB)()){
    while(programRunning){
        if(renderStart){
            renderStart = false;
            renderFinished = false;

            if(*renderCB != nullptr){
                (*renderCB)();
            }

            renderFinished = true;
        }
    }
}


Rasterizer::Rasterizer(int width, int height)
    : width(width), height(height), renderCB(nullptr),
      sFrame(nullptr), rFrame(nullptr), currentframe(0) {

    framebuffers[0] = new Framebuffer(width, height);
    framebuffers[1] = new Framebuffer(width, height);
    swap();

    programRunning = true;
    renderStart = false;
    renderFinished = false;
    renderThread = std::thread(renderThreadF, &renderCB);
}

Rasterizer::~Rasterizer() {
    programRunning = false;

    renderThread.join();

    delete framebuffers[1];
    delete framebuffers[0];
}

void Rasterizer::presentFrame() {
    renderStart = true;
    sFrame->show();
    while (!renderFinished);
}

void Rasterizer::clear() {
    rFrame->clear(' ');
}

float edgeCross(const Vector2& a, const Vector2& b, Vector2& p) {
    Vector2 ab = b - a;// Vector2(b.x - a.x, b.y - a.y);
    Vector2 ap = p - a;

    return ap % ab;
}

void Rasterizer::drawTri(const Vector2& vv0, const Vector2& vv1, const Vector2& vv2) {

    float h_width = this->width * 0.5, h_height = this->height * 0.5;

    Vector2 v0 = Vector2(vv0.x * h_width + h_width, -vv0.y * h_height + h_height);
    Vector2 v1 = Vector2(vv1.x * h_width + h_width, -vv1.y * h_height + h_height);
    Vector2 v2 = Vector2(vv2.x * h_width + h_width, -vv2.y * h_height + h_height);

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

Vector4 transformVertex(const Vector4& vec, const Matrix4x4& MPVMatrix) {
    Vector4 res = MPVMatrix * vec;

    res.x /= res.w;
    res.y /= res.w;
    res.z /= res.w;

    return res;
}

void Rasterizer::drawModel(const Model& m, const Matrix4x4& transform) {
    for (int i = 0; i < m.indices->size(); i += 3) {

        int i0 = m.indices->at(i);
        int i1 = m.indices->at(i + 1);
        int i2 = m.indices->at(i + 2);

        Vector4 v0 = transformVertex(Vector4(m.vertices->at(i0)), transform);
        Vector4 v1 = transformVertex(Vector4(m.vertices->at(i1)), transform);
        Vector4 v2 = transformVertex(Vector4(m.vertices->at(i2)), transform);

        drawTri(v0.getXY(), v1.getXY(), v2.getXY());
    }
}

            /*float w0 = ((x - v0.x)*(v2.y - v0.y) - (v2.x - v0.x)*(y - v0.y)) /
                ((v1.x - v0.x)*(v2.y - v0.y) - (v1.y - v0.y)*(v2.x - v0.x));

            float w1 = (y - v0.y - w0*(v1.y - v0.y)) / (v2.y - v0.y);

            if (w0 >= 0 && w1 >= 0 && (w0 + w1) <= 1) {
                rFrame->setPixel(x, y, 0, '#');
            }*/
