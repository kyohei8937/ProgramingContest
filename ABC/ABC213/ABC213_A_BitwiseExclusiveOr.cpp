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

int A,B;
string bin_A,bin_B;

string to_binString(unsigned int val){
    if( !val ) {
        return string("0");
    }
    string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}

void solve(){

    bin_A = to_binString(A);
    bin_B = to_binString(B);

    while( bin_A.size() < 8){
        bin_A.insert(bin_A.begin(), '0');
    }
    while( bin_B.size() < 8){
        bin_B.insert(bin_B.begin(), '0');
    }
    /*
    cout << bin_A << endl;
    cout << bin_B << endl;
    */
    int ans = 0;
    rep(i,8){
        if(bin_A.at(i) != bin_B.at(i)){
            ans += pow(2,7-i);
        }
    }
    cout << ans << endl;
    return;
}

signed main(){
    cin >> A >> B;
    solve();
    return 0;
}