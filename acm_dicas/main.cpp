#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

/*
    dicas acm
    http://acm.timus.ru/help.aspx?topic=cpp
*/

/*
scanf("%lld", &a);
scanf("%llu", &b);
printf("%lld", a);
printf("%llu", b);

long long a;
unsigned long long b;

*/

map<string, int> getWords() {
    map<string, int> words;
    string word;

   while (getline(cin, word))
      words[word]++;

   for (map<string, int>::iterator it = words.begin(); it != words.end(); it++)
      cout << it->first << " - " << it->second << endl;

    return words;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
