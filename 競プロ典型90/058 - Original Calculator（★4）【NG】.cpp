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

#define N_MAX 99999

int N,K;

bool vis[N_MAX+1];

int calc_y(int x){
    int y = 0;
    while(x > 0){
        y += x % 10;
        x = x / 10;
    }
    //cout << y << endl;
    return y;
}

void solve(){
    int x,y,z;
    x = N;

    // サイクルに入るタイミングを求める
    int cycleStart = 0;
    do{
        vis[x] = true;
        x = (x+calc_y(x))%100000;
        cycleStart++;

        // サイクル確認中に終了した場合は出力
        if(cycleStart == K){
            cout << x << endl;
            return;
        }
    }while(vis[x] == false);

    // 周期を求める
    int org = x;
    int cycleCount = 0;
    do{
        x = (x+calc_y(x))%100000; 
        cycleCount++;
        // サイクル確認中に終了した場合は出力
        if(cycleStart+cycleCount == K){
            cout << x << endl;
            return;
        }

    }while(x != org);

    K = (K-cycleStart) % cycleCount;

    /*
    cout << "x:" << x << endl;
    cout << "cycleStart:" << cycleStart << endl;
    cout << "cycleCount:" << cycleCount << endl;
    cout << "K:" << K << endl;
    */
    rep(i,K){
        x = (x+calc_y(x))%100000;    
    }
    cout << x << endl;
    return;
}

void solve2(){
    int x,y,z;
    x = N;
    rep(i,K){
        y = x/10000 + x/1000 + x/100 + x/10 + x%10;
        x = (x+y)%100000;
    }
    cout << x << endl;
    return;
}

signed main(){
    cin >> N >> K;
    //solve2();
    solve();
    return 0;
}