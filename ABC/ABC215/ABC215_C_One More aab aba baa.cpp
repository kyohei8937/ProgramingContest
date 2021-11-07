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

string S;
int K;
vector<int> arrayS;

void solve(){

    rep(i,S.size()){
        int a = S[i];
        arrayS.push_back(a);
    }
    sort(ALL(arrayS));

    int count = 1;
    do {
        if(count == K){
            for (int i = 0; i < arrayS.size(); i++) {
                printf("%c",arrayS[i]);
            }
            std::cout << std::endl;
        }
        count++;
    }while (next_permutation(ALL(arrayS)));    


    return;
}

signed main(){
    cin >> S >> K;
    solve();
    return 0;
}