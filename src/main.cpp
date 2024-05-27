#include "../lib/defs.h"
#include "../lib/Vector2.h"
#include "../lib/Rasterizer.h"

#define WW 200
#define WH 100

bool is_running = 1;

Rasterizer *raster = nullptr;

int main() {
    std::cout << "Program started...\n";

    initscr();

    noecho();

    raster = new Rasterizer(WW, WH);

    Vector2 points[3] = {
        Vector2(20, 10),
        Vector2(10, 20),
        Vector2(15, 30)
    };

    raster->drawTri(points[0], points[1], points[2]);
    raster->swap();
    raster->show();

    
    getch();

    endwin();

    delete raster;

    return 0;
}
