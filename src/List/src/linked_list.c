#include "linked_list.h"


List* New_List( dataptr data )
{
    List *l;

    l = C_New( List, 1 );
    Return_Value_If_Fail( l, NULL );

    l->data = data;
    l->next = NULL;

    return l;
}


List* Append_To_List( List *list, dataptr data )
{
    List *end;
    List *new;

    Return_Value_If_Fail( list, NULL );

    new = New_List( data );
    Return_Value_If_Fail( new, NULL );

    end = End_Of_List( list );
    end->next = new;

    return list;
}


List* Prepend_To_List( List *list, dataptr data )
{
    List *new;

    Return_Value_If_Fail( list, NULL );

    new = New_List( data );
    Return_Value_If_Fail( new, NULL );

    new->next = list;

    return new;
}


List* Remove_List_Segment( List *list, List *seg )
{
    List *temp;

    Return_Value_If_Fail( list, NULL );
    Return_Value_If_Fail( seg, list );

    if( list == seg )
    {
	temp = list->next;
	Free_List_Segment( list );
	return temp;
    }
    
    temp = list;

    while( temp && temp->next && ( temp->next != seg ) )
    {
	temp = temp->next;
    }
    
    Return_Value_If_Fail( temp, list );

    temp->next = seg->next;

    Free_List_Segment( seg );
   
    return list;
}


List* Remove_From_List( List *list, dataptr rm, bool all )
{
    List *temp;

    Return_Value_If_Fail( list, NULL );

    temp = list;

    while( temp )
    {
	if( temp->data == rm )
	{
	    Remove_List_Segment( list, temp );
	    
	    if( !all ) break;
	}

	temp = temp->next;
    }

    return list;
}


List* Find_In_List( List *list, dataptr data )
{
    while( list )
    {
	if( list->data == data ) break;

	list = list->next;
    }

    return list;
}


List* End_Of_List( List* list )
{
    Return_Value_If_Fail( list, NULL );

    while( list->next )
    {
	list = list->next;
    }

    return list;
}


uint64 Length_Of_List( List *list )
{
    uint64 c = 0;

    while( list )
    {
	c++;

	list = list->next;
    }

    return c;
}


List* Duplicate_List( List *list )
{
    List *clone, *new, *prev;

    clone = NULL;

    while( list )
    {
	new = New_List( list->data );
	if( !new )
	{
	    Free_List( &clone );
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


void Free_List_Segment( List *seg )
{
    Return_If_Fail( seg );

    free( seg );
}


void Free_List( List **list )
{
    List *temp, *next;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    temp = *list;

    while( temp )
    {
	next = temp->next;
	Free_List_Segment( temp );
	temp = next;
    }

    *list = NULL;
}


/*eof*/
