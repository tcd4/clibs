#include "vector.h"


/* 2d vector functions */
void Vec2_Normalize( vec2_t *v )
{
    float m;

    Return_If_Fail( v );

    m = Vec2_Get_Magnitude( *v );
    Return_If_Fail( m != 0.0f );
    m = 1 / m;

    *v[ 0 ] *= m;
    *v[ 1 ] *= m;
}


float Vec2_Get_Magnitude( vec2_t v )
{
    return sqrt( v[ 0 ] * v[ 0 ] + v[ 1 ] * v[ 1 ] );
}


void Vec2_Set_Magnitude( vec2_t *v, float m )
{
    Return_If_Fail( v );

    Vec2_Normalize( v );
    
    *v[ 0 ] *= m;
    *v[ 1 ] *= m;
}


int8 Vec2_Magnitude_Compare( vec2_t v1, vec2_t v2 )
{
    float m1, m2;

    m1 = Vec2_Get_Magnitude( v1 );
    m2 = Vec2_Get_Magnitude( v2 );

    if( m1 > m2 ) return 1;
    else if( m1 < m2 ) return -1;
    else return 0;
}


uint32 Vec2_Distance_Between( vec2_t v1, vec2_t v2 )
{
    Vec2_Subtract( v1, v2, v1 );

    return abs( Vec2_Get_Magnitude( v1 ) );
}


void Vec2_Set_Angle_Degs( vec2_t *v, float a )
{
    Return_If_Fail( v );

    a = Angle_To_Rad( a );

    *v[ 0 ] = cos( a );
    *v[ 1 ] = sin( a );
}


void Vec2_Set_Angle_Rads( vec2_t *v, float a )
{
    Return_If_Fail( v );

    *v[ 0 ] = cos( a );
    *v[ 1 ] = sin( a );
}


/* 3d vector functions */

void Vec3_Normalize( vec3_t *v )
{
    float m;

    Return_If_Fail( v );

    m = Vec3_Get_Magnitude( *v );
    Return_If_Fail( m != 0.0f );
    m = 1 / m;

    *v[ 0 ] *= m;
    *v[ 1 ] *= m;
    *v[ 2 ] *= m;
}


float Vec3_Get_Magnitude( vec3_t v )
{
    return sqrt( v[ 0 ] * v [ 0 ] + v[ 1 ] * v[ 1 ] + v[ 2 ] * v[ 2 ] );
}


void Vec3_Set_Magnitude( vec3_t *v, float m )
{
    Return_If_Fail( v );

    Vec3_Normalize( v );
    
    *v[ 0 ] *= m;
    *v[ 1 ] *= m;
    *v[ 2 ] *= m;
}


int8 Vec3_Magnitude_Compare( vec3_t v1, vec3_t v2 )
{
    float m1, m2;

    m1 = Vec3_Get_Magnitude( v1 );
    m2 = Vec3_Get_Magnitude( v2 );

    if( m1 > m2 ) return 1;
    else if( m1 < m2 ) return -1;
    else return 0;
}


uint32 Vec3_Distance_Between( vec3_t v1, vec3_t v2 )
{
    Vec3_Subtract( v1, v2, v1 );

    return abs( Vec3_Get_Magnitude( v1 ) );
}


void Vec3_Set_Angle_Degs( vec3_t *v, float a )
{
    Return_If_Fail( v );

    a = Angle_To_Rad( a );

    *v[ 0 ] = cos( a );
    *v[ 1 ] = sin( a );
}


void Vec3_Set_Angle_Rads( vec3_t *v, float a )
{
    Return_If_Fail( v );

    *v[ 0 ] = cos( a );
    *v[ 1 ] = sin( a );
}


/* 4d vector functions */
/*
void Vec4_Normalize( vec4_t *v )
{
}


float Vec4_Get_Magnitude( vec4_t v )
{
}


void Vec4_Set_Magnitude( vec4_t *v, float m )
{
}


int8 Vec4_Magnitude_Compare( vec4_t v1, vec4_t v2 )
{
}


uint32 Vec4_Distance_Between( vec4_t v1, vec4_t v2 )
{
}


void Vec4_Set_Angle_Degs( vec4_t *v, float a )
{
}


void Vec4_Set_Angle_Rads( vec4_t *v, float a )
{
}
*/

/* non-specific functions */
/*
float Get_Angle( float x, float y )
{
}


void Cross_Product( vec3_t *out, vec3_t v1, vec3_t v2 )
{
}
*/

/*eof*/
