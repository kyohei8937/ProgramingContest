#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)

// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

int H,W;
int A[2000][2000];
int sumH[2000],sumW[2000];

signed main(){
    cin >> H >> W;
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
            sumW[i]+=A[i][j];
            sumH[j]+=A[i][j];
        }
    }
    rep(i,H){
        rep(j,W){
            cout << sumW[i] + sumH[j] - A[i][j];
            if(j!=W-1){
                cout << " ";
            }
        }
        cout << endl;
    }


    return 0;
}