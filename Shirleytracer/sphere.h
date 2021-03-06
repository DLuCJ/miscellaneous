#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"

struct sphere: public hitable
{
  sphere(){}
  sphere(vec3 cen, float r) : center(cen), radius(r) {};
  virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
  vec3 center;
  float radius;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
  vec3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = 2.0f * dot(oc, r.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminant = b*b - 4*a*c;

  float q = -0.5f * (b + sqrt(discriminant));
  if(discriminant > 0) {
    float temp = q / a;
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.point_at_parameter(rec.t);
      rec.normal = (rec.p - center) / radius;
      return true;
    }

    temp = c / q;
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.point_at_parameter(rec.t);
      rec.normal = (rec.p - center) / radius;
      return true;
    } 
  }
  return false;
}
  
#endif //SPHERE_H
