/**
 * @file vector.h
 *
 * @brief file containing the vector type with functions and macros
 */


#ifndef __VECTOR__
#define __VECTOR__


/* vector typedefs */
/*< 1d vector type */
typedef float vec_t;

/*< 2d vector type */
typedef vec_t vec2_t[ 2 ];

/*< 3d vector type */
typedef vec_t vec3_t[ 3 ];

/*< 4d vector type */
typedef vec_t vec4_t[ 4 ];


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


#endif
