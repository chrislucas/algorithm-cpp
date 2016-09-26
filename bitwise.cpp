#include <iostream>
#include <cstdio>
using namespace std;

/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/
http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-c
http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/
*/

int togglebit(int n, int nth) {
    return n ^ 1 << nth; //n ^= 1 << nth;
}

int unsetBit(int n, int nth) {
    return n & ~(1 << nth); //n &= ~(1 << nth);
}

int setBit(int n, int nth) {
    return n | 1 << nth; //n |= 1 << nth;
}

int checkBit(int n, int nth) {
    return (n >> nth) & 1;
}
// Bit n will be set if x is 1, and cleared if x is 0.
int changeBit(int n, int nth) {
    return n ^= (checkBit(n, nth) ^ n) & (1 << nth);
}

void flipTeste() {
    // 2147483647
    unsigned int n = 1;
    int m =  1;
    //printf("%lli\n", 0xffffffff);
    printf("%u\n", 0xffffffff);
    //printf("%d %d %d\n", (~n), (~m), m ^ 0xffffff);
    printf("%u %u %u %u\n", (~n), (~m), n ^ 0xffffffff, m ^ 0xffffffff);
    printf("%d %d", n ^ 0xffffffff, m ^ 0xffffffff);
    //printf("%d %d %u\n", n ^ 0xffffff, m ^ 0xffffff);
}

int main()
{
    //flipTeste();
    printf("%d %d %d\n"
       ,togglebit(10, 0)
       ,unsetBit(10, 1)
       ,setBit(10, 2)
    );
    return 0;
}
