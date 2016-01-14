/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

int C[256];

bool isGood(int c) {
    return (C[c] > 0) && (c != '\n') && (c != '\r') && (c != ' ');
}

int main() {
    for (int i = 0; i < 256; i++) {
        C[i] = 0;
    }
    for (std::string message; std::getline(std::cin, message);) {
        for (int i = 0; i < message.size(); i++) {
            C[message[i]]++;
        }
    }
    int max = 0;
    for (int i = 0; i < 256; i++) {
        if ((C[i] > max) && isGood(i)) {
            max = C[i];
        }
    }
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < 256; j++) {
            if (isGood(j)) {
                if (C[j] >= i) {
                    std::cout << "#";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < 256; j++) {
        if (isGood(j)) {
            std::cout << (char) j;
        }
    }
    std::cout << std::endl;
    return 0;
}
