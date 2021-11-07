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
const int MAX_SUM = 100*110;

llong N;
llong p[MAX_N];
bool dp[MAX_N][MAX_SUM];

int main()
{
    cin >> N;
    llong sum = 0;
    rep(i,N){
        cin >> p[i];
        sum += p[i];
    };

    llong count = 1;
    dp[0][0] = true;
    rep(i,1,N+1) {
        rep(j,MAX_SUM){
            if(dp[i-1][j] == true){
                dp[i][j] = true;
            }else{
                if(j-p[i-1] >= 0 && dp[i-1][j-p[i-1]]){
                    dp[i][j] = true;
                    count++;
                }
            }
        }
    }
    /*
    rep(i,N+1) {
        rep(j,sum+1){    
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << count << endl;
}