//
// Created by zhang on 2019/2/16.
//

#ifndef ALGS_QUICK_SORT_H
#define ALGS_QUICK_SORT_H

#include "../generalalgs.h"

template<typename Val_t, typename Size_t>
Size_t PARTITION_HOARE(Val_t arr[], Size_t p, Size_t r) {
    Val_t x = arr[p];
    --r;
    while(true) {
        while(arr[r] >= x && r > p)
            --r;
        if(r == p)
            break;
        arr[p] = arr[r];
        ++p;
        if(r == p)
            break;
        while(arr[p] <= x && r > p)
            ++p;
        if(r == p)
            break;
        arr[r] = arr[p];
        --r;
        if(r == p)
            break;
    }
    arr[p] = x;
    return p;
}

template<typename Val_t, typename Size_t>
Size_t PARTITION(Val_t arr[], Size_t p, Size_t r) {
    Val_t x = arr[r-1];
    Size_t s = p;
    for (Size_t i = p; i < r - 1; ++i) {
        if (arr[i] <= x) {
            exchangevalue(arr[i], arr[s]);
            ++s;
        }
    }
    exchangevalue(arr[r-1], arr[s]);
    return s;
}

template<typename Val_t, typename Size_t>
void QUICK_SORT(Val_t arr[], Size_t p, Size_t r) {
    if (r - p <= 1)
        return;

    Size_t q = PARTITION_HOARE(arr, p, r);
    QUICK_SORT(arr, p, q);
    QUICK_SORT(arr, q + 1, r);
}


#endif //ALGS_QUICK_SORT_H
