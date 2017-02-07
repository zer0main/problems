/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

typedef std::vector<int> Ints;

Ints tree;

void initialize(int N) {
    tree.resize(N, 0);
}

void update(int i, int val) {
    for (; i < tree.size(); i = (i | (i + 1))) {
        tree[i] += val;
    }
}

int sum(int i) {
    int sum = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        sum += tree[i];
    }
    return sum;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

enum Command {
    STOP,
    UPDATE,
    SUM
};

int main() {
    int N;
    std::cin >> N;
    initialize(N);
    int command, p1, p2;
    while (true) {
        std::cin >> command;
        if (command == STOP) {
            break;
        } else if (command == UPDATE) {
            std::cin >> p1 >> p2;
            update(p1 - 1, p2);
        } else if (command == SUM) {
            std::cin >> p1 >> p2;
            std::cout << sum(p1 - 1, p2 - 1) << std::endl;
        } else {
            std::cerr << "Invalid command." << std::endl;
        }
    }
    return 0;
}
