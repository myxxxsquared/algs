//
// Created by zhang on 2019/2/10.
//

#include "INSERTION-SORT.h"
#include "MERGE-SORT.h"
#include "FIND_INVERSION.h"

#include <cstdio>
#include <cstdlib>
#include <random>

void test_SORT()
{
    constexpr int len = 100;
    auto arr = new int[len];
    for(int i = 0; i < len; ++i)
        arr[i] = i;

    constexpr int changetimes = 500;
    std::random_device rd;
    std::default_random_engine el{rd()};
    std::uniform_int_distribution<int> randint{0, len - 1};

    for(int i = 0; i < changetimes; ++i)
    {
        int idx = randint(el);
        int tmp = arr[0];
        arr[0] = arr[idx];
        arr[idx] = tmp;
    }

    for(int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n\n");

    INSERTION_SORT(arr, 0, len);

    for(int i = 0; i < len - 1; ++i) {
        if(arr[i] > arr[i+1]) {
            printf("ERROR!\n");
        }
    }


    for(int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n\n");

    delete[] arr;

    int findinv[] = {2, 3, 8, 6, 1, -1};
    int inv = FIND_INVERSION(findinv, 0, 6);
    printf("%d\n", inv);
}