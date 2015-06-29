/**
 * @file linked_list.h
 *
 * @brief contains support for singly linked lists
 */

#ifndef __LINKED_LIST__
#define __LINKED_LIST__


#include "basics.h"
#include "macros.h"


START_DECLS


/*< the singly linked list struct */
typedef struct list_s
{
    dataptr         data;        /*< the data in the segment */
    struct list_s   *next;       /*< the next segment in the list */
}List;


/**
 * @brief initializes a new List
 *
 * @param data the data the List is initialized with
 *
 * @return a pointer to the new list or NULL on failure
 */
List* New_List( dataptr data );

/**
 * @brief appends data to a lLst
 *
 * @param list the List to append to
 * @param data the data to append
 *
 * @return a pointer to the list or NULL on failure
 */
List* Append_To_List( List *list, dataptr data );

/**
 * @brief removes a segment from a List
 *
 * @param list the List to remove from
 * @param seg the segment to remove
 *
 * @return a pointer to the updated List 
 */
List* New_List();

/**
 * @brief appends data to a lLst
 *
 * @param list the List to append to
 * @param data the data to append
 *
 * @return a pointer to the list or NULL on failure
 */
List* Append_To_List( List *list, dataptr data );

/**
 * @brief removes a segment from a List
 *
 * @param list the List to remove from
 * @param seg the segment to remove
 *
 * @return a pointer to the updated List or NULL on failure
 */
List* Remove_List_Segment( List *list, List *seg );

/**
 * @brief prepends data to a List
 *
 * @param list the List to prepend to
 * @param data the data to prepend
 *
 * @return a pointer to the new List head or NULL on failure
 */
List* Prepend_To_List( List *list, dataptr data );

/**
 * @brief removes data from a List
 *
 * @param list the List to remove from
 * @param rm the data to remove
 * @param all whether to remove only the first instance of rm or all the instances
 *
 * @return a pointer to the List or NULL on failure
 */
List* Remove_From_List( List *list, dataptr rm, bool all );

/**
 * @brief searches a List for data
 *
 * @param list the List to search
 * @param data the data to find
 *
 * @return a pointer to the List segment or NULL on failure
 */
List* Find_In_List( List *list, dataptr data );

/**
 * @brief finds the final element of a List
 *
 * @param list the List to use
 *
 * @return a pointer to the final element of the List or NULL on failure
 */
List* End_Of_List( List* list );

/**
 * @brief finds the number of elements in a List
 *
 * @param list the List to count
 *
 * @return the number of elements in a List
 */
uint64 Length_Of_List( List *list );

/**
 * @brief duplicates a List
 *
 * @param list the List to duplicate
 *
 * @return a pointer to the clone or NULL on failure
 */
List* Duplicate_List( List *list );

/**
 * @brief frees the memory of a List segment
 *
 * @param seg the segment to free
 */
void Free_List_Segment( List *seg );

/**
 * @brief frees the memory of an entire List
 *
 * @param list a pointer to the List pointer of the List to free
 */
void Free_List( List **list );


END_DECLS


#endif
