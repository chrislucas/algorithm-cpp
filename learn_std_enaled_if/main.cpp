#include <iostream>
#include <limits>
#include <climits>
#include <type_traits>
using namespace std;

/*
http://en.cppreference.com/w/cpp/types/enable_if
*/
/*
template<bool b, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {
    typedef T type;
};
*/
// declarando template function
//http://en.cppreference.com/w/cpp/types/is_integral
template<typename Integer,typename = enable_if<is_integral<Integer>::value>>
void f(Integer a) {
    cout << a <<endl;
    return;
}

template<typename T, typename enable_if<numeric_limits<T>::is_integer, bool>::value>
void d(T a) {
    f(a);
    return;
}


int main()
{
    f(10.0);
    d(10)
    return 0;
}
