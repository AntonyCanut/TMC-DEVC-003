#include "../Headers/header.h"

Invaders *AddAtFrontInvaderList(Invaders *list, InvaderStruct *value)
{
	Invaders *newElement = InitInvaderList();
	newElement->Current = value;
	newElement->Next = list;
    return (newElement);
}

Invaders *DeleteAtFrontInvaderList(Invaders *list)
{
    if(list != NULL)
    {
        Invaders* toReturn = list->Next;
        free(list);
        return (toReturn);
    }
    else
        return (NULL);
}

Invaders *AddAtEndInvaderList(Invaders *list, InvaderStruct *value)
{
    Invaders* newElement = InitInvaderList();
 	newElement->Current = value;
    if(list == NULL)
    	return (newElement);
    else
    {
    	Invaders* temp=list;
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newElement;
        return (list);
    }
}

Invaders *DeleteAtEndInvaderList(Invaders *list)
{
    if(list != NULL)
    {
        Invaders* toReturn = list->Next;
        free(list);
        return (toReturn);
    }
    else
        return (NULL);
}

Invaders *DeleteElementInvaderList(Invaders *list, InvaderStruct *value)
{
    if(list == NULL)
        return NULL;
    if(list->Current == value)
    {
        Invaders* tmp = list->Next;
        list->Current->Destroy(list->Current);
        free(list);
        tmp = DeleteElementInvaderList(tmp, value);
        return tmp;
    }
    else
    {
        list->Next = DeleteElementInvaderList(list->Next, value);
        return list;
    }
}

Invaders *ElementiInvaderList(Invaders *list, int item)
{
    int i;
    for(i=0; i<item && list != NULL; i++)
    {
        list = list->Next;
    }
 	
 	if(list == NULL)
    {
        return (NULL);
    }
    else
    {
        return (list);
    }
}

Invaders *EraseInvaderList(Invaders *list)
{
    if(list == NULL)
    	return (NULL);
    else
    {
        Invaders *tmp;
        tmp = list->Next;
        free(list);
        return (EraseInvaderList(tmp));
    }
}

int IsEmptyInvaderList(Invaders *list)
{
    return ((list == NULL)? 1 : 0);
}

int CountInvaderList(Invaders *list)
{
    if(list == NULL)
        return 0;
    return (CountInvaderList(list->Next)+1);
}

Invaders *InitInvaderList()
{
	Invaders *listOfInvaders;
    listOfInvaders = malloc(sizeof(*listOfInvaders));
	listOfInvaders->AddAtFront = AddAtFrontInvaderList;
    listOfInvaders->Add = AddAtFrontInvaderList;
    listOfInvaders->DeleteAtEnd = DeleteAtEndInvaderList;
    listOfInvaders->DeleteAtFront = DeleteAtFrontInvaderList;
    listOfInvaders->Delete = DeleteElementInvaderList;
    listOfInvaders->Clear = EraseInvaderList;
    listOfInvaders->ReturnIElement = ElementiInvaderList;
    listOfInvaders->Count = CountInvaderList;
    listOfInvaders->IsEmpty = IsEmptyInvaderList;
    listOfInvaders->Next = NULL;
    return (listOfInvaders);
}