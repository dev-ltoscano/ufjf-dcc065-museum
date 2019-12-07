#ifndef CYLINDER_H_INCLUDED
#define CYLINDER_H_INCLUDED

#define CIRCLE_VERTEX_COUNT 360

#include <vector>
#include <iostream>

#include "object/Object.h"
#include "primitive/Vertex3D.h"
#include "primitive/Triangle.h"

class Cylinder : public Object
{
    public:
        Cylinder(double radius);
};

#endif // CYLINDER_H_INCLUDED
