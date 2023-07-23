#ifndef __ORC_H__
#define __ORC_H__

#include "enemy.h"

class orc : public enemy {
public:
    orc(double x, double y)
    {
        position.set(x, y);
        bitmap = al_load_bitmap(ORC_1_PATH);
        width = al_get_bitmap_width(bitmap);
        height = al_get_bitmap_height(bitmap);
        hitbox_start.set(x, y);
        hitbox_end.set(x + width, y + height);
        health_points = ORC_HEALTH;
        fire_damage = ORC_FIRE_DAMAGE;
        magic_damage = ORC_MAGIC_DAMAGE;
        can_player_pass = false;
    }
    void move(entity ** entities, coordinate player_hitbox_start, coordinate player_hitbox_end)
    {
        if(!exist)
            return;
        if(direction == ORC_DIRECTION_UP_RIGHT)
        {
            move_in_direction(UP, entities, player_hitbox_start, player_hitbox_end);
            move_in_direction(RIGHT, entities, player_hitbox_start, player_hitbox_end);
        }
        if(direction == ORC_DIRECTION_DOWN_LEFT)
        {
            move_in_direction(DOWN, entities, player_hitbox_start, player_hitbox_end);
            move_in_direction(LEFT, entities, player_hitbox_start, player_hitbox_end);
        }
        if(direction == ORC_DIRECTION_UP_LEFT)
        {
            move_in_direction(UP, entities, player_hitbox_start, player_hitbox_end);
            move_in_direction(LEFT, entities, player_hitbox_start, player_hitbox_end);
        }
        if(direction == ORC_DIRECTION_DOWN_RIGHT)
        {
            move_in_direction(DOWN, entities, player_hitbox_start, player_hitbox_end);
            move_in_direction(RIGHT, entities, player_hitbox_start, player_hitbox_end);
        }
        std::random_device dev;
        std::mt19937 rng;
        rng = std::mt19937(dev());
        std::uniform_int_distribution<std::mt19937::result_type> change_direction_generator;

        change_direction_generator = std::uniform_int_distribution<std::mt19937::result_type>(0, CHANCE_TO_CHANGE_DIRECTION);
        if(change_direction_generator(rng) == 0)
        {
            if(direction == NONE)
            {
                std::uniform_int_distribution <std::mt19937::result_type> new_direction;
                new_direction = std::uniform_int_distribution<std::mt19937::result_type>(0, DIRECTIONS_NUMBER);
                direction = new_direction(rng);
            }
            else
                direction = NONE;
        }
    }
};

#endif //__ORC_H__

