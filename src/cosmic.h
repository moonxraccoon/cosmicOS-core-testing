#ifndef _COSMIC_H
#define _COSMIC_H

#include <stdint.h> 

/**
 * Create string with size `n`
 */
#define from_string(n)   (char[(n)]){}

//#define     u8      uint8_t

// ======| unsigned int |======

/**
 * 8-bit unsigned integer
 */
typedef uint8_t         u8;
/**
 * 16-bit unsigned integer
 */
typedef uint16_t        u16;
/**
 * 32-bit unsigned integer
 */
typedef uint32_t        u32;

/**
 * 64-bit unsigned integer
 */
typedef uint64_t        u64;

// ======| signed int |======

/**
 * 8-bit signed integer
 */
typedef int8_t          i8;
/**
 * 16-bit signed integer
 */
typedef int16_t         i16;
/**
 * 32-bit signed integer
 */
typedef int32_t         i32;
/**
 * 64-bit signed integer
 */
typedef int64_t         i64;

// ======| floats |======

/**
 * 32-bit float
 */
typedef float           f32;
/**
 * 64-bit float
 */
typedef double          f64;
 
/**
 * String
 */
typedef char*           str;

/**
 * Byte 
 */
typedef uint8_t         byte;


/**
 * 3D Vector
 */
typedef struct _vec3 {
    f32     x;
    f32     y;
    f32     z;
} vec3;

/**
 * 4D Vector
 */
typedef struct _vec4 {
    f32     x;
    f32     y;
    f32     z;
    f32     w;
} vec4;

#endif
