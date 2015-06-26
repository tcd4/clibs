/**
 * @file bool.h
 *
 * @brief file containing standard boolean functions
 *
 * conversion of a string to a bool
 *      String_To_Bool( char *str )
 *      String_To_True( char *str )
 *      String_To_False( char *str )
 *
 * conversion of a bool to a string
 *      Bool_To_String( bool b )
 */

#ifndef __BOOL__
#define __BOOL__


#include "basics.h"
#include "macros.h"


START_DECLS

/**
 * @brief converts a string to a boolean value
 *
 * accepts "true", "True", or "TRUE" / "false", "False", or "FALSE"
 *
 * @param str   the string to convert
 *
 * @return TRUE if "true", FALSE if "false", or -1 if anything else
 */
bool String_To_Bool( char *str );

/**
 * @brief converts a string to TRUE
 *
 * accepts "true", "True", or "TRUE"
 *
 * @param str   the string to convert
 *
 * @return TRUE if "true", FALSE if anything else
 */
bool String_To_True( char *str);

/**
 * @brief converts a string to FALSE
 *
 * accepts "false", "False", or "FALSE"
 *
 * @param str   the string to convert
 *
 * @return FALSE if "false", or TRUE if anything else
 */
bool String_To_False( char *str );

/**
 * @brief converts a boolean value to a string
 *
 * @param b   the bool to convert
 *
 * @return "true" if TRUE or "false" if anything else
 */
char* Bool_To_String( bool b );


END_DECLS
#endif
