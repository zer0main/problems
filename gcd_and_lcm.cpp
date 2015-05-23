/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void lcmAndGcd(int* arr, int size) {
    int lcm1 = lcm(arr[0], arr[1]);
    int gcd1 = gcd(arr[0], arr[1]);
    for (int i = 2; i < size; i++) {
        lcm1 = lcm(lcm1, arr[i]);
        gcd1 = gcd(gcd1, arr[i]);
    }
    std::cout << lcm1 << std::endl;
    std::cout << gcd1 << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    lcmAndGcd(arr, n);
    delete[] arr;
    return 0;
}
