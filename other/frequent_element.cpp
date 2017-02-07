/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/**
  The majority element is the element that occurs more
  than half of the size of the array.
  How to find the majority element in an array in O(n)?
  There is a guarantee that it exists.
*/

#include <bits/stdc++.h>

#define MAX_SIZE 100500

int main() {
    int array[MAX_SIZE];
    int size;
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    int count = 0, ans;
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            ans = array[i];
        }
        if (array[i] == ans) {
            count++;
        } else {
            count--;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
