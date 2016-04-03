#ifndef RAYS_H
#define RAYS_H

#include "vec3.h"

struct ray
{
  ray(){}
  ray(const vec3& a, const vec3&b) { A = a; B = b; }
  vec3 origin() const { return A; }
  vec3 direction() const { return B; }
  vec3 point_at_parameter(float t) { return A + t*B; }

  vec3 A;
  vec3 B;
};

#endif //RAYS_H
