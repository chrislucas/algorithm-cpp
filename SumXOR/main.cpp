#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

/*
https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/BitOp/xor.html
https://www.topcoder.com/community/data-science/data-science-tutorials/a-bit-of-fun-fun-with-bits/
https://rakhinr.wordpress.com/2011/10/17/tricks-using-bitwise-operators/
https://en.wikipedia.org/wiki/Exclusive_or

Problems
https://www.hackerrank.com/challenges/xor-and-sum
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2683
https://www.quora.com/How-do-I-find-sum-of-xor-of-every-pair-of-element-in-array-in-less-than-O-n-2-Is-there-any-linear-time-algorithm-for-this

*/
/*
    INFO
    1) n for uma potencia de 2 o numero de solucoes
    para i+n == (i^n) onde i <= 0 <= n eh igual a n

    Se testarmos numeros entre i e j o numero maximo
    de solucoes para i+n == (i^n) de um numero eh 2 ^ log(j, 2)
*/
int sumXORPattern(int n) {
    int _count = 0;
    for(int i=0; i<=n; i++) {
        if(i+n == (i^n))
            _count++;
        //cout<<i <<" " <<n <<" " <<(i^n) <<endl;
    }
    //cout<<_count <<endl;
    return _count;
}

double _log(double lg, double c) {
    /*
        troca de base -> trocar base c por b
        log a base b
        log c base b
    */
    return log10(lg) / log10(c);
}

bool isPowOfTwo(long n) {
   return (long) pow(2, _log(n, 2)) == n;
}

bool ipot2(long n) {
    return n+(n-1) == (n ^ (n-1));
}

bool ipot3(long n) {
    return n>0 && !(n&(n-1));
}

void run(int n) {
    if(ipot2(n)) {
        printf("%d\n", n);
    }
}

void runTest() {
    /*
        Inreressante quando i == uma potencia de 2 o resultado eh
        o proprio i
    */
    for(int i=0; i<=128; i++) {
        cout << i <<" " <<sumXORPattern(i) << endl;
    }
}

int main()
{
    // cout << sizeof(short int) << endl;
    //cout << floor(_log(10000, 2)) <<endl;
    runTest();
    // cout << _log(100, 10);
    //long num = 128;
    //cout << num <<" " << isPowOfTwo(num) << " " << ipot2(num) << " " << ipot3(num) << endl;
    return 0;
}
