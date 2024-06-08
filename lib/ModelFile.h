#ifndef INCLUDE_MODELFILE_H
#define INCLUDE_MODELFILE_H

#include "Vector3.h"

#include <vector>
#include <string>

class Model {
    public:
        Model() {}
        Model(const std::string& filename);
        ~Model();

        Model& operator=(const Model& m);

        std::vector<Vector3>* vertices;
        std::vector<int>* indices;

    private:
        std::string filename;
        void readFile();
};

#endif
