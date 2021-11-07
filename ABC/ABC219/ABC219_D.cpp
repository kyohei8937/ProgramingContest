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
int X, Y;
vector<pair<int, int>> bento;

int A_sum, B_sum;

void solve() {

    int ans = 0;
    bool isFinish = false;
    while (!isFinish) {
        ans++;
        int minLast = INF;
        int selectNo;
        for (auto it = bento.begin(); it != bento.end();it++) {
            int index = it - bento.begin();
            int lastX = X - bento[index].first;
            int lastY = Y - bento[index].second;

            if (lastX <= 0 && lastY <= 0) {
                isFinish = true;
                break;
            }

            int last = lastX + lastY;
            if (last < minLast) {
                selectNo = index;
                minLast = last;
            }
        }
        auto elem_to_remove = bento.begin() + selectNo;
        bento.erase(elem_to_remove);
        X = X - minLast;
        Y = Y - minLast;
    }

    cout << ans << endl;
    return;
}

signed main() {
    cin >> N >> X >> Y;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        A_sum += a;
        B_sum += b;
        bento.push_back(make_pair(a, b));
    }
    if (A_sum < X || B_sum < Y) {
        cout << -1 << endl;
    }
    else {
        solve();
    }
    return 0;
}