#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <limits>
#include <climits>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cassert>
/*
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
*/
#include <numeric>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <string>
/*
nem todos os compiladores tem esse header
#include <bits/stdc++.h>
*/

using namespace std;


#define rite(x)     freopen(x,"w",stdout);
#define read(x)     freopen(x,"r",stdin);
#define rep(i,n)    for(auto i=0; i<(n); i++)
#define mem(x,val)  memset((x),(val),sizeof(x));
#define rite(x)     freopen(x,"w",stdout);
#define read(x)     freopen(x,"r",stdin);
#define all(x)      x.begin(),x.end()
#define sz(x)       ((int)x.size())
#define sqr(x)      ((x)*(x))
#define pb          push_back
#define clr         clear()
#define inf         (1<<30)


typedef long long ll;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvii;

std::string readLine() {
    string line;
    std::getline(std::cin, line);
    return line;
}

/**
http://www.cplusplus.com/doc/tutorial/preprocessor/
*/
#define str(x) #x
void run() {
    //printf("MODO JUIZ ONLINE");
    string line = readLine();
    cout<< line <<endl;
    return;
}


int main()
{
    //cout<< str(test);
    //ios_base::sync_with_stdio(0);
    //http://acm.timus.ru/help.aspx?topic=cpp
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        run();
        return 0;
}
