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

string S;

int main()
{
    cin >> S;
    reverse(S.begin(), S.end());
    int i = 0;
    while(S[i] != '\0') {
        switch(S[i]){
            case '6':
                S[i] = '9';
                break;
            case '9':
                S[i] = '6';
                break;
            default:
                break;
        }
        i++;
    }
    cout << S;
    return 0;
}