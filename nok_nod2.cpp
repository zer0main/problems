#include <iostream>

int nod(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nok(int a, int b) {
    return (a * b) / nod(a, b);
}

void nokAndNod(int* arr, int size) {
    int nok1 = nok(arr[0], arr[1]);
    int nod1 = nod(arr[0], arr[1]);
    for (int i = 2; i < size; i++) {
        nok1 = nok(nok1, arr[i]);
        nod1 = nod(nod1, arr[i]);
    }
    std::cout << nok1 << std::endl;
    std::cout << nod1 << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    nokAndNod(arr, n);
    delete[] arr;
    return 0;
}
