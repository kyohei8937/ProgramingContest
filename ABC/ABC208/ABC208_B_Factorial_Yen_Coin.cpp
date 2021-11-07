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

int P;
const int coins[10] = {3628800,362880,40320,5040,720,120,24,6,2,1};

void solve(){
    int sum = 0;
    rep(i,10){
        if(coins[i] <= P){
            sum += P / coins[i];
            P = P % coins[i];
        }
    }
    cout << sum << endl;
}

signed main(){
    cin >> P;
    solve();
    return 0;
}