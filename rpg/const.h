#ifndef __CONST_H__
#define __CONST_H__

/* GENERAL */

#define FPS 100
#define TPS 200

/* WINDOW */

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

/* PROJECTILES */

#define MAX_PROJECTILES 100

#define MAGIC_ATTACK 0
#define FIRE_ATTACK 1

#define MAGIC_PROJECTILE_SPEED 1
#define MAGIC_PROJECTILE_LIFETIME 3
#define MAGIC_PROJECTILE_RANGE (TPS * MAGIC_PROJECTILE_LIFETIME)

#define FIRE_PROJECTILE_SPEED 2
#define FIRE_PROJECTILE_LIFETIME 1
#define FIRE_PROJECTILE_RANGE (TPS * FIRE_PROJECTILE_LIFETIME)

/* ENTITIES */

#define MAX_ENTITIES 250

#define ENTITY_TYPE_PIG 0
#define ENTITY_TYPE_ORC 1
#define ENTITY_TYPE_ROCK 2
#define ENTITY_TYPE_BUSH 3
#define ENTITY_TYPE_TREE 4

#define ENTITIES_NUMBER_OF_TYPES 5

    /* PLANTS */

#define TREE_TIME_TO_BURN 600

#define BUSH_TIME_TO_BURN 300
#define BUSH_BERRIES_RESPAWN_TIME 1000
    /* ENEMIES */

#define CHANCE_TO_CHANGE_DIRECTION 200

#define PIG_MAGIC_DAMAGE 25
#define PIG_FIRE_DAMAGE 100
#define PIG_HEALTH 60

#define ORC_MAGIC_DAMAGE 50
#define ORC_FIRE_DAMAGE 35
#define ORC_HEALTH 300

#define ORC_DIRECTION_UP_LEFT 0
#define ORC_DIRECTION_UP_RIGHT 1
#define ORC_DIRECTION_DOWN_LEFT 2
#define ORC_DIRECTION_DOWN_RIGHT 3
#define ORC_DIRECTION_NONE 4
#define ORC_DIRECTIONS_NUMBER 5

/* PLAYER */


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define NONE 4
#define DIRECTIONS_NUMBER 5

/* BITMAPS */

#define BITMAP_PLAYER_PATH "bitmaps/player.piko"
#define BITMAP_ORC_PATH "bitmaps/orc1.piko"
#define BITMAP_PIG_PATH "bitmaps/pig1.piko"
#define BITMAP_ROCK_PATH "bitmaps/rock1.piko"
#define BITMAP_BUSH_PATH "bitmaps/bush1.piko"
#define BITMAP_TREE_PATH "bitmaps/tree1.piko"
#define BITMAP_FIRE_PROJECTILE_PATH "bitmaps/fire_projectile.piko"
#define BITMAP_MAGIC_PROJECTILE_PATH "bitmaps/magic_projectile.piko"
#define BITMAP_TREE_ON_FIRE_PATH "bitmaps/tree1_on_fire.piko"
#define BITMAP_BUSH_ON_FIRE_PATH "bitmaps/bush1_on_fire.piko"
#define BITMAP_BUSH_NO_BERRIES_PATH "bitmaps/bush1_no_berries.piko"
#define BITMAP_BUSH_NO_BERRIES_ON_FIRE_PATH "bitmaps/bush1_no_berries_on_fire.piko"
#define BITMAP_MAP_PATH "bitmaps/map.piko"

#define BITMAPS_NUMBER 13

/* TYPES */

#define PLAYER_TYPE 0
#define TREE_TYPE 1
#define BUSH_TYPE 2
#define PIG_TYPE 3
#define ROCK_TYPE 4
#define ORC_TYPE 5
#define FIRE_PROJECTILE_TYPE 6
#define MAGIC_PROJECTILE_TYPE 7

#endif /* __CONST_H__ */