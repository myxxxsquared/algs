//
// Created by zhang on 2019/2/16.
//

#ifndef ALGS_COUNTING_SORT_H
#define ALGS_COUNTING_SORT_H

template<typename Val_t, typename Size_t>
void COUNTING_SORT(Val_t arr[], Size_t len, Val_t max) {
    auto tmp = new Size_t[max];
    auto result = new Val_t[len];

    for (Val_t i = 0; i < max; ++i)
        tmp[i] = 0;
    for (Size_t i = 0; i < len; ++i)
        ++tmp[arr[i]];
    for (Size_t i = 1; i < max; ++i)
        tmp[i] += tmp[i - 1];
    for (Size_t i = len - 1; i >= 0; --i)
        result[--tmp[arr[i]]] = arr[i];
    for (Size_t i = 0; i < len; i++)
        arr[i] = result[i];

    delete[]tmp;
    delete[]result;
}

#endif //ALGS_COUNTING_SORT_H
