/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

// The problem is to make queue from two stacks.

std::stack<int> input, output;

void move() {
    while (!input.empty()) {
        int element = input.top();
        input.pop();
        output.push(element);
    }
}

enum Command {
    PUSH,
    POP
};

int main() {
    while (true) {
        int command, arg;
        std::cin >> command;
        if (command == PUSH) {
            std::cin >> arg;
            input.push(arg);
        } else if (command == POP) {
            if (output.empty()) {
                move();
            }
            output.pop();
        } else {
            std::cerr << "Invalid command." << std::endl;
        }
    }
    return 0;
}
