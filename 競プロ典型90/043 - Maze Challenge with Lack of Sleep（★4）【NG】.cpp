#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

const int MAX = 1000;

struct pos {
	int row;
	int col;
};

struct state {
	pos position;
	int dir;
};

int H, W;
pos start, target;
int mp[MAX + 2][MAX + 2];
int cnt[MAX + 2][MAX + 2][4];

int d_row[4] = { 0,1,0,-1 };
int d_col[4] = { 1,0,-1,0 };

void solve() {

	rep(i, H + 2) {
		rep(j, W + 2) {
			rep(k, 4) {
				cnt[i][j][k] = INF;
			}
		}
	}

	deque<state> bfs;
	rep(i, 4) {
		cnt[start.row][start.col][i] = 0;
		bfs.push_back({ { start.row,start.col },i });
	}

	while (!bfs.empty()) {
		state current = bfs.front();
		bfs.pop_front();

		rep(i, 4) {
			pos next;
			next.row = current.position.row + d_row[i];
			next.col = current.position.col + d_col[i];
			int cost = cnt[current.position.row][current.position.col][current.dir];
			if (i != current.dir) {
				cost++;
			}
			if (mp[next.row][next.col] == 1 && cnt[next.row][next.col][i] > cost) {
				cnt[next.row][next.col][i] = cost;
				if (current.dir != i) {
					bfs.push_back({ { next.row,next.col },i });
				}
				else {
					bfs.push_front({ { next.row,next.col },i });
				}
			}
		} 
        /*
		rep(i, H) {
			rep(j, W) {
				printf("{");
				rep(k, 4) {
					if (cnt[i + 1][j + 1][k] == INF) {
						printf("-1 ");
					}else {
						printf("%02lld ", cnt[i + 1][j + 1][k]);
					}
				}
				printf("} ");
			}
			printf("\n");
		}
		printf("===============================================\n");
        */
	}

	int ans = INF;
	rep(i, 4) {
		chmin(ans, cnt[target.row][target.col][i]);
	}

	cout << ans << endl;

	return;
}


signed main() {

	cin >> H >> W;
	cin >> start.row >> start.col;
	cin >> target.row >> target.col;

	rep(i, H) {
		rep(j, W) {
			char inputChar;
			cin >> inputChar;
			if (inputChar == '.') mp[i + 1][j + 1] = 1;
		}
	}
	solve();
	return 0;
}
