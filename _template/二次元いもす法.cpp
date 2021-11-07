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
// https://atcoder.jp/contests/typical90/tasks/typical90_ab
// https://github.com/E869120/kyopro_educational_90/blob/main/editorial/028.jpg

#define N_MAX 100100
#define MAP_MAX 1010

struct pos{
    int y;
    int x;
};

int N;
int mp[MAP_MAX][MAP_MAX];
pos l[N_MAX],r[N_MAX];

void solve(){
    rep(i,N){
        mp[l[i].y][l[i].x]++;
        mp[r[i].y][r[i].x]++;
        mp[l[i].y][r[i].x]--;
        mp[r[i].y][l[i].x]--;
    }
    /*
    rep(i,10){
        rep(j,10){
            printf("%02lld ",mp[i][j]);
        }
        printf("\n");
    }
    printf("==================================\n");
    */

    // x方向累積和
    rep(i,1001){
        rep2(j,1,1001){
            mp[i][j] = mp[i][j]+mp[i][j-1];
        }
    }

    // y方向累積和
    rep2(i,1,1001){
        rep(j,1001){
            mp[i][j] = mp[i][j]+mp[i-1][j];
        }
    }
    /*
    rep(i,10){
        rep(j,10){
            printf("%02lld ",mp[i][j]);
        }
        printf("\n");
    }
    printf("==================================\n");
    */

    // ヒストグラム作成
    int hist[N_MAX+1];
    rep(i,1001){
        rep(j,1001){
           if(mp[i][j] >= 1){
               hist[mp[i][j]]++;
           } 
        }
    }
    rep2(i,1,N+1){
        cout << hist[i] << endl;
    }

}

signed main(){
    cin >> N;
    rep(i,N){
        cin >> l[i].x >> l[i].y >> r[i].x >> r[i].y;       
    }

    solve();
    return 0;
}