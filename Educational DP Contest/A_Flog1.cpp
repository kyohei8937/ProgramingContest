#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// タイプ定義
typedef long long llong;

// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N;
int h[1000000];
int cost[1000000];

int main()
{
    cin >> N;
    rep(i,N){
        cin >> h[i];
    }

    cost[0] = 0;
    cost[1] = abs(h[1] - h[0]);
    rep(i,2,N){
        cost[i] = cost[i-1] + abs(h[i] - h[i-1]);
        chmin(cost[i], cost[i-2] + abs(h[i] - h[i-2]));
    }

    cout << cost[N-1] << endl;

    return 0;
}