#include <iostream>

using namespace std;


void deslocamento(int * arr, int _size, int from, int to) {
    int * aux = new int [_size];

    // de cima para baixo
    if(from < to) {
        arr[from] = arr[to];
    }
    // de baixo para cima
    else {
        arr[to] = arr[from];
    }
}
class FX {
public:
    int sz, xp, mp;
    float d;
    FX() {}
};

int main()
{
    int arr [] = {1,2,3,4,4,5};
    cout << sizeof(FX);

    deslocamento(arr, sizeof(arr) / sizeof(int), 5, 0);
    return 0;
}
