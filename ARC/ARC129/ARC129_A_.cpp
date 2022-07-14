#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 62;
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
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

int N, L, R;

string toBinary(int n)
{
    string r;
    while (n != 0) {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}

void solve() {

    string bin = toBinary(N);
    //cout << bin << endl;
    int keta = bin.size();

    int ans = 0;
    rep(i, keta) {
        int v = bin[i] - '0';
        //int ketaR = keta - i;
        int ketaR = i;
        if (v == 0) {
            int l = modpow(2, i, INF);
            int r = modpow(2, i + 1, INF) - 1;
            if (L > l) l = L;
            if (R < r) r = R;
            int kosu = r - l + 1;
            if (kosu < 0) kosu = 0;
            ans += kosu;
        }
    }

    int mx = modpow(2, keta, INF);
    if (mx < L) mx = L;
    int plus = R - mx + 1;
    int zero = 0;
    chmax(plus, zero);
    //cout << "ans:" << ans + plus << " = " << ans << "+" << plus << endl;
    ans += plus;


    /*
    int ans2 = 0;
    rep2(i, L, R + 1) {
        int x = i ^ N;
        //cout << i << ":" << x << endl;
        if (x < N) {
            ans2++;
        }
    }
    cout << ans2 << endl;
    */

    cout << (R - L + 1) - ans << endl;

    return;
}
signed main() {
    cin >> N >> L >> R;
    solve();
    return 0;
}