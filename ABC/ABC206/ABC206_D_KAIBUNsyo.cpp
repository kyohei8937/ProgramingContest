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

const int N_MAX = 2 * 100000;
const int A_MAX = 2 * 100000;

int N;
int A[N_MAX];

vector<int> G[N_MAX];

signed main() {
	cin >> N;
	rep(i, N) {
		cin >> A[i];
	}

	for (int i = 0; i < (N / 2); i++) {
		if (A[i] != A[N - 1 - i]) {
			G[A[i]].push_back(A[N - 1 - i]);
			G[A[N - 1 - i]].push_back(A[i]);
		}
	}

	bool isSearched[A_MAX] = { false };

	int sum = 0;
	rep(i, A_MAX) {
		if (isSearched[i]) {
			continue;
		}
		rep(j, G[i].size()) {

			stack<int> dfs_stack;

			// 開始点設定
			dfs_stack.push(i);
			isSearched[i] = true;

			while (!dfs_stack.empty()) {
				int current = dfs_stack.top();
				dfs_stack.pop();

				rep(k, G[current].size()) {
					int next = G[current][k];
					if (!isSearched[next]) {
						isSearched[next] = true;
						sum++;
						dfs_stack.push(next);
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}