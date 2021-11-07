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

const int N_MAX = 2000;
int N;
int t[N_MAX];
int l[N_MAX], r[N_MAX];
signed main() {
	cin >> N;
	rep(i, N) {
		cin >> t[i] >> l[i] >> r[i];
		l[i] = l[i] * 10;
		r[i] = r[i] * 10;
		// 以上・以下に直す
		if (t[i] == 2) {
			r[i] = r[i] - 1;
		}
		else if (t[i] == 3) {
			l[i] = l[i] + 1;
		}
		else if (t[i] == 4) {
			l[i] = l[i] + 1;
			r[i] = r[i] - 1;
		}
	}

	int count = 0;
	for (int i = 0; i <N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			// 左端が範囲内
			if (l[i] <= l[j] && l[j] <= r[i]) {
				count++;
			}
			// 右端が範囲内
			else if (l[i] <= r[j] && r[j] <= r[i]) {
				count++;
			}
			// 左端が範囲内
			else if (l[j] <= l[i] && l[i] <= r[j]) {
				count++;
			}
			// 右端が範囲内
			else if (l[j] <= r[i] && r[i] <= r[j]) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}