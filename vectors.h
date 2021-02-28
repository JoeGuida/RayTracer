
#ifndef _VECTORS_H_
#define _VECTORS_H_

#include <cmath>
#include <cfloat>

#define CMP(x, y)                    \
	(fabsf((x)-(y)) <= FLT_EPSILON * \
		fmaxf(1.0f,                  \
		fmaxf(fabsf(x), fabsf(y)))   \
	)

#define RAD2DEG(x) ((x) * 57.295754f)
#define DEG2RAD(x) ((x) * 0.0174533f)

typedef struct Vec2 {
	union {
		struct {
			float x;
			float y;
		};
		float asArray[2];
	};

	float& operator[](int i) {
		return asArray[i];
	}

	inline Vec2() : x(0.0f), y(0.0f) { }
	inline Vec2(float _x) : x(_x), y(_x) { }
	inline Vec2(float _x, float _y) : x(_x), y(_y) { }
} Vec2;

typedef struct Vec3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float asArray[3];
	};

	float& operator[](int i) {
		return asArray[i];
	}

	inline Vec3() : x(0.0f), y(0.0f), z(0.0f) { }
	inline Vec3(float _x) : x(_x), y(_x), z(_x) { }
	inline Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }
} Vec3;

// Vector/Vector Addition
Vec2 operator+(const Vec2& l, const Vec2& r);
Vec3 operator+(const Vec3& l, const Vec3& r);

// Vector/float Addition
Vec2 operator+(const Vec2& l, float r);
Vec2 operator+(float l, const Vec2& r);
Vec3 operator+(const Vec3& l, float r);
Vec3 operator+(float l, const Vec3& r);

// Vector/Vector Addition Assignment
void operator+=(Vec2& l, const Vec2& r);
void operator+=(Vec3& l, const Vec3& r);

// Vector/float Addition Assignment
void operator+=(Vec2& l, float r);
void operator+=(Vec3& l, float r);

// Vector/Vector Subtraction
Vec2 operator-(const Vec2& l, const Vec2& r);
Vec3 operator-(const Vec3& l, const Vec3& r);

// Vector/float Subtraction
Vec2 operator-(const Vec2& l, float r);
Vec2 operator-(float l, const Vec2& r);
Vec3 operator-(const Vec3& l, float r);
Vec3 operator-(float l, const Vec3& r);

// Vector/Vector Subtraction Assignment
void operator-=(Vec2& l, const Vec2& r);
void operator-=(Vec3& l, const Vec3& r);

// Vector/float Subtraction Assignment
void operator-=(Vec2& l, float r);
void operator-=(Vec3& l, float r);

// Vector Negation
Vec2 operator-(const Vec2& v);
Vec3 operator-(const Vec3& v);

// Vector/Vector Multiplication
Vec2 operator*(const Vec2& l, const Vec2& r);
Vec3 operator*(const Vec3& l, const Vec3& r);

// Vector/float Multiplication
Vec2 operator*(const Vec2& l, float r);
Vec3 operator*(const Vec3& l, float r);
Vec2 operator*(float l, const Vec2& r);
Vec3 operator*(float l, const Vec3& r);

// Vector/Vector Multiplication Assignment
void operator*=(Vec2& l, const Vec2& r);
void operator*=(Vec3& l, const Vec3& r);

// Vector/float Multiplication Assignment
void operator*=(Vec2& l, float r);
void operator*=(Vec3& l, float r);

// Vector/float Division
Vec2 operator/(const Vec2& l, float r);
Vec3 operator/(const Vec3& l, float r);

// Vector Equality
bool operator==(const Vec2& l, const Vec2& r);
bool operator==(const Vec3& l, const Vec3& r);

// Vector Inequality
bool operator!=(const Vec2& l, const Vec2& r);
bool operator!=(const Vec3& l, const Vec3& r);

// Vector Dot Product
float Dot(const Vec2& l, const Vec2& r);
float Dot(const Vec3& l, const Vec3& r);

// Vector Magnitude
float Magnitude(const Vec2& v);
float Magnitude(const Vec3& v);

// Vector Magnitude Squared
float MagnitudeSq(const Vec2& v);
float MagnitudeSq(const Vec3& v);

// Vector Distance
float Distance(const Vec3& p1, const Vec3& p2);
float Distance(const Vec2& p1, const Vec2& p2);

// Vector Normalization Inplace
void Normalize(Vec2& v);
void Normalize(Vec3& v);

// Vector Normalization 
Vec2 Normalized(const Vec2& v);
Vec3 Normalized(const Vec3& v);

// Vector Cross Product
Vec3 Cross(const Vec3& l, const Vec3& r);

// Angle Between Vectors
float Angle(const Vec2& l, const Vec2& r);
float Angle(const Vec3& l, const Vec3& r);

// Vector Projection
Vec2 Project(const Vec2& length, const Vec2& direction);
Vec3 Project(const Vec3& length, const Vec3& direction);

// Perpendicular Vector
Vec2 Perpendicular(const Vec2& length, const Vec2& direction);
Vec3 Perpendicular(const Vec3& length, const Vec3& direction);

// Vector Reflection
Vec2 Reflection(const Vec2& vec, const Vec2& normal);
Vec3 Reflection(const Vec3& vec, const Vec3& normal);

#endif