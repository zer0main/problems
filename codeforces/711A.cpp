/* http://codeforces.com/problemset/submission/711/43706549 */

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    bool found = false;
    std::vector<std::string> rows;
    for (int i = 0; i < n; i++) {
        std::string row;
        std::cin >> row;
        size_t pos = row.find("OO");
        if (pos != std::string::npos && !found) {
            found = true;
            row[pos] = '+';
            row[pos + 1] = '+';
        }
        rows.push_back(row);
    }
    std::cout << ((found) ? "YES" : "NO") << std::endl;
    if (found) {
        for (int i = 0; i < rows.size(); i++) {
            std::cout << rows[i] << std::endl;
        }
    }
    return 0;
}
