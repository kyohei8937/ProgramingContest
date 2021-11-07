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

string N;
int K;
void solve() {
	if (N == "0") {
		cout << 0 << endl;
		return;
	}
	rep(loop, K) {
		// 10進数に変換
		unsigned int value = 0;
		rep(i, N.size()) {
			unsigned int num = N[i] - '0';
			unsigned int keisu = 1;
			rep(j, N.size() - 1 - i) {
				keisu = keisu * 8;
			}
			value += num * keisu;
		}
		//cout << "10:" << value << endl;

		// 9進数に変換
		string nine = "";
		unsigned int org = value;
		for (int i = 20; i >= 0; i--) {
			unsigned int keisu = 1;
			rep(j, i) {
				keisu = keisu * 9;
			}

			if (org < keisu) {
				continue;
			}

			char c[2];
			c[0] = value / keisu + '0';
			c[1] = '\0';
			// 8の場合は5に変換
			if (c[0] == '8') c[0] = '5';
			nine.append(c);
			value = value % keisu;
		}
		N = nine;
		//cout << "9:" << N << endl;
	}
	cout << N << endl;
}

signed main() {
	cin >> N >> K;
	solve();
	return 0;
}