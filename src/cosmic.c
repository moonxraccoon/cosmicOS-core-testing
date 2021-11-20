#include "cosmic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vec3 v3_add(const vec3 v1, const vec3 v2) {
    vec3 out = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    return out;    
}

vec4 v4_add(const vec4 v1, const vec4 v2) {
    vec4 out = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
    return out;    
}

vec3 v3_smult(const vec3 v1, const f32 s) {
    vec3 out = {v1.x * s, v1.y * s, v1.z * s};
    return out;
}

vec4 v4_smult(const vec4 v1, const f32 s) {
    vec4 out = {v1.x * s, v1.y * s, v1.z * s, v1.w * s};
    return out;
}

vec3 v3_mult(const vec3 v1, const vec3 v2) {
    vec3 out = {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
    return out;    
}

vec4 v4_mult(const vec4 v1, const vec4 v2) {
    vec4 out = {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w};
    return out;    
}

vec3 v3_id(const vec3 v, const vec4 null) {
    return (vec3){v.x, v.y, v.z};
}

vec4 v4_id(const vec4 v, const vec3 null) {
    return (vec4){v.x, v.y, v.z, v.w};
}

void v3_to_string(const vec3 v, str buf) {
    sprintf(buf, "(%.2f,%.2f,%.2f)", v.x, v.y, v.z);
}

void v4_to_string(const vec4 v, str buf) {
    sprintf(buf, "(%.2f,%.2f,%.2f,%.2f)", v.x, v.y, v.z, v.w);
}
