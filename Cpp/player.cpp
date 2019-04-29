#include <iostream>
#include "player.hpp"
#include "enemy.hpp"

void player::print_health() {
    std::cout << health << '\n';
}

void player::attack(enemy& rival) {
    rival.health = rival.health - attack_dmg;
}
