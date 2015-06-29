/**
 * @file doubly_linked_list.h
 *
 * @brief contains support for doubly linked lists
 */

#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__


#include "basics.h"
#include "macros.h"


START_DECLS


/*< the doubly linked list struct */
typedef struct dlist_s
{
    dataptr          data;       /*< the data in the segment */
    struct dlist_s   *prev;      /*< the previous segment in the list */
    struct dlist_s   *next;      /*< the next segment in the list */
}DList;


/**
 * @brief initializes a new DList
 *
 * @return a pointer to the new DList or NULL on failure
 */
DList* New_DList();

/**
 * @brief appends data to a lLst
 *
 * @param list the List to append to
 * @param data the data to append
 *
 * @return a pointer to the DList or NULL on failure
 */
DList* Append_To_DList( DList *list, dataptr data );

/**
 * @brief prepends data to a DList
 *
 * @param list the DList to prepend to
 * @param data the data to prepend
 *
 * @return a pointer to the new DList head or NULL on failure
 */
DList* Prepend_To_DList( DList *list, dataptr data );

/**
 * @brief removes a segment from a DList
 *
 * @param list the DList to remove from
 * @param seg the segment to remove
 *
 * @return a pointer to the updated DList or NULL on failure
 */
DList* Remove_DList_Segment( DList *list, DList *seg );

/**
 * @brief removes data from a DList
 *
 * @param list the DList to remove from
 * @param rm the data to remove
 * @param all whether to remove only the first instance of rm or all the instances
 *
 * @return a pointer to the DList or NULL on failure
 */
DList* Remove_From_DList( DList *list, dataptr rm, bool all );

/**
 * @brief searches a DList for data
 *
 * @param list the DList to search
 * @param data the data to find
 *
 * @return a pointer to the List segment or NULL on failure
 */
DList* Find_In_DList( DList *list, dataptr data );

/**
 * @brief finds the final element of a DList
 *
 * @param list the DList to use
 *
 * @return a pointer to the final element of the DList or NULL on failure
 */
DList* End_Of_DList( DList* list );

/**
 * @brief finds the number of elements in a DList
 *
 * @param list the DList to count
 *
 * @return the number of elements in a DList
 */
uint64 Length_Of_DList( DList *list );

/**
 * @brief duplicates a DList
 *
 * @param list the DList to duplicate
 *
 * @return a pointer to the clone or NULL on failure
 */
DList* Duplicate_DList( DList *list );

/**
 * @brief frees the memory of a DList segment
 *
 * @param seg the segment to free
 */
void Free_DList_Segment( DList *seg );

/**
 * @brief frees the memory of an entire DList
 *
 * @param list a pointer to the DList pointer of the DList to free
 */
void Free_DList( DList **list );


END_DECLS


#endif
