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

float delta_time;

Model* firstModel;

bool renderFunc() {
    cam->calculateViewMatrix();
    Matrix4x4 PVMatrix = cam->getProjMat();

    angle += delta_time;

    Matrix4x4 transform(1);
    transform.translate(Vector3(0, 0, -7));
    transform.rotate(Vector3(0, 1, 0), angle);
    transform.rotate(Vector3(0, 0, 1), angle);
    
    Matrix4x4 finalmat = PVMatrix * transform;

    raster->clear();
    raster->drawModel(*firstModel, finalmat);
    return true;
}


int main() {
    std::cout << "Program started...\n";

    firstModel = new Model("models/teapot.obj");

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

        //refresh();

        c = getch();

        //erase();
        

    }
    
    curs_set(1);

    endwin();

    delete raster;
    delete firstModel;
    delete cam;

    return 0;
}
