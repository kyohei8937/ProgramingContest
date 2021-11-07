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
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=ja

int N;
vector<int> edgeList[100];

signed main() {
	cin >> N;
	rep(i, N) {
		int u, k;
		cin >> u >> k;
		rep(i, k) {
			int pos;
			cin >> pos;
			edgeList[u - 1].push_back(pos - 1);
		}
	}

	stack<int> stack_graph;
	int time_start[100], time_end[100];
	memset(time_start, 0, sizeof(int) * 100);
	memset(time_end, 0, sizeof(int) * 100);
	int current_time = 0;
	rep(j, N) {
		if (time_start[j] != 0) {
			continue;
		}
        current_time++;
		time_start[j] = current_time;
		stack_graph.push(j);
		while (!stack_graph.empty()) {
			current_time++;
			int top = stack_graph.top();

			bool isHit = false;
			rep(i, edgeList[top].size()) {
				if (time_start[edgeList[top][i]] == 0) {
					time_start[edgeList[top][i]] = current_time;
					stack_graph.push(edgeList[top][i]);
					isHit = true;
					break;
				}
			}
			if (!isHit) {
				time_end[top] = current_time;
				stack_graph.pop();
			}
			/*
			rep(i, N) {
				cout << i + 1 << " " << time_start[i] << " " << time_end[i] << endl;
			}
			cout << "----------------------------" << endl;	
            */
		}
	}

	rep(i, N) {
		cout << i + 1 << " " << time_start[i] << " " << time_end[i] << endl;
	}

	return 0;
}