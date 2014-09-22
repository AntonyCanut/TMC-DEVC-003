
#ifndef SpaceInvader_listFormat_h
#define SpaceInvader_listFormat_h

typedef struct sBullets Bullets;

typedef Bullets *(*AddAtFrontBullet)(Bullets *list, BulletStruct *value);
typedef Bullets *(*AddBullet)(Bullets *list, BulletStruct *value);
typedef Bullets *(*DeleteAtFrontBullet)(Bullets *list);
typedef Bullets *(*DeleteAtEndBullet)(Bullets *list);
typedef Bullets *(*DeleteBullet)(Bullets *list);
typedef Bullets *(*ClearBullet)(Bullets *list);
typedef Bullets *(*SearchBullet)(Bullets *list, BulletStruct *value);
typedef Bullets *(*ReturnIElementBullet)(Bullets *list, int item);
typedef Bullets *(*DeleteItemBullet)(Bullets *list, BulletStruct item);
typedef Bullets *(*NextBullet)(Bullets *list);
typedef Bullets *(*CurrentBullet)(Bullets *list);
typedef int (*CountBullet)(Bullets *list);
typedef int (*IsEmptyBullet)(Bullets *list);

struct sBullets{
	AddAtFrontBullet AddAtFront;
	AddBullet Add;
	DeleteAtFrontBullet DeleteAtFront;
	DeleteAtEndBullet DeleteAtEnd;
	ClearBullet Clear;
    BulletStruct *Current;
    Bullets *Next;
	SearchBullet Search;
	CountBullet Count;
	DeleteItemBullet DeleteItem;
	ReturnIElementBullet ReturnIElement;
	IsEmptyBullet IsEmpty;
};


typedef struct sInvaders Invaders;

typedef Invaders *(*AddAtFrontInvader)(Invaders *list, InvaderStruct *value);
typedef Invaders *(*AddInvader)(Invaders *list, InvaderStruct *value);
typedef Invaders *(*DeleteAtFrontInvader)(Invaders *list);
typedef Invaders *(*DeleteAtEndInvader)(Invaders *list);
typedef Invaders *(*DeleteInvader)(Invaders *list);
typedef Invaders *(*ClearInvader)(Invaders *list);
typedef Invaders *(*SearchInvader)(Invaders *list, InvaderStruct *value);
typedef Invaders *(*ReturnIElementInvader)(Invaders *list, int item);
typedef Invaders *(*DeleteItemInvader)(Invaders *list, InvaderStruct item);
typedef Invaders *(*NextInvader)(Invaders *list);
typedef Invaders *(*CurrentInvader)(Invaders *list);
typedef int (*CountInvader)(Invaders *list);
typedef int (*IsEmptyInvader)(Invaders *list);

struct sInvaders{
	AddAtFrontInvader AddAtFront;
	AddInvader Add;
	DeleteAtFrontInvader DeleteAtFront;
	DeleteAtEndInvader DeleteAtEnd;
	ClearInvader Clear;
    InvaderStruct *Current;
    Invaders *Next;
	SearchInvader Search;
	CountInvader Count;
	DeleteItemInvader DeleteItem;
	ReturnIElementInvader ReturnIElement;
	IsEmptyInvader IsEmpty;
};

#endif