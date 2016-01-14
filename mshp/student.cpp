/*
 * Copyright (C) 2015-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

int dumay(stud& w) {
    w.srok = 1;
    #define offsetof(st, m) ((size_t)(&(((st*)0)->m)))
    #define O(m) offsetof(stud, m)
    const size_t n_params = 10;
    size_t size[n_params];
    for (int i = 1; i < n_params; i++) {
        size[i] = sizeof(int);
    }
    size[0] = sizeof(long int);
    size_t param[n_params] = {
        O(money),
        O(energy),
        O(eda),
        O(hp),
        O(kg),
        O(brain),
        O(comm),
        O(happy),
        O(mad),
        O(rom),
    };
    int inc_act[n_params] = {3, 2, 1, 7, 5, 4, 5, 6, 7, 5};
    int dec_act[n_params] = {3, 4, 0, 7, 6, 4, 5, 3, 7, 6};
    int max[n_params] = {0, 105, 110, 0, 115, 0, 0, 450, 5, 110};
    int min[n_params] = {65, 50, 40, 80, 65, 30, 25, 10, 0, 10};
    int priority[n_params] = {3, 1, 8, 4, 0, 5, 2, 6, 7, 9};
    int problematic[n_params];
    for (int i = 0; i < n_params; i++) {
        problematic[i] = 0;
    }
    for (int i = 0; i < n_params; i++) {
        long int value;
        char* ptr = reinterpret_cast<char*>(&w);
        ptr += param[i];
        if (size[i] == sizeof(int)) {
            value = *reinterpret_cast<int*>(ptr);
        } else if (size[i] == sizeof(long int)) {
            value = *reinterpret_cast<long int*>(ptr);
        }
        if ((value <= min[i]) && (min[i] != 0)) {
            problematic[i] = 1;
        } else if ((value >= max[i]) && (max[i] != 0)) {
            problematic[i] = 2;
        }
    }
    for (int i = 0; i < n_params; i++) {
        int index = priority[i];
        int f = problematic[index];
        if (f) {
            w.doing = ((f == 1) ? inc_act : dec_act)[index];
            return 0;
        }
    }
    w.doing = rand() % 8;
    return 0;
}
