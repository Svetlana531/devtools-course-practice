// Copyright 2022 Kozel Svetlana

#include "include/combinations.h"

combinations::combinations() {
    std::vector<int> v(1, 0);
    this->n = 1;
    this->m = 1;
    this->vec = v;
}

combinations::combinations(int _n, int _m) {
    std::vector<int> v(_m, 0);
    for (int i = 0; i < _m; i++) {
        v[i] = i + 1;
    }
    this->n = _n;
    this->m = _m;
    this->vec = v;
}

bool combinations::next_set() {
    for (int i = m - 1; i >= 0; i--) {
        if (vec[i] < n - m + i + 1) {
            vec[i]++;
            for (int j = i; j < m - 1; j++) {
                vec[j + 1] = vec[j] + 1;
            }
            return true;
        }
    }
    return false;
}

int combinations::get_cnm() {
    int res = 0;
    if (n >=m) {
        while (next_set()) {
            res++;
        }
    } else {
        throw std::invalid_argument("N is less then M");
    }
    res++;
    return res;
}

combinations::~combinations() {
    this->n = 0;
    this->m = 0;
    this->vec.clear();
}
