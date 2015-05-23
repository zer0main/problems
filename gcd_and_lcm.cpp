/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <iostream>

/* gcd means "greatest common divisor" */
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* lcm means "least common multiple" */
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int arrayGcd(int* arr, int size) {
    int gcd1 = gcd(arr[0], arr[1]);
    for (int i = 2; i < size; i++) {
        gcd1 = gcd(gcd1, arr[i]);
    }
    return gcd1;
}

void arrayLcm(int* arr, int size) {
    int lcm1 = lcm(arr[0], arr[1]);
    for (int i = 2; i < size; i++) {
        lcm1 = lcm(lcm1, arr[i]);
    }
    return lcm1;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int gcd_number = arrayGcd(arr, n);
    int lcm_number = arrayLcm(arr, n);
    std::cout << lcm_number << std::endl;
    std::cout << gcd_number << std::endl;
    delete[] arr;
    return 0;
}
