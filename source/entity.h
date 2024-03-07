#pragma once

#include <string>
#include <gccore.h>

class Entity {
public:
    Entity(std::string name);

    void Start();
    void Update();

private:
    std::string m_name;
};