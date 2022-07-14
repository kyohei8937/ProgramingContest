#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
#ifdef DEBUG
# define _PRINTF(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _PRINTF(fmt, ...)
#endif

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

string S;

void solve() {

    if(S == "xx" || S == "x"){
        cout << "Yes" << endl;
        return;        
    }

    int index = 0;
    // 丸が出るまでxo
    while (S[index] != 'o') {
        index++;
        if (index > 2 || index == S.size()) {
            cout << "No" << endl;
            return;
        }
    }
    int index2 = 0;
    rep2(i, index, S.size()) {
        if (index2 % 3 == 0) {
            if (S[i] != 'o') {
                cout << "No" << endl;
                return;
            }
        }
        if (index2 % 3 == 1) {
            if (S[i] != 'x') {
                cout << "No" << endl;
                return;
            }
        }
        if (index2 % 3 == 2) {
            if (S[i] != 'x') {
                cout << "No" << endl;
                return;
            }
        }
        index2++;
    }
    cout << "Yes" << endl;
    return;
}

signed main() {
    cin >> S;
    solve();
    return 0;
}