#include "../Headers/header.h"

ListBullet *AddAtFrontBulletList(ListBullet *list, BulletStruct value)
{
	ListBullet* newElement = malloc(sizeof(ListBullet));
	newElement->Current = value;
	newElement->Next = list;
    return (newElement);
}

ListBullet *DeleteAtFrontBulletList(ListBullet *list)
{
    if(list != NULL)
    {
        ListBullet* toReturn = list->Next;
        free(list);
        return (toReturn);
    }
    else
        return (NULL);
}

ListBullet *AddAtEndBulletList(ListBullet *list, BulletStruct value)
{
    ListBullet* newElement = malloc(sizeof(ListBullet));
 	newElement->Current = value;
 	newElement->Next = NULL;
    if(list == NULL)
    	return (newElement);
    else
    {
    	ListBullet* temp=list;
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newElement;
        return (list);
    }
}

ListBullet *DeleteAtEndBulletList(ListBullet *list)
{
    if(list != NULL)
    {
        ListBullet* toReturn = list->Next;
        free(list);
        return (toReturn);
    }
    else
        return (NULL);
}

// ListBullet *SearchInBulletList(ListBullet *list, BulletStruct value)
// {
//     ListBullet *tmp=list;
//     while(tmp != NULL)
//     {
//         if(tmp->Current == value)
//         	return (tmp);
//         tmp = tmp->Next;
//     }
//     return (NULL);
// }

ListBullet *ElementiBulletList(ListBullet *list, int item)
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

// ListBullet *DeleteElementBulletList(ListBullet *list, BulletStruct value)
// {
//     if(list == NULL)
//         return (NULL);
 
//     if(list->Current == value)
//     {
//         ListBullet* tmp = list->Next;
//         free(list);
//         tmp = deleteElement(tmp, value);
//         return (tmp);
//     }
//     else
//     {
//         list->Next = deleteElement(list->Next, value);
//         return (list);
//     }
// }

ListBullet *EraseBulletList(ListBullet *list)
{
    if(list == NULL)
    	return (NULL);
    else
    {
        ListBullet *tmp;
        tmp = list->Next;
        free(list);
        return (EraseBulletList(tmp));
    }
}

int IsEmptyBulletList(ListBullet *list)
{
    return ((list == NULL)? 1 : 0);
}

// Obtenu grace a l'exemple web potentiellement inutile
// void PrintBulletList(ListBullet *list)
// {
//     ListBullet *tmp = list;
//     while(tmp != NULL)
//     {
//     	printf("%d ", tmp->Current);
//         tmp = tmp->Next;
//     }
// }

void InitBulletList()
{
	Bullets *listOfBullets;
    listOfBullets = malloc(sizeof(*listOfBullets));
	listOfBullets->AddAtFront = AddAtFrontBulletList;
    listOfBullets->Add = AddAtFrontBulletList;
    listOfBullets->DeleteAtEnd = DeleteAtEndBulletList;
    listOfBullets->DeleteAtFront = DeleteAtFrontBulletList;
    listOfBullets->Clear = EraseBulletList;
    // listOfBullets->Search = SearchInBulletList;
    listOfBullets->ReturnIElement = ElementiBulletList;
    // listOfBullets->DeleteItem = DeleteElementBulletList;
    listOfBullets->IsEmpty = IsEmptyBulletList;
}