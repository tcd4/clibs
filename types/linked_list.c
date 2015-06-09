#include "linked_list.h"

/* List functions */
List* New_List()
{
    List *l;

    l = C_New( List, 1 );
    
    /* not enough memory for a new list */
    Return_Value_If_Fail( l, NULL );

    l->data = NULL;
    l->next = NULL;

    return l;
}


List* Append_To_List( List *list, dataptr data )
{
    List *end;
    List *new;

    Return_Value_If_Fail( list, NULL );

    new = New_List();
    Return_Value_If_Fail( new, NULL );

    new->data = data;

    end = End_Of_List( list );
    end->next = new;

    return list;
}


List* Prepend_To_List( List *list, dataptr data )
{
    List *new;

    Return_Value_If_Fail( list, NULL );

    new = New_List();
    Return_Value_If_Fail( new, NULL );

    new->data = data;
    new->next = list;

    return new;
}


List* Remove_List_Segment( List *list, List *seg )
{
    Return_Value_If_Fail( list, NULL );

    while( list && ( list->next != seg ) )
    {
	list = list->next;
    }

    /* segment was not in the list */
    Return_Value_If_Fail( list, NULL );

    list->next = seg->next;

    Free_List_Segment( seg );

    return list;
}


List* Remove_From_List( List *list, dataptr rm, bool all )
{
    List *temp;

    Return_Value_If_Fail( list, NULL );

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

    while( list )
    {
	new = New_List();
	Return_Value_If_Fail( new, NULL );

	new->data = list->data;

	if( clone )
	{
	    prev->next = new;
	    prev = prev->next;
	}
	else
	{
	    clone = new;
	    prev = new;
	}

	list = list->next;
    }

    return clone;
}


void Free_List_Segment( List *seg )
{
    Return_If_Fail( seg );

    free( seg->data );
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


/* DList functions */
DList* New_DList()
{
}


DList* Append_To_DList( DList *list )
{
}


DList* Prepend_To_DList( DList *list )
{
}


DList* Remove_DList_Segment( DList *list, DList *seg )
{
}


DList* Remove_From_DList( DList *list, dataptr rm, bool all )
{
}


DList* Find_In_DList( DList *list, dataptr data )
{
}


DList* End_Of_DList( DList* list )
{
}


uint64 Length_Of_DList( DList *list )
{
}


DList* Duplicate_DList( DList *list )
{
}


void Free_DList_Segment( DList *seg )
{
}


void Free_DList( DList *list )
{
}

/*eof*/
