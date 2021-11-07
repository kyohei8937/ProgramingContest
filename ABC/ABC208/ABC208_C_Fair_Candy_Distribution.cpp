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

#define N_MAX 200000

int N,K;
vector<pair<int,int>> a;
int ans[N_MAX];

void solve(){
    int base = K / N;
    // 全員に基本くばる
    rep(i,N){
        ans[i] = base;
    }

    int amari = K % N;

    // あまりをくばる
    rep(i,amari){
        ans[a[i].second]++;
    }

    rep(i,N){
        cout << ans[i] << endl;
    }

}

signed main(){
    cin >> N >> K;
    rep(i,N) {
        int temp;
        cin >> temp;
        pair<int,int> data = {temp,i};
        a.push_back(data);
    }
    sort(ALL(a));
    solve();
    return 0;
}