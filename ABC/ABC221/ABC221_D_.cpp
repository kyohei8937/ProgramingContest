#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 998244353;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
vector<int> a, b;
int dp[3010][3010];

void solve() {

    rep(i, 3001) {
        if (i >= a[0] && i <= b[0]) {
            dp[0][i] = 1;
        }
    }

    rep2(i, 1, N) {
        rep(j, b[i] + 1) {
            if (j <= a[i]) {
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][j]) % MOD;
            }
            else if (j > a[i] && j <= b[i]) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            }
            //printf("%lld %lld -> %lld\n", i, j, dp[i][j]);
        }
    }
    int ans = 0;
    rep(i, 3001) {
        ans = (ans + dp[N - 1][i]) % MOD;
    }
    cout << ans << endl;
    return;
}

signed main() {
    cin >> N;
    a.resize(N);
    b.resize(N);
    rep(i, N) {
        cin >> a[i];
    }
    rep(i, N) {
        cin >> b[i];
    }
    solve();
    return 0;
}