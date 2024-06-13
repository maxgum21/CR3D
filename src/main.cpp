#include "../lib/Vector2.h"
#include "../lib/Rasterizer.h"
#include "../lib/Matrix4x4.h"
#include "../lib/Camera.h"
#include "../lib/ModelFile.h"

#include <sstream>
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <time.h>

#define WW 400
#define WH 200
#define PI 3.14159

bool is_running = 1;

Rasterizer *raster = nullptr;

Camera *cam = nullptr;

std::stringstream debug;

int framerate = 0;

float angle = 0.0;
float offsetx, offsetz = -3;

float delta_time;

Model* firstModel;

bool renderFunc() {
    cam->calculateViewMatrix();
    Matrix4x4 PVMatrix = cam->getProjMat();

    angle += delta_time;

    Matrix4x4 transform(1);
    transform.translate(Vector3(offsetx, -0, offsetz));
    transform.rotate(Vector3(0, 1, 0).normalized(), angle);
    //transform.rotate(Vector3(0, 0, 1), angle);
    
    Matrix4x4 finalmat = PVMatrix * transform;

    raster->clear();

    for (int i = 0; i < firstModel->getSizeInd(); i += 3) {
        int j1 = firstModel->ind[i + 0].v;
        Vector4 v1(
                firstModel->vert[j1 * 3 + 0],
                firstModel->vert[j1 * 3 + 1],
                firstModel->vert[j1 * 3 + 2],
                1
                );

        int j2 = firstModel->ind[i + 1].v;
        Vector4 v2(
                firstModel->vert[j2 * 3 + 0],
                firstModel->vert[j2 * 3 + 1],
                firstModel->vert[j2 * 3 + 2],
                1
                );

        int j3 = firstModel->ind[i + 2].v;
        Vector4 v3(
                firstModel->vert[j3 * 3 + 0],
                firstModel->vert[j3 * 3 + 1],
                firstModel->vert[j3 * 3 + 2],
                1
                );

        Vector4 f1 = finalmat * v1;
        Vector4 f2 = finalmat * v2;
        Vector4 f3 = finalmat * v3;

        f1 = Vector4( f1.x / f1.w, f1.y / f1.w, f1.z / f1.w, f1.w );
        f2 = Vector4( f2.x / f2.w, f2.y / f2.w, f2.z / f2.w, f2.w );
        f3 = Vector4( f3.x / f3.w, f3.y / f3.w, f3.z / f3.w, f3.w );

        raster->drawTri(
                f1.getXY(),
                f2.getXY(),
                f3.getXY()
                );
    }

    return true;
}


int main() {
    std::cout << "Program started...\n";

    firstModel = new Model("models/amogus.obj");

    initscr();

    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    int mw, mh;

    getmaxyx(stdscr, mh, mw);

    raster = new Rasterizer(mw, mh);
    raster->setRenderCB(&renderFunc);
    
    cam = new Camera();

    cam->calculateProjMatrix(PI / 2.0, (mw * 0.5f) / (float)mh, 0.2f, 400.0f);
    
    char c = 0;

    clock_t begin_time = clock();

    while (c != 'q') {

        clock_t new_time = clock();
        delta_time = (new_time - begin_time) / (float)CLOCKS_PER_SEC;
        begin_time = new_time;

        raster->presentFrame();
        raster->swap();
        mvprintw(0, (mw * 80) / 100, "Framerate: %d f/s", (int)(1.0 / delta_time));
        mvprintw(1, (mw * 80) / 100, "Resolution: %d by %d", mw, mh);

        refresh();

        c = getch();

        erase();

        switch (c) {
            case 'w':
                offsetz -= 0.1;
                break;
            case 's':
                offsetz += 0.1;
                break;
            case 'a':
                offsetx -= 0.1;
                break;
            case 'd':
                offsetx += 0.1;
                break;
        }
        

    }
    
    curs_set(1);

    endwin();

    delete raster;
    delete firstModel;
    delete cam;

    return 0;
}
