#ifndef PLAYER_H
#define PLAYER_H

#include "enemy.hpp"

class player : public entity {
    hp health {100};
    hp attack_dmg {20};
    hp cure_h {10};

    public:
    void cure() { health = health + cure_h; }
    void print_health();
    void attack(enemy& rival);

    friend class enemy;
};

#endif
