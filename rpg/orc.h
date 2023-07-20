#ifndef __ORC_H__
#define __ORC_H__

#include "enemy.h"

class orc : public enemy {
public:
    orc(double x, double y)
    {
        position.set(x, y);
        size = ORC_SIZE;
        hitbox_start.set(x - size / 2, y - size / 2);
        hitbox_end.set(x + size / 2, y + size / 2);
        health_points = ORC_HEALTH;
        fire_damage = ORC_FIRE_DAMAGE;
        magic_damage = ORC_MAGIC_DAMAGE;
        color = ORC_COLOR;
        can_player_pass = false;
    }
    void update_hitbox()
    {
        hitbox_start.set(position.x - size / 2, position.y - size / 2);
        hitbox_end.set(position.x + size / 2, position.y + size / 2);
    }
    void move(entity ** entities, coordinate player_hitbox_start, coordinate player_hitbox_end)
    {
        if(!exist)
            return;
        is
        }
        if(direction == DOWN)
        {
            position.x--;
            position.y++;
        }
        if(direction == LEFT)
        {
            position.x--;
            position.y--;
        }
        if(direction == RIGHT)
        {
            position.x++;
            position.y++;
        }
        update_hitbox();
        if(!check_position(entities, player_hitbox_start, player_hitbox_end))
        {
            if(direction == UP)
            {
                position.x--;
                position.y++;
            }
            if(direction == DOWN)
            {
                position.x++;
                position.y--;
            }
            if(direction == LEFT)
            {
                position.x++;
                position.y++;
            }
            if(direction == RIGHT)
            {
                position.x--;
                position.y--;
            }
            update_hitbox();
        }s

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
