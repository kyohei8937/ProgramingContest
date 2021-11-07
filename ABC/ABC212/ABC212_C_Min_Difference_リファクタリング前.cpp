#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}

//============================================================================
//ここまでテンプレ
//============================================================================

int N,M;
vector<pair<int,int>> Array;

void solve(){
    sort(ALL(Array));

    int ans = INF;
    int currentA = 0;
    int currentB = 0;
    int flag = 0;

    // 最初
    if(Array[0].second==0){
        currentA = Array[0].first;
        flag = 0;
    }else{
        currentB = Array[0].first;
        flag = 1;
    }

    rep2(i,1,M+N){

        // A選択中で、今回もA
        if(Array[i].second == 0 && flag == 0){
            // Aを更新
            currentA = Array[i].first;
        }

        // A選択中で、今回はB
        if(Array[i].second == 1 && flag == 0){
            // Bを更新
            currentB = Array[i].first;
            // 差を作成
            int diff = currentB - currentA;
            chmin(ans,diff);
            flag = 1;
        }

        // B選択中で、今回もB
        if(Array[i].second == 1 && flag == 1){
            // Bを更新
            currentB = Array[i].first;
        }

        // B選択中で、今回はA
        if(Array[i].second == 0 && flag == 1){
            // Aを更新
            currentA = Array[i].first;
            // 差を作成
            int diff = currentA - currentB;
            chmin(ans,diff);
            flag = 0;
        }
    }
    cout << ans << endl;
    return;
}

signed main(){
    cin >> N >> M;
    rep(i,N){
        int a;
        cin >> a;
        Array.push_back(make_pair(a,0));
    }
    rep(i,M){
        int b;
        cin >> b;
        Array.push_back(make_pair(b,1));
    }

    solve();
    return 0;
}