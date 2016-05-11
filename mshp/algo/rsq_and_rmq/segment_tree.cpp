/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 10000

int tree[SIZE * 4];

void buildTree(int v, int tree_l, int tree_r) {
    if (tree_l == tree_r) {
        tree[v] = 0;
    } else {
        int mid = (tree_l + tree_r) / 2;
        buildTree(v * 2, tree_l, mid);
        buildTree(v * 2 + 1, mid + 1, tree_r);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int sum(int v, int tree_l, int tree_r, int l, int r) {
    if (l > r) {
        return 0;
    }
    if ((tree_l == l) && (tree_r == r)) {
        return tree[v];
    }
    int mid = (tree_l + tree_r) / 2;
    return sum(v * 2, tree_l, mid, l, std::min(mid, r)) +
           sum(v * 2 + 1, mid + 1, tree_r, std::max(l, mid + 1), r);
}

void update(int v, int tree_l, int tree_r, int i, int val) {
    if (tree_l == tree_r) {
        tree[v] += val;
    } else {
        int mid = (tree_l + tree_r) / 2;
        if (i <= mid) {
            update(v * 2, tree_l, mid, i, val);
        } else {
            update(v * 2 + 1, mid + 1, tree_r, i, val);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

enum Command {
    STOP,
    UPDATE,
    SUM
};

int main() {
    int N;
    std::cin >> N;
    buildTree(1, 0, N - 1);
    int command, p1, p2;
    while (true) {
        std::cin >> command;
        if (command == STOP) {
            break;
        } else if (command == UPDATE) {
            std::cin >> p1 >> p2;
            update(1, 0, N - 1, p1 - 1, p2);
        } else if (command == SUM) {
            std::cin >> p1 >> p2;
            std::cout << sum(1, 0, N - 1, p1 - 1, p2 - 1) << std::endl;
        } else {
            std::cerr << "Invalid command." << std::endl;
        }
    }
    return 0;
}
