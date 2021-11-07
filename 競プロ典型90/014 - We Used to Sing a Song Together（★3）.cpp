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
vector<int> A,B;
void solve(){

}

signed main(){
    cin >> N;
	A.resize(N);
	B.resize(N);
	rep(i,N){cin >> A[i];}
	rep(i,N){cin >> B[i];}
	sort(ALL(A));
	sort(ALL(B));
	int sum = 0;
	rep(i,N){
		sum += abs(A[i]-B[i]);
	}
	cout << sum <<endl;
    return 0;
}