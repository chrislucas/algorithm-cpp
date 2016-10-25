#include <iostream>
#include <cstdio>
using namespace std;


int fn(int n) {
    int sum = 0;
    while(n>0) {
        sum += n % 10;
        n /= 10;
        if(n == 0 &&  sum > 9) {
            n = sum;
            sum = 0;
        }
    }
    return sum;
}

void run() {
    printf("%d\n%d\n%d\n"
           ,fn(121)
           ,fn(12345678)
           ,fn(12521)
    );
}
int main()
{
    run();
    return 0;
}
