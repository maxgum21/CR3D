#include "../lib/defs.h"
#include "../lib/Vector2.h"
#include "../lib/Rasterizer.h"
#include "../lib/Matrix4x4.h"
#include "../lib/Camera.h"
#include <ctime>
#include <iterator>
#include <ncurses.h>

#define WW 400
#define WH 200
#define PI 3.14159

bool is_running = 1;

Rasterizer *raster = nullptr;

Camera *cam = nullptr;

std::stringstream debug;

int framerate = 0;

float angle = 0.0;
float offset = 0.0;

Vector4 f1(-1, 1, 0, 1);
Vector4 f2(1, 1, 0, 1);
Vector4 f3(0, -1, 0, 1);

bool renderFunc() {
    cam->calculateViewMatrix();
    Matrix4x4 PVMatrix = cam->getProjMat();

    angle += 0.0001;
    offset += 0.0001;

    Matrix4x4 transform(1);
    transform.translate(Vector3(0, 0, -2.f));
    transform.rotate(Vector3(0, 1, 0), angle);
    
    Matrix4x4 finalmat = PVMatrix * transform;

    Vector4 v1 = transformVertex(f1, finalmat);
    Vector4 v2 = transformVertex(f2, finalmat);
    Vector4 v3 = transformVertex(f3, finalmat);

    //v1.print(debug);
    //debug <<'\n';

    raster->clear();
    raster->drawTri(Vector2(v1.x, v1.y), Vector2(v2.x, v2.y), Vector2(v3.x, v3.y));
    return true;
}


int main() {
    std::cout << "Program started...\n";
    
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
        raster->presentFrame();
        raster->swap();
        mvprintw(10, (mw * 100) / 70, "Framerate: %d f/s", framerate);

        refresh();

        c = getch();

        erase();
        
        clock_t new_time = clock();
        framerate =  CLOCKS_PER_SEC /  (new_time - begin_time);
        begin_time = new_time;

    }
    
    curs_set(1);

    endwin();

    delete raster;
    delete cam;

    Matrix4x4 tr(1);
    tr.translate(Vector3(1, 2, 3));
    Vector4 vec(0, 4, 7, 1);

    tr.print(debug);

    (tr * vec).print(debug);

    std::cout << debug.str();

    return 0;
}
