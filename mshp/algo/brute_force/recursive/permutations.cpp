/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 8

void generate(
    const char* str,
    int size,
    char* prefix,
    int prefix_size,
    unsigned int bitset
) {
    if (prefix_size == size) {
        fwrite(prefix, 1, prefix_size, stdout);
        fwrite("\n", 1, 1, stdout);
    } else {
        char prev = '\0';
        for (int i = 0; i < size; i++) {
            if (str[i] != prev) {
                if (bitset & (1 << (size - i - 1))) {
                    prev = str[i];
                    prefix[prefix_size] = str[i];
                    int del = std::pow(2.0, size - i - 1);
                    generate(
                        str,
                        size,
                        prefix,
                        prefix_size + 1,
                        bitset - del
                    );
                }
            }
        }
    }
}

int main() {
    char str[SIZE], prefix[SIZE];
    int size = fread(str, 1, 8, stdin);
    for (int i = 0; i < size; i++) {
        if (isspace(str[i])) {
            size = i;
            break;
        }
    }
    std::sort(str, str + size);
    unsigned int bitset = 1;
    for (int i = 0; i < size; i++) {
        bitset *= 2;
    }
    bitset--;
    generate(str, size, prefix, 0, bitset);
    return 0;
}
