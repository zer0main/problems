/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <sys/types.h>
#include <unistd.h>

#include <bits/stdc++.h>

int main() {

    srand(time(NULL) ^ getpid());
    auto coinFlipping = []() {
        return rand() < (RAND_MAX / 2);
    };

    auto getBit = []() {
        char bit;
        int read_bytes = fread(&bit, 1, 1, stdin);
        if (read_bytes != 1) {
            throw std::logic_error("Bad input");
        }
        return bit == '1';
    };

    bool result = [&]() {
        while (true) {
            bool random_bit = coinFlipping();
            bool expected_bit = getBit();
            if (random_bit < expected_bit) {
                // generated number < input
                return 1;
            }
            if (random_bit > expected_bit) {
                // generated number > input
                return 0;
            }
        }
    }();

    std::cout << result << std::endl;
    return 0;
}
