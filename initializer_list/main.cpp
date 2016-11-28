#include <iostream>

using namespace std;

/*
http://en.cppreference.com/w/cpp/language/initializer_list

// interessante
http://en.cppreference.com/w/cpp/language/list_initialization
http://en.cppreference.com/w/cpp/utility/initializer_list

Construtores em cpp
explicit constructor e converting  constructors
http://en.cppreference.com/w/cpp/language/converting_constructor

Inicializacao de classe
http://en.cppreference.com/w/cpp/language/copy_initialization
http://en.cppreference.com/w/cpp/language/direct_initialization

Palavra reservada explicit
http://en.cppreference.com/w/cpp/language/explicit

Mais construtores
http://en.cppreference.com/w/cpp/language/converting_constructor
http://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
*/

class Point2D {
// aparentemente no cpp se nao definirmos que os membros
// da classe sao publicos, por padrao sao privados
// Vale estudar sobre isso
// http://www.cplusplus.com/doc/tutorial/classes/
public:
    int x, y;
    // declaracao do construtor
    // converting constructor (since C++11)
    Point2D(int, int);
    /*
        S()         // definicao do construtor
        : x()       // initializer list
        : x(7) {}   // corpo da funcao
    */
    Point2D() : x(7), y(8) {}
    Point2D(int) {}
};

Point2D::Point2D(int x, int y) : x(x), y(y) {}


class Point3D {
public:
    int x, y, z;
    explicit Point3D(int , int, int);
    explicit Point3D() : x(0), y(0), z(0) {}
    //explicit Point3D(int) {}
    explicit Point3D(int x) : x(x) {}
};

Point3D::Point3D(int x, int y, int z) : x(x), y(y), z(z) {}

int main()
{
    // direct initializer
    // anoun constructor parameter is copy-initialize from values 10 and 4
    Point2D p1(10, 4);
    // se for executar o construtor sem parametros faça igual a linha abaixo
    Point2D p2;
    // Point p2() nao funciona pois o compilador pensa que p2() eh uma funcao que retorna Point
    /*
        Sobre a questao acima, leia
        most vexing parse issue.
        https://en.wikipedia.org/wiki/Most_vexing_parse
        http://stackoverflow.com/questions/11535388/understanding-most-vexing-parse-why-allow-ambiguous-syntax
        http://stackoverflow.com/questions/2318650/is-no-parentheses-on-a-constructor-with-no-arguments-a-language-standard
    */
    cout << p2.x <<" " << p2.y <<endl;
    cout << p1.x <<" " << p1.y <<endl;
    Point2D p3 = 10;
    cout << p3.x <<" " << p3.y <<endl;

    Point3D pA, pB(1,2,3);
    cout << pA.x <<" " <<pA.y  <<" " << pA.z <<endl;
    cout << pB.x <<" " <<pB.y  <<" " << pB.z <<endl;
    // vai dar errp, construtor explicito, estudar sobre isso
    // Point3D pC = 1;

    return 0;
}
