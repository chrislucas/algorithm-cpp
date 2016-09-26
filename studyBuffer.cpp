#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

/*
http://www.songho.ca/misc/tokenizer/tokenizer.html
http://www.partow.net/programming/strtk/index.html

http://stackoverflow.com/questions/2462951/c-equivalent-of-stringbuffer-stringbuilder
http://www.guj.com.br/t/stringbuffer-no-c/324453/2
*/

// http://www.cplusplus.com/reference/sstream/stringstream/stringstream/
void example_sstream1() {
    stringstream sstream;

    sstream << 4 <<" " <<4.5 <<" " << "text";
    // convertendo um stream em string
    cout << sstream.str();
    return;
}

void read_file() {
    // http://www.cplusplus.com/reference/istream/istream/read/
    ifstream file("../Salto/salto_in/salto_11.in");
    stringstream ss;
    string line;

    if(file) {
        while(getline(file, line)) {
            ss << line << endl;
        }
        cout << ss.str();
    }

    return;
}

int main()
{
    //example_sstream1();
    read_file();
    return 0;
}
