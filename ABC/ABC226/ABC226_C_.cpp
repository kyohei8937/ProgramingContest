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

#define MAX 200000

int N;
vector<int> T;
vector<int> K;
vector<vector<int>> A;

int useMap[MAX + 1];

void solve() {

    //memset(useMap,-1,sizeof(int)*MAX);

    // 習得必要なやつをゴールから逆探索
    stack<int> stc;
    useMap[N] = 1;
    useMap[0] = 1;
    rep(i, K[N - 1]) {
        useMap[A[N - 1][i]] = 1;
        stc.push(A[N - 1][i]);
    }


    while (!stc.empty()) {
        int cur = stc.top();
        stc.pop();

        rep(i, K[cur - 1]) {
            if (!useMap[A[cur - 1][i]]) {
                stc.push(A[cur - 1][i]);
                useMap[A[cur - 1][i]+1] = 1;
            }
        }
    }
    int ans = 0;
    rep2(i, 1, N + 1) {
        if (useMap[i]) {
            ans += T[i - 1];
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    cin >> N;
    T.resize(N);
    K.resize(N);
    A.resize(N);
    rep(i, N) {
        cin >> T[i] >> K[i];
        A[i].resize(K[i]);
        rep(j, K[i]) {
            cin >> A[i][j];
        }
    }
    solve();
    return 0;
}