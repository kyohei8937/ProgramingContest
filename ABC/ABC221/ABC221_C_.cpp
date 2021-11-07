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

int N, M;
char A[100][100];
int juni[100];
vector<pair<int, int>> katikazu;

void solve() {
    rep(i, M) {
        rep2(j, 1,N+1) {
            int first = -katikazu[2 * j - 2].second;
            int second = -katikazu[2 * j -1].second;

            // あいこ
            if (A[first][i] == A[second][i]) {
                continue;
            }
            // firstの勝ち
            else if ((A[first][i] == 'G' && A[second][i] == 'C') ||
                (A[first][i] == 'C' && A[second][i] == 'P') ||
                (A[first][i] == 'P' && A[second][i] == 'G')) {
                katikazu[2 * j - 2].first++;
            }
            // secondの勝ち
            else {
                katikazu[2 * j -1].first++;
            }
        }
        sort(ALL(katikazu), std::greater<pair<int, int>>());
    }

    rep(i, 2 * N) {
        cout << -1 * katikazu[i].second + 1 << endl;
    }
    return;
}

signed main() {
    cin >> N >> M;
    rep(i, 2 * N) {
        rep(j, M) {
            cin >> A[i][j];
        }
        katikazu.push_back(make_pair(0, -i));
    }

    solve();
    return 0;
}