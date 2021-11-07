#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define N_MAX 100000

int N;
vector<int> A,B,C;
int A_hist[46],B_hist[46],C_hist[46];

void solve(){

    rep(i,N){
        A_hist[A[i] % 46]++;
        B_hist[B[i] % 46]++;
        C_hist[C[i] % 46]++;
    }

    int sum = 0;
    rep(i,46){
        rep(j,46){
            rep(k,46){
                if((i+j+k)%46==0 && A_hist[i] > 0 && B_hist[j] > 0 && C_hist[k] > 0){
                    //printf("%lld %lld %lld\n",A_hist[i] , B_hist[j] , C_hist[k]);
                    sum = sum + (A_hist[i] * B_hist[j] * C_hist[k]);
                }
            }
        }
    }
    cout << sum << endl;
}

signed main(){
    cin >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    rep(i,N){
        cin >> C[i];
    }
    solve();
    return 0;
}