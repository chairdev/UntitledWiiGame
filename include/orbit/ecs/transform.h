#pragma once

#include "orbit/ecs/vector3.h"

class Transform {
public:
    Transform(Vector3 pos);

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

};