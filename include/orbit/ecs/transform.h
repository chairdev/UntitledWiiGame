#pragma once

#include "orbit/math/vector3.h"

class Transform {
public:
    Transform() = default; // Add default constructor

    Transform(Vector3 pos);

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

};