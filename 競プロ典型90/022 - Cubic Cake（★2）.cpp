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

int a,b,c;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

void solve(){
	int ippen = gcd(gcd(a,b),c);
	int ans = (a/ippen-1) + (b/ippen-1) + (c/ippen-1);
	cout << ans << endl;	
}

signed main(){
    cin >> a >> b >> c;
    solve();
    return 0;
}