#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

// https://brilliant.org/practice/floor-and-ceiling-functions-level-3-challenges/?p=4#
void floor_function() {
    double a = 18, b = 35;
    double ans = 0.0;
    for(int x = 1; x<=34; x++) {
        ans += floor(a*x/b);
    }
    printf("%f\n%f\n%f\n%f\n%f\n",
       ans
       ,floor(2.3) + floor(-2.3)
       ,floor(-2.3)
       ,floor(5.75)
       ,floor(-5.75)
    );
}

void tobinany(int x) {
    while(x >= 1) {
        printf("%d", x & 1);
        x >>= 1;
    }
    printf("\n");
}

/*
http://en.cppreference.com/w/cpp/iterator/istream_iterator
http://en.cppreference.com/w/cpp/algorithm/partial_sum
*/

int main()
{
    floor_function();
    //tobinany(127);
    //tobinany(22);
    return 0;
}
