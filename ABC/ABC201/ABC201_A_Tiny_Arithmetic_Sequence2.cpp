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

int A[3];

int main()
{
    cin >> A [0] >> A[1] >> A[2];
    std::vector<int> v;
    v.push_back(A[0]);
    v.push_back(A[1]);
    v.push_back(A[2]);

    std::sort(v.begin(), v.end());
    //cout << v[0] << v[1] << v[2];
    if((v[1]-v[0]) == (v[2]-v[1])) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}