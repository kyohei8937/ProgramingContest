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

llong N,W;
llong w[110],v[110];
llong dp[110][1000100];

int main()
{
    cin >> N >> W;
    rep(i,N){
        cin >> w[i] >> v[i];
    }

    rep(i,N){
        rep(sum_w,W+1){
            // i番目の品物を選ぶ場合
            if(sum_w - w[i] >= 0){
                chmax(dp[i+1][sum_w], dp[i][sum_w - w[i]] + v[i]);
            }
            // i番目の品物を選ばない場合
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }
    // 最適化の出力
    cout << dp[N][W] << endl;
    return 0;
}