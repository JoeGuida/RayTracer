
#include "vectors.h"

// Vector/Vector Addition
Vec2 operator+(const Vec2& l, const Vec2& r) {
	return { l.x + r.x, l.y + r.y };
}

Vec3 operator+(const Vec3& l, const Vec3& r) {
	return { l.x + r.x, l.y + r.y, l.z + r.z };
}

// Vector/float Addition
Vec2 operator+(const Vec2& l, float r) {
	return { l.x + r, l.y + r };
}

Vec2 operator+(float l, const Vec2& r) {
	return r + l;
}

Vec3 operator+(const Vec3& l, float r) {
	return { l.x + r, l.y + r, l.z + r };
}

Vec3 operator+(float l, const Vec3& r) {
	return r + l;
}

// Vector/Vector Addition Assignment
void operator+=(Vec2& l, const Vec2& r) {
	l = l + r;
}

void operator+=(Vec3& l, const Vec3& r) {
	l = l + r;
}

// Vector/float Addition Assignment
void operator+=(Vec2& l, float r) {
	l = { l.x + r, l.y + r };
}

void operator+=(Vec3& l, float r) {
	l = { l.x + r, l.y + r, l.z + r };
}

// Vector/Vector Subtraction
Vec2 operator-(const Vec2& l, const Vec2& r) {
	return { l.x - r.x, l.y - r.y };
}

Vec3 operator-(const Vec3& l, const Vec3& r) {
	return { l.x - r.x, l.y - r.y, l.z - r.z };
}

// Vector/float Subtraction
Vec2 operator-(const Vec2& l, float r) {
	return { l.x - r, l.y - r };
}

Vec2 operator-(float l, const Vec2& r) {
	return r - l;
}

Vec3 operator-(const Vec3& l, float r) {
	return { l.x - r, l.y - r, l.z - r };
}

Vec3 operator-(float l, const Vec3& r) {
	return r - l;
}

// Vector/Vector Subtraction Assignment
void operator-=(Vec2& l, const Vec2& r) {
	l = l - r;
}

void operator-=(Vec3& l, const Vec3& r) {
	l = l - r;
}

// Vector/float Subtraction Assignment
void operator-=(Vec2& l, float r) {
	l = { l.x - r, l.y - r };
}

void operator-=(Vec3& l, float r) {
	l = { l.x - r, l.y - r, l.z - r };
}

// Vector Negation
Vec2 operator-(const Vec2& v) {
	return { -v.x, -v.y };
}

Vec3 operator-(const Vec3& v) {
	return { -v.x, -v.y, -v.z };
}

// Vector/Vector Multiplication
Vec2 operator*(const Vec2& l, const Vec2& r) {
	return { l.x * r.x, l.y * r.y };
}

Vec3 operator*(const Vec3& l, const Vec3& r) {
	return { l.x * r.x, l.y * r.y, l.z * r.z };
}

// Vector/float Multiplication
Vec2 operator*(const Vec2& l, float r) {
	return { l.x * r, l.y * r };
}

Vec3 operator*(const Vec3& l, float r) {
	return { l.x * r, l.y * r, l.z * r };
}

Vec2 operator*(float l, const Vec2& r) {
	return r * l;
}

Vec3 operator*(float l, const Vec3& r) {
	return r * l;
}

// Vector/Vector Multiplication Assignment
void operator*=(Vec2& l, const Vec2& r) {
	l = l * r;
}

void operator*=(Vec3& l, const Vec3& r) {
	l = l * r;
}

// Vector/float Multiplication Assignment
void operator*=(Vec2& l, float r) {
	l = { l.x * r, l.y * r };
}

void operator*=(Vec3& l, float r) {
	l = { l.x * r, l.y * r, l.z * r };
}

// Vector/float Division
Vec2 operator/(const Vec2& l, float r) {
	float s = 1.0f / r;
	return { l.x * s, l.y * s };
}

Vec3 operator/(const Vec3& l, float r) {
	float s = 1.0f / r;
	return { l.x * s, l.y * s, l.z * s };
}

// Vector Equality
bool operator==(const Vec2& l, const Vec2& r) {
	return CMP(l.x, r.x) && CMP(l.y, r.y);
}

bool operator==(const Vec3& l, const Vec3& r) {
	return CMP(l.x, r.x) && CMP(l.y, r.y) && CMP(l.z, r.z);
}

// Vector Inequality
bool operator!=(const Vec2& l, const Vec2& r) {
	return !(l == r);
}

bool operator!=(const Vec3& l, const Vec3& r) {
	return !(l == r);
}

// Vector Dot Product
float Dot(const Vec2& l, const Vec2& r) {
	return l.x * r.x + l.y * r.y;
}

float Dot(const Vec3& l, const Vec3& r) {
	return l.x * r.x + l.y * r.y + l.z * r.z;
}

// Vector Magnitude
float Magnitude(const Vec2& v) {
	return sqrtf(Dot(v, v));
}

float Magnitude(const Vec3& v) {
	return sqrtf(Dot(v, v));
}

// Vector Magnitude Squared
float MagnitudeSq(const Vec2& v) {
	return Dot(v, v);
}

float MagnitudeSq(const Vec3& v) {
	return Dot(v, v);
}

// Vector Distance
float Distance(const Vec3& p1, const Vec3& p2) {
	Vec3 t = p1 - p2;
	return Magnitude(t);
}

float Distance(const Vec2& p1, const Vec2& p2) {
	Vec2 t = p1 - p2;
	return Magnitude(t);
}

// Vector Normalization Inplace
void Normalize(Vec2& v) {
	v = v * (1.0f / Magnitude(v));
}

void Normalize(Vec3& v) {
	v = v * (1.0f / Magnitude(v));
}

// Vector Normalization 
Vec2 Normalized(const Vec2& v) {
	return v * (1.0f / Magnitude(v));
}

Vec3 Normalized(const Vec3& v) {
	return v * (1.0f / Magnitude(v));
}

// Vector Cross Product
Vec3 Cross(const Vec3& l, const Vec3& r) {
	Vec3 result;
	result.x = l.y * r.z - l.z * r.y;
	result.y = l.z * r.x - l.x * r.z;
	result.z = l.x * r.y - l.y * r.x;
	return result;
}

// Angle Between Vectors
float Angle(const Vec2& l, const Vec2& r) {
	float m = sqrtf(MagnitudeSq(l) * MagnitudeSq(r));
	return acos(Dot(l, r) / m);
}

float Angle(const Vec3& l, const Vec3& r) {
	float m = sqrtf(MagnitudeSq(l) * MagnitudeSq(r));
	return acos(Dot(l, r) / m);
}

// Vector Projection
Vec2 Project(const Vec2& length, const Vec2& direction) {
	float dot = Dot(length, direction);
	float magSq = MagnitudeSq(direction);
	return direction * (dot / magSq);
}

Vec3 Project(const Vec3& length, const Vec3& direction) {
	float dot = Dot(length, direction);
	float magSq = MagnitudeSq(direction);
	return direction * (dot / magSq);
}

// Perpendicular Vector
Vec2 Perpendicular(const Vec2& length, const Vec2& direction) {
	return length - Project(length, direction);
}

Vec3 Perpendicular(const Vec3& length, const Vec3& direction) {
	return length - Project(length, direction);
}

Vec2 Reflection(const Vec2& vec, const Vec2& normal) {
	float d = Dot(vec, normal);
	return vec - 2 * Dot(vec, normal) * normal;
}

// Vector Reflection
Vec3 Reflection(const Vec3& vec, const Vec3& normal) {
	float d = Dot(vec, normal);
	return vec - 2 * Dot(vec, normal) * normal;
}