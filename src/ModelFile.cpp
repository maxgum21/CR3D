#include "../lib/ModelFile.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Model::Model(const std::string& filename) :
    filename(filename),
    vert(nullptr),
    normals(nullptr),
    uvs(nullptr),
    ind(nullptr)
{
    vertices = new std::vector<Vector3>();
    indices = new std::vector<int>();
    readFile();
}

Model::~Model() {
    delete vertices;
    delete indices;

    if (vert) delete[] vert;
    if (normals) delete[] normals;
    if (uvs) delete[] uvs;

    if (ind) delete[] ind;
}

Model& Model::operator=(const Model& m) {
    vertices = m.vertices;
    indices = m.indices;
    filename = m.filename;

    vert = m.vert;
    normals = m.normals;
    uvs = m.uvs;

    ind = m.ind;

    return *this;
}

std::vector<std::string> split(std::string& str, char delim) {
    std::stringstream stream(str);
    std::vector<std::string> spl;
    std::string token;

    while (std::getline(stream, token, delim)) {
        spl.push_back(token);
    }
    return spl;
}

void Model::readFile() {
    std::ifstream objfile;
    objfile.open(filename);

    if (!objfile.is_open()) {
        std::cerr << "Can't open file: " << filename << '\n';
    }

    std::cout << filename << '\n';

    std::string line;

    std::vector<float> vert_vec, norms_vec, uvs_vec;
    std::vector<Vertex> ind_vec;

    while ( std::getline(objfile, line) ) {
        std::stringstream lstr;

        if (line[0] == 'v') {
            if (line[1] == 'n') {
                //std::cout << "Got normal: " << line << '\n';
                std::vector<std::string> spl = split(line, ' ');

                float x = std::stof(spl[1]), y = std::stof(spl[2]), z = std::stof(spl[3]);

                norms_vec.push_back(x);
                norms_vec.push_back(y);
                norms_vec.push_back(z);
            } else if (line[1] == 't') {
                //std::cout << "Got UV: " << line << '\n';
                std::vector<std::string> spl = split(line, ' ');

                float x = std::stof(spl[1]), y = std::stof(spl[2]);

                uvs_vec.push_back(x);
                uvs_vec.push_back(y);
            } else {
                //std::cout << "Got vert: " << line << '\n';

                std::vector<std::string> spl = split(line, ' ');

                float x = std::stof(spl[1]), y = std::stof(spl[2]), z = std::stof(spl[3]);

                vert_vec.push_back(x);
                vert_vec.push_back(y);
                vert_vec.push_back(z);
                Vector3 vec = Vector3(x, y, z);

                vertices->push_back(vec);
            }
        } else if (line[0] == 'f') {
            lstr.str(line.substr(2, 15));

            int a, b, c;
            lstr >> a >> b >> c;

            indices->push_back(a - 1);
            indices->push_back(b - 1);
            indices->push_back(c - 1);

            std::vector<std::string> spl = split(line, ' ');

            for (int i = 1; i <= 3; i++) {
                std::vector<std::string> spl2 = split(spl[i], '\\');

                Vertex v;
                if (spl2.size() == 3) v.n  = std::stoi(spl2[2]) - 1;
                if (spl2.size() >= 2) v.uv = std::stoi(spl2[1]) - 1;
                v.v = std::stoi(spl2[0]) - 1;

                ind_vec.push_back(v);
            }
        }
    }

    objfile.close();

    sizeVert = vert_vec.size();
    sizeNorm = norms_vec.size();
    sizeUV = uvs_vec.size();
    sizeInd = ind_vec.size();

    vert = new float[sizeVert];
    for (int i = 0; i < sizeVert; i++) vert[i] = vert_vec[i];

    if (sizeNorm) {
        normals = new float(sizeNorm);
        for (int i = 0; i < sizeNorm; i++) normals[i] = norms_vec[i];
    }

    if (sizeUV) {
        uvs = new float(sizeUV);
        for (int i = 0; i < sizeVert; i++) uvs[i] = uvs_vec[i];
    }

    ind = new Vertex[sizeInd];
    for (int i = 0; i < sizeInd; i++) ind[i] = ind_vec[i];
}
