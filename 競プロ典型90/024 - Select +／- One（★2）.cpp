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

int N,K;
int A[1000],B[1000];

void solve(){
    int diff_sum = 0;
    rep(i,N){
        diff_sum += abs(A[i]-B[i]);
    }
    if(diff_sum > K){
        cout << "No" << endl;
    }else{
        if((K-diff_sum)%2 == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

signed main(){
    cin >> N >> K;
    rep(i,N){cin >> A[i];}
    rep(i,N){cin >> B[i];}
    solve();
    return 0;
}