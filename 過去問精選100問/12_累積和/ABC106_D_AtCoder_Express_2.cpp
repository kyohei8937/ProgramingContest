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
// https://atcoder.jp/contests/abc106/tasks/abc106_d
// https://tutuz.hateblo.jp/entry/2018/08/19/064525

int N,M,Q;
int L[200000],R[200000];
int p[100000],q[100000];

int mat[510][510];
int sum[510][510];

void solve(){
	rep(i,M){
		mat[L[i]][R[i]]++;
	}
	
	rep(i,N+1){
		rep(j,N+1){
			sum[i][j] = mat[i][j];
			if(j-1>=0) sum[i][j] += sum[i][j-1];
			if(i-1>=0) sum[i][j] += sum[i-1][j];
			if(i-1>=0 && j-1 >=0) sum[i][j] -= sum[i-1][j-1];
		}
	}

	/*
	rep(i,N+1){
		rep(j,N+1){printf("%02lld ",mat[i][j]);}
		printf("\n");
	}
	rep(i,N+1){
		rep(j,N+1){printf("%02lld ",sum[i][j]);}
		printf("\n");
	}
	*/

	rep(i,Q){
		cout << sum[q[i]][q[i]] - sum[p[i]-1][q[i]] - sum[q[i]][p[i]-1] + sum[p[i]-1][p[i]-1] << endl;
	}
}

signed main(){
    cin >> N >> M >> Q;
	rep(i,M){cin >> L[i] >> R[i];}
	rep(i,Q){cin >> p[i] >> q[i];}
    solve();
    return 0;
}