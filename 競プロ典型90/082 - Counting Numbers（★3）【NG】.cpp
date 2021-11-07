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

unsigned int L, R;
unsigned long long power10[22];

unsigned int GetDigit(unsigned int num) {
	unsigned int digit = 0;
	while (num != 0) {
		num /= 10;
		digit++;
	}
	return digit;
}

void init() {
	// Calculate 10^i
	power10[0] = 1;
	for (int i = 1; i <= 19; i++) power10[i] = (10ULL * power10[i - 1]);
}

void solve() {

	init();

	// Lの桁数算出
	unsigned int l_digit = GetDigit(L);

	// Rの桁数算出
	unsigned int r_digit = GetDigit(R);

	unsigned int ans = 0;
	for (int i = l_digit; i <= r_digit; i++) {
		unsigned int upper, lower;
		if (i == l_digit == r_digit) {
			lower = L;
			upper = R;
		}
		else if (i == l_digit) {
			lower = L;
			upper = power10[i] - 1;
		}
		else if (i == r_digit) {
			lower = power10[i-1];
			upper = R;
		}
		else {
			lower = power10[i-1];
			upper = power10[i] - 1;
		}
		ans += i*(((lower + upper) * (upper - lower + 1)) % MOD / 2);
		ans %= MOD;
	}
	cout << ans << endl;
	return;
}

signed main() {
	cin >> L >> R;
	solve();
	return 0;
}