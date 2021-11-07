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

int A1, A2, A3;

void solve() {
	int mn = INF;
	int target;
	int diff = 0;
	// 0に合わせる。
	int minusFor0 = min(min(A1, A2), A3);
	A1 -= minusFor0;
	A2 -= minusFor0;
	A3 -= minusFor0;

	if (A1 == 0) {

		// 昇順
		if (A2<A3) {
			target = A2 - (A3 - A2);
		}
		// 降順
		else {
			target = A2 + (A2 - A3);
		}
		diff = target - A1;
		if (diff >= 0) {
			chmin(mn, diff);
		}
		else {
			chmin(mn, diff*-2);
		}

	}
	if (A2 == 0) {

		// 割り切れるパターン
		if (abs(A1 - A3) % 2 == 0) {
			// 昇順
			if (A1<A3) {
				target = A1 + (A3 - A1) / 2;
			}
			// 降順
			else {
				target = A1 - (A1 - A3) / 2;
			}
			diff = target - A2;
			if (diff >= 0) {
				chmin(mn, diff);
			}
			else {
				chmin(mn, diff*-2);
			}
		}

		// 割り切れないパターン
		else {
			// 昇順
			if (A1<A3) {
				A1++;
				target = A1 + (A3 - A1) / 2;
			}
			// 降順
			else {
				A3++;
				target = A1 - (A1 - A3) / 2;
			}
			diff = target - A2;
			if (diff >= 0) {
				chmin(mn, diff + 1);
			}
			else {
				chmin(mn, diff*-2 +1);
			}
		}
	}
	if (A3 == 0) {

		// 昇順
		if (A1<A2) {
			target = A2 + (A2 - A1);
		}
		// 降順
		else {
			target = A2 - (A1 - A2);
		}
		diff = target - A3;
		if (diff >= 0) {
			chmin(mn, diff);
		}
		else {
			chmin(mn, diff*-2);
		}
	}
	cout << mn << endl;
	return;
}

signed main() {
	cin >> A1 >> A2 >> A3;
	solve();
	return 0;
}