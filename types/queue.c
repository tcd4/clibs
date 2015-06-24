#include "queue.h"


Queue* New_Queue()
{
    Queue *new;

    new = C_New( Queue, 1 );
    Return_Value_If_Fail( new, NULL );

    new->head = NULL;
    new->length = 0;

    return new;
}


void Push_Queue( Queue *queue, dataptr data )
{
    List *new;

    Return_If_Fail( queue );

    if( !queue->head )
    {
	new = New_List();
	Return_If_Fail( new );
	new->data = data;
    }
    else
    {
	new = Append_To_List( queue->head, data );
	Return_If_Fail( new );
    }

    queue->head = new;
    queue->length++;
}


dataptr Pop_Queue( Queue *queue )
{
    dataptr temp;

    Return_Value_If_Fail( queue, NULL );

    temp = queue->head->data;

    queue->head = Remove_List_Segment( queue->head, queue->head );
    queue->length--;

    return temp;
}


void Clear_Queue( Queue *queue )
{
    Return_If_Fail( queue );

    Free_List( &queue->head );

    queue->length = 0;
}


bool Queue_Is_Empty( Queue *queue )
{
    Return_Value_If_Fail( queue, FALSE );
    Return_Value_If_Fail( queue->head, FALSE );
    return TRUE;
}


Queue* Duplicate_Queue( Queue *queue )
{
    Queue *new;

    Return_Value_If_Fail( queue, NULL );

    new = New_Queue();
    Return_Value_If_Fail( new, NULL );

    if( !Queue_Is_Empty( queue ) )
    {
	new->head = Duplicate_List( queue->head );
	if( !new->head )
	{
	    Free_Queue( &new );
	    return NULL;
	}
    }

    new->length = queue->length;

    return new;
}


void Free_Queue( Queue **queue )
{
    Queue *temp;
    
    Return_If_Fail( queue );
    
    temp = *queue;
    Return_If_Fail( temp );

    Free_List( &temp->head );
    free( temp );
    *queue = NULL;
}


/*eof*/
