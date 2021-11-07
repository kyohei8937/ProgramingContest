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

// グローバル変数（input格納用）
int n,k,w[100000];

// 積載量がPのk台のトラックで何個の荷物を積めるか
int check(llong P){
    int i = 0;
    rep(j,k){
        llong s = 0;
        while(s + w[i] <= P) {
            s += w[i];
            i++;
            if(i == n) {
                return n;
            }
        }
    }
    return i;
}

int solve() {
    llong left = 0;
    llong right = 100000 * 10000;    
    llong mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int v = check(mid);
        //cout << "P:" << mid << ",v:" << v << ",left:" << left << ",right:" << right << endl;
        if(v >= n) {
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int main()
{
    cin >> n >> k;
    
    rep(i, n) {
        cin >> w[i];
    }
    cout << solve() << endl;
    return 0;
}