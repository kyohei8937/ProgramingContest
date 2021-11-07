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

int N, L, K;
int A[100001];

bool isCheck(int inValue){
    int cnt = 0;
    int before = 0;
    rep(i,1,N+1){
        if(A[i]-before >= inValue && L - A[i] >= inValue){
            cnt++;
            before = A[i];
        }        
    }
    if(cnt >= K) {
        return true;
    }
    return false;
}

void solve() {
    // 二分探索
    int left = -1, right = L+1;
    while(right - left > 1){
        int mid = left + (right - left) / 2;
        if(!isCheck(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << left << endl;
}

signed main() {
	cin >> N >> L >> K;
	rep(i, 1,N+1) {
		cin >> A[i];
	}
	solve();
	return 0;
}