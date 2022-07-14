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

llong N,M;
llong a[1000100];
llong dp[1000100];

int main()
{
    cin >> N >> M;

    rep(i,M){
        llong b;
        cin >> b;
        a[b] = true;
    }

    int breakCount = 0;
    dp[0] = 1;
    rep(i,N+1){
        if(a[i] == false){
            // 1段上に移動できるか確認
            if(a[i+1] == false) {
                dp[i+1] = dp[i+1] + dp[i];
            }
            // 2段上に移動できるか確認
            if(a[i+2] == false) {
                dp[i+2] = dp[i+2] + dp[i];
            }
        }
        //cout << i+1 << ":" << dp[i+1] << " - " << i+2 << ":" << dp[i+2] << endl;
    }

    llong result = dp[N] %  1000000007; 
    cout << result << endl;
    return 0;
}
