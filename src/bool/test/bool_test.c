#include <stdio.h>
#include <bool.h>


/* file to test bool library */


int main( int argc, char *argv[] )
{
    bool t1;

    t1 = String_To_Bool( "true" );
    printf( "t1 = %s\n", Bool_To_String( t1 ) );

    t1 = String_To_Bool( "True" );
    printf( "t1 = %s\n", Bool_To_String( t1 ) );

    t1 = String_To_Bool( "TRUE" );
    printf( "t1 = %s\n", Bool_To_String( t1 ) );

    t1 = String_To_Bool( "false" );
    printf( "t1 = %s\n", Bool_To_String( t1 ) );

    t1 = String_To_Bool( "false" );
    printf( "t1 = %s\n", Bool_To_String( t1 ) );

    t1 = String_To_Bool( "false" );
    printf( "t1 = %s\n", Bool_To_String( t1 ) );

    return 0;
}


/*eof*/
