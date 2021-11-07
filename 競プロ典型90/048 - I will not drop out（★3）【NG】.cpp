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

int N,K;
vector<int> score;
signed main(){
    cin >> N >> K;
    rep(i,N){
        int a,b;
        cin >> a >> b;
        score.push_back(b);
        score.push_back(a-b);
    }

    sort(ALL(score), greater<int>());
    int ans = 0;
    rep(i,K){
        ans+=score[i];
    }
    cout << ans << endl;
    return 0;
}