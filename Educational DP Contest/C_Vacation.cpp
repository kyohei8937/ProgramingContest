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

llong N;
llong a[100000][3];
llong dp[100000][3];

int main()
{
    cin >> N;
    rep(i,N){
        cin >> a[i][0] >> a[i][1] >> a[i][2];

        if(i == 0){
            dp[i][0] = a[i][0];
            dp[i][1] = a[i][1];
            dp[i][2] = a[i][2];
        }else{
            rep(j,3) {
                rep(k,3){
                    if(j!=k){
                        chmax(dp[i][j],dp[i-1][k] + a[i][j]);
                    }
                }
            }
        }
    }

    llong max = 0;
    chmax(max,dp[N-1][0]);
    chmax(max,dp[N-1][1]);
    chmax(max,dp[N-1][2]);
    cout << max << endl;
    
    return 0;
}