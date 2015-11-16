/*
 * Copyright (C) 2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

/* http://codeforces.com/contest/576/submission/13054549 */

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    /* Sieve of Eratosthenes */
    std::vector<char> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (1ll * i * i <= n) {
            for (int x = i * i; x <= n; x += i) {
                prime[x] = false;
            }
        }
    }
    typedef std::vector<int> Ints;
    Ints result;
    for (int i = 0; i <= n; i++) {
        if (prime[i]) {
            int s = 1;
            while (s <= n / i) {
                s *= i;
                result.push_back(s);
            }
        }
    }
    std::cout << result.size() << std::endl;
    for (Ints::const_iterator i = result.begin(); i != result.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}
