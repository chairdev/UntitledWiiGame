#include "entity.h"
#include <cstdio>

Entity::Entity(std::string name) : m_name(name) {}

void Entity::Start() {
    printf("Entity %s started\n", m_name.c_str());
}

void Entity::Update() {
    printf("Entity %s updated\n", m_name.c_str());
}
