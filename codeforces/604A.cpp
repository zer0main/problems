#include <bits/stdc++.h>

#define SIZE 5
#define SUCCESS 100
#define FAILURE 50

int max[SIZE] = {500, 1000, 1500, 2000, 2500};
int minutes[SIZE];
int submissions[SIZE];
int s, u;

double my_max(double a, double b) {
    return ((a - b) > 0.000001) ? a : b;
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        std::cin >> minutes[i];
    }
    for (int i = 0; i < SIZE; i++) {
        std::cin >> submissions[i];
    }
    std::cin >> s >> u;
    double ans_d = 0.0;
    for (int i = 0; i < SIZE; i++) {
        double n1 = 0.3 * max[i];
        double n2 = (1 - (minutes[i] / 250.0)) * max[i];
        n2 -= 50 * submissions[i];
        ans_d += my_max(n1, n2);
    }
    ans_d += s * SUCCESS - u * FAILURE;
    std::cout << ans_d << std::endl;
    return 0;
}
