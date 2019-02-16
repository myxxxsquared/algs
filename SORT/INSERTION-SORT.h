//
// Created by zhang on 2019/2/10.
//

#ifndef ALGS_INSERTION_SORT_H
#define ALGS_INSERTION_SORT_H

template<typename Val_t, typename Size_t>
void INSERTION_SORT(Val_t arr[], Size_t p, Size_t r) {
    for (Size_t i = p + 1; i < r; ++i) {
        Val_t key = arr[i];
        Size_t j;
        for (j = i - 1; j >= p && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

#endif //ALGS_INSERTION_SORT_H
