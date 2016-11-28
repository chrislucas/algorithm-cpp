#include <iostream>
#include <cstdio>
#include <cstddef>

using namespace std;

#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

typedef long long int int64;

/*
    http://stackoverflow.com/questions/492384/how-to-find-the-sizeofa-pointer-pointing-to-an-array
    http://stackoverflow.com/questions/3368883/how-does-this-size-of-array-template-function-work
    http://www.4devs.com.br/calculadora_mmc
    http://www.calculatorsoup.com/calculators/math/lcm.php
*/

template<class T, size_t sz>
size_t len(T (& _array)[sz]) {
    return sz;
}

int64 gdc(int64 a, int64 b) {
    while(a%b!=0) {
        int64 mod = a % b;
        a = b;
        b = mod;
    }
    return b;
}

int64 gdc(int64 * _array, int sz) {
    int64 ans = gdc(_array[0], _array[1]);
    for(int idx=2; idx<sz; idx++) {
        ans = gdc(ans, _array[idx]);
    }
    return ans;
}

int64 lcm(int64 a, int64 b) {
    return (a / gdc(a , b)) * b ;
    //return (a*b)/gdc(a,b);
}

int64 lcm(int64 * _array, int sz) {
    int64 ans = lcm(_array[0], _array[1]);
    for(int idx=2; idx<sz; idx++) {
        ans = lcm(ans, _array[idx]);
    }
    return ans;
}

int64 solver(int64 * _array, int64 qBlocks, int sz) {
     int64 ans = lcm(_array, sz);
     return qBlocks / (int64)ans;
}

int64 solver2(int64 * _array, int64 qBlocks, int sz) {
     int64 ans = lcm(_array, sz);
     if(ans > qBlocks) {
        return 0;
     }
     int jump = 1;
     while(ans < qBlocks) {
        for(int idx = 0; idx < sz; idx++) {
            _array[idx] += ans;
        }
        ans = lcm(_array, sz);
        jump++;
     }
     return qBlocks / ans;
}

void runTest()
{
    int64 _array [][5] =  {
         {1,2,1,1,1}
        ,{2,5,11,1,1}
        ,{2,3,4,5,7}
    };
    int64 blocks [] = {12, 500, 100};
    int64 l = lcm(_array[0], ARRAY_SIZE(_array[0]));
    int64 g = gdc(_array[0], ARRAY_SIZE(_array[0]));
    int64 j = solver(_array[0], blocks[0], ARRAY_SIZE(_array[0]));
    printf("%lli %lli %lli", l, g, j);

}

void read() {
    int64 qBlocks;
    int players;
    scanf("%lli %d", &qBlocks, &players);
    int64 * _array = new int64[players];

    for(int idx=0; idx<players; idx++)
        scanf("%lli", &_array[idx]);
    int64 ans = solver(_array, qBlocks, players);
    printf("%lli\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("salto_in/salto_11.in","rt",stdin);
    freopen("salto_out/output_salto_11.txt","wt",stdout);
#endif
    read();
    return 0;
}
