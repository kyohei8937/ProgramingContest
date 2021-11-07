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

int N;

void output(int A, int B, string S) {

	if (A>0) {
		output(A - 1, B, S + "(");
	}
	if (B>A) {
		output(A, B - 1,S + ")");
	}
	if (A == 0 && B == 0) {
		cout << S << endl;
	}
}

void solve() {
	if (N % 2 == 0) {
		output(N / 2, N / 2, "");
	}
}

signed main() {
	cin >> N;
	solve();
	return 0;
}