#pragma once

using namespace std;

#include <string>
#include <gccore.h>
#include "transform.h"

class Entity {
public:
    Entity(string name);

    Transform transform;

    void Awake();
    void Start();
    void Update();

private:
    string m_name;
};