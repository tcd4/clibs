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

    array->data[ array->length - 1 ] = data;
    
    return array;
}


DArray* Prepend_To_DArray( DArray *array, dataptr data )
{
    Return_Value_If_Fail( array, NULL );

    Resize_DArray( array, array->length + 1 );
    Return_Value_If_Fail( array, NULL );

    memmove( array->data + 1, array->data, sizeof( dataptr ) * ( array->length - 1 ) );
    array->data[ 0 ] = data;

    return array;
}


DArray* Insert_To_DArray( DArray *array, dataptr data, uint64 index )
{
    Return_Value_If_Fail( array, NULL);

    if( ( index < 0 ) || ( index >= array->length ) )
    {
	return NULL;
    }

    Resize_DArray( array, array->length + 1 );
    Return_Value_If_Fail( array, NULL );

    memmove( array->data + index + 1, array->data + index, sizeof( dataptr ) * ( array->length - index ) );

    return array;
}


DArray* Remove_From_DArray( DArray *array, uint64 index )
{
    Return_Value_If_Fail( array, NULL);

    if( ( index < 0 ) || ( index >= array->length ) )
    {
	return NULL;
    }

    if( array->Free )
    {
	array->Free( array->data[ index ] );
    }

    if( index != array->length - 1 )
    {
	memmove( array->data + index, array->data + index + 1, sizeof( dataptr ) * ( array->length - index - 1 ) );
    }

    Resize_DArray( array, array->length - 1 );
    Return_Value_If_Fail( array, NULL );

    return NULL;
}


void Free_DArray( DArray **array )
{
    DArray *temp;
    uint64 i;

    Return_If_Fail( array );
    Return_If_Fail( *array );

    temp = *array;

    if( temp->Free )
    {
	for( i = 0; i < temp->length; i++ )
	{
	    if( temp->data[ i ] ) temp->Free( temp->data[ i ] );
	}
    }

    free( temp->data );
    free( temp );
    *array = NULL;
}


/*eof*/
