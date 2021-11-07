#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

int N, Q;
vector<int> A, B;

void solve() {
	sort(ALL(A));


	rep(i, Q) {
		auto it = lower_bound(ALL(A), B[i]);
		int index = it - A.begin();

		int ans;
		//cout << index << ":";
		if (index == A.size()) {
			ans = abs(A[index - 1] - B[i]);
		}
		else if (index == 0) {
			ans = abs(A[index] - B[i]);
		}
		else {
			ans = min(abs(A[index] - B[i]), abs(A[index - 1] - B[i]));
		}
		cout << ans << endl;
	}
}

signed main() {
	cin >> N;
	A.resize(N);
	rep(i, N) { cin >> A[i]; }
	cin >> Q;
	B.resize(Q);
	rep(i, Q) { cin >> B[i]; }
	solve();
	return 0;
}