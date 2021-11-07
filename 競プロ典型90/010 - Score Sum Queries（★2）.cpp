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
#define N_MAX (100100)
#define Q_MAX (100100)
int N, Q;
int S1[N_MAX], S2[N_MAX];

signed main() {
	cin >> N;
	rep(i, N) {
		int C, P;
		cin >> C >> P;
		if (C == 1) {
			if (i == 0) {
				S1[i] = P;
			}
			else {
				S1[i] = S1[i - 1] + P;
				S2[i] = S2[i - 1];
			}
		}
		else {
			if (i == 0) {
				S2[i] = P;
			}
			else {
				S1[i] = S1[i - 1];
				S2[i] = S2[i - 1] + P;
			}
		}
	}
	
	cin >> Q;
	int ans1[Q_MAX], ans2[Q_MAX];
	
	rep(i, Q) {
		int L, R;
		cin >> L >> R;
		ans1[i] = S1[R - 1] - S1[L - 2];
		ans2[i] = S2[R - 1] - S2[L - 2];
	}
	rep(i, Q) {
		cout << ans1[i] << " " << ans2[i] << endl;
	}
	
	return 0;
}