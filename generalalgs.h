//
// Created by zhang on 2019/2/15.
//

#ifndef ALGS_GENERALALGS_H
#define ALGS_GENERALALGS_H

template<typename _T>
void exchangevalue(_T &l, _T &r) {
    _T tmp = l;
    l = r;
    r = tmp;
}

#endif //ALGS_GENERALALGS_H
