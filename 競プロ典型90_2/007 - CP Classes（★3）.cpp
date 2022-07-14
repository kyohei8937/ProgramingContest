#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

//#define RANDOM_CHECK
#define DEBUG
#ifdef DEBUG
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c){size_t n = c.size() / 2;std::nth_element(c.begin(), c.begin() + n, c.end());return c[n];}
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) {int res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
// ...最大公約数
int gcd(int a, int b) {if (b==0) return a;else return gcd(b, a%b);}
// ...最小公倍数
int lcm(int a, int b) {return a * b / gcd(a, b);}

void random_checker();

//============================================================================
//ここまでテンプレ
//============================================================================

int N, Q;
vector<int> A,B;

void solve(){

    sort(ALL(A));

    rep(i,Q) {

        decltype(A)::iterator itr = lower_bound(ALL(A),B[i]);
        size_t pos = distance(A.begin(), itr);
        if(pos ==0) {
            cout << abs(A[0] - B[i]) << endl; 
        }else if(pos == N) {
            cout << abs(A[N-1] - B[i]) << endl; 
        }else {
            cout << min(abs(A[pos] - B[i]), abs(A[pos-1] - B[i])) << endl;
        }
    }

    return;
}

signed main(){
#ifndef RANDOM_CHECK
    cin >> N;
    A.resize(N);
    rep(i,N){
        cin >> A[i];
    }
    cin >> Q;
    B.resize(Q);
    rep(i,Q){
        cin >> B[i];
    }
    solve();

#else
    random_checker();
#endif

    return 0;
}

//============================================================================
//ここからランダムチェッカー用
//============================================================================
string solve_fast(){
    sort(ALL(A));
    string ret = "";
    rep(i,Q) {
        decltype(A)::iterator itr = lower_bound(ALL(A),B[i]);
        size_t pos = distance(A.begin(), itr);
        int ans = 0;
        if(pos ==0) {
            ans = abs(A[0] - B[i]);
        }else if(pos == N) {
            ans = abs(A[N-1] - B[i]);
        }else {
            ans = min(abs(A[pos] - B[i]), abs(A[pos-1] - B[i]));
        }
        //cout << ans << endl;
        ostringstream oss;
        oss << ans;
        ret = ret + ";" + oss.str().c_str();
    }
    return ret;
}
// ここに愚直法を書く
string solve_Jury(){
    string ret = "";
    rep(i,Q) {
        int ans = INF;
        rep(j,N) {
            int diff = abs(B[i] - A[j]);
            if(diff < ans) {
                ans = diff;
            }
        }
        ostringstream oss;
        oss << ans;
        ret = ret + ";" + oss.str().c_str();
    }
    return ret;
}

void random_generate() {
    // ここでランダム生成をする。例えば次のような感じ。
    for (int i = 0; i < N; i++) A[i] = rand() % 1000;
    for (int i = 0; i < Q; i++) B[i] = rand() % 1000;
}
void random_checker() {
    srand((unsigned int) time(NULL));
    for (int t = 1; t <= 1000; t++) {
        N = 10;
        Q = 10;
        A.resize(N), B.resize(Q); // プログラムで使用する変数
        random_generate();
        string J1 = solve_fast();
        string J2 = solve_Jury();
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            // テストケースを出力
            for (int i = 0; i < N; i++) {
                cout << A[i] << ",";
            }
            cout << endl;
            for (int i = 0; i < Q; i++) {
                cout << B[i] << ",";
            }
            cout << endl;
            return;
        }
    }
    cout << "OK!" << endl;
    return;
}