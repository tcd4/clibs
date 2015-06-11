/**
 * @file dynamic_array.h
 *
 * @brief contains functionality for dynamic arrays
 */

#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__


#include "basics.h"
#include "macros.h"


START_DECLS


typedef struct
{
    dataptr   *data;                       /*< the data the array contains */
    uint64    length;                      /*< the length of the array */
    void      ( *Free )( dataptr data );   /*< custom free function for data */
}DArray;


/**
 * @brief creates a new DArray
 *
 * @param size the size of the DArray
 * @param free a free function for the data in the DArray
 *
 * @return a new DArray
 */
DArray* New_DArray( uint64 size, void ( *free )() );

/**
 * @brief expands/contracts the size of a DArray
 *
 * @param array the DArray to expand
 * @param size the size to expand to
 *
 * @return the expanded DArray
 */
DArray* Resize_DArray( DArray *array, uint64 size );

/**
 * @brief appends data to a DArray
 *
 * @param array the DArray to append to
 * @param data the data to append
 *
 * @return the updated DArray
 */
DArray* Append_To_DArray( DArray *array, dataptr data );

/**
 * @brief prepends data to a DArray
 *
 * @param array the DArray to prepend to
 * @param data the data to prepend
 *
 * @return the updated DArray
 */
DArray* Prepend_To_DArray( DArray *array, dataptr data );

/**
 * @brief inserts data into a DArray at an index
 *
 * @param array the DArray to insert into
 * @param data the data to insert
 * @param index the index to insert into
 *
 * @return the updated DArray
 */
DArray* Insert_To_DArray( DArray *array, dataptr data, uint64 index );

/**
 * @brief froms data from a DArray at an index
 *
 * @param array the DArray to remove from
 * @param index the index to remove
 *
 * @return the updated DArray
 */
DArray* Remove_From_DArray( DArray *array, uint64 index );

/**
 * @brief frees the memory from a DArray
 *
 * @param array the DArray to free
 */
void Free_DArray( DArray **array );


END_DECLS


#endif
