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
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
char S[1000][1000];
char T[1000][1000];
void solve() {
    bool ans = false;
    rep(loop, 4) {
        // 回転する。
        if (loop > 0) {
            int layer;
            for (layer = 0; layer < N / 2; ++layer) {
                int first = layer;
                int last = N - 1 - layer;
                for (int i = first; i < last; i++) {
                    int j = last - i + first;
                    char tmp = S[first + 250][i + 250];
                    S[first + 250][i + 250] = S[j + 250][first + 250];
                    S[j + 250][first + 250] = S[last + 250][j + 250];
                    S[last + 250][j + 250] = S[i + 250][last + 250];
                    S[i + 250][last + 250] = tmp;
                }
            }
        }

        // 一番最初に出てくる#の位置を探す
        int s_first_i = 0;
        int s_first_j = 0;
        rep(i, N) {
            rep(j, N) {
                if (S[i + 250][j + 250] == '#') {
                    s_first_i = i;
                    s_first_j = j;
                    break;
                }
            }
        }
        int t_first_i = 0;
        int t_first_j = 0;
        rep(i, N) {
            rep(j, N) {
                if (T[i + 250][j + 250] == '#') {
                    t_first_i = i;
                    t_first_j = j;
                    break;
                }
            }
        }

        int offset_i = t_first_i - s_first_i;
        int offset_j = t_first_j - s_first_j;
        bool isMatch = true;
        rep(i, N) {
            rep(j, N) {
                if (S[i + 250][j + 250] != T[i + 250 + offset_i][j + 250 + offset_j]) {
                    isMatch = false;
                    break;
                }
            }
            if (!isMatch) {
                break;
            }
        }
        if (isMatch) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }


    return;
}

signed main() {
    cin >> N;
    memset(S, '.', 1000000);
    memset(T, '.', 1000000);
    int count_s = 0,count_t = 0;
    rep(i, N) {
        rep(j, N) {
            cin >> S[i + 250][j + 250];
            if(S[i + 250][j + 250] == '#'){
                count_s++;
            }
        }
    }
    rep(i, N) {
        rep(j, N) {
            cin >> T[i + 250][j + 250];
            if(T[i + 250][j + 250] == '#'){
                count_t++;
            }
        }
    }

    if(count_s != count_t){
        cout << "No" << endl;
    }else{
        solve();
    }
    return 0;
}