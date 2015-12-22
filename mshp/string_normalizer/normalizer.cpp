#include <bits/stdc++.h>

std::string deleteBoundarySpaces(const std::string& str) {
    int size = str.size();
    std::string result;
    int begin = 0;
    while (isspace(str[begin])) {
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
    std::string value = deleteBoundarySpaces(str);
    return deleteExtraSpaces(value);
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << correct(str) << std::endl;
    return 0;
}
