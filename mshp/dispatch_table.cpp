/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

class SomeClass {
public:
    void someMethod() {
        std::cout << "Method 0" << std::endl;
    }

    void someAnotherMethod() {
        std::cout << "Method 1" << std::endl;
    }

};

typedef void (SomeClass::*SomeMethod) ();

SomeMethod methods[] = {
    &SomeClass::someMethod,
    &SomeClass::someAnotherMethod,
};

int main() {
    SomeClass obj;
    while (true) {
        std::cout << "Please enter index of action: " << std::endl;
        int action;
        std::cin >> action;
        if ((action >= 0) && (action <= 1)) {
            (obj.*methods[action])();
        }
    }
    return 0;
}
