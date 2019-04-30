#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

class player;

class enemy : public entity {
    std::string name;
    hp health {80};
    hp attack_dmg {10};
    hp cure_h {5};

    public:
    enemy()
        :name("Bob")
    {}
    enemy(std::string e_name)
        :name(e_name) 
    {}

    void cure() { health = health + cure_h; }
    void print_health();
    void attack(player& rival);

    friend class player;
};

#endif
