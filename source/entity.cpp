#include <cstdio>
#include "orbit/ecs/entity.h"
#include "orbit/math/vector3.h" // Include the header for Vector3
#include "orbit/ecs/transform.h" // Include the header for Transform


Entity::Entity(std::string name, Vector3 pos) : m_name(name), transform(Transform(pos)) {
}

void Entity::Awake() {
    printf("Entity %s awoken\n", m_name.c_str());
}

void Entity::Start() {
    printf("Entity %s started\n", m_name.c_str());
}

void Entity::Update() {
    printf("Entity %s updated\n", m_name.c_str());
}
