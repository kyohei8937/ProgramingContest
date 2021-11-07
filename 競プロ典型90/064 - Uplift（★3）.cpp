#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define MAX 100000

int N, Q;
int A[MAX];
int L[MAX], R[MAX], V[MAX];

int diff[MAX];

void solve() {

	// 初期差分と不便さをメモ
	int huben = 0;
	rep(i, N - 1) {
		diff[i] = A[i + 1] - A[i];
		huben += abs(diff[i]);
	}

	rep(i, Q) {
		int before_diff;
		if (L[i] >= 2) {
			before_diff = diff[L[i] - 2];
			diff[L[i] - 2] = diff[L[i] - 2] + V[i];
			huben = huben - abs(before_diff) + abs(diff[L[i] - 2]);
		}
		if (R[i] - 1<N-1) {
			before_diff = diff[R[i] - 1];
			diff[R[i] - 1] = diff[R[i] - 1] - V[i];
			huben = huben - abs(before_diff) + abs(diff[R[i] - 1]);
		}
		cout << huben << endl;
	}
}

signed main() {
	cin >> N >> Q;
	rep(i, N) {
		cin >> A[i];
	}
	rep(i, Q) {
		cin >> L[i] >> R[i] >> V[i];
	}
	solve();
	return 0;
}