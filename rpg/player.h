#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <mutex>
#include <thread>
#include <condition_variable>
#include <random>
#include <queue>
#include "enemy.h"
#include "magic_wand.h"
#include "fire_wand.h"
#include "no_weapon.h"

class player : public entity{
protected:

    weapon * weapons[WEAPONS_NUMBER];
    int current_weapon;

    int direction_x;
    int direction_y;

    void teleport(int x, int y)
    {
        position.set(x, y);
    }

    void set_weapons()
    {
        weapons[0] = new no_weapon(bitmaps);
        weapons[1] = new magic_wand(bitmaps);
        weapons[2] = new fire_wand(bitmaps);
    }

public:

    player(ALLEGRO_BITMAP ** bitmaps)
    {
        direction_x = 0;
        direction_y = 0;
        bitmap_index = BITMAP_PLAYER_INDEX;
        entity_type = PLAYER_TYPE;
        entity::init(0, 0, bitmaps);
        current_weapon = 0;
        set_weapons();
    }

    void move(entity ** entities, entity * player)
    {
        position.change(direction_x, direction_y);
        update_hitbox();
        if(check_ban_map(BITMAP_WATER_MAP_INDEX))
        {
            position.change(-direction_x, -direction_y);
        }
        else
        {
            for (int i = 0; i < MAX_ENTITIES; i++)
            {
                if (entity_collide(entities[i]))
                {
                    position.change(-direction_x, -direction_y);
                    i = MAX_ENTITIES;
                }
            }
        }
        position.trim(map_width - width, map_height - height);
        position.trim_bottom(0, 0);
        update_hitbox();
    }

    void change_direction(int dx, int dy)
    {
        direction_x += dx;
        direction_y += dy;
        if(direction_x > 1)
            direction_x = 1;
        if(direction_x < -1)
            direction_x = -1;
        if(direction_y > 1)
            direction_y = 1;
        if(direction_y < -1)
            direction_y = -1;
    }

    bool entity_collide(entity * e)
    {
        bool ans = entity::entity_collide(e);
        if (ans)
        {
            if (e->get_type() == ORC_TYPE)
                teleport(0, 0);
        }
        return ans;
    }

    bool collide(coordinate left_upper, coordinate right_bottom, int type)
    {
        bool ans = entity::collide(left_upper, right_bottom, type);
        if (ans)
        {
            if (type == ORC_TYPE)
                teleport(0, 0);
        }
        return ans;
    }

    coordinate get_position()
    {
        return position;
    }

    void hit_by(int type)
    {
        return;
    }

    void change_weapon(int number)
    {
        current_weapon = number - 1;
        if(number == 1)
            bitmap_index = BITMAP_PLAYER_INDEX;
        if(number == 2)
            bitmap_index = BITMAP_PLAYER_WITH_MAGIC_WAND_INDEX;
        if(number == 3)
            bitmap_index = BITMAP_PLAYER_WITH_FIRE_WAND_INDEX;
    }

    void use_weapon(int mouse_x, int mouse_y, int mode, projectile * projectiles, coordinate camera)
    {
        for(int i = 0; i < MAX_PROJECTILES; i++)
        {
            if(!projectiles[i].does_exist())
            {
                double dx = mouse_x + camera.x - position.x;
                double dy = mouse_y + camera.y - position.y;
                weapons[current_weapon]->attack(position.x, position.y, dx, dy, mode, &(projectiles[i]));
                return;
            }
        }
    }
};

#endif /* __PLAYER_H__ */