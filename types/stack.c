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
    List *new;

    Return_If_Fail( stack );

    if( !stack->head )
    {
	new = New_List();
	Return_If_Fail( new );

	new->data = data;
    }
    else
    {
	new = Append_To_List( stack->head, data );
	Return_If_Fail( new );
    }

    stack->head = new;
    stack->tail = End_Of_List( new );
    stack->length++;
}


dataptr Pop_Stack( Stack *stack )
{
    dataptr temp;

    Return_Value_If_Fail( stack, NULL );

    temp = stack->tail->data;

    stack->head = Remove_List_Segment( stack->head, stack->tail );
    stack->length--;

    return temp;
}


void Clear_Stack( Stack *stack )
{
    Return_If_Fail( stack );

    Free_List( &stack->head );
   
    stack->tail = NULL;
    stack->length = 0;
}


bool Stack_Is_Empty( Stack *stack )
{
    Return_Value_If_Fail( stack, FALSE );
    Return_Value_If_Fail( stack->head, FALSE );
    return TRUE;
}


Stack* Duplicate_Stack( Stack *stack )
{
    Stack *new;

    Return_Value_If_Fail( stack, NULL );

    new = New_Stack();
    Return_Value_If_Fail( new, NULL );

    if( !Stack_Is_Empty( stack ) )
    {
	if( !new->head )
	{
	    Free_Stack( &new );
	    return NULL;
	}

	new->head = Duplicate_List( stack->head );
	new->tail = End_Of_List( stack->head );
    }
    
    new->length = stack->length;

    return new;
}


void Free_Stack( Stack **stack )
{
    Stack *temp;

    Return_If_Fail( stack );
    
    temp = *stack;
    Return_If_Fail( temp );

    Free_List( &temp->head );
    free( temp );
    *stack = NULL;
}


/*eof*/
