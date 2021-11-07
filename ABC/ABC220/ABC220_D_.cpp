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
vector<int> A;

// dp[i][j]:i桁目でjになる組み合わせ数
int dp[1000100][10];

void solve() {

    dp[0][A[0]] = 1;
    rep2(i, 1, N) {
        rep(j, 10) {
            if (dp[i - 1][j] > 0) {
                int retF = (j + A[i]) % 10;
                dp[i][retF] = (dp[i][retF] + dp[i - 1][j]) % MOD;
                int retG = (j * A[i]) % 10;
                dp[i][retG] = (dp[i][retG] + dp[i - 1][j]) % MOD;
            }
        }
    }
    /*
    rep(i, N) {
        rep(j, 10) {
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    */


    rep(j, 10) {
        cout << dp[N - 1][j] << endl;
    }
    return;
}

signed main() {
    cin >> N;
    A.resize(N);
    rep(i, N) {
        cin >> A[i];
    }
    solve();
    return 0;
}