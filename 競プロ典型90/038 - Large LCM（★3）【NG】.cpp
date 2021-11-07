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
int gcd(int a, int b) { if (b == 0) return a; else return gcd(b, a%b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

//============================================================================
//ここまでテンプレ
//============================================================================

#define MAX 1000000000000000000
int A, B;

void solve() {
	int r = B / gcd(A,B);
	if(r > MAX /A){
		cout << "Large" << endl;
	}else{
		cout << r*A << endl;
	}
}


signed main() {
	cin >> A >> B;
	solve();
	return 0;
}