#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "doubly_linked_list.h"


void List_Test();
void DList_Test();


int main( int argc, char *argv[] )
{
    List_Test();
    DList_Test();
}


void DList_Test()
{
    DList *dlist, *temp;
    int *s, *p, *a;

    printf( "\n#### Dist test ####\n" );

    s = C_New( int, 1 );
    *s = 10;
    p = C_New( int, 1 );
    *p = 1;
    a = C_New( int, 1 );
    *a = 100;

    printf( "start: %i\n", *s );
    printf( "prepend: %i\n", *p );
    printf( "append: %i\n", *a );


}


void List_Test()
{
    List *list, *temp, *nomemleak;
    int *start, *prepend, *append;

    printf( "\n#### List test ####\n" );

    start = C_New( int, 1 );
    *start = 5;
    prepend = C_New( int, 1 );
    *prepend = 0;
    append = C_New( int, 1 );
    *append = 9;

    printf( "start: %i\n", *start );
    printf( "prepend: %i\n", *prepend );
    printf( "append: %i\n", *append );

    /* New_List test */
    list = New_List( start );
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
    temp = Prepend_To_List( list, prepend );
    if( temp ) list = temp;
    temp = Prepend_To_List( list, prepend );
    if( temp ) list = temp;

    /* Append_To_List test */
    temp = Append_To_List( list, append );
    if( temp ) list = temp;
    temp = Append_To_List( list, append );
    if( temp ) list = temp;

    /* Length_Of_List test */
    printf( "length: %i\n", ( int )( Length_Of_List( list ) ) );


    /* Find_In_List test */
    temp = Find_In_List( list, start );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );
    temp = Find_In_List( list, prepend );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );
    temp = Find_In_List( list, append );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );
    temp = Find_In_List( list, NULL );
    if( temp ) printf( "found: %i\n", *( int* )( temp->data ) );

    /* Remove_From_List test */
    list = Remove_From_List( list, start, FALSE );
    list = Remove_From_List( list, append, TRUE );

    /* End_Of_List test */
    temp = End_Of_List( list );
    printf( "last: %i\n", *( int* )( temp->data ) );
    
    /* Duplicate_List test */
    temp = Duplicate_List( list );
    nomemleak = temp;
    while( temp )
    {
	printf( "dup: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }

    /* print values in the List */
    printf( "data in the list\n" );
    temp = list;
    while( temp )
    {
	printf( "data: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }

    /* Free_List test */
    temp = NULL;
    Free_List( &nomemleak );
    Free_List( &list );
}


/*eof*/
