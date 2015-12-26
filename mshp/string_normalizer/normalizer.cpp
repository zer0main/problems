/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

std::string correctUppers(const std::string& str) {
    // a single-character delimiters between sentences
    static const char delimiters[] = {'.', '?', '!'};
    int size = str.size();
    std::string result;
    bool new_sentence = false;
    result.push_back(toupper(str[0]));
    for (size_t pos = 1; pos < size; pos++) {
        for (int i = 0; i < 3; i++) {
            if (str[pos] == delimiters[i]) {
                new_sentence = true;
            }
        }
        if (islower(str[pos]) && new_sentence) {
            result.push_back(toupper(str[pos]));
            new_sentence = false;
        } else {
            result.push_back(str[pos]);
        }
    }
    return result;
}

std::string clearBorders(const std::string& str) {
    int size = str.size();
    std::string result;
    int begin = 0;
    while (!isalnum(str[begin])) {
        begin++;
    }
    int end = size - 1;
    while (isspace(str[end])) {
        end--;
    }
    for (size_t i = begin; i <= end; i++) {
        result.push_back(str[i]);
    }
    return result;
}

std::string deleteExtraSpaces(const std::string& str) {
    size_t size = str.size();
    std::string result;
    int spaces = 0;
    for (size_t pos = 0; pos < size; pos++) {
        if (isspace(str[pos])) {
            spaces++;
            if (spaces == 1) {
                result.push_back(str[pos]);
            }
        } else {
            spaces = 0;
            result.push_back(str[pos]);
        }
    }
    return result;
}

std::string correct(const std::string& str) {
    std::string value = clearBorders(str);
    return deleteExtraSpaces(value);
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << correct(str) << std::endl;
    return 0;
}
