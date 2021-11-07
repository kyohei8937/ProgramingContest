#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define N_MAX 100

int N;
int A[N_MAX][6];
int sum[N_MAX];

void solve(){

    rep(j,6){
        sum[0] = sum[0]+A[0][j];
    }
    rep2(i,1,N){
        rep(j,6){
            sum[i] += sum[i-1]* A[i][j];
            sum[i] %= MOD;
        }
    }

    cout << sum[N-1] << endl;
}

signed main(){
    cin >> N;
    rep(i,N){
        rep(j,6){
            cin >> A[i][j];
        }
    }
    solve();
    return 0;
}