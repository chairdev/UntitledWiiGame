#pragma once

using namespace std;

#include <string>
#include <gccore.h>
#include "transform.h"
#include "orbit/math/vector3.h" // Include the header file for the Vector3 class
#include "transform.h" // Include the header file for the Transform class


class Entity {
public:
    Entity(string name, Vector3 pos = Vector3(0, 0, 0));

    Transform transform = Transform(Vector3(0, 0, 0));

    void Awake();
    void Start();
    void Update();

private:
    string m_name;
};