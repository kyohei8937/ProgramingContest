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

#define MAX 1000000010

vector<pair<int, int>> row_array, col_array;
int H, W, N;
pair<int, int> ans_map[100010];

void solve() {
    sort(ALL(row_array));
    sort(ALL(col_array));

    int row_dup = 1;
    rep(i, N) {
        if (i != 0 && row_array[i].first != row_array[i - 1].first) {
            row_dup++;
        }
        ans_map[row_array[i].second].first = row_dup;
    }

    int col_dup = 1;
    rep(i, N) {
        if (i != 0 && col_array[i].first != col_array[i - 1].first) {
            col_dup++;
        }
        ans_map[col_array[i].second].second = col_dup;
    }

    rep(i, N) {
        cout << ans_map[i].first << " " << ans_map[i].second << endl;
    }
    return;
}

signed main() {
    cin >> H >> W >> N;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        row_array.push_back(make_pair(a, i));
        col_array.push_back(make_pair(b, i));
    }
    solve();
    return 0;
}