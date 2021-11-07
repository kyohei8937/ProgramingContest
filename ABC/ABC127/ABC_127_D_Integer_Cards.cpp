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
vector<int> A;
vector<pair<int, int>> CB;

void solve() {
	sort(ALL(A));
	sort(ALL(CB), greater<pair<int, int>>());

	vector<int> dst;
	rep(i, M) {
		rep(j, CB[i].second) {
			dst.push_back(CB[i].first);
			if (dst.size() >= N) {
				break;
			}
		}
		if (dst.size() >= N) {
			break;
		}
	}
	int sum = 0;
	rep(i, N) {
		if (i <= dst.size()-1 ) {
			sum += max(A[i], dst[i]);
		}else{
			sum += A[i];
		}
	}
	cout << sum << endl;
	return;
}

signed main() {
	cin >> N >> M;
	A.resize(N);
	CB.resize(M);
	rep(i, N) { cin >> A[i]; };
	rep(i, M) {
		int B, C;
		cin >> B >> C;
		CB[i] = make_pair(C, B);
	}
	solve();
	return 0;
}