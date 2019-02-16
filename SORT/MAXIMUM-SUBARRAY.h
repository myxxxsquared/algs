//
// Created by zhang on 2019/2/15.
//

#ifndef ALGS_MAXIMUM_SUBARRAY_H
#define ALGS_MAXIMUM_SUBARRAY_H

#include <stdexcept>

template<typename Val_t, typename Size_t>
struct MaximumSubarray {
    Size_t begin, end;
    Val_t sum;
};

template<typename Val_t, typename Size_t>
MaximumSubarray<Val_t, Size_t> FindMaximumSubarray(Val_t arr[], Size_t p, Size_t r) {
    typedef MaximumSubarray<Val_t, Size_t> Result_t;

    if (r <= p)
        throw std::runtime_error("empty array");

    if (r - p == 1) {
        Result_t result;
        result.begin = p;
        result.end = r;
        result.sum = arr[p];
        return result;
    }

    Size_t q = (p + r) / 2;
    Result_t rl = FindMaximumSubarray(arr, p, q);
    Result_t rr = FindMaximumSubarray(arr, q, r);

    Val_t lsum = arr[q - 1];
    Val_t lsummax = lsum;
    Size_t lind = q - 1;
    for (Size_t i = q - 2; i >= p; --i) {
        lsum += arr[i];
        if (lsum > lsummax) {
            lsummax = lsum;
            lind = i;
        }
    }

    Val_t rsum = arr[q];
    Val_t rsummax = rsum;
    Val_t rind = q;
    for (Size_t i = q + 1; i < r; ++i) {
        rsum += arr[i];
        if (rsum > rsummax) {
            rsummax = rsum;
            rind = i;
        }
    }

    Result_t rt;
    rt.begin = lind;
    rt.end = rind + 1;
    rt.sum = lsummax + rsummax;

    if (rl.sum >= rt.sum) {
        if (rl.sum >= rr.sum)
            return rl;
        else
            return rr;
    } else {
        if (rt.sum >= rr.sum)
            return rt;
        else
            return rr;
    }
};

template<typename Val_t, typename Size_t>
MaximumSubarray<Val_t, Size_t> FindMaximumSubarray_Linear(Val_t arr[], Size_t p, Size_t r) {
    typedef MaximumSubarray<Val_t, Size_t> Result_t;

    Size_t summinind = p;

    Size_t sum = arr[p];
    if (sum < 0)
        sum = 0;

    Result_t result;
    result.begin = p;
    result.end = p + 1;
    result.sum = sum;

    for (Size_t i = p + 1; i < r; ++i) {
        sum += arr[i];

        if (sum > result.sum) {
            result.sum = sum;
            result.begin = summinind + 1;
            result.end = i + 1;
        }

        if (sum <= 0) {
            sum = 0;
            summinind = i;
        }
    }

    return result;
}

#endif //ALGS_MAXIMUM_SUBARRAY_H
