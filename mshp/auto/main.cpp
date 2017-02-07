/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "Auto.hpp"

Strings names, colors;
Ints release_years, max_speeds, costs;

void prompt() {
    std::cout << ">>> ";
}

void searchInfo() {
    std::cout << std::endl;
    std::cout << "===Search===" << std::endl;
    std::cout << "Format: " << std::endl;
    std::cout << "BY_NAME: 0 value" << std::endl;
    std::cout << "BY_COLOR: 1 value" << std::endl;
    std::cout << "BY_RELEASE_YEAR: 2 value" << std::endl;
    std::cout << "BY_MAX_SPEED: 3 value" << std::endl;
    std::cout << "BY_COST: 4 value" << std::endl;
}

void input() {
    std::string name, color;
    int release_year, max_speed, cost;
    std::cout << "Name: " << std::endl;
    prompt();
    std::cin >> name;
    std::cout << "Color: " << std::endl;
    prompt();
    std::cin >> color;
    std::cout << "Release year: " << std::endl;
    prompt();
    std::cin >> release_year;
    std::cout << "Maximum speed: " << std::endl;
    prompt();
    std::cin >> max_speed;
    std::cout << "Cost: " << std::endl;
    prompt();
    std::cin >> cost;
    names.push_back(name);
    colors.push_back(color);
    release_years.push_back(release_year);
    max_speeds.push_back(max_speed);
    costs.push_back(cost);
}

int main() {
    std::cout << "Please enter numbers of cars: " << std::endl;
    int cars;
    std::cin >> cars;
    for (int i = 0; i < cars; i++) {
        input();
    }
    Auto auto_obj(names, colors, release_years, max_speeds, costs);
    searchInfo();
    while (true) {
        prompt();
        int search_type;
        std::cin >> search_type;
        if ((search_type >= BY_NAME) && (search_type <= BY_COLOR)) {
            std::string str;
            std::cin >> str;
            auto_obj.search(search_type, str);
        } else if ((search_type > BY_COLOR) && (search_type <= BY_COST)) {
            int par;
            std::cin >> par;
            auto_obj.search(search_type, par);
        } else {
            std::cout << "Invalid type of search" << std::endl;
        }
    }
    return 0;
}
