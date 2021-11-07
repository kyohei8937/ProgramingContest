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
int A[3000];
int S[3001];


void solve(){
    S[0] = 0;
    int max_sum[3000] = {0};
    rep(i,1,N+1){
        S[i] = S[i-1] + A[i-1];        
        rep(j,i){
            if((i-j-1)>=0){
                chmax(max_sum[j], S[i] - S[i-j-1]);
            }
            //cout << "j:" << j << ", max:" << max_sum[j] << endl;
        }
    }

    rep(i,N){
        cout << max_sum[i] << endl;
    }

}

signed main(){
    cin >> N;
    rep(i,N){cin >> A[i];}
    solve();
    return 0;
}