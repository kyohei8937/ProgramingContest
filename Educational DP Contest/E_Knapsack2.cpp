#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// タイプ定義
typedef long long llong;
// 値定義
const llong INF = 1LL << 60;

// マクロ
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int MAX_N = 110;
const int MAX_V = 100100;

llong N,W;
llong w[MAX_N],v[MAX_N];
llong dp[MAX_N][MAX_V];

int main()
{
    cin >> N >> W;
    rep(i,N){
        cin >> w[i] >> v[i];
    }

    rep(i,MAX_N){
        rep(j,MAX_V){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    rep(i,N){
        rep(sum_v,MAX_V){
            // i番目の品物を選ぶ場合
            if(sum_v - v[i] >= 0) {
                chmin(dp[i+1][sum_v], dp[i][sum_v - v[i]] + w[i]);
            }
            // i番目の品物を選ぶ場合
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }
    // 最適値の出力
    llong res = 0;
    rep(sum_v,MAX_V){
        if (dp[N][sum_v] <= W) res = sum_v;
    }
    cout << res << endl;
    return 0;
}