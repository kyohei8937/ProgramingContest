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

const int N_MAX = 2 * 100000;
int N;

priority_queue<int, vector<int>, greater<int> > children[N_MAX];
//priority_queue<int> children[N_MAX];
int score[N_MAX];
vector<int> ans;

// 再帰関数による実装
void dfs(int current, int prev) {
	ans.push_back(current + 1);
	priority_queue<int, vector<int>, greater<int> > current_queue = children[current];
	for (int i = 0; i < children[current].size(); i++) {
		int next = current_queue.top();
		current_queue.pop();
		if (next != prev) {
			score[next] += score[current];
			dfs(next, current);
		}
		ans.push_back(current + 1);
	}
}

signed main() {

	// 標準入力
	cin >> N;

	int parent[N_MAX];
	memset(parent, -1, sizeof(int) * N_MAX);

	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		children[a].push(b);
		children[b].push(a);
	}
	dfs(0, -1);

	rep(i, ans.size()) {
		if (i == 0 || ans[i] != ans[i - 1]) {
			cout << ans[i];
			if (i != ans.size() - 1) {
				cout << " ";
			}
		}
	}
	cout << endl;

	return 0;
}