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

int N;
int L[200000];
int R[200000];
int dis;

void solve() {

    priority_queue<int> L_down;
    priority_queue<int, vector<int>, greater<int>> R_up;

    L_down.push(L[0]);
    R_up.push(R[0]);
    cout << 0 << endl;

    int maxdis = 0;
    rep2(i, 1, N) {
        int disR = L_down.top() - R[i];
        if (disR < 0)disR = 0;

        int disL = L[i] - R_up.top();
        if (disL < 0)disL = 0;

        int dis = max(disR, disL) / 2;
        if (max(disR, disL) % 2 == 1) {
            dis++;
        }
        if (maxdis < dis) {
            maxdis = dis;
        }
        cout << maxdis << endl;
        L_down.push(L[i]);
        R_up.push(R[i]);
    }

    return;
}

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> L[i] >> R[i];
    }
    solve();
    return 0;
}