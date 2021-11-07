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

int m,n;
vector<pair<int,int>> m_list, n_list;

signed main() {
	cin >> m;
	rep(i, m) { int x, y; cin >> x >> y; m_list.push_back(make_pair(x, y)); }
	cin >> n;
	rep(i, n) { int x, y; cin >> x >> y; n_list.push_back(make_pair(x, y)); }
	// x座標昇順でソート
	sort(m_list.begin(), m_list.end());
	sort(n_list.begin(), n_list.end());

	rep(i, m) {
		rep(j, n) {

			int x_diff = m_list[i].first - n_list[j].first;
			int y_diff = m_list[i].second - n_list[j].second;

			// マッチング
			bool isMatch = true;
			rep(k, m) {
				bool currentMatch = false;
				rep(l, n) {
					// 座標合わせながらマッチング
					if (m_list[k].first == n_list[l].first + x_diff && m_list[k].second == n_list[l].second + y_diff) {
						currentMatch = true;
						break;
					}
				}
				if (currentMatch) {
					continue;
				}
				else {
					isMatch = false;
					break;
				}
			}
			if (isMatch) {
				cout << -x_diff << " " << -y_diff << endl;
				return 0;
			}
		}
	}
	return 0;
}