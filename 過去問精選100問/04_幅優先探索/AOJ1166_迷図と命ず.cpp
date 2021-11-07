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
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int W,H; 
int meiro[MAX][MAX];
bool isWall[MAX][MAX][4];

void print_Wall(){
	rep(i,H){
		rep(j,W){
			printf("{");
			rep(k,4){
				printf("%d ",isWall[i][j][k]);
			}
			printf("}");		
		}
		printf("\n");
	}
	printf("===============================\n");
}

void print_meiro(){
	rep(i,H){
		rep(j,W){		
			printf("%02lld  ",meiro[i][j]);	
		}
		printf("\n");
	}
	printf("===============================\n");
}


int solve_smallest(pos inStart, pos inGoal){
	queue<pos> bfs_queue;
	bfs_queue.push(inStart);
	meiro[inStart.y][inStart.x] = 1;
	int smallest = 0;
	while(!bfs_queue.empty()){
		pos current = bfs_queue.front();
		bfs_queue.pop();
		int step = meiro[current.y][current.x];

		if(pos_equal(&current,&inGoal)){
			smallest = step;
			break;
		}

		rep(i,4){
			// 次の方向が壁じゃない場合
			if(isWall[current.y][current.x][i] == false){
				pos next;
				next.y = current.y + dy[i];
				next.x = current.x + dx[i];
				if(meiro[next.y][next.x] == 0){
					meiro[next.y][next.x] = step+1;
					bfs_queue.push(next);
				}
			}
		}
		//print_meiro();
	}
	return smallest;
}

signed main() {
	vector<int> anserList;
	while(true){

		// 初期化
		memset(meiro,0,sizeof(int)*MAX*MAX);
		memset(isWall,0,sizeof(bool)*MAX*MAX*4);

		cin >> W >> H;
		if(W==0 && H==0){
			break;
		}
		// 外周に壁を作る
		rep(i,H){
			isWall[i][0][3] = true;
			isWall[i][W-1][1] = true;
		}
		rep(j,W){
			isWall[0][j][0] = true;
			isWall[H-1][j][2] = true;
		}

		rep(i,H*2-1){
			if(i%2==0){
				rep(j,W-1){
					int value;
					cin >> value;
					if(value == 1){
						isWall[i/2][j][1] = true;
						isWall[i/2][j+1][3] = true;
					}
				}			
			}else{
				rep(j,W){
					int value;
					cin >> value;
					if(value == 1){
						isWall[i/2][j][2] = true;
						isWall[i/2+1][j][0] = true;
					}
				}		
			}
		}
		int ans = solve_smallest({0,0},{H-1,W-1});
		anserList.push_back(ans);
	}

	//print_Wall();
	rep(i,anserList.size()) cout << anserList[i] << endl;

	return 0;
}