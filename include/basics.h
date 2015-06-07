/**
 * @file basics.h
 *
 * @brief contains basics type definitions for c
 *
 * integer defines
 *      unsigned sized integer types
 *           uint8, uint16, uint32, uint64
 *      signed sized integer types
 *           int8, int16, int32, int64
 *
 * NULL define
 *
 * boolean defines
 *      TRUE
 *      FALSE
 *      boolean type
 *           bool
 *
 * pointer defines
 *      pointer types
 *           dataptr
 *           constdataptr
 */


#ifndef __BASIC__
#define __BASIC__


/* unsigned sized int defines */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;

/* signed sized int defines */
typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long int64;


/* NULL define */
#ifndef NULL

#  ifdef __cplusplus
#  define NULL (0L)
#  else
#  define NULL ( ( void * ) 0 )
#  endif

#endif


/* data pointer defines */
typedef void* dataptr;
typedef const void* constdataptr;


/* TRUE/FALSE defines */
#ifndef FALSE
#define FALSE ( 0 )
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

/* boolean define */
typedef uint8 bool;


#endif
