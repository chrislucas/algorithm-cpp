#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

using namespace std;

/*
https://www.hackerrank.com/domains/data-structures/heap/difficulty/all/page/1
https://www.hackerrank.com/challenges/qheap1
https://www.hackerrank.com/challenges/find-median-1

http://www.geeksforgeeks.org/why-is-binary-heap-preferred-over-bst-for-priority-queue/
http://www.geeksforgeeks.org/binomial-heap-2/
http://www.geeksforgeeks.org/applications-of-heap-data-structure/

http://www.geeksforgeeks.org/category/heap/
http://www.geeksforgeeks.org/fibonacci-heap-set-1-introduction/
http://geeksquiz.com/binary-heap/
http://www.geeksforgeeks.org/binomial-heap-2/

http://www.sanfoundry.com/cpp-program-implement-binary-heap/
http://www.codeproject.com/Tips/816934/Min-Binary-Heap-Implementation-in-Cplusplus


Constructors
https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
http://www.cplusplus.com/forum/general/7912/
https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
*/

/*
Pesquisar por
algorithm heapify
heapify up heapify down
https://en.wikipedia.org/wiki/Binary_heap

Estudar
https://www.hackerearth.com/practice/algorithms/sorting/heap-sort/tutorial/
https://www.hackerearth.com/practice/algorithms/sorting/heap-sort/tutorial/
https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/

pesquisar
const_iterator
http://www.cplusplus.com/forum/beginner/126145/

*/

const int INF = numeric_limits<int>::max();

template<class T>
/*
    Esta implementaao eh baseada somente nesse tutorial
    http://www.sanfoundry.com/cpp-program-implement-binary-heap/

*/
class BinaryHeap {
public:
    vector<T> _heap;
    BinaryHeap();
    T left(int parent);
    T right(int parent);
    T parent(int child);
    void heapifyup(int idx);
    void heapifydown(int idx);
    int _size();
    void add(T t);
    T get(int idx);
    void deleteMin();
    T extractMin();
    void print();
private:
    bool validate(int idx);
};


template<class T>
BinaryHeap<T>::BinaryHeap() {
}

template<class T>
T BinaryHeap<T>::left(int parent) {
    int idx = 2 * parent + 1;
    return idx < _heap.size() ? idx : -1;
}

template<class T>
T BinaryHeap<T>::right(int parent) {
    int idx = 2 * parent + 2;
    return idx < _heap.size() ? idx : -1;
}

template<class T>
T BinaryHeap<T>::parent(int child) {
    int idx = (child - 1) / 2;
    return child == 0 ? -1 : idx;
}


template<class T>
int BinaryHeap<T>::_size() {
    return _heap.size();
}

template<class T>
bool BinaryHeap<T>::validate(int idx) {
    return idx < _size();
}

template<class T>
void BinaryHeap<T>::add(T t) {
    _heap.push_back(t);
    heapifyup(_heap.size() - 1);
    return;
}

template<class T>
void BinaryHeap<T>::deleteMin() {
    if(_heap.size() == 0)
        return;
    _heap[0] = _heap[_heap.size() - 1];
    _heap.pop_back();
    heapifydown(0);
}

template<class T>
T BinaryHeap<T>::extractMin() {
    if(_heap.size() == 0)
        return INF;
    return _heap.front();
}



template<class T>
void BinaryHeap<T>::print() {
    /*
        Link sobre vector e template
        http://stackoverflow.com/questions/5192874/question-about-vector-iterator-in-template-functions

        http://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords

        Pesquisar
        const_iterator
        http://stackoverflow.com/questions/8017036/understanding-const-iterator-with-pointers
    */
    // http://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
    // o codigo abaixo diz ao compilador que  vector<T>::iterator deve ser tratado como tipo
    /*typename~*/ class vector<T>::iterator it = _heap.begin();
    while(it != _heap.end()) {
        cout<< *(it++) << " ";
    }
    cout << endl;
}

template<class T>
T BinaryHeap<T>::get(int idx) {
    return  validate(idx) ? /*_heap.at(idx)*/ _heap[idx] : NULL;
}

// Maintai heap bottom up
template<class T>
void BinaryHeap<T>::heapifyup(int idx) {
    int p  = parent(idx);
    if(idx >= 0 && p >= 0) {
        int hp = _heap[p];
        int hi = _heap[idx];
        if(hp > hi) {
            int tmp = _heap[idx];
            _heap[idx] = _heap[p];
            _heap[p] = tmp;
            heapifyup(p);
        }
    }
    return;
}

template<class T>
void BinaryHeap<T>::heapifydown(int idx) {
    int childL = left(idx);
    int childR = right(idx);
    if(childL >= 0 && childR >=0) {
        if(_heap[childL] > _heap[childR])
            childL = childR;
    }
    if(childL > 0) {
        int tmp = _heap[idx];
        _heap[idx] = _heap[childL];
        _heap[childL] = tmp;
        heapifydown(childL);
    }
    return;
}



void run_1() {
    BinaryHeap<int> bh;
    bh.add(7);
    bh.print();
    bh.add(4);
    bh.print();
    bh.add(9);
    bh.print();
    bh.add(3);
    bh.print();
    cout << bh.extractMin() << endl;
}

int main()
{
    //cout<< INF <<" " << ((1<<31)-1) << endl ;
    run_1();
    return 0;
}
