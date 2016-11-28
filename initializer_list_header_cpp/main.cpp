#include <utility>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*
http://en.cppreference.com/w/cpp/utility/initializer_list

Pair: utility
http://en.cppreference.com/w/cpp/utility/pair

*/

template <class T>
class Set {
public:
    vector<T> vect;
    Set(initializer_list<T> initL) : vect(initL) {
        cout << "Tamanho da lista   " << vect.size() << endl;
    }

    void apppend(initializer_list<T> initL) {
        // http://www.cplusplus.com/reference/vector/vector/insert/
        // const iterator
        // http://stackoverflow.com/questions/28497616/why-stl-requires-a-temporary-iterator-variable-to-compile-this
        string::size_type s =  initL.size();
        // (iterator position, InputIterator first, InputIterator last)
        vect.insert(vect.end(), initL.begin(), initL.end());
    }

    pair<const T*, size_t> getPair() const {
        return  {&vect[0], vect.size()};
    }
};


int main()
{

    Set<int> _set = {1,2,3,4,5,65};
    for( auto e : _set.vect) {
        cout << e << " ";
    }
    cout << endl;
    _set.apppend( {5,7,8} );
    for( auto e : _set.vect) {
        cout << e << " ";
    }
    cout << endl;

    pair<const int *, int> p = _set.getPair();
    cout << p.first << " " << p.second << endl;

    return 0;
}
