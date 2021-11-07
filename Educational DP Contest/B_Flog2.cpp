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
const llong INF = 1LL << 60;

llong N,K;
llong h[1000000];
llong cost[1000000];

int main()
{
    cin >> N >> K;
    rep(i,N){
        cin >> h[i];
        cost[i] = INF;
    }

    cost[0] = 0;
    rep(i,1,N){
        rep(j,1,K+1){
            if((i-j)<0){
                break;
            }
            chmin(cost[i], cost[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout << cost[N-1] << endl;

    return 0;
}