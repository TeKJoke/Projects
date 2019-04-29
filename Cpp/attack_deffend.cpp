#include <iostream>
#include <limits>
#include "player.hpp"

int main() {
    player my_player;
    enemy my_enemy;

    std::string answer;

    std::cout << "This is a game about attacking and healing... Enjoy!\n\n";

    for(;;) {
        std::cout << "Its the players turn!\n";
        std::cout << "Do you want to attack the enemy? (y/n): ";
        std::cin >> answer;

        if(!std::cin) {
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input... continuing!\n";
        }

        for(size_t i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        if(answer == "Y" || answer =="YES") {
            my_player.attack(my_enemy);
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...\n";
        } else {
            std::cout << "Wrong input... continuing...\n";
        }

        std::cout << "Current health of enemy: ";
        my_enemy.print_health();

        std::cout << "\nIts the enemies turn!\n";
        std::cout << "Do you want to attack the player? (y/n): ";
        std::cin >> answer;

        if(!std::cin) {
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input... continuing!\n";
        }

        for(size_t i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        if(answer == "Y" || answer =="YES") {
            my_enemy.attack(my_player);
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...\n";
        } else {
            std::cout << "Wrong input... continuing...\n";
        }

        std::cout << "Current health of player: ";
        my_player.print_health();

        std::cout << "\nPlayers turn!\n";
        std::cout << "Do you want to heal yourself? (y/n): ";
        std::cin >> answer;

        for(size_t i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        if(answer == "Y" || answer =="YES") {
            my_player.cure();
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...";
        } else {
            std::cout << "Wrong input... continuing\n";
        }

        std::cout << "Current health: ";
        my_player.print_health();

        std::cout << "\nEnemies turn!\n";
        std::cout << "Do you want to heal yourself? (y/n): ";
        std::cin >> answer;

        for(size_t i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        if(answer == "Y" || answer =="YES") {
            my_enemy.cure();
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...";
        } else {
            std::cout << "Wrong input... continuing\n";
        }

        std::cout << "Current health: ";
        my_enemy.print_health();

        std::cout << "\nDo you want to continue playing? (y/n): ";
        std::cin >> answer;

        for(size_t i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        if(answer == "Y" || answer =="YES") {
            continue;
        } else if(answer == "N" || answer == "NO") {
            break;
        } else {
            std::cout << "Wrong input... exiting!\n";
            break;
        }
    }
    std::cout << "GAME END\n";

    return 0;
}

