#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
map<string,int> mp;

signed main() {
	cin >> N;
	rep(i, N) {
		string str;
		cin >> str;
		auto itr = mp.find(str);
		if( itr == mp.end() ) {
			mp[str] = i+1;
		}
	}
	vector<int> ans;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
		ans.push_back(itr->second);
    }
	sort(ALL(ans));

	rep(i,ans.size()){
		cout << ans[i] << endl;
	}

	return 0;
}