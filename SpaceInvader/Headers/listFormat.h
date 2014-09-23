
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
    struct sBullets *Next;
	SearchBullet Search;
	CountBullet Count;
	DeleteItemBullet DeleteItem;
	ReturnIElementBullet ReturnIElement;
	IsEmptyBullet IsEmpty;
};

#endif