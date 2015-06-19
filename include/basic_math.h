/**
 * @file basic_math.h
 *
 * @brief contains basic math variables and macros
 */


#ifndef __BASIC_MATH__
#define __BASIC_MATH__


#include <stdlib.h>


/*< PI define */
#define PI 3.14159265

/*< TAU define */
#define TAU 6.283185308

/*< radian to degree conversion constant */
#define TODEG 57.2957795

/*< degree to radian conversion constant */
#define TORAD 0.0174532925


/*< converts an angle from radians to degrees */
#define Angle_To_Deg( a )                       ( a * TODEG )

/*< converts an angle from degrees to radians */
#define Angle_To_Rad( a )                       ( a * TORAD )


/**
 * @brief random macro from Id Software's Quake 2 Source
 * This macro makes rand() more random
 *
 * @return a random float from 0 to 1.0
 */
#define random()	( ( rand() & 0x7fff ) / ( ( float )0x7fff ) )

/**
 * @brief random macro from Id Software's Quake 2 Source
 * 
 * @return a random float from -1.0 to 1.0
 */
#define crandom()	( 2.0 * ( random() - 0.5 ) )


#endif
