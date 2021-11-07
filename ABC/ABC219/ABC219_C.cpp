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

string X;
map<char, char> m;
string org = "abcdefghijklmnopqrstuvwxyz";
int N;
string S[50000];
vector<pair<string, int>> S_aft;

void solve() {

    rep(i, 26) {
        m.insert(make_pair(X[i], org[i]));
    }

    rep(i, N) {
        string aft = S[i];
        rep(j, S[i].size()) {
            aft[j] = m.at(S[i][j]);
        }
        S_aft.push_back(make_pair(aft, i));
    }

    sort(ALL(S_aft));

    rep(i, N) {
        cout << S[S_aft[i].second] << endl;
    }

    return;
}

signed main() {
    cin >> X >> N;
    rep(i, N) {
        cin >> S[i];
    }
    solve();
    return 0;
}