#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// http://www.geeksforgeeks.org/fast-io-for-competitive-programming/

/*
Material CP
https://sites.google.com/site/stevenhalim/home/material
*/

/*
https://www.hackerrank.com/challenges/two-strings/topics
Fato interessante a ser estudado
Uma string tem (n*(n+1))/2 substrings
*/

/*
https://en.wikipedia.org/wiki/Longest_common_substring_problem
*/
string LCSubs(string A, string B) {
    string ans = "";
    int m = A.size();
    int n = B.size();
    // cpp eh um saco nessas horas
    int **matrix = new int *[m+1];
    for(int i=0; i<m; i++) {
        matrix[m] = new int[n+1];
        memset(matrix, 0, sizeof(matrix));
    }


    int counter  = 0;
    int *arr;
    vector<string> subs;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(A[i-1] == B[j-1]) {
                if(i == 1 || j == 1)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                if(matrix[i][j] > counter) {
                    counter = matrix[i][j];
                    ans = A.substr(i-counter+1, i);
                }
                else if(matrix[i][j] == counter) {
                    ans = A.substr(i-counter+1, i);
                }

            }
            else {
               matrix[i][j] = 0;
            }
        }
    }


    // defaz a bagunca
    for (int i = 0; i < m; ++i)
        delete [] matrix[i];
    delete [] matrix;

    return ans;
}
/*
http://www.geeksforgeeks.org/longest-common-substring/
https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-string-searching-algorithms/
*/
string lcsubs(string S, string T) {
    string ans = "";
    int m = A.size();
    int n = B.size();
    // cpp eh um saco nessas horas
    int **matrix = new int *[m+1];
    for(int i=0; i<m; i++) {
        matrix[m] = new int[n+1];
        memset(matrix, 0, sizeof(matrix));
    }
    return ans;
}

/*
LCS
http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

/*
Template class
http://www.cprogramming.com/tutorial/templates.html
*/

class IO {
public:
    IO() {}
    int readInt();
    float readFloat();
    double readDouble();
    string readLine();
    string readLineEOF();
    //http://en.cppreference.com/w/cpp/language/member_template
    template<class T>
    T parse(const string number);
    template<class T>
    vector<T> split(string text, char token);
};

template<class T>
T IO::parse(const string number) {
    istringstream iss(number);
    T result;
    // usando o operador de output >>
    // pega o valor armazenado em iss
    // e tenta inserir na variavel result
    // se o formato da string condizer com
    // o tipo T, a conversao String to Number eh feita
    return iss >> result ? result : 0;
}

string IO::readLine() {
    string n;
    getline(cin, n);
    return n;
}

int IO::readInt() {
    int n = parse<int>(readLine());
    return n;
}

float IO::readFloat() {
    float n = parse<float>(readLine());
    return n;
}

double IO::readDouble() {
    double n = parse<double>(readLine());
    return n;
}
template<class T>
vector<T> IO::split(string text, char token) {
    vector<T> buffer;
    istringstream iss(text);
    string value;
    //input  - fluxo de dados; string - variavel que recebe os dados; delim  - caracter delimitador
    while(getline(iss, value, token)) {
        buffer.push_back(parse<T>(value));
    }
    return buffer;
}


void runTestReadLine() {
    IO io;
    string in   = io.readLine();
    int n       = io.readInt();
    float f     = io.readFloat();
    double d    = io.readDouble();
    cout << in <<" " << n << " " << f << " " << d << endl;
}

void runTestSplitLine() {
    IO io;
    vector<int> vect = io.split<int>(io.readLine(), ' ');
    vector<int>::iterator it = vect.begin();
    while(it != vect.end()) {
        cout << *(it++) << " ";
    }
}

int main()
{
    LCSubs("abab", "baba");
    return 0;
}
