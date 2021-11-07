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

int H,W;
int P[8][10000];

// R[i][j] : 行パターンがiのとき、j列目の数字がなにであるか
int R[255][10000];

void solve(){

    // 全行bit全探索
    int ans = 0;
    for (int bit = 0; bit < (1<<H); ++bit) {
        map<int,int> mp;
        rep(j,W){
            int num = 0,count = 0;
            for (int i = 0; i < H; ++i) {
                if (bit & (1<<i)) { // 列挙に i が含まれるか
                    if(num==0){
                        num = P[i][j];
                        count++;
                    }else{
                        if(P[i][j] != num){
                            num = 0;
                            break;
                        }else{
                            count++;
                        }
                    }
                }
            }
            if(num!=0){
                R[bit][j] = num;
                mp[R[bit][j]] += count;
                //printf("[%lld %lld]num:%lld, count:%lld\n", bit,j,num,count);
                chmax(ans,mp[R[bit][j]]);
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    cin >> H >> W;
    rep(i,H){
        rep(j,W){
            cin >> P[i][j];
        }
    }
    solve();
    return 0;
}