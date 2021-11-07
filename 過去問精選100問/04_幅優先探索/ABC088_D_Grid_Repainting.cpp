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
// https://atcoder.jp/contests/abc088/tasks/abc088_d

const int MAX = 50;

struct pos{
	int y;
	int x;
};
bool pos_equal(struct pos* a, struct pos *b) {
	return a->y == b->y && a->x == b->x;
}

int W,H; 
int meiro[MAX+2][MAX+2];
int ans;

void print_map(){
	rep(i,H+2){
		rep(j,W+2){
			printf("%02lld ",meiro[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int solve_smallest(pos inStart, pos inGoal){
	queue<pos> bfs_queue;
	bfs_queue.push(inStart);
	meiro[inStart.y][inStart.x] = 1;
	int smallest = -1;
	while(!bfs_queue.empty()){
		pos current = bfs_queue.front();
		bfs_queue.pop();
		int step = meiro[current.y][current.x];

		if(pos_equal(&current,&inGoal)){
			smallest = step;
			break;
		}

		rep(i,4){
			pos next;
			next.y = current.y + dy[i];
			next.x = current.x + dx[i];
			if(meiro[next.y][next.x] == 0){
				meiro[next.y][next.x] = step+1;
				bfs_queue.push(next);
			}
		}
		//print_map();
	}
	return smallest;
}

signed main() {
	cin >> H >> W;
	memset(meiro,-1,sizeof(int)*(MAX+2)*(MAX+2));
	int num_of_white = 0;
	rep(i,H){
		rep(j,W){
			char moji;
			cin >> moji;
			if(moji == '.'){
				meiro[i+1][j+1] = 0;
				num_of_white++;
			}else{
				meiro[i+1][j+1] = -1;
			}
		}
	}

	//solve({1,1},{H,W});
	//print_map();
	int smallest = solve_smallest({1,1},{H,W});
	int ans;
	if(smallest != -1){
		ans = num_of_white - smallest;
	}else{
		ans = -1;
	}
	cout << ans << endl;

	return 0;
}