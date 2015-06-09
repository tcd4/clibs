/**
 * @file linked_list.h
 *
 * @brief contains support for singly and doubly linked lists
 */

#ifndef __LINKED_LIST__
#define __LINKED_LIST__


#include "basics.h"
#include "macros.h"

/*< the singly linked list struct */
typedef struct list_s
{
    dataptr         data;        /*< the data in the segment */
    struct list_s   *next;       /*< the next segment in the list */
}List;

/*< the doubly linked list struct */
typedef struct dlist_s
{
    dataptr          data;       /*< the data in the segment */
    struct dlist_s   *prev;      /*< the previous segment in the list */
    struct dlist_s   *next;      /*< the next segment in the list */
}DList;


/* List functions */
/**
 * @brief initializes a new List
 *
 * @return a pointer to the new list or NULL on failure
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


/* DList functions */
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


#endif
