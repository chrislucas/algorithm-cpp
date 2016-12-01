#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;



char * sum(const char * m, const char * n) {
    int lenM = strlen(m), lenN = strlen(n), sz = lenM > lenN ? lenM : lenN;
    int lenA = sz + 1;
    char * answer = new char [ lenA ];
    answer[lenA] = '\0';
    //char answer[100];
    int idx  = lenA - 1, carry = 0;
    //int diff = (lenM - lenN) < 0 ? -(lenM - lenN) : (lenM - lenN);
    lenM--;
    lenN--;
    while(lenM>=0 && lenN>=0) {
        int a = m[lenM] & 0x0f;
        int b = n[lenN] & 0x0f;
        carry += a + b;
        answer[idx--] = (char) (carry % 10) + 48;
        carry /= 10;
        lenM--;
        lenN--;
    }
    const  char * S = lenM > lenN ? m : n;
    int len = lenM > lenN ? lenM : lenN;
    while(len>=0) {
        int a = S[len--] & 0x0f;
        carry += a;
        answer[idx--] = (char) (carry % 10) + 48;
        carry /= 10;
    }

    if(carry > 0)
        answer[idx--] = (char) (carry % 10) + 48;

    if(idx >= 0) {
        char * buffer = new char[lenA - idx];
        memcpy(buffer, answer + idx, lenA);
        buffer[lenA - idx] = '\0';
        return buffer;
    }
    return answer;
}

/*
https://www.hackerrank.com/challenges/a-very-big-sum?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=75-day-campaign
*/

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

int main()
{
    /*
    printf("%s\n", sum("1123", "321"));
    printf("%s\n", sum("123", "321"));
    printf("%s\n", sum("999", "1"));
    printf("%s\n", sum("123456789", "987654321"));
    printf("%s\n", sum("1011", "129911"));
    printf("%s\n", sum("1011", "12011"));
    */
    string number, in;
    int cases, counter = 0;
    scanf("%d", &cases);
    cin.ignore('\n');
    getline(cin, in);
    vector<string> numbers = split(in, ' ');
    for(int i=0; i<numbers.size(); i++) {
        cout << numbers[i] << endl;
    }
    const char *m = numbers[0].c_str()
    ,*n = numbers[1].c_str()
    ,*ans = sum(m,n);

    for(int i=2; i<numbers.size(); i++) {
        ans = sum(numbers[1].c_str(), ans);
    }
    printf("%s\n", ans);

    return 0;
}
