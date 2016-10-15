/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define MAX_SIZE 100

int labyrinth[MAX_SIZE][MAX_SIZE];

const char* DIRECTIONS[] = {"NORTH", "WEST", "EAST", "SOUTH"};

typedef std::pair<int, int> IntPair;

void initialize() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            labyrinth[i][j] = 0;
        }
    }
}

std::string getResult(int dir_n) {
    std::string dir = DIRECTIONS[dir_n];
    std::cout << dir << std::endl;
    std::cout.flush();
    std::string res;
    std::cin >> res;
    return res;
}

IntPair moveInDir(IntPair from, int dir_n) {
    if (dir_n == 0) {
        return IntPair(from.first, from.second + 1);
    } else if (dir_n == 1) {
        return IntPair(from.first - 1, from.second);
    } else if (dir_n == 2) {
        return IntPair(from.first + 1, from.second);
    } else if (dir_n == 3) {
        return IntPair(from.first, from.second - 1);
    }
}

void finish(int dir_n) {
    if (dir_n == -1) {
        std::cout << "DONE" << std::endl;
        std::cout.flush();
    } else {
        std::cout << DIRECTIONS[3 - dir_n] << std::endl;
        std::cout.flush();
        std::string garbage;
        std::cin >> garbage;
    }
}

void walk(IntPair xy, int prev_dir) {
    for (int dir_n = 0; dir_n < 4; dir_n++) {
        if (labyrinth[xy.first][xy.second] == dir_n) {
            labyrinth[xy.first][xy.second]++;
            std::string res = getResult(dir_n);
            if (res == "EMPTY") {
                IntPair next = moveInDir(xy, dir_n);
                walk(next, dir_n);
            }
        }
    }
    finish(prev_dir);
}

int main() {
    initialize();
    walk(IntPair(MAX_SIZE / 2, MAX_SIZE / 2), -1);
    return 0;
}
