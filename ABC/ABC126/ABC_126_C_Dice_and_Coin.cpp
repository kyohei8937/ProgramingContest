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

int binary_search(int key, int mx) {
	int left = 0, right = mx; // 配列 a の左端と右端
	int mid = 0;

	while (right >= left) {
		mid = left + (right - left) / 2; // 区間の真ん中
		if (key*pow(2, mid) > K) {
			right = mid - 1;
		}
		else if (key*pow(2, mid) < K) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return left;
}

void solve() {

	double ans = 0.0;
	int mx = K;
	rep2(i, 1, N + 1) {
		int count = binary_search(i, mx); // 連続回数
		ans += (1.0 / N) * pow(0.5, count);
		mx = count;
	}
	printf("%.12f\n", ans);

	return;
}

signed main() {
	cin >> N >> K;
	solve();
	return 0;
}