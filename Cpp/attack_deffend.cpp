#include <limits>
#include <vector>
#include "player.hpp"

void player_attack(std::vector<player>& a_player, enemy& a_enemy); 
void enemy_attack(enemy& a_enemy, std::vector<player>& a_player); 
void player_cure(std::vector<player>& c_player);
void enemy_cure(enemy& c_enemy);
void mechanics(std::vector<player>& m_player, enemy& m_enemy);
void create_players(std::vector<player>& c_players);

int main() {
    std::vector<player> players;
    enemy my_enemy;

    std::cout << "This is a game about attacking and healing... Enjoy!\n\n";
    create_players(players);

    mechanics(players, my_enemy);
    std::cout << "GAME END\n";

    return 0;
}

void player_attack(std::vector<player>& a_player, enemy& a_enemy) {
    std::string answer;
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

    size_t size = a_player.size();

    for(size_t i = 0; i < size; i++) {
        if(answer == "Y" || answer =="YES") {
            a_player[i].attack(a_enemy);
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...\n";
        } else {
            std::cout << "Wrong input... continuing...\n";
        }

        std::cout << "Current health of enemy: ";
        a_enemy.print_health();
    }
}

void enemy_attack(enemy& a_enemy, std::vector<player>& a_player) {
    std::string answer;
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

    size_t size = a_player.size();

    for(size_t i = 0; i < size; i++) {
        if(answer == "Y" || answer =="YES") {
            a_enemy.attack(a_player[i]);
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...\n";
        } else {
            std::cout << "Wrong input... continuing...\n";
        }

        std::cout << "Current health of player: ";
        a_player[i].print_health();
    }

}

void player_cure(std::vector<player>& c_player) {
    std::string answer;
    std::cout << "Do you want to heal yourself? (y/n): ";
    std::cin >> answer;

    for(size_t i = 0; i < answer.length(); i++) {
        answer[i] = toupper(answer[i]);
    }

    size_t size = c_player.size();

    for(size_t i = 0; i < size; i++) {
        if(answer == "Y" || answer =="YES") {
            c_player[i].cure();
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Continuing...\n";
        } else {
            std::cout << "Wrong input... continuing\n";
        }
        std::cout << "Current health of palyer " << i << " :";
        c_player[i].print_health();
    }

}

void enemy_cure(enemy& c_enemy) {
    std::string answer;
    std::cout << "Do you want to heal yourself? (y/n): ";
    std::cin >> answer;

    for(size_t i = 0; i < answer.length(); i++) {
        answer[i] = toupper(answer[i]);
    }

    if(answer == "Y" || answer =="YES") {
        c_enemy.cure();
    } else if(answer == "N" || answer == "NO") {
        std::cout << "Continuing...\n";
    } else {
        std::cout << "Wrong input... continuing\n";
    }

    std::cout << "Current health: ";
    c_enemy.print_health();
}

void mechanics(std::vector<player>& m_player, enemy& m_enemy) {
    std::string answer;

    for(;;) {
        std::cout << "Its the players turn!\n";
        player_attack(m_player, m_enemy);

        std::cout << "\nIts the enemies turn!\n";
        enemy_attack(m_enemy, m_player);

        std::cout << "\nPlayers turn!\n";
        player_cure(m_player);

        std::cout << "\nEnemies turn!\n";
        enemy_cure(m_enemy);

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
}

void create_players(std::vector<player>& c_players) {
    size_t answer;
    std::cout << "How many players do you want to make?: ";
    std::cin >> answer;

    if(!std::cin) { 
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Wrong input... making default 1!\n"; 
        answer = 1;
    }

    std::string player_names;

    std::cout << "Give me the names of the players separated by spaces. Any extra names will be truncated!\n";

    for(size_t i = 0; i < answer; i++) {
        std::cin >> player_names;

        player new_players(player_names);
        c_players.push_back(new_players);
    }
}

