#include <stdio.h>
#include "queue.h"


int main( int argc, char *argv[] )
{
    Queue *queue, *dup;
    int a, b, c;

    a = 1;
    b = 3;
    c = 5;

    /* New_Queue test */
    queue = New_Queue();

    /* Push_Queue test */
    Push_Queue( queue, &a );
    Push_Queue( queue, &b );
    Push_Queue( queue, &c );
    
    /* Pop_Queue test */
    printf( "pop: %i\n", *( int* )( Pop_Queue( queue ) ) );

    /* Queue_Is_Empty test */
    printf( "empty: %i\n", ( int )( Queue_Is_Empty( queue ) ) );
    
    /* Duplicate_Queue test */
    dup = Duplicate_Queue( queue );
    printf( "dup: %i\n", *( int* )( Pop_Queue( dup ) ) );
    printf( "dup: %i\n", *( int* )( Pop_Queue( dup ) ) );

    /* Clear_Queue test */
    Clear_Queue( queue );

    /* Queue_Is_Empty test */
    printf( "empty: %i\n", ( int )( Queue_Is_Empty( queue ) ) );    

    /* Free_Queue test */
    Free_Queue( &queue );

    return 0;
}


/*eof*/
