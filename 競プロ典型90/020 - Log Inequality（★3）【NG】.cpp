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

#define N_MAX 9000000000000000000
int a,b,c;

void solve(){
	
	double C = log2(c);
	cout << log2(b) << " " << log2(C) << endl;
	if(a < (log2(b)+log2(C))){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

}

signed main(){
    cin >> a >> b >> c;
    solve();
    return 0;
}