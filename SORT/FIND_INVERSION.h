//
// Created by zhang on 2019/2/13.
//

#ifndef ALGS_FIND_INVERSION_H
#define ALGS_FIND_INVERSION_H

template<typename Val_t, typename Size_t>
Size_t FIND_INVERSION_MERGE(Val_t arr[], Size_t p, Size_t q, Size_t r) {
    Val_t *L = new Val_t[q - p];
    Val_t *R = new Val_t[r - q];

    for (Size_t i = p; i < q; ++i)
        L[i - p] = arr[i];
    for (Size_t i = q; i < r; ++i)
        R[i - q] = arr[i];

    Size_t i = 0, j = 0, k = p;

    Size_t inv = 0;

    while (i < q - p && j < r - q) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            inv += (q - p) - i;
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < q - p) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < r - q) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[]L;
    delete[]R;

    return inv;
}

template<typename Val_t, typename Size_t>
Size_t FIND_INVERSION(Val_t arr[], Size_t p, Size_t r) {
    if (p + 1 < r) {
        Size_t q = (p + r) / 2;
        Size_t inv = 0;
        inv += FIND_INVERSION(arr, p, q);
        inv += FIND_INVERSION(arr, q, r);
        inv += FIND_INVERSION_MERGE(arr, p, q, r);
        return inv;
    }

    return 0;
}

#endif //ALGS_FIND_INVERSION_H
