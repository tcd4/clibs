/**
 * @file queue.h
 * 
 * @brief contains support for queues
 */


#ifndef __QUEUE__
#define __QUEUE__


#include "linked_list.h"
#include "macros.h"
#include "basics.h"


/*< the queue struct */
typedef struct
{
    List     *head;    /*< the first element of the queue */
    List     *tail;    /*< the last element of the queue */
    uint64   length;   /*< the length of the queue */
}Queue;


/**
 * @brief creates a new Queue
 *
 * @return a pointer to the new Queue
 */
Queue* New_Queue();

/**
 * @brief pushes data onto the end of a Queue
 *
 * @param queue the Queue to use
 * @param data the data to push onto the Queue
 */
void Push_Queue( Queue *queue, dataptr data );

/**
 * @brief pops data off of a Queue
 *
 * @param queue the Queue to use
 *
 * @return a pointer to the popped data
 */
dataptr Pop_Queue( Queue *queue );

/**
 * @brief clears all the data from a Queue
 *
 * @param queue the Queue to use
 */
void Clear_Queue( Queue *queue );

/**
 * @brief checks if a Queue is empty
 *
 * @param queue the Queue to use
 *
 * @return True if the Queue is empty, False if else
 */
bool Queue_Is_Empty( Queue *queue );

/**
 * @brief duplicates a Queue
 *
 * @param queue the Queue to use
 *
 * @return a pointer to the duplicate Queue
 */
Queue* Duplicate_Queue( Queue *queue );

/**
 * @brief frees the memory of a Queue
 *
 * @param queue the Queue to use
 */
void Free_Queue( Queue **queue );


#endif
