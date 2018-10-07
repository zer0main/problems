/* http://codeforces.com/contest/814/submission/43921447 */

#include <bits/stdc++.h>

#define MAX_LETTERS 26
#define MAX_LEN 1550

int ans[MAX_LETTERS][MAX_LEN];

int main() {
    int n, q, m;
    char c;
    std::string str;
    std::cin >> n >> str >> q;
    for (int letter = 0; letter < MAX_LETTERS; letter++) {
        for (int i = 0; i < n; i++) {
            int replacements = 0;
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                if (str[j] != (letter + 'a')) {
                    replacements++;
                }
                ans[letter][replacements] = std::max(ans[letter][replacements], len);
            }
        }
        for (int i = 1; i < MAX_LEN; i++) {
            ans[letter][i] = std::max(ans[letter][i], ans[letter][i - 1]);
        }
    }
    for (int i = 0; i < q; i++) {
        std::cin >> m >> c;
        std::cout << ans[c - 'a'][m] << std::endl;
    }
    return 0;
}
