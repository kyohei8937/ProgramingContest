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

vector<int> xArray;
vector<int> yArray;
vector<pair<int, int>> points;

void solve() {

    int ans = 0;
    rep(i, N) {
        // xが同じyを探す
        rep2(j, i + 1, N) {
            if (points[i].first != points[j].first) {
                // xが変わった時点でbreak;
                break;
            }

            // yが同じxを探す
            bool search = false;
            int memX;
            rep2(k, j + 1, N) {
                if (!search) {
                    if (points[j].first == points[k].first) {
                        // xが同じなら無視
                        continue;
                    }
                    // 左下と右下が同じyなら候補
                    if (points[i].second == points[k].second) {
                        search = true;
                        memX = points[k].first;
                    }
                }
                else
                {
                    if (memX != points[k].first) {
                        // 左下と右下が同じyなら候補
                        if (points[i].second == points[k].second) {
                            search = true;
                            memX = points[k].first;
                        }
                        else {
                            search = false;
                        }
                    }
                    else {
                        if (points[j].second == points[k].second) {
                            ans++;
                            search = false;
                        }
                    }
                }
            }

        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    cin >> N;
    points.resize(N);
    yArray.resize(N);
    rep(i, N) {
        cin >> points[i].first >> points[i].second;
    }

    sort(ALL(points));

    solve();
    return 0;
}