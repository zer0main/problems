/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

// nspaces <= 5
bool hasEndSpaces(const std::string& line, int nspaces) {
    const char* line_end = line.c_str() + line.size();
    return line.size() >= nspaces &&
        memcmp(line_end - nspaces, "     ", nspaces) == 0;
}

int main() {
    std::ifstream input_file("100.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error: Unable to open intput file." << std::endl;
        return 1;
    }
    std::string line;
    std::string result;
    int bit_counter = 0;
    while (std::getline(input_file, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r') {
            // WINDOWS
            line.resize(line.size() - 1);
        }
        if (hasEndSpaces(line, 4)) {
            int byte_counter = bit_counter / 8;
            if (byte_counter >= result.size()) {
                result.push_back(0);
            }
            char& c = result[result.size() - 1];
            if (hasEndSpaces(line, 5)) {
                // set bit to 1
                int shift = 7 - (bit_counter % 8);
                c |= (1 << shift);
            } else {
                // set bit to 0
            }
            bit_counter += 1;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
