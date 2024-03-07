#pragma once

class Vector3 {
public:
    // Constructors
    Vector3();
    Vector3(float x, float y, float z);

    // Destructor
    ~Vector3();

    // Getters and Setters
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    // Vector operations
    Vector3 add(const Vector3& other) const;
    Vector3 subtract(const Vector3& other) const;
    Vector3 multiply(float scalar) const;
    Vector3 divide(float scalar) const;
    float dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;
    float magnitude() const;
    Vector3 normalize() const;

private:
    float m_x;
    float m_y;
    float m_z;
};