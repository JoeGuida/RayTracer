#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "ray.h"
#include "hit.h"
#include "color.h"

class Object {
public:
	virtual ~Object() = default;
	virtual bool Intersect(const Ray& ray, Hit& hit) const = 0;
	virtual Color GetColor() const = 0;
};

#endif
