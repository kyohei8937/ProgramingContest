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
// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e

const int MAX = 100;

struct pos{
	int y;
	int x;
};
bool pos_equal(struct pos* a, struct pos *b) {
	return a->y == b->y && a->x == b->x;
}

int W,H; 
int buildings[MAX+2][MAX+2];
int ans;

void print_map(){
	rep(i,H+2){
		rep(j,W+2){
			if(buildings[i][j] == -1){
				printf("□");
			}else if(buildings[i][j] == 0){
				printf("○");
			}else if(buildings[i][j] == 1){
				printf("■");
			}else{
				printf("★");
			}
		}
		printf("\n");
	}
	printf("===============================\n");
}

pos GetNextPos(int inDir, pos inPos){
	pos next;
	switch(inDir){
		case 0:	// 右上
			next.y = inPos.y - 1;
			if(inPos.y%2==0 ) {
				next.x = inPos.x;
			}else if(inPos.y%2==1) {
				next.x = inPos.x + 1;
			}
			break;
		case 1: // 右
			next.y = inPos.y;
			next.x = inPos.x + 1;
			break;
		case 2: // 右下
			next.y = inPos.y + 1;
			if(inPos.y%2==0 ) {
				next.x = inPos.x;
			}else if(inPos.y%2==1) {
				next.x = inPos.x + 1;
			}
			break;
		case 3: // 左下
			next.y = inPos.y + 1;
			if(inPos.y%2==0 ) {
				next.x = inPos.x - 1;
			}else if(inPos.y%2==1) {
				next.x = inPos.x;
			}
			break;
		case 4: // 左
			next.y = inPos.y;
			next.x = inPos.x - 1;
			break;
		case 5: // 左上
			next.y = inPos.y - 1;
			if(inPos.y%2==0 ) {
				next.x = inPos.x - 1;
			}else if(inPos.y%2==1) {
				next.x = inPos.x;
			}
			break;
		default:
			break;
	}
	// 範囲外の場合、現在値を返す
	if(next.x < 0 || next.y < 0 || next.x >= (MAX+2) || next.y >= (MAX+2)){
		next = inPos;
	}
	return next;
}

void solve(pos inStart){
	queue<pos> bfs_queue;
	bfs_queue.push(inStart);
	buildings[inStart.y][inStart.x] = 2;
	while(!bfs_queue.empty()){
		pos current = bfs_queue.front();
		bfs_queue.pop();
		rep(i,6){
			pos next = GetNextPos(i,current);
			if(!pos_equal(&next,&current)){
				if(buildings[next.y][next.x] == 0){
					buildings[next.y][next.x] = 2;
					bfs_queue.push(next);
				}
				if(buildings[next.y][next.x] == -1){
					ans++;
				}				
			}
		}
	}
}

signed main() {
	cin >> W >> H;
	rep(i,H){
		rep(j,W){
			cin >> buildings[i+1][j+1];
		}
	}

	// 番兵流し込み
	queue<pos> bfs_queue;
	bfs_queue.push({0,0});
	buildings[0][0] = -1;
	while(!bfs_queue.empty()){
		pos current = bfs_queue.front();
		bfs_queue.pop();
		rep(i,6){
			pos next = GetNextPos(i,current);
			if(!pos_equal(&next,&current) && buildings[next.y][next.x] == 0){
				buildings[next.y][next.x] = -1;
				bfs_queue.push(next);
			}
		}
	}
	//print_map();
	rep(i,H){
		rep(j,W){
			if(buildings[i+1][j+1] == 1){
				solve({i+1,j+1});
			}
		}
	}

	cout << ans << endl;

	return 0;
}