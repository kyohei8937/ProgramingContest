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

deque<pair<double, double>> deq;

void solve() {

    pair<double, double> left, right;

    if (N == 1) {
        double ans = (deq.front().first) / 2.0;
        printf("%.15f\n", ans);
        return;
    }

    left = deq.front();
    deq.pop_front();
    right = deq.back();
    deq.pop_back();

    double left_lastLength = left.first;
    double right_lastLength = right.first;
    double left_next = left.first / left.second;
    double right_next = right.first / right.second;

    double ans = 0;
    while (!deq.empty()) {
        // 左が先に燃えつきる
        if (left_next <= right_next) {
            // 右は時間分進む
            right_next = right_next - left_next;
            right_lastLength = right_lastLength - right.second * left_next;

            // 左は次の導火線
            ans = ans + left_lastLength;
            left = deq.front();
            deq.pop_front();
            left_next = left.first / left.second;
            left_lastLength = left.first;
        }

        // 右が先に燃えつきる
        else{
            // 左は時間分進む
            left_next = left_next - right_next;
            left_lastLength = left_lastLength - left.second * right_next;
            ans = ans + left.second * right_next;

            // 右は次の導火線
            right = deq.back();
            deq.pop_back();
            right_next = right.first / right.second;
            right_lastLength = right.first;
        }
    }

    // ここに来た時点で、leftもrightも別々の導火線を一本ずつもっている
    // leftが先に燃える
    if (left_next < right_next) {
        // 左は全部燃える
        ans = ans + left_lastLength;
        // 右は時間分進む
        right_lastLength = right_lastLength - right.second * left_next;
        // 中間
        ans = ans + (right_lastLength / 2.0);
    }
    else if (left_next > right_next) {
        // 左は時間分進む
        left_next = left_next - right_next;
        left_lastLength = left_lastLength - left.second * right_next;
        ans = ans + left.second * right_next;
        // 中間
        ans = ans + (left_lastLength / 2.0);
    }
    else {
        ans = ans + left_lastLength;
    }
    printf("%.15f\n", ans);
    return;
}

signed main() {
    cin >> N;

    rep(i, N) {
        double A, B;
        cin >> A >> B;
        deq.push_back(make_pair(A, B));
    }
    solve();
    return 0;
}