/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

// The problem is to write the most elegant code
// for calculating median of three numbers.

int median(int n1, int n2, int n3) {
    int numbers[] = {n1, n2, n3};
    std::sort(numbers, numbers + 3);
    return numbers[1];
}

int main() {
    int n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    std::cout << median(n1, n2, n3) << std::endl;
    return 0;
}
