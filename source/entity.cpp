#include <cstdio>
#include "orbit/ecs/entity.h"

Entity::Entity(std::string name) : m_name(name) {}

void Entity::Awake() {
    printf("Entity %s awoken\n", m_name.c_str());
}

void Entity::Start() {
    printf("Entity %s started\n", m_name.c_str());
}

void Entity::Update() {
    printf("Entity %s updated\n", m_name.c_str());
}
