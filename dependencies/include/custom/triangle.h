#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object.h"
class Triangle : public Object {
    public:
        Triangle(float* vertices, size_t size_v, unsigned int* indicies, size_t size_i);
        ~Triangle();
        void draw() override;
};

#endif // !TRIANGLE_H

