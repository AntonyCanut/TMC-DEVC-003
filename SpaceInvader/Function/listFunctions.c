#include "../Headers/header.h"

Bullets *AddAtFrontBulletList(Bullets *list, BulletStruct *value)
{
	Bullets* newElement = InitBulletList();
	newElement->Current = value;
	newElement->Next = list;
    return (newElement);
}

Bullets *DeleteAtFrontBulletList(Bullets *list)
{
    if(list != NULL)
    {
        Bullets* toReturn = list->Next;
        free(list);
        return (toReturn);
    }
    else
        return (NULL);
}

Bullets *AddAtEndBulletList(Bullets *list, BulletStruct *value)
{
    Bullets* newElement = InitBulletList();
 	newElement->Current = value;
    if(list == NULL)
    	return (newElement);
    else
    {
    	Bullets* temp=list;
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newElement;
        return (list);
    }
}

Bullets *DeleteAtEndBulletList(Bullets *list)
{
    if(list != NULL)
    {
        Bullets* toReturn = list->Next;
        free(list);
        return (toReturn);
    }
    else
        return (NULL);
}

Bullets *ElementiBulletList(Bullets *list, int item)
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

Bullets *EraseBulletList(Bullets *list)
{
    if(list == NULL)
    	return (NULL);
    else
    {
        Bullets *tmp;
        tmp = list->Next;
        free(list);
        return (EraseBulletList(tmp));
    }
}

int IsEmptyBulletList(Bullets *list)
{
    return ((list == NULL)? 1 : 0);
}

int CountBulletList(Bullets *list)
{
    if(list == NULL)
        return 0;
    return (CountBulletList(list->Next)+1);
}

Bullets *InitBulletList()
{
	Bullets *listOfBullets;
    listOfBullets = malloc(sizeof(*listOfBullets));
	listOfBullets->AddAtFront = AddAtFrontBulletList;
    listOfBullets->Add = AddAtEndBulletList;
    listOfBullets->DeleteAtEnd = DeleteAtEndBulletList;
    listOfBullets->DeleteAtFront = DeleteAtFrontBulletList;
    listOfBullets->Clear = EraseBulletList;
    listOfBullets->ReturnIElement = ElementiBulletList;
    listOfBullets->Count = CountBulletList;
    listOfBullets->IsEmpty = IsEmptyBulletList;
    listOfBullets->Next = NULL;
    return (listOfBullets);
}