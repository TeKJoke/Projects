#include <iostream>
#include <limits>

typedef int hp;

class entity {
    public:
    virtual void print_health() = 0;
    virtual void attack() = 0;
    virtual void cure() = 0;
};

class player : entity {
    hp health {100};
    hp attack_dmg {20};
    hp cure_h {10};

    public:
    void print_health() { std::cout << health << '\n'; }
    void attack();
    void cure();

    friend class enemy;

};

void player::attack() {
    health = health - attack_dmg;
}

void player::cure() {
    health = health + cure_h;
}

class enemy : public entity {
    hp health {85};
    hp attack_dmg {10};
    hp cure_h {5};

    public:
    void print_health() {std::cout << health << '\n';}
    void attack();
    void cure(); 

    friend class player;
};

void enemy::attack() {
    health = health - attack_dmg;
}

void enemy::cure() {
    health = health + cure_h;
}

int main() {
    player my_player;
    std::string answer;

    std::cout << "This is a game about attacking and healing... Enjoy!\n\n";

    for(;;) {
        std::cout << "Do you want to attack? (y/n): ";
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
            my_player.attack();
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Current health: ";
            my_player.print_health();
        } else {
            std::cout << "Wrong input... continuing\n";
        }

        std::cout << "Current health: ";
        my_player.print_health();

        std::cout << "Do you want to heal? (y/n): ";
        std::cin >> answer;

        for(size_t i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        if(answer == "Y" || answer =="YES") {
            my_player.cure();
        } else if(answer == "N" || answer == "NO") {
            std::cout << "Current health: ";
            my_player.print_health();
        } else {
            std::cout << "Wrong input... continuing\n";
        }

        std::cout << "Current health: ";
        my_player.print_health();

        std::cout << "Do you want to continue playing? (y/n): ";
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
            continue;
        }
    }
    std::cout << "GAME END\n";

    return 0;
}

