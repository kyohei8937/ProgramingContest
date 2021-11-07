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

int N,M;
int A[100][100];
int sum[100][100];

signed main(){
    cin >> N >> M;

    rep(i,N){
        rep(j,M){
            cin >> A[i][j];
        }   
    }

    rep(i,N){
        rep(j,M-1){
            rep(k,j+1,M){
                if(A[i][j] < A[i][k]){
                    sum[j][k] = sum[j][k] + A[i][k];
                }else{
                    sum[j][k] = sum[j][k] + A[i][j];
                }
            }
        }   
    }

    int max = 0;
    rep(i,N){
        rep(j,M){
            chmax(max,sum[i][j]);
        }   
    }

    cout << max << endl;

    return 0;
}