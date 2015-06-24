#include "stack.h"


Stack* New_Stack()
{
    Stack *new;

    new = C_New( Stack, 1 );
    Return_Value_If_Fail( new, NULL );

    new->head = NULL;
    new->tail = NULL;
    new->length = 0;

    return new;
}


void Push_Stack( Stack *stack, dataptr data )
{
    DList *new;

    Return_If_Fail( stack );

    if( !stack->head )
    {
	new = New_DList();
	Return_If_Fail( new );

	new->data = data;
    }
    else
    {
	new = Append_To_DList( stack->head, data );
	Return_If_Fail( new );
    }

    stack->head = new;
    stack->tail = End_Of_DList( new );
    stack->length++;
}


dataptr Pop_Stack( Stack *stack )
{
    dataptr temp;

    Return_Value_If_Fail( stack, NULL );

    temp = stack->tail->data;

    stack->head = Remove_DList_Segment( stack->head, stack->tail );
    stack->length--;

    return temp;
}


void Clear_Stack( Stack *stack )
{
    Return_If_Fail( stack );

    Free_DList( &stack->head );
   
    stack->tail = NULL;
    stack->length = 0;
}


bool Stack_Is_Empty( Stack *stack )
{
    Return_Value_If_Fail( stack, FALSE );
    Return_Value_If_Fail( ( stack->length > 0 ) || ( stack->length < 0 ), FALSE );
    return TRUE;
}


void Free_Stack( Stack **stack )
{
    Stack *temp;

    Return_If_Fail( stack );
    
    temp = *stack;
    Return_If_Fail( temp );

    Free_DList( &temp->head );
    free( temp );
    *stack = NULL;
}


/*eof*/
