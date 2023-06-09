#ifndef __FIRE_PROJECTILE_H__
#define __FIRE_PROJECTILE_H__

#include "const.h"
#include "coordinate.h"
#include <mutex>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "projectile.h"

class fire_projectile: public projectile {
public:
    fire_projectile()
    {
        dx = 0;
        dy = 0;
        color = FIRE_PROJECTILE_COLOR;
        size = FIRE_PROJECTILE_SIZE;
        speed = FIRE_PROJECTILE_SPEED;
        range = FIRE_PROJECTILE_RANGE;
    }

    fire_projectile(coordinate camera, int mouse_x, int mouse_y)
    {
        x = camera.x * MAP_CELL_SIZE + mouse_x;
        y = camera.y * MAP_CELL_SIZE + mouse_y;
        color = FIRE_PROJECTILE_COLOR;
        size = FIRE_PROJECTILE_SIZE;
        speed = FIRE_PROJECTILE_SPEED;
        range = FIRE_PROJECTILE_RANGE;
    }

};

#endif //__FIRE_PROJECTILE_H__
