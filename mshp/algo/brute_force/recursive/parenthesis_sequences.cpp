/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

void generate(std::string prefix, int open, int len) {
    if (len == prefix.size()) {
        std::cout << prefix << std::endl;
    } else {
        if (open < (len - prefix.size())) {
            generate(prefix + '(', open + 1, len);
        }
        if (open > 0 ) {
            generate(prefix + ')', open - 1, len);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    generate("", 0, n * 2);
    return 0;
}
