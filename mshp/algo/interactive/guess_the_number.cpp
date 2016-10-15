#include <bits/stdc++.h>

void search(int l, int r) {
    std::string res;
    while (true) {
        std::cout << (l + r) / 2 << std::endl;
        std::cout.flush();
        std::cin >> res;
        if (res == "Greater") {
            r = (l + r) / 2 + 1;
        } else if (res == "Less") {
            l = (l + r) / 2;
        } else {
            break;
        }
    }
}

int main() {
    search(0, 101);
    return 0;
}
