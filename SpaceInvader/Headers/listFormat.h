#include <stdlib.h>
#include "spriteFunc.h"

#ifndef SpaceInvader_listFormat_h
#define SpaceInvader_listFormat_h

// typedef struct sListBullet ListBullet;

typedef struct sListBullet {
    BulletStruct Current;
    struct sListBullet *Next;
} ListBullet;

typedef ListBullet (*AddAtFrontBullet)(ListBullet list, BulletStruct value);
typedef ListBullet (*AddBullet)(ListBullet list, BulletStruct value);
typedef ListBullet (*DeleteAtFrontBullet)(ListBullet list);
typedef ListBullet (*DeleteAtEndBullet)(ListBullet list);
typedef ListBullet (*DeleteBullet)(ListBullet list);
typedef ListBullet (*ClearBullet)(ListBullet list);
typedef ListBullet (*SearchBullet)(ListBullet list, BulletStruct value);
typedef ListBullet (*ReturnIElementBullet)(ListBullet list, int item);
typedef ListBullet (*DeleteItemBullet)(ListBullet list, BulletStruct item);
typedef int (*IsEmptyBullet)(ListBullet list);

typedef struct sBullets{
	AddAtFrontBullet AddAtFront;
	AddBullet Add;
	DeleteAtFrontBullet DeleteAtFront;
	DeleteAtEndBullet DeleteAtEnd;
	ClearBullet Clear;
	SearchBullet Search;
	DeleteItemBullet DeleteItem;
	ReturnIElementBullet ReturnIElement;
	IsEmptyBullet IsEmpty;
} Bullets;

#endif