/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/522/submission/13219579 */

#include <map>
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string name1, buff, name2;
    std::map<std::string, int> rating;
    rating["polycarp"] = 1;
    int result = 1;
    for (int i = 0; i < n; i++) {
        std::cin >> name1 >> buff >> name2;
        for (int i = 0; i < name1.size(); i++) {
            name1[i] = tolower(name1[i]);
        }
        for (int i = 0; i < name2.size(); i++) {
            name2[i] = tolower(name2[i]);
        }
        int score = rating[name2] + 1;
        rating[name1] = score;
        if (score > result) {
            result = score;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
