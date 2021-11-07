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
vector<pair<int, int>> Array;

void solve() {

	deque<int> queA, queB, queC;
	int ans = 0;
	rep(i, 3*N) {
		if (Array[i].second == 0) {
			queA.push_back(Array[i].first);
		}
		else if (Array[i].second == 1) {
			if (queA.size()>queB.size()) {
				if (queA.at(queB.size()) < Array[i].first) {
					queB.push_back(Array[i].first);
				}
			}
		}
		else if (Array[i].second == 2) {
			if (queB.size()>queC.size()) {
				if (queB.front() < Array[i].first) {
					queA.pop_front();
					queB.pop_front();
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
}

signed main() {
	cin >> N;
	rep(i, N) {
		int A;
		cin >> A;
		Array.push_back(make_pair(A, 0));
	}
	rep(i, N) {
		int B;
		cin >> B;
		Array.push_back(make_pair(B, 1));
	}
	rep(i, N) {
		int C;
		cin >> C;
		Array.push_back(make_pair(C, 2));
	}
	sort(ALL(Array));
	solve();
	return 0;
}