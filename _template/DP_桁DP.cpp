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

const int MOD = 1e9 + 7;

int D;
string N;

// dp[ i ][smaller][ j ] := i 桁目までの各桁の数の和が mod Dで j となる数。
// ただし smaller が true ならNより小さい場合を考え、smallerが false ならNと同じ場合を考える。
int dp[100100][2][110];

signed main(){
    cin >> D >> N;
    int n = N.size();
    dp[0][0][0] = 1;

    rep(i,n) {
        rep(j,D){
            // i桁目まででNより小さいならi+1桁目は何でも良い
            rep(k,10){
                dp[i + 1][1][(j + k) % D] += dp[i][1][j];
                dp[i + 1][1][(j + k) % D] %= MOD;                
            }

            int ni = (N[i] - '0');
            // i桁目までNと同じで、i+1桁目はNより小さい数の時
            rep(k, ni) {
                dp[i + 1][1][(j + k) % D] += dp[i][0][j];
                dp[i + 1][1][(j + k) % D] %= MOD;
            }
            //  i桁目までNと同じで、i+1桁目もNと同じ数の時
            dp[i + 1][0][(j + ni) % D] = dp[i][0][j];
        }
    }
    cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;
    return 0;
}