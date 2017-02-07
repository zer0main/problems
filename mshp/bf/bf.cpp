/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 10000

char tape[SIZE];
int tape_index = 0;

void clear() {
    for (int i = 0; i < SIZE; i++ ) {
        tape[i] = 0;
    }
}

char my_getchar() {
    std::cout << ">>> ";
    char res;
    std::cin >> res;
    std::cout << std::endl;
    return res;
}

void parse(const std::vector<char>& code,
           std::ofstream& result_file) {
    for (int i = 0; i < code.size(); ++i) {
        switch (code[i]) {
            case '>':
                tape_index++;
                break;
            case '<':
                tape_index--;
                break;
            case '+':
                tape[tape_index]++;
                break;
            case '-':
                tape[tape_index]--;
                break;
            case '.':
                result_file << tape[tape_index];
                break;
            case ',':
                tape[tape_index] = my_getchar();
                break;
            case '[':
                if (!tape[tape_index]) {
                    int brackets = 1;
                    while (brackets) {
                        i++;
                        if (code[i] == '[') {
                            brackets++;
                        } else if (code[i] == ']') {
                            brackets--;
                        }
                    }
                }
                break;
            case ']':
                if (tape[tape_index]) {
                    int brackets = 1;
                    while (brackets) {
                        i--;
                        if (code[i] == '[') {
                            brackets--;
                        } else if (code[i] == ']') {
                            brackets++;
                        }
                    }
                    i--;
                }
                break;
        }
    }
}

int main() {
    clear();
    std::ifstream bf_code("bf_code.bf");
    std::vector<char> code;
    if (bf_code.is_open()) {
        while (bf_code) {
            char c;
            bf_code.get(c);
            code.push_back(c);
        }
        bf_code.close();
    } else {
        std::cerr << "Error: Unable to open intput file." << std::endl;
    }
    std::ofstream result_file("result.txt");
    if (result_file.is_open()) {
        parse(code, result_file);
        result_file.close();
    } else {
        std::cerr << "Error: Unable to open output file." << std::endl;
    }
    return 0;
}
