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
// https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t4/review/2009-yo-t4-review.html

const int MAX = 90;
int m,n;
int ice_map[MAX+2][MAX+2];
int max_depth;

int dx[4] = {-1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1};

void dfs(int y, int x, int depth){
	chmax(max_depth,depth);
	rep(i,4){
		int new_y = y+dy[i];
		int new_x = x+dx[i];
		if(ice_map[new_y][new_x] == 1){
			ice_map[new_y][new_x] = 0;
			dfs(new_y,new_x,depth+1);
			ice_map[new_y][new_x] = 1;
		}
	}
}

signed main() {

	// 入力
	cin >> m >> n;
	rep(i,n){rep(j,m){cin >> ice_map[i+1][j+1];}}

	rep(i,n){
		rep(j,m){
			if(ice_map[i+1][j+1]==1){
				int depth = 0;
				dfs(i+1,j+1,depth);
			}
		}
	}
	cout << max_depth << endl;
	return 0;
}