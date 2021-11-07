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

int N,P,Q;
int A[N_MAX];

void solve(){

    int ans = 0;
    rep(i,N-4){
        rep2(j,i+1,N-3){
            rep2(k,j+1,N-2){
                rep2(l,k+1,N-1){
                    rep2(m,l+1,N){
                        if(A[i] * A[j] %P * A[k] %P * A[l] %P * A[m] %P == Q){
                            //printf("%lld %lld %lld %lld %lld\n",i,j,k,l,m);
                            ans++;
                        } 
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

signed main(){
    cin >> N >> P >> Q;
    rep(i,N){
        cin >> A[i];
    }
    solve();
    return 0;
}