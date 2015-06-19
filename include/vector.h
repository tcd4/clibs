/**
 * @file vector.h
 *
 * @brief file containing the vector type with functions and macros
 */


#ifndef __VECTOR__
#define __VECTOR__


#include "basics.h"
#include "macros.h"
#include "basic_math.h"


/* vector typedefs */
/*< 1d vector type */
typedef float vec_t;

/*< 2d vector type */
typedef vec_t vec2_t[ 2 ];

/*< 3d vector type */
typedef vec_t vec3_t[ 3 ];

/*< 4d vector type */
typedef vec_t vec4_t[ 4 ];


/* vector macros */


/* 2d vector macros */
/*< subtracts 2 2d vectors */
#define Vec2_Subtract( a, b, c )	        ( c[ 0 ] = a[ 0 ] - b[ 0 ], c[ 1 ] = a[ 1 ] - b[ 1 ] )

/*< adds 2 2d vectors */
#define Vec2_Add( a, b, c )		        ( c[ 0 ] = a[ 0 ] + b[ 0 ], c[ 1 ] = a[ 1 ] + b[ 1 ] )

/*< finds the dot product of 2 2d vectors */
#define Vec2_Dot_Product( a, b )                ( a[ 0 ] * b[ 0 ] + a[ 1 ] * b[ 1 ] )

/*< copys 2d vector a into b */
#define Vec2_Copy( a, b )		        ( b[ 0 ] = a[ 0 ], b[ 1 ] = a[ 1 ] )

/*< sets a 2d vector to [ 0, 0 ] */
#define Vec2_Clear( a )			        ( a[ 0 ] = 0, a[ 1 ] = 0 )

/*< checks if 2 2d vectors are equal */
#define Vec2_Compare( a, b )		        ( ( a[ 0 ] == b[ 0 ] && a[ 1 ] == b[ 1 ] ) ? 1: 0 )

/*< checks if a 2d vector is zeroed */
#define Vec2_Zeroed( a )			( ( a[ 0 ] == 0 && a[ 1 ] == 0 ) ? 1: 0 )

/*< scales a 2d vector */
#define Vec2_Scale( dst, src, factor )          ( dst[ 0 ] = src[ 0 ] * factor, dst[ 1 ] = src[ 1 ] * factor )


/* 3d vector macros */
/*< subtracts 2 3d vectors */
#define Vec3_Subtract( a, b, c )	        ( Vec2_Subtract( a, b, c ), c[ 2 ] = a[ 2 ] - b[ 2 ] )

/*< adds 2 3d vectors */
#define Vec3_Add( a, b, c )		        ( Vec2_Add( a, b, c ), c[ 2 ] = a[ 2 ] + b[ 2 ] )

/*< finds the dot product of 2 3d vectors */
#define Vec3_Dot_Product( a, b )                ( Vec2_Dot_Product( a, b ) + a[ 2 ] * b[ 2 ] )

/*< copys 3d vector a into b */
#define Vec3_Copy( a, b )		        ( Vec2_Copy( a, b ), b[ 2 ] = a[ 2 ] )

/*< sets a 3d vector to [ 0, 0, 0 ] */
#define Vec3_Clear( a )			        ( Vec2_Clear( a ), a[ 2 ] = 0 )

/*< checks if 2 3d vectors are equal */
#define Vec3_Compare( a, b )		        ( ( Vec2_Compare( a, b ) && a[ 2 ] == b[ 2 ] ) ? 1: 0 )

/*< checks if a 3d vector is zeroed */
#define Vec3_Zeroed( a )			( ( a[ 0 ] == a[ 1 ] == a[ 2 ] == 0 ) ? 1: 0 )

/*< scales a 3d vector */
#define Vec3_Scale( dst, src, factor )          ( Vec2_Scale( dst, src, factor ), dst[ 2 ] = src[ 2 ] * factor )


/* 4d vector macros */
/*< subtracts 2 4d vectors */
#define Vec4_Subtract( a, b, c )	        ( Vec3_Subtract( a, b, c ), c[ 3 ] = a[ 3 ] - b[ 3 ] )

/*< adds 2 4d vectors */
#define Vec4_Add( a, b, c )		        ( Vec3_Add( a, b, c ), c[ 3 ] = a[ 3 ] + b[ 3 ] )

/*< finds the dot product of 2 4d vectors */
#define Vec4_Dot_Product( a, b )                ( Vec3_Dot_Product( a, b ) + a[ 3 ] * b[ 3 ] )

/*< copys 4d vector a into b */
#define Vec4_Copy( a, b )		        ( Vec3_Copy( a, b ), b[ 3 ] = a[ 3 ] )

/*< sets a 4d vector to [ 0, 0, 0, 0 ] */
#define Vec4_Clear( a )			        ( Vec3_Clear( a ), a[ 3 ] = 0 )

/*< checks if 2 4d vectors are equal */
#define Vec4_Compare( a, b )		        ( ( Vec3_Compare( a, b ) && a[ 3 ] == b[ 3 ] ) ? 1: 0 )

/*< checks if a 4d vector is zeroed */
#define Vec4_Zeroed( a )			( ( a[ 0 ] == a[ 1 ] == a[ 2 ] == a[ 3 ] == 0 ) ? 1: 0 )

/*< scales a 4d vector */
#define Vec4_Scale( dst, src, factor )          ( Vec3_Scale( dst, src, factor ), dst[ 3 ] = src[ 3 ] * factor )


/* vector functions */


/* 2d vector functions */
/**
 * @brief normalizes a vector
 *
 * @param v the vector to normalize
 */
void Vec2_Normalize( vec2_t *v );

/**
 * @brief gets the magnitude of a vector
 *
 * @param v the vector to use
 *
 * @return the magnitude of a vector
 */
float Vec2_Get_Magnitude( vec2_t v );

/**
 * @brief normalizes a vector then sets its magnitude
 *
 * @param v the vector to use
 * @param m the magnitude to set the vector to
 */
void Vec2_Set_Magnitude( vec2_t *v, float m );

/**
 * @brief compares the magnitudes of 2 vectors
 *
 * @param v1 the 1st vector to compare
 * @param v2 the 2nd vector to compare
 *
 * @return 1 if v1 > v2, 0 if v1 == v2, -1 if v1 < v2
 */
int8 Vec2_Magnitude_Compare( vec2_t v1, vec2_t v2 );

/**
 * @brief gets the distance between 2 vectors
 *
 * @param v1 the 1st vector to use
 * @param v2 the 2nd vector to use
 *
 * @return the distance between the 2 vectors
 */
uint32 Vec2_Distance_Between( vec2_t v1, vec2_t v2 );

/**
 * @brief sets the angle of a vector
 *
 * @param v the vector to use
 * @param a the angle ( in degrees ) to use
 */
void Vec2_Set_Angle_Degs( vec2_t *v, float a );

/**
 * @brief sets the angle of a vector
 *
 * @param v the vector to use
 * @param a the angle ( in radians ) to use
 */
void Vec2_Set_Angle_Rads( vec2_t *v, float a );


/* 3d vector functions */
/**
 * @brief normalizes a vector
 *
 * @param v the vector to normalize
 */
void Vec3_Normalize( vec3_t *v );

/**
 * @brief gets the magnitude of a vector
 *
 * @param v the vector to use
 *
 * @return the magnitude of a vector
 */
float Vec3_Get_Magnitude( vec3_t v );

/**
 * @brief normalizes a vector then sets its magnitude
 *
 * @param v the vector to use
 * @param m the magnitude to set the vector to
 */
void Vec3_Set_Magnitude( vec3_t *v, float m );

/**
 * @brief compares the magnitudes of 2 vectors
 *
 * @param v1 the 1st vector to compare
 * @param v2 the 2nd vector to compare
 *
 * @return 1 if v1 > v2, 0 if v1 == v2, -1 if v1 < v2
 */
int8 Vec3_Magnitude_Compare( vec3_t v1, vec3_t v2 );

/**
 * @brief gets the distance between 2 vectors
 *
 * @param v1 the 1st vector to use
 * @param v2 the 2nd vector to use
 *
 * @return the distance between the 2 vectors
 */
uint32 Vec3_Distance_Between( vec3_t v1, vec3_t v2 );

/**
 * @brief sets the angle of a vector
 *
 * @param v the vector to use
 * @param a the angle ( in degrees ) to use
 */
void Vec3_Set_Angle_Degs( vec3_t *v, float a );

/**
 * @brief sets the angle of a vector
 *
 * @param v the vector to use
 * @param a the angle ( in radians ) to use
 */
void Vec3_Set_Angle_Rads( vec3_t *v, float a );


/* 4d vector functions */
/**
 * @brief normalizes a vector
 *
 * @param v the vector to normalize
 */
void Vec4_Normalize( vec4_t *v );

/**
 * @brief gets the magnitude of a vector
 *
 * @param v the vector to use
 *
 * @return the magnitude of a vector
 */
float Vec4_Get_Magnitude( vec4_t v );

/**
 * @brief normalizes a vector then sets its magnitude
 *
 * @param v the vector to use
 * @param m the magnitude to set the vector to
 */
void Vec4_Set_Magnitude( vec4_t *v, float m );

/**
 * @brief compares the magnitudes of 2 vectors
 *
 * @param v1 the 1st vector to compare
 * @param v2 the 2nd vector to compare
 *
 * @return 1 if v1 > v2, 0 if v1 == v2, -1 if v1 < v2
 */
int8 Vec4_Magnitude_Compare( vec4_t v1, vec4_t v2 );

/**
 * @brief gets the distance between 2 vectors
 *
 * @param v1 the 1st vector to use
 * @param v2 the 2nd vector to use
 *
 * @return the distance between the 2 vectors
 */
uint32 Vec4_Distance_Between( vec4_t v1, vec4_t v2 );

/**
 * @brief sets the angle of a vector
 *
 * @param v the vector to use
 * @param a the angle ( in degrees ) to use
 */
void Vec4_Set_Angle_Degs( vec4_t *v, float a );

/**
 * @brief sets the angle of a vector
 *
 * @param v the vector to use
 * @param a the angle ( in radians ) to use
 */
void Vec4_Set_Angle_Rads( vec4_t *v, float a );


/* non-specific functions */
float Get_Angle( float x, float y );
void Cross_Product( vec3_t *out, vec3_t v1, vec3_t v2 );


#endif
