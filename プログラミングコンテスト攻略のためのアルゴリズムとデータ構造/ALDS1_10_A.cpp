#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// タイプ定義
typedef long long llong;
// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int n;
int F[44];

int main()
{
    cin >> n;
    F[0] = 1;
    F[1] = 1;
    rep(i,2,n+1) {
        F[i] = F[i-1] + F[i-2];
    }

    cout << F[n] << endl;

    return 0;
}