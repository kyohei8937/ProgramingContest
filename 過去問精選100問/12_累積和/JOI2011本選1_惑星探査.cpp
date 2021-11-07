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

struct pos{
    int y;
    int x;
};

int M,N,K;
int expMap[1001][1001];
pos expArea[100000][2];

int S[1001][1001][3];

void solve(){
    // 2乗累積和を求める
    rep(i,1,M+1){
        rep(j,1,N+1){
            rep(l,3){
                if(l == expMap[i][j]){
                    S[i][j][l] = S[i-1][j][l] + S[i][j-1][l] - S[i-1][j-1][l] + 1;
                }else{
                    S[i][j][l] = S[i-1][j][l] + S[i][j-1][l] - S[i-1][j-1][l];
                }
            }     
        }
    }

    // デバッグ出力
    /*
    rep(l,3){
        rep(i,1,M+1){
            rep(j,1,N+1){
                printf("%02lld ",S[i][j][l]);
            }
            printf("\n");
        }
        printf("====================\n");
    }
    */

    int ans[3] = {0};
    rep(k,K){
        pos start = expArea[k][0];
        pos end = expArea[k][1];
        rep(l,3){
            ans[l] =    S[end.y][end.x][l] - 
                        S[start.y-1][end.x][l] -
                        S[end.y][start.x-1][l] +
                        S[start.y-1][start.x-1][l];
        }         
        cout << ans[0] << " "  << ans[1] << " "  << ans[2] << endl; 
    }
}

signed main(){
    cin >> M >> N >> K;
    rep(i,M){
        string touzaiStr;
        cin >> touzaiStr;
        rep(j,touzaiStr.size()){
            if(touzaiStr[j] == 'J'){
                expMap[i+1][j+1] = 0;
            }
            else if(touzaiStr[j] == 'O'){
                expMap[i+1][j+1] = 1;
            }
            else if(touzaiStr[j] == 'I'){
                expMap[i+1][j+1] = 2;
            }
        }
    }
    rep(i,K){
        cin >> expArea[i][0].y >> expArea[i][0].x  >> expArea[i][1].y >> expArea[i][1].x;
    }
    solve();
    return 0;
}