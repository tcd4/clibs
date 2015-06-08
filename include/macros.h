/**
 * @file macros.h
 *
 * @brief contains macros for commonly used functions
 *
 * defines for code to be used in c++
 *      START_DECLS
 *      END_DECLS
 *
 * defines for macro statements
 *      STMT_START
 *      STMT_END
 *
 * defines for parameter checking
 *      Return_If_Fail( expr )
 *      Return_Value_If_Fail( expr )
 *
 * macros for memory allocation
 *      C_New( type, number )
 *      C_New_Zeroed( type, number )
 *      C_Realloc( location, type, number )
 */

#ifndef __MACROS__
#define __MACROS__


#include <stdlib.h>


/* allows code use in c and c++ */
#ifdef __cplusplus

/*< start declaration of cross language coding */
#define START_DECLS   extern "C" {
/*< end declaration of cross language coding */
#define END_DECLS     }

#else

#define START_DECLS
#define END_DECLS

#endif


/*< begins a statement for creating macros */
#define STMT_START   do{
/*< ends a statement for creating macros */
#define STMT_END     }while(0)


/*< ends a function if an expression equates to false */
#define Return_If_Fail( expr )   \
    STMT_START                   \
    if( !expr ) {return;};	 \
    STMT_END

/*< ends a functions with value as the return value if an expression equates to false */
#define Return_Value_If_Fail( expr, value )	\
    STMT_START                                  \
    if( !expr ) {return value;};                \
    STMT_END


/* memory allocation macros */
/**
 * @brief allocates memory
 *
 * @param type     the type to allocate
 * @param number   the number of the type to allocate for
 */
#define C_New( type, number )                ( ( type* ) malloc( sizeof( type ) * number ) )

/**
 * @brief allocates memory and zeroes it
 *
 * @param type     the type to allocate
 * @param number   the number of the type to allocate for
 */
#define C_New_Zeroed( type, number )         ( ( type* ) calloc( number, sizeof( type ) ) )

/**
 * @brief reallocates memory
 *
 * @param location   a pointer to the memory space
 * @param type       the type to reallocate to
 * @param number     the number of the type to allocate for
 */
#define C_Realloc( location, type, number )  ( ( type* ) realloc( location, sizeof( type ) * number ) ) 


#endif
