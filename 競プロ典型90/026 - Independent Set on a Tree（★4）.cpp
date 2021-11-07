#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep2(i,n,m) for(int i=(int)n;i<(int)m;++i)
#define ALL(x) (x).begin(),(x).end()

// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define N_MAX 100000

int N;
int A[N_MAX], B[N_MAX];

vector<vector<int>> G;

void solve() {
    // 頂点が2なら、1でOK
    if(N==2) {
        cout << "1" << endl;
        return;
    }

	G.resize(N);
	rep(i, N - 1) {
		G[A[i] - 1].push_back(B[i] - 1);
		G[B[i] - 1].push_back(A[i] - 1);
	}

	// 辺が1の頂点を探す
	int edge = -1;
	rep(i, N) {
		if (G[i].size() == 1) {
			edge = i;
			break;
		}
	}

	// その頂点から深さ有線探索を行い、深さが奇数の集合と偶数の集合を作成（いずれかの個数がN/2に達したらそれらを出力）
	stack<int> dfs;
	dfs.push(edge);
	vector<int> depth;
	depth.resize(N);
	rep(i, N) depth[i] = 0;
	depth[edge] = 1;

	vector<int> ansArray1;
	vector<int> ansArray2;
	ansArray1.push_back(edge);
	while (!dfs.empty()) {
		int cur_no = dfs.top();
		dfs.pop();
		int cur_depth = depth[cur_no];

		rep(i, G[cur_no].size()) {
			int next = G[cur_no][i];
			if (depth[next] == 0) {
				depth[next] = cur_depth + 1;
				if (depth[next] % 2 == 1) {
					ansArray1.push_back(next);
					if (ansArray1.size() == (N / 2)) {
						rep(k, ansArray1.size()) {
							cout << ansArray1[k] + 1;
							if (k != (ansArray1.size() - 1)) cout << " ";
						}
						cout << endl;
						return;
					}
				}else{
					ansArray2.push_back(next);
					if (ansArray2.size() == (N / 2)) {
						rep(k, ansArray2.size()) {
							cout << ansArray2[k] + 1;
							if (k != (ansArray2.size() - 1)) cout << " ";
						}
						cout << endl;
						return;
					}					
				}
				dfs.push(G[cur_no][i]);
			}
		}
	}
}

signed main() {
	cin >> N;
	rep(i, N - 1) { cin >> A[i] >> B[i]; }
	solve();
	return 0;
}