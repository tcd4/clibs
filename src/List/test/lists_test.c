#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "doubly_linked_list.h"


int main( int argc, char *argv[] )
{
    List *list, *temp;
    DList *dlist, *dtemp;
    int start, prepend, append;

    start = 5;
    prepend = 0;
    append = 9;

    printf( "#### List test ####\n" );
    /* New_List test */
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

    /* Length_Of_List test */
    printf( "length: %i\n", ( int )( Length_Of_List( list ) ) );

    /* Prepend_To_List test */
    temp = Prepend_To_List( list, &prepend );
    if( temp ) list = temp;
    temp = Prepend_To_List( list, &prepend );
    if( temp ) list = temp;

    /* Append_To_List test */
    temp = Append_To_List( list, &append );
    if( temp ) list = temp;
    temp = Append_To_List( list, &append );
    if( temp ) list = temp;

    /* Find_In_List test */
    temp = Find_In_List( list, &start );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );
    temp = Find_In_List( list, &prepend );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );
    temp = Find_In_List( list, &append );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );
    temp = Find_In_List( list, NULL );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );

    /* Remove_From_List test */
    /*
    list = Remove_From_List( list, &start, FALSE );
    list = Remove_From_List( list, &append, TRUE );
    */

    /* End_Of_List test */
    temp = End_Of_List( list );
    printf( "last: %i\n", *( int* )( temp->data ) );

    /* Length_Of_List test */
    printf( "length: %i\n", ( int )( Length_Of_List( list ) ) );

    /* print values in the List */
    printf( "data in the list\n" );
    temp = list;
    while( temp )
    {
	printf( "data: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }

    /* Duplicate_List test */
    temp = Duplicate_List( list );
    while( temp )
    {
	printf( "dup: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }

    /* Free_List test */
    temp = NULL;
    Free_List( &list );



    printf( "\n#### DList test ####\n" );
    /* New_DList test */
    dlist = New_DList( &start );
    if( !dlist )
    {
	printf( "NULL dlist" );
	exit( -1 );
    }
    if( dlist->next )
    {
	printf( "next in the dlist isn't NULL" );
    }
    if( dlist->prev )
    {
	printf( "prev in the dlist isn't NULL" );
    }
    if( dlist->data )
    {
	printf( "start data: %i\n", *( int* )( dlist->data ) );
    }

    /* Length_Of_DList test */
    printf( "length: %i\n", ( int )( Length_Of_DList( dlist ) ) );

    /* Prepend_To_DList test */
    dtemp = Prepend_To_DList( dlist, &prepend );
    if( dtemp ) dlist = dtemp;
    dtemp = Prepend_To_DList( dlist, &prepend );
    if( dtemp ) dlist = dtemp;

    /* Append_To_DList test */
    dtemp = Append_To_DList( dlist, &append );
    if( dtemp ) dlist = dtemp;
    dtemp = Append_To_DList( dlist, &append );
    if( dtemp ) dlist = dtemp;

    /* Find_In_DList test */
    dtemp = Find_In_DList( dlist, &start );
    if( dtemp ) printf( "found: %i\n", *( int* )( dtemp->data ) );
    dtemp = Find_In_DList( dlist, &prepend );
    if( dtemp ) printf( "found: %i\n", *( int* )( dtemp->data ) );
    dtemp = Find_In_DList( dlist, &append );
    if( dtemp ) printf( "found: %i\n", *( int* )( dtemp->data ) );
    dtemp = Find_In_DList( dlist, NULL );
    if( dtemp ) printf( "found: %i\n", *( int* )( dtemp->data ) );

    /* Remove_From_DList test */
    /*
    dlist = Remove_From_DList( dlist, &start, FALSE );
    dlist = Remove_From_DList( dlist, &append, TRUE );
    */

    /* End_Of_DList test */
    dtemp = End_Of_DList( dlist );
    printf( "last: %i\n", *( int* )( dtemp->data ) );

    /* Length_Of_DList test */
    printf( "length: %i\n", ( int )( Length_Of_DList( dlist ) ) );

    /* print values in the DList */
    printf( "data in the dlist\n" );
    dtemp = dlist;
    while( dtemp )
    {
	printf( "data: %i\n", *( int* )( dtemp->data ) );
	dtemp = dtemp->next;
    }

    /* Duplicate_DList test */
    dtemp = Duplicate_DList( dlist );
    while( dtemp )
    {
	printf( "dup: %i\n", *( int* )( dtemp->data ) );
	dtemp = dtemp->next;
    }

    /* Free_List test */
    dtemp = NULL;
    Free_DList( &dlist );
}


/*eof*/
