#include <string.h>
#include "bool.h"


bool String_To_Bool( char *str )
{
    Return_Value_If_Fail( str, FALSE );

    if( String_To_True( str ) )
    {
	return TRUE;
    }
    else if( !String_To_False( str ) )
    {
	return FALSE;
    }
    
    return -1;
}


bool String_To_True( char *str )
{
    Return_Value_If_Fail( str, FALSE );

    if( ( strcmp( str, "true" ) == 0 ) ||
	( strcmp( str, "True" ) == 0 ) ||
	( strcmp( str, "TRUE" ) == 0 ) )
    {
	return TRUE;
    }
   
    return FALSE;
}


bool String_To_False( char *str )
{
    Return_Value_If_Fail( str, FALSE );

    if( ( strcmp( str, "true" ) == 0 ) ||
	( strcmp( str, "True" ) == 0 ) ||
	( strcmp( str, "TRUE" ) == 0 ) )
    {
	return FALSE;
    }

    return TRUE;
}


char* Bool_To_String( bool b )
{
    if( b )
    {
	return "true";
    }

    return "false";
}


/*eof*/
