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

int H, W, C, Q;

int tList[300000];
int nList[300000];
int cList[300000];


// 各数字の数
int ans[300001];

set<int> usedH;
set<int> usedW;

void solve() {
    for (int i = Q - 1; i >= 0; i--) {
        int t = tList[i];
        int n = nList[i];
        int c = cList[i];
        if (t == 1) {
            set<int>::iterator it = usedW.find(n);
            if (it == usedW.end()) {
                usedW.insert(n);
                ans[c] = ans[c] + W - usedH.size();
            }
        }
        else {
            set<int>::iterator it = usedH.find(n);
            if (it == usedH.end()) {
                usedH.insert(n);
                ans[c] = ans[c] + H - usedW.size();
            }
        }
    }

    rep2(i, 1, C + 1) {
        cout << ans[i];
        if (i != C) {
            cout << " ";
        }
    }
    cout << endl;
    return;
}

signed main() {
    cin >> H >> W >> C >> Q;
    rep(i, Q) {
        cin >> tList[i] >> nList[i] >> cList[i];
    }
    solve();
    return 0;
}