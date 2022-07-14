#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;
const int MOD = 1000000007;

// マクロ
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG
#ifdef DEBUG
# define _PRINTF(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _PRINTF(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

string str_a, str_b;
multiset<int> a;
multiset<int> b;

bool isSwap;
void solve() {

    int loopMax = min(str_a.size(), str_b.size());

    string ans_a = "";
    string ans_b = "";
    int ketaUp = 0;
    rep(i, loopMax) {
        auto a_itr = a.end();
        a_itr--;
        int b_target = 10 - (*a_itr + ketaUp);
        auto b_itr = b.lower_bound(b_target);

        // 見つかった
        if (b_itr != b.end()) {
            // 超えてる場合は、ちょうどいいaを探す
            if (*b_itr + *a_itr > 10) {
                int a_target = 10 - (*b_itr + ketaUp);
                auto a_itr2 = a.lower_bound(a_target);
                // 見つかった
                if (a_itr2 != a.end()) {
                    //それを使う
                    ans_a = to_string(*a_itr2) + ans_a;
                    ans_b = to_string(*b_itr) + ans_b;
                    a.erase(a_itr2);
                    b.erase(b_itr);
                    ketaUp = 1;
                    continue;
                }
                // ない場合
                else {
                    ans_a = to_string(*a_itr) + ans_a;
                    ans_b = to_string(*b_itr) + ans_b;
                    a.erase(a_itr);
                    b.erase(b_itr);
                    ketaUp = 1;
                    continue;
                }
            }
            // 10ピタリの場合は採用
            else {
                ans_a = to_string(*a_itr) + ans_a;
                ans_b = to_string(*b_itr) + ans_b;
                a.erase(a_itr);
                b.erase(b_itr);
                ketaUp = 1;
                continue;
            }
        }
        // 見つからなかった場合、bの最小を使う
        else {
            ans_a = to_string(*a_itr) + ans_a;
            ans_b = to_string(*b.begin()) + ans_b;
            a.erase(a_itr);
            b.erase(b.begin());
            ketaUp = 0;
        }
    }

    while (!b.empty()) {
        auto b_itr = b.end();
        b_itr--;
        ans_b = to_string(*b_itr) + ans_b;
        b.erase(b_itr);
    }

    if(!isSwap){
        cout << ans_a << endl;
        cout << ans_b << endl;
    }else{
        cout << ans_b << endl;
        cout << ans_a << endl;
    }
    return;
}

signed main() {
    cin >> str_a >> str_b;
    if(str_a.size() > str_b.size()){
        string tmp = str_a;
        str_a = str_b;
        str_b = tmp;
        isSwap = true;
    }
    rep(i, str_a.size()) {
        a.insert(str_a[i] - '0');
    }
    rep(i, str_b.size()) {
        b.insert(str_b[i] - '0');
    }
    solve();
    return 0;
}