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
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

int w,h;
int island_map[52][52];

void dfs(int start_i, int start_j){
	island_map[start_i][start_j] = 1;
	stack<pair<int,int>> dfs_stack;
	dfs_stack.push(make_pair(start_i,start_j));

	while(!dfs_stack.empty()){
		pair<int,int> current_pos = dfs_stack.top();
		dfs_stack.pop();

		rep(direction,8){
			pair<int,int> next_pos = current_pos;
			switch(direction){
				case 0: // 上
					next_pos.first = current_pos.first-1;
					break;
				case 1: // 右上
					next_pos.first = current_pos.first-1;
					next_pos.second = current_pos.second+1;
					break;
				case 2: // 右
					next_pos.second = current_pos.second+1;
					break;
				case 3: // 右下
					next_pos.first = current_pos.first+1;
					next_pos.second = current_pos.second+1;
					break;
				case 4: // 下
					next_pos.first = current_pos.first+1;
					break;
				case 5: // 左下
					next_pos.first = current_pos.first+1;
					next_pos.second = current_pos.second-1;
					break;
				case 6: // 左
					next_pos.second = current_pos.second-1;
					break;
				case 7: // 左上
					next_pos.first = current_pos.first-1;
					next_pos.second = current_pos.second-1;
					break;
			}
			if(island_map[next_pos.first][next_pos.second] == -1){
				island_map[next_pos.first][next_pos.second] = island_map[next_pos.first][next_pos.second] + 1;
				dfs_stack.push(make_pair(next_pos.first,next_pos.second));
			}
		}
	}

}

signed main() {
	vector<int> resultArray;
	while(true){
		cin >> w >> h;
		if(w==0 || h==0){
			break;
		}
		rep(i,1,h+1){
			rep(j,1,w+1){
				cin >> island_map[i][j];
				island_map[i][j] = -island_map[i][j];
			}
		}
		int num_island = 0;
		rep(i,1,h+1){
			rep(j,1,w+1){
				if(island_map[i][j] == -1){
					dfs(i,j);
					num_island++;
				}
			}
		}
		/*
		printf("-----------------------------------\n");
		rep(i,1,h+1){
			rep(j,1,w+1){
				printf("%02lld ",island_map[i][j]);
			}
			printf("\n");
		}
		printf("-----------------------------------\n");
		*/
		resultArray.push_back(num_island);
	}

	rep(i,resultArray.size()){
		cout << resultArray[i] << endl;
	}

	return 0;
}