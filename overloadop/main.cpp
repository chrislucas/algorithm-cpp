#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
http://stackoverflow.com/questions/4421706/operator-overloading
http://stackoverflow.com/questions/4421706/operator-overloading/4421708#4421708
http://users.cms.caltech.edu/~donnie/cs11/cpp/cpp-ops.html

about pass reference
http://stackoverflow.com/questions/11484175/passing-by-reference-operator-overloading
http://stackoverflow.com/questions/23438243/why-do-we-pass-a-reference-to-the-object-as-an-argument-to-the-overloaded-output
*/

class Point2D {
public:
    int x, y;
    Point2D(int, int);

    /*
        Um motivo para que o parametros seja passado como const
        eh para que a sobrecarga aceite tanto const quanto non-const
        Um motivo para que o parametro seja passado por referencia
        eh que eh menos custoso, ja que passando por valor eh feito uma copia
        do elemento. Se for so um tipo primitivo, passagem por valor nao
        eh tao custoso, mas se for um objeto mais complexo sim
    */
    inline bool operator == (const Point2D& that) {
        return x == that.x && y == that.y;
    }

    inline bool operator < (const Point2D& that) {
        return x < that.x && y < that.y;
    }

    // https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm
    // friend function nao eh uma funcao membro da classe, mas tem acesso aos atributos, private e protected dela
    // friend ostream& operator << (ostream& stream, const Point2D that);

    int euclidianDistance(Point2D that) {
        int diffX = abs(that.x - x);
        int diffY = abs(that.y - y);
        return diffX * diffX - diffY * diffY;
    }
};

/*
functor comparison
http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html
http://www.cplusplus.com/forum/general/59164/
*/
class Cmp1 {
public:
    /*
        Na classe Point2D somente o segundo parametro eh const
        'this' nao o eh. Assim o primeiro parametro desse operador
        sobrecarregado nao deve ser const
    */
    bool operator () (Point2D& p, /*const*/ Point2D& q) {
        return (p < q);
    }
};

Point2D::Point2D(int x, int y) : x(x), y(y) {}

// http://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
ostream& operator << (ostream& stream, const Point2D that) {
    stream << that.x << " " << that.y << endl;
    return stream;
}

void test() {
    vector<Point2D> points;
    Cmp1 comp;
    Point2D a(1,2), b(3,4), c(5,1);
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    sort(points.begin(), points.end(), comp);
    vector<Point2D>::iterator it = points.begin();
    while(it != points.end()) {
        cout << (*it);
        it++;
    }
    return;
}

int main()
{
    //Point2D a(1, 2);
    //const Point2D b(1, 2);
    //cout << (a == b) << endl;
    test();
    return 0;
}
