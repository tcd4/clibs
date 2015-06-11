#include <string.h>
#include "dynamic_array.h"


DArray* New_DArray( uint64 size, void ( *free )() )
{
    DArray *new;

    Return_Value_If_Fail( size > 0, NULL );

    new = C_New( DArray, 1 );
    Return_Value_If_Fail( new, NULL );

    new->data = NULL;
    new->Free = free;

    new = Resize_DArray( new, size );

    return new;
}


DArray* Resize_DArray( DArray *array, uint64 size )
{
    dataptr new;

    Return_Value_If_Fail( array, NULL );
    Return_Value_If_Fail( size > 0, NULL );

    new = C_New( dataptr, size );
    Return_Value_If_Fail( new, NULL );
  
    memcpy( new, array->data, size );
    array->data = new;
    array->length = size;

    return array;
}


DArray* Append_To_DArray( DArray *array, dataptr data )
{
    Return_Value_If_Fail( array, NULL );

    Resize_DArray( array, ++array->length );
    Return_Value_If_Fail( array, NULL );

    memcpy( array->data[ array->length - 1 ], data, sizeof( dataptr );
    
    return array;
}


DArray* Prepend_To_DArray( DArray *array, dataptr data )
{
    uint64 i;
    dataptr temp;

    Return_Value_If_Fail( array, NULL );

    Resize_DArray( array, array->length + 1 );
    Return_Value_If_Fail( array, NULL );

    memmove( array->data + 1, array->data, array->length );
    memcpy( array->data[ 0 ], data );

    return array;
}


DArray* Insert_To_DArray( DArray *array, dataptr data, uint64 index )
{
}


DArray* Remove_From_DArray( DArray *array, uint64 index )
{
}


void Free_DArray( DArray **array )
{
}


/*eof*/
