#include <iostream>
#include "enemy.hpp"
#include "player.hpp"

void enemy::print_health() {
    std::cout << health << '\n';
}

void enemy::attack(player& rival) {
    rival.health = rival.health - attack_dmg;
}
