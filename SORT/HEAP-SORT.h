//
// Created by zhang on 2019/2/15.
//

#ifndef ALGS_HEAP_SORT_H
#define ALGS_HEAP_SORT_H

#include "../generalalgs.h"

template<typename Size_t>
inline Size_t HEAP_LEFT(Size_t p) { return 2 * p + 1; }

template<typename Size_t>
inline Size_t HEAP_RIGHT(Size_t p) { return 2 * p + 2; }

template<typename Size_t>
inline Size_t HEAP_PARENT(Size_t p) { return (p - 1) / 2; }

template<typename Val_t, typename Size_t>
void MAX_HEAPIFY(Val_t arr[], Size_t len, Size_t i) {
    Size_t p = i;

    Val_t originval = arr[p];

    while (true) {
        Size_t l = HEAP_LEFT(p);
        Size_t r = HEAP_RIGHT(p);

        Size_t maxid;
        if (l < len && arr[l] > originval)
        {
            if(r < len && arr[r] > arr[l])
                maxid = r;
            else
                maxid = l;
        } else if (r < len && arr[r] > originval)
            maxid = r;
        else
            break;

//        exchangevalue(arr[p], arr[maxid]);
        arr[p] = arr[maxid];

        p = maxid;
    }

    arr[p] = originval;
}

template<typename Val_t, typename Size_t>
void HEAP_SORT(Val_t arr[], Size_t len) {
    for (Size_t i = len / 2 - 1; i >= 0; --i) {
        MAX_HEAPIFY(arr, len, i);
    }
    for (Size_t i = len - 1; i > 0; --i) {
        exchangevalue(arr[0], arr[i]);
        MAX_HEAPIFY(arr, i, 0);
    }
}

template<typename Val_t, typename Size_t>
void HEAP_SORT(Val_t arr[], Size_t p, Size_t r) {
    HEAP_SORT<Val_t, Size_t>(arr + p, r - p);
}

#endif //ALGS_HEAP_SORT_H
