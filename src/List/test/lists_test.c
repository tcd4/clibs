#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "doubly_linked_list.h"


int main( int argc, char *argv[] )
{
    List *list;
    int start, prepend, append;

    start = 5;
    prepend = 0;
    append = 9;

    list = New_List( &start );
    if( !list )
    {
	printf( "NULL list" );
	exit( -1 );
    }
    if( list->next )
    {
	printf( "next in the list isn't NULL" );
    }
    if( list->data )
    {
	printf( "start data: %i\n", *( int* )( list->data ) );
    }
}


/*eof*/
