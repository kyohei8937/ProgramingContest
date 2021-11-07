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
int a[100100],b[100100],c[100100];

// dp[i][j] i日目にjを選択した場合の最大幸福値
int dp[100100][3];

void solve(){

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    rep2(i,1,N){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c[i];
    }

    int ans = max(max(dp[N-1][0],dp[N-1][1]),dp[N-1][2]);
    cout << ans << endl;
    return;
}

signed main(){
    cin >> N;
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    solve();
    return 0;
}