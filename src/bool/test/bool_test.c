#include <stdio.h>
#include <bool.h>


/* file to test bool library */


int main( int argc, char *argv[] )
{
    bool t1;
    char *t2;

    t1 = TRUE;
    t2 = Bool_To_String( t1 );
    /*printf( "test = %s", Bool_To_String( test ) );*/

    return 0;
}


/*eof*/
