#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "custom/object.h"
class Rectangle : public Object {
    public:
        Rectangle(float* vertices, size_t size_v, unsigned int* indicies, size_t size_i);
        ~Rectangle();
        void draw() override;
};
#endif 
