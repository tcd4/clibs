#include "doubly_linked_list.h"


DList* New_DList( dataptr data )
{
    DList *new;

    new = C_New( DList, 1 );
    Return_Value_If_Fail( new, NULL );

    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    
    return new;
}


DList* Append_To_DList( DList *list, dataptr data )
{
    DList *end;
    DList *new;

    Return_Value_If_Fail( list, NULL );

    new = New_DList( data );
    Return_Value_If_Fail( new, NULL );

    end = End_Of_DList( list );

    new->prev = end;
    end->next = new;

    return list;
}


DList* Prepend_To_DList( DList *list, dataptr data )
{
    DList *new;

    Return_Value_If_Fail( list, NULL );

    new = New_DList( data );
    Return_Value_If_Fail( new, NULL );

    new->next = list;

    return new;
}


DList* Remove_DList_Segment( DList *list, DList *seg )
{
    DList *temp;

    Return_Value_If_Fail( list, NULL );
    Return_Value_If_Fail( seg, list );

    if( list == seg )
    {
	temp = list->next;
	Free_DList_Segment( list );
	return temp;
    }
    
    temp = list;

    while( temp && temp->next && ( temp->next != seg ) )
    {
	temp = temp->next;
    }
    
    Return_Value_If_Fail( temp, list );

    temp->next = seg->next;

    Free_DList_Segment( seg );

    return list;
}


DList* Remove_From_DList( DList *list, dataptr rm, bool all )
{
    DList *temp;

    Return_Value_If_Fail( list, NULL );

    temp = list;

    while( temp )
    {
	if( temp->data == rm )
	{
	    Remove_DList_Segment( list, temp );
	    
	    if( !all ) break;
	}

	temp = temp->next;
    }

    return list;
}


DList* Find_In_DList( DList *list, dataptr data )
{
    while( list )
    {
	if( list->data == data ) break;

	list = list->next;
    }

    return list;
}


DList* End_Of_DList( DList* list )
{
    Return_Value_If_Fail( list, NULL );

    while( list->next )
    {
	list = list->next;
    }

    return list;
}


uint64 Length_Of_DList( DList *list )
{
    uint64 c = 0;

    while( list )
    {
	c++;

	list = list->next;
    }

    return c;
}


DList* Duplicate_DList( DList *list )
{
    DList *clone, *new, *prev;

    clone = NULL;

    while( list )
    {
	new = New_DList( list->data );
	if( !new )
	{
	    Free_DList( &clone );
	}

	if( !clone )
	{
	    clone = new;
	    prev = new;
	}
	else
	{
	    prev->next = new;
	    prev = prev->next;
	}
      
	list = list->next;
    }

    return clone;
}


void Free_DList_Segment( DList *seg )
{
    Return_If_Fail( seg );

    free( seg->data );
    free( seg );
}


void Free_DList( DList **list )
{
    DList *temp, *next;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    temp = *list;

    while( temp )
    {
	next = temp->next;
	Free_DList_Segment( temp );
	temp = next;
    }

    *list = NULL;
}


/*eof*/
