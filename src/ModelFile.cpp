#include "../lib/ModelFile.h"

#include <fstream>
#include <iostream>
#include <sstream>

Model::Model(const std::string& filename) 
    : filename(filename)
{
    vertices = new std::vector<Vector3>();
    indices = new std::vector<int>();
    readFile();
}

Model::~Model() {
    delete vertices;
    delete indices;
}

Model& Model::operator=(const Model& m) {
    vertices = m.vertices;
    indices = m.indices;
    filename = m.filename;
    return *this;
}

void Model::readFile() {
    std::ifstream objfile;
    objfile.open(filename);

    if (!objfile.is_open()) {
        std::cerr << "Can't open file: " << filename << '\n';
    }

    std::cout << filename << '\n';

    std::string line;

    while ( std::getline(objfile, line) ) {

        if (line[0] == 'v') {
            if (line[1] == 'n') {
                //std::cout << "Got normal: " << line << '\n';
            } else if (line[1] == 't') {
                //std::cout << "Got UV: " << line << '\n';
            } else {
                //std::cout << "Got vert: " << line << '\n';
                std::stringstream lstr;
                lstr.str(line.substr(2, 40));
                float x, y, z;

                lstr >> x >> y >> z;

                Vector3 vec(x, y, z);

                vertices->push_back(vec);
            }
        } else if (line[0] == 'f') {
            std::stringstream lstr;
            lstr.str(line.substr(2, 15));

            int a, b, c;
            lstr >> a >> b >> c;

            indices->push_back(a - 1);
            indices->push_back(b - 1);
            indices->push_back(c - 1);
        }
    }

    objfile.close();
}
