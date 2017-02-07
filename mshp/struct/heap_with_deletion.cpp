/*
 * Copyright (C) 2015-2017 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <bits/stdc++.h>

#define SIZE 150500
#define HEAP_SIZE 10500

int N, K;
int arr[SIZE];

int size = 0;
int heap[HEAP_SIZE];
int where[SIZE];

void heapSwap(int head_index_1, int heap_index_2) {
    where[heap[head_index_1]] = heap_index_2;
    where[heap[heap_index_2]] = head_index_1;
    std::swap(heap[head_index_1], heap[heap_index_2]);
}

int heapParent(int index) {
    return (index - 1) / 2;
}

int leftChild(int index) {
    return index * 2 + 1;
}

int rightChild(int index) {
    return index * 2 + 2;
}

void siftUp(int v) {
    while (v > 0 && arr[heap[v]] < arr[heap[heapParent(v)]]) {
        heapSwap(v, heapParent(v));
        v = heapParent(v);
    }
}

void siftDown(int v) {
    while (leftChild(v) < size) {
        int left = leftChild(v);
        int right = rightChild(v);
        int min = left;
        if ((right < size) && (arr[heap[right]] < arr[heap[left]])) {
            min = right;
        }
        if (arr[heap[v]] <= arr[heap[min]]) {
            return;
        }
        heapSwap(v, min);
        v = min;
    }
}

int getMin() {
    return heap[0];
}

void insert(int array_index) {
    heap[size] = array_index;
    size++;
    where[array_index] = size - 1;
    siftUp(size - 1);
}

void heapDelete(int array_index) {
    int heap_index = where[array_index];
    bool is_last = (size - 1 == heap_index);
    heapSwap(size - 1, heap_index);
    size--;
    where[array_index] = -1;
    if (!is_last) {
        siftUp(heap_index);
        siftDown(heap_index);
    }
}

int main() {
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < K; i++) {
        insert(i);
    }
    for (int i = K; i <= N; i++) {
        std::cout << arr[getMin()] << std::endl;
        heapDelete(i - K);
        insert(i);
    }
    return 0;
}
