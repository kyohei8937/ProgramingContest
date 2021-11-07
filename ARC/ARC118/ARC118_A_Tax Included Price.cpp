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

llong t, N;

int main()
{
    cin >> t >> N;
    llong a = ((N*100)-1) / t;

    llong result = (((a+1) * (100+t)) / 100) - 1;
    cout << result << endl;
    return 0;
}