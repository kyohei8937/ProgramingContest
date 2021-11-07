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
// https://atcoder.jp/contests/abc007/tasks/abc007_3

const int MAX = 50;

struct pos{
	int x;
	int y;
};

int R,C;
pos start;
pos goal;
int meiro[MAX+2][MAX+2];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0,-1};

signed main() {
	cin >> R >> C;
	cin >> start.y >> start.x;
	cin >> goal.y >> goal.x;
	memset(meiro,-1,sizeof(int)*(MAX+2)*(MAX+2));

	rep(i,R){
		rep(j,C){
			char tmp;
			cin >> tmp;
			if(tmp=='#'){
				meiro[i+1][j+1] = -1;
			}else{
				meiro[i+1][j+1] = 0;
			}
		}
	}

	queue<pos> bfs_queue;
	bfs_queue.push(start);
	meiro[start.y][start.x] = 1;
	while(!bfs_queue.empty()){
		pos current = bfs_queue.front();
		bfs_queue.pop();

		int step = meiro[current.y][current.x];

		rep(i,4){
			pos next;
			next.y = current.y + dy[i];
			next.x = current.x + dx[i];
			if(next.y == goal.y && next.x == goal.x) {
				cout << step << endl;
				return 0;
			}
			if(meiro[next.y][next.x] == 0){
				meiro[next.y][next.x] = step+1;
				bfs_queue.push(next);
			}
		}
	}
	return 0;
}