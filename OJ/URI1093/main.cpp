#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;


// https://www.urionlinejudge.com.br/judge/pt/problems/view/1093

int main()
{
    double ev1, ev2, _at, D;
    while(true) {
        scanf("%lf %lf %lf %lf", &ev1, &ev2, &_at, &D);
        if(ev1 == 0 && ev2 == 0 && _at == 0 && D == 0)
            break;
        double prob = _at / 6.0;
        double ans = 0.0;
        int x =(int)ev1;
        ev1 = 0;
        for(; x>0; x-=(int)D)
            ev1+=1.0;
        x = (int)ev2;
        ev2 = 0;
        for(; x>0; x-=(int)D)
            ev2+=1.0;

        if(prob == 0.5) {
            ans = ev1/(ev1+ev2);
            printf("%.1lf\n", 100 * ans);
        }
        else {
            /*
            double P   = prob;
            double Q   = 1 - P;
            double DA  = P/Q;
            double DB  = Q/P;
            printf("%f %f\n", P, Q);
            */
            double P = 1.0 - (1.0 - _at/6.0);
            P = (1.0 - P) / P;
            double p1 = (1.0 - pow(P, ev1)) / (1.0 - pow(P, ev1+ev2));
            printf("%.1lf\n", 100.0 * p1);
        }
    }
    return 0;
}
