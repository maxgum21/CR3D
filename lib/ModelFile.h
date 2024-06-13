#ifndef INCLUDE_MODELFILE_H
#define INCLUDE_MODELFILE_H

#include "Vector3.h"

#include <vector>
#include <string>

typedef struct {
    int v;
    int n;
    int uv;
} Vertex;

class Model {
    public:
        Model() {}
        Model(const std::string& filename);
        ~Model();

        Model& operator=(const Model& m);

        std::vector<Vector3>* vertices;
        std::vector<int>* indices;

        float *vert, *normals, *uvs;
        Vertex* ind;

        int getSizeVert() { return sizeVert; }
        int getSizeNorm() { return sizeNorm; }
        int getSizeUV()   { return sizeUV;   }
        int getSizeInd()  { return sizeInd;  }

    private:
        std::string filename;
        void readFile();
        int sizeVert, sizeNorm, sizeUV, sizeInd;
};

#endif
