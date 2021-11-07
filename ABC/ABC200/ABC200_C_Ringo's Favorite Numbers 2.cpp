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

llong N, A[200000];

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

int main()
{
    cin >> N;
    llong hash[200];
    memset(hash,0,sizeof(llong)*200);
    llong result = 0;
    rep(i,N){
        cin >> A[i];
        hash[A[i] % 200]++;
    }
    rep(i,200){
        if(hash[i] >= 2) {
            result = result + nCr(hash[i],2);
        }
    }
    cout << result << endl;
    return 0;
}