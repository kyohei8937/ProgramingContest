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

#define Q_MAX 100000

int Q;
int t[Q_MAX],x[Q_MAX];

deque<int> deq;

void solve(){

    rep(i,Q){
        if(t[i]==1){

            deq.push_front(x[i]);

        }else if(t[i]==2){

            deq.push_back(x[i]);

        }else{

            cout << deq[x[i]-1] << endl;

        }
    }

}

signed main(){
    cin >> Q;
    rep(i,Q) cin >> t[i] >> x[i];
    solve();
    return 0;
}