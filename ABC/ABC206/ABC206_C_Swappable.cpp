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

const int N_MAX = 3 * 100000;
const int A_MAX = 1000000000;
int N;
vector<int> A;

void solve() {
	int sum_minus = 0;
	int current_count = 0;
	int current_num = 0;
	rep(i, N) {
		if (current_num != A[i]) {
			if (current_count >= 2) {
				sum_minus += (current_count * (current_count - 1) / 2);
				//printf("current_num:%lld,current_count:%lld\n", current_num, current_count);
			}
			current_num = A[i];
			current_count = 1;
		}
		else {
			current_count++;
			if (i == N - 1) {
				sum_minus += (current_count * (current_count - 1) / 2);
				//printf("current_num:%lld,current_count:%lld\n", current_num, current_count);
			}
		}
	}
	int ans = (N*(N - 1) / 2) - sum_minus;
	cout << ans << endl;
}


signed main() {
	cin >> N;
	rep(i, N) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	sort(ALL(A));
	solve();
	return 0;
}