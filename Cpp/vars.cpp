#include <iostream>
#include <limits>
#include <vector>

int main() {
    int n;

    std::cin >> n;

    for(int i = 0; i < n; i++) {
    }

    size_t answer;
    std::cout << "How many variable do you want to make?: ";
    std::cin >> answer;

    if(!std::cin) { 
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Wrong input... making default 1!\n"; 
        answer = 1;
    }

    std::vector<std::string> variables(answer);
    std::string var_names;

    std::cout << "Give me the names of the variables separated by spaces and end the input witha semicolon (;).\n";

    while(std::cin >> var_names && var_names != ";") { 
        variables.push_back(var_names);
    }

    for(auto i : variables) {
        std::cout << i << '\n';
    }

    return 0;
}

