#ifndef PLAYER_H
#define PLAYER_H

#include "enemy.hpp"

class player : public entity {
    std::string name;
    hp health {100};
    hp attack_dmg {20};
    hp cure_h {10};

    public:
    player()
        :name("bad bob")
    {}
    player(std::string p_name)
        :name(p_name)
    {}

    void cure() { health = health + cure_h; }
    void print_name() { std::cout << name << '\n'; }
    void print_health();
    void attack(enemy& rival);

    friend class enemy;
};

#endif
