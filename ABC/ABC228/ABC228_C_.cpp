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

int N, K;

vector<pair<int, int>> P;

priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>> > ansList;

void solve() {
    rep(i, N) {
        pair<int, bool> ans;
        // 順位が↑なら
        if (i + 1 <= K) {
            ans.first = P[i].second;
            ans.second = true;
            ansList.push(ans);
            continue;
        }
        if ((P[K - 1].first - P[i].first) <= 300) {
            ans.first = P[i].second;
            ans.second = true;
            ansList.push(ans);
        }
        else {
            ans.first = P[i].second;
            ans.second = false;
            ansList.push(ans);
        }
    }
    rep(i, N) {
        pair<int, bool> ans = ansList.top();
        ansList.pop();
        if (ans.second) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return;
}

signed main() {
    cin >> N >> K;
    P.resize(N);
    rep(i, N) {
        P[i].second += i;
        rep(j, 3) {
            int score;
            cin >> score;
            P[i].first += score;
        }
    }
    sort(ALL(P), greater<pair<int, int>>());
    solve();
    return 0;
}