#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

/*
http://mathforum.org/library/drmath/view/55843.html
http://www.geeksforgeeks.org/find-divisors-natural-number-set-1/
http://www.geeksforgeeks.org/find-all-divisors-of-a-natural-number-set-2/
*/
/*
    Para criar-mos uma forma mais rapida de se computar
    os divisores usamos um fato interessante sobre os divisores de N
    N = 100
    D = 1,2,4,5,10,20,25,50,100
    Se pegarmos os valores das pontas temos os seguintes pares
    (1,100);(2,50);(4,25);(5,20);(10,10)
*/
vector<lli> divisotrs(lli number) {
    vector<lli> divs;
    lli lim = sqrt(number);
    for(lli i = 1; i<=lim; i++) {
        if(number % i == 0) {
            // para nao contarmos duas vezes um divisor que apareca em dupla(10,10)
            if(number/i == i) {
                divs.push_back(i);
                continue;
            }
            else {
                divs.push_back(i);
                divs.push_back(number/i);
            }
        }
    }
    return divs;
}

int main()
{
    vector<lli> divs = divisotrs(511);
    vector<lli>::iterator it = divs.begin();
    while(it != divs.end()) {
        cout << *it << " ";
        it++;
    }

}
