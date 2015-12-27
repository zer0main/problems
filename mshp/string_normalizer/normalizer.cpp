/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

std::string correctUppers(const std::string& str) {
    // a single-character delimiters between sentences
    static const char delimiters[] = {'.', '?', '!'};
    size_t size = str.size();
    std::string result;
    bool new_sentence = false;
    if (size != 0) {
        result.push_back(toupper(str[0]));
    }
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
    while ((begin < size) && !isalnum(str[begin])) {
        begin++;
    }
    int end = size - 1;
    while ((end >= 0) && isspace(str[end])) {
        end--;
    }
    for (int i = begin; i <= end; i++) {
        result.push_back(str[i]);
    }
    return result;
}

std::string deleteExtraPunctuation(const std::string& str) {
    int size = str.size();
    std::string result;
    for (int pos = 0; pos < size; pos++) {
        if ((pos < size - 1) && ispunct(str[pos + 1])) {
            if (!isspace(str[pos]) && !ispunct(str[pos])) {
                result.push_back(str[pos]);
            } else if ((str[pos] == '.') ||
                       (str[pos] == '!')) {
                // ... or !!! exceptions
                int index = pos;
                while ((index < size) &&
                       (str[pos] == str[index])) {
                    index++;
                }
                if ((index - pos) == 3) {
                    result += std::string(str[pos], 3);
                } else {
                    result += str[pos];
                }
                pos = index - 1;
            } else if (str[pos] == '?') {
                // ?! exception
                if (str[pos+ 1] == '!') {
                    result += "?!";
                    pos += 1;
                }
            }
        } else {
            result.push_back(str[pos]);
        }
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
    std::string fix = clearBorders(str);
    fix = deleteExtraSpaces(fix);
    fix = deleteExtraPunctuation(fix);
    fix = correctUppers(fix);
    return fix;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << correct(str) << std::endl;
    return 0;
}
