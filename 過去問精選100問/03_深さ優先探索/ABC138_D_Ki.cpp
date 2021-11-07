#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================
// https://atcoder.jp/contests/abc138/tasks/abc138_d

const int N_MAX = 2*100000;
const int Q_MAX = 2*100000;

int N,Q;

vector<int> children[N_MAX];
int score[N_MAX];

// 再帰関数による実装
void dfs(int current, int prev){
	for(int next:children[current]){
		if(next!=prev){
			score[next] += score[current];
			dfs(next,current);
		}
	}
}

// スタックによる実装
void dfs_stack_solve(){
	stack<int> dfs_stack;
	bool isSearched[N_MAX] = {false};

	// 開始点設定
	dfs_stack.push(0);
	isSearched[0] = true;

	while(!dfs_stack.empty()){
		int current = dfs_stack.top();
		dfs_stack.pop();
		for(auto next:children[current]){
			if(!isSearched[next]){
				isSearched[next] = true;
				score[next] += score[current];
				dfs_stack.push(next);
			}
		}
	}
}

signed main() {

	// 標準入力
	cin >> N >> Q;

	int parent[N_MAX];
	memset(parent,-1,sizeof(int)*N_MAX);

	rep(i,N-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		children[a].push_back(b);
		children[b].push_back(a);
	}

	rep(i,Q){
		int p,x;
		cin >> p >> x;
		p--;
		score[p] += x;
	}

	//dfs(0,-1);
	dfs_stack_solve();

	rep(i,N){
		cout << score[i] << " ";
	 }
	 cout << endl;

	return 0;
}