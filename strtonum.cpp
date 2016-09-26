#include <cstdio>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;
/*
http://www.cplusplus.com/reference/string/stoi/
http://www.cplusplus.com/reference/string/stol/
http://www.cplusplus.com/reference/string/stoll/
*/

// http://www.cplusplus.com/articles/D9j2Nwbp/

template<typename T>
T toNumber(const string number) {
    istringstream iss(number);
    T result;
    // usando o operador de output >>
    // pega o valor armazenado em iss
    // e tenta inserir na variavel result
    // se o formato da string condizer com
    // o tipo T, a conversao String to Number eh feita
    return iss >> result ? result : 0;
}

void runTest() {
   float f  = toNumber<float> ("2.23");
   double d = toNumber<double> ("6.14");
   printf("%f\n%f\n", f, d);
}

/*
    diferenca entre
    std::istringstream  e std::stringstream
    O primeiro eh uma classe que representa
    stream de input
    Para representar stream output temos a classe
    std::ostringstream
    std::stringstream representa ambos Input e Output
    http://stackoverflow.com/questions/3292107/whats-the-difference-between-istringstream-ostringstream-and-stringstream-w
*/

void runTestStreamIO() {
    /*
        http://www.cplusplus.com/reference/sstream/stringstream/
        Characters can be inserted and/or extracted
        from the stream using any operation
        allowed on both input and output streams.
        output "<<"  e input ">>" respectivamente
    */
    std::stringstream ss;
    ss << 100 << ' ' << 200;
    int a, b;
    ss >> a >> b;
    printf("%d %d\n", a, b);

    /*
        http://www.cplusplus.com/reference/sstream/istringstream/
        The characters in the sequence can be extracted from the stream using any operation allowed on input streams.
        input ">>" operator
    */
    std::istringstream iss("10 20 30 40 50");
    int value;
    while(iss >> value) {
        // http://stackoverflow.com/questions/3672234/c-function-to-count-all-the-words-in-a-string
        printf("%d\n", value);
    }

}

/*
http://stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings
*/
vector<string> split(string text, char token) {
    istringstream iss(text);
    string value;
    vector<string> buffer;
    // http://pt.cppreference.com/w/cpp/string/basic_string/getline
    /*
        input - fluxo de dados
        string - variavel que recebe os dados
        delim - caracter delimitador
    */
    while(getline(iss, value, token)) {
        cout << value << endl;
        buffer.push_back(value);
    }
    return buffer;
}

vector<string> tokenizer(string text, char dem) {
    vector<string> tokens;
    stringstream ss(text);
    for(string v; getline(ss, v, dem); tokens.push_back(v)) {
        cout << v << endl;
    }
    return tokens;
}

/*
http://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
http://www.cplusplus.com/reference/cstring/strtok/
http://stackoverflow.com/questions/275733/how-can-i-tokenize-a-c-string
*/


/*
    Estudar istream_iterator
    http://stackoverflow.com/questions/275733/how-can-i-tokenize-a-c-string
    http://en.cppreference.com/w/cpp/iterator/istream_iterator
    http://www.cplusplus.com/reference/iterator/istream_iterator/
    http://www.cplusplus.com/forum/beginner/100055/
*/

void run_test_istream_iterator() {
    stringstream ss("0.1 0.2 0.3");
    istream_iterator<double> iit(ss);
    // o construtor padrao de std::istream_iterator e conhecido
    // como end of stram. Quando um std::istream_iterator valido
    // chaga ao fim do stream ele tera o valor igual ao eos
    istream_iterator<double> eos;

    while(iit != eos) {
        cout<< *iit << endl;
        iit++;
    }
}
template<typename T>
void run_test_istream_iterator2() {
    istream_iterator<T> iit(std::cin);
    istream_iterator<T> eos;
    while(iit != eos) {
        cout<< *iit << endl;
        iit++;
    }
}

/*
http://www.informit.com/articles/article.aspx?p=25088&seqNum=11
http://en.cppreference.com/w/cpp/iterator/ostream_iterator
*/


/*
http://www.guj.com.br/t/stringbuffer-no-c/324453/2
https://dxr.mozilla.org/mozilla-central/source/js/src/vm/StringBuffer.cpp
*/

/*
    precisao ponto flutuandte
    https://github.com/lyx-x/ACM-cheatsheet-latex/blob/master/code/io.cpp
*/





int main()
{
    //runTestStreamIO();
    //tokenizer("teste,da,funcao,split", ',');
    //run_test_istream_iterator();
    run_test_istream_iterator2<string>();
    return 0;
}
