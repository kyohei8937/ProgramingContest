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
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

int T;
int N2, N3, N4;
vector<int> ansArray;

void solve() {
    return;
}

signed main() {
    cin >> T;
    rep(i, T) {
        cin >> N2 >> N3 >> N4;
        int ans = 0;
        // 3,3,4を探す
        if (N3 >= 2 && N4 >= 1) {
            // 3が余るパターン
            if (N3 >= N4 * 2) {
                ans += N4;
                N3 = N3 - N4 * 2;
                N4 = 0;
            }
            // 4が余るパターン
            else {
                ans += N3 / 2;
                N3 = N3 % 2;
                N4 = N4 - N3 / 2;
            }
        }

        // 2,4,4を探す
        if (N2 >= 1 && N4 >= 2) {
            // 4が余るパターン
            if (N4 >= N2 * 2) {
                ans += N2;
                N2 = 0;
                N4 = N4 - N2 * 2;
            }
            // 2が余るパターン
            else {
                ans += N4 / 2;
                N2 = N2 - N4 / 2;
                N4 = N4 % 2;
            }
        }

        // 2,2,3,3を探す
        if (N2 >= 2 && N3 >= 2) {
            // 2が余るパターン
            if (N2 >= N3) {
                ans += N3 / 2;
                N2 = N2 - N3 / 2;
                N3 = N3 % 2;
            }
            // 3が余るパターン
            else {
                ans += N2 / 2;
                N2 = N2 % 2;
                N3 = N3 - N2 / 2;
            }
        }

        // 2,2,2,4を探す
        if (N2 >= 3 && N4 >= 1) {
            // 2が余るパターン
            if (N2 >= N4 * 3) {
                ans += N4;
                N2 = N2 - N4 * 3;
                N4 = 0;
            }
            // 4が余るパターン
            else {
                ans += N2 / 3;
                N2 = N2 % 3;
                N4 = N4 - N2 / 3;
            }
        }

        // 2,2,2,2,2を探す
        if (N2 >= 5) {
            ans += N2 / 5;
        }

        ansArray.push_back(ans);
    }


    rep(i, ansArray.size()) {
        cout << ansArray[i] << endl;
    }

    return 0;
}