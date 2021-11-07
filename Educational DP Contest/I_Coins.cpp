#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
double p[3000];

// dp[i][j] := 最初の i 枚のコインを投げたときに、表が j 枚となる確率
double dp[3000][3000];

void solve(){
    dp[1][0] = 1-p[0];
    dp[1][1] = p[0];
    rep2(i,2,N+1){
        rep(j,i+1){
            dp[i][j] = dp[i-1][j] * (1-p[i-1]) + dp[i-1][j-1] * p[i-1];
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    double ans = 0.0;
    for(int i = N/2+1; i <= N; i++){
        ans += dp[N][i];
    }
    printf("%.10f\n", ans);
    return;
}

signed main(){
    cin >> N;
    rep(i,N){
        cin >> p[i];
    }
    solve();
    return 0;
}