#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================
// 尺取方を使う。
// https://qiita.com/drken/items/ecd1a472d3a0e7db8dce

int N, K;
int a[100000];

void solve() {
	int right = 0;
	int ans = 0;
	int sum = 0;
	for (int left = 0; left < N; left++) {
		while (right < N && sum < K) {
			sum += a[right];
			right++;
		}
		// break した状態で right は始めて条件を満たした //
		if (sum >= K) {
			ans += N - right+1;
		}

		// left をインクリメントする準備
		if (right == left) {
			++right;
		}
		else {
			sum -= a[left];
		}
	}
	cout << ans << endl;
}

signed main() {
	cin >> N >> K;
	rep(i, N) { cin >> a[i]; }
	solve();
	return 0;
}