/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 100

int dequeue[SIZE];
int L = 0;
int R = SIZE - 1;
int curr_size = 0;

enum Commands {
    PUSH_FRONT,
    PUSH_BACK,
    POP_FRONT,
    POP_BACK,
    FRONT,
    BACK,
    SIZE_Q,
    CLEAR,
    FINISH
};

void push_front(int x) {
    curr_size++;
    L = (L + SIZE - 1) % SIZE;
    dequeue[L] = x;
}

void push_back(int x) {
    curr_size++;
    R = (R + 1) % SIZE;
    dequeue[R] = x;
}

int front() {
    return (L == 0) ? dequeue[0] : dequeue[L];
}

int back() {
    return (R == SIZE - 1) ? dequeue[SIZE - 1] : dequeue[R];
}

int pop_front() {
    curr_size--;
    int temp = front();
    L = (L + 1) % SIZE;
    return temp;
}

int pop_back() {
    curr_size--;
    int temp = back();
    R = (R + SIZE - 1) % SIZE;
    return temp;
}

int size() {
    return curr_size;
}

void clear() {
    curr_size = 0;
    L = 0;
    R = SIZE - 1;
}

int main() {
    bool finish = false;
    while (true) {
        if (finish) {
            break;
        }
        int command, x;
        std::cin >> command;
        switch (command - 1) {
            case PUSH_FRONT:
                std::cin >> x;
                push_front(x);
                break;
            case PUSH_BACK:
                std::cin >> x;
                push_back(x);
                break;
            case POP_FRONT:
                std::cout << pop_front() << std::endl;
                break;
            case POP_BACK:
                std::cout << pop_back() << std::endl;
                break;
            case FRONT:
                std::cout << front() << std::endl;
                break;
            case BACK:
                std::cout << back() << std::endl;
                break;
            case SIZE_Q:
                std::cout << size() << std::endl;
                break;
            case CLEAR:
                clear();
                break;
            case FINISH:
                finish = true;
                break;
        }
    }
    return 0;
}
