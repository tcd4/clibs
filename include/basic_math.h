/**
 * @file basic_math.h
 *
 * @brief contains basic math variables and macros
 */


#ifndef __BASIC_MATH__
#define __BASIC_MATH__


#include <stdlib.h>


#define PI 3.14159265
#define TAU 6.283185308
#define TODEG 57.2957795
#define TORAD 0.0174532925


#define random()	( ( rand() & 0x7fff ) / ( ( float )0x7fff ) )
#define crandom()	( 2.0 * ( random() - 0.5 ) )


#endif
