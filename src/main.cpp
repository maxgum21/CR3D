#include "../lib/defs.h"
#include "../lib/Vector2.h"
#include "../lib/Rasterizer.h"
#include "../lib/Matrix3x3.h"

#define WW 300
#define WH 200

bool is_running = 1;

Rasterizer *raster = nullptr;

int main() {
    std::cout << "Program started...\n";
    
    
    initscr();

    noecho();
    curs_set(0);

    raster = new Rasterizer(WW, WH);

    Vector2 points[3] = {
        Vector2(20, 10),
        Vector2(10, 20),
        Vector2(105, 10)
    };

    raster->clear();
    raster->drawTri(points[0], points[1], points[2]);
    raster->swap();
    raster->show();

    
    char c = getch();

    curs_set(1);

    endwin();

    std::cout << "Got char: " << c << std::endl;

    delete raster;

    Matrix3x3 m = Matrix3x3(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 8.0, 9.0);

    m.invert();

    return 0;
}
