#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

int W,N,K;
int A[50],B[50];

// dp[i][j][k] := i 番目以下の荷物から j 個以下選び、
// 重さkがWを超えないように荷物を選んだ時の価値の最大値
// http://chiwawa-star.hatenablog.com/entry/2018/03/04/190244
double dp[51][51][100001];

signed main(){

    cin >> W;
    cin >> N >> K;
    rep(i,N){
        cin >> A[i] >> B[i];
    }

    dp[0][0][0] = 0;
    rep(i,1,N+1){
        rep(j,1,K+1){
            rep(k,1,W+1){
                if(k >= A[i-1]){
                     dp[i][j][k] = max( { dp[i-1][j][k], dp[i-1][j-1][k], dp[i-1][j-1][k-A[i-1]] + B[i-1] } );
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j-1][k], dp[i-1][j][k] );
                }
            }
        }
    }
    cout << dp[N][K][W ] << endl;
    return 0;
}