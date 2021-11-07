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
// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e

const int MAX = 1000;

struct pos{
	int y;
	int x;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0,-1};

int H,W,N; 
int meiro[MAX+2][MAX+2];
pos first_start;
pos cheese_pos[9];

signed main() {
	cin >> H >> W >> N;
	memset(meiro,-1,sizeof(int)*(MAX+2)*(MAX+2));
	rep(i,H){
		rep(j,W){
			char data;
			cin >> data;
			if(data == 'X'){
				meiro[i+1][j+1] = -1;
			}else{
				meiro[i+1][j+1] = 0;
				if(data >= '1' && data <= '9'){
					cheese_pos[data-'1'] = {i+1,j+1};
				}
				if(data == 'S'){
					first_start = {i+1,j+1};
				}
			}
		}
	}

	int sum_step = 0;
	rep(i,N){
		pos start,goal;
		if(i==0){
			start = first_start;
			goal = cheese_pos[i];
		}else{
			start = cheese_pos[i-1];
			goal = cheese_pos[i];
		}
		
		queue<pos> bfs_queue;
		bfs_queue.push(start);
		int meiro_copy[MAX+2][MAX+2];
		memcpy(meiro_copy,meiro,sizeof(int)*(MAX+2)*(MAX+2));
		meiro_copy[start.y][start.x] = 1;
		
		while(!bfs_queue.empty()){
			pos current = bfs_queue.front();
			bfs_queue.pop();
			int step = meiro_copy[current.y][current.x];

			// ゴール到達
			if(current.y == goal.y && current.x == goal.x) {
				sum_step = sum_step + (step-1);
				break;
			}

			rep(i,4){
				pos next;
				next.y = current.y + dy[i];
				next.x = current.x + dx[i];
				if(meiro_copy[next.y][next.x] == 0){
					meiro_copy[next.y][next.x] = step+1;
					bfs_queue.push(next);
				}
			}
			/*
			rep(i,H){
				rep(j,W){
					printf("%02lld ",meiro_copy[i+1][j+1]);
				}
				printf("\n");
			}
			printf("----------------------------\n");
			*/
		}
		//cout << sum_step << endl;
	}

	cout << sum_step << endl;
	return 0;
}