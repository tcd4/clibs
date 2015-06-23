/**
 * @file stack.h
 *
 * @brief contains support for stacks
 */


#ifndef __STACK__
#define __STACK__


#include "linked_list.h"
#include "macros.h"
#include "basics.h"


/*< the stack struct */
typedef struct
{
    DList    *head;    /*< the first element of the stack */
    DList    *tail;    /*< the last element of the stack */
    uint64   length;   /*< the number of elements in the stack */
}Stack;


/**
 * @brief creates a new Stack
 *
 * @return a pointer to the new Stack
 */
Stack* New_Stack();

/**
 * @brief pushes data onto a Stack
 *
 * @param stack the Stack to use
 * @param data the data to push onto the Stack
 */
void Push_Stack( Stack *stack, dataptr data );

/**
 * @brief removes and returns the data from the last element of the Stack
 *
 * @param stack the Stack to use
 *
 * @return a pointer to the data of the last element of the Stack
 */
dataptr Pop_Stack( Stack *stack );

/**
 * @brief clears the elements of a Stack
 *
 * @param stack the Stack to use
 */
void Clear_Stack( Stack *stack );

/**
 * @brief checks if a Stack is empty
 *
 * @param stack the Stack to use
 *
 * @return TRUE if the Stack is empty, False if else
 */
bool Stack_Is_Empty( Stack *stack );

/**
 * @brief frees the memory of a Stack
 *
 * @param stack the Stack to use
 */
void Free_Stack( Stack *stack );


#endif
