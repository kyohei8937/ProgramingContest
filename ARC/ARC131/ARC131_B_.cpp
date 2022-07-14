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
# define _printf(fmt, ...)  printf(fmt, __VA_ARGS__);                   
#else
# define _printf(fmt, ...)
#endif

// 便利関数
// ...最小値・最大値交換
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int modpow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }
// ...最大公約数
int gcd(int a, int b) { if (b == 0) return a; else return gcd(b, a % b); }
// ...最小公倍数
int lcm(int a, int b) { return a * b / gcd(a, b); }

//============================================================================
//ここまでテンプレ
//============================================================================

int H, W;
int c[702][702];

vector<pair<int, int>> mawari4, mawari3, mawari2, mawari1, mawari0;

int dir_i[4] = { -1,0,1,0 };
int dir_j[4] = { 0,1,0,-1 };

void solve() {

    rep2(i, 1, H + 1) {
        rep2(j, 1, W + 1) {
            if(c[i][j] == 0){
                int numOfSuji = 0;
                rep(dir, 4) {
                    if (c[i + dir_i[dir]][j + dir_j[dir]] != 0) {
                        numOfSuji++;
                    }
                }
                if (numOfSuji == 4) {
                    mawari4.push_back(make_pair(i, j));
                }
                else if (numOfSuji == 3) {
                    mawari3.push_back(make_pair(i, j));
                }
                else if (numOfSuji == 2) {
                    mawari2.push_back(make_pair(i, j));
                }
                else if (numOfSuji == 1) {
                    mawari1.push_back(make_pair(i, j));
                }
                else {
                    mawari0.push_back(make_pair(i, j));
                }
            }
        }
    }

    rep(loop, mawari4.size()) {
        int i = mawari4[loop].first;
        int j = mawari4[loop].second;
        bool isUsed[5] = { false };
        rep(dir, 4) {
            int suji = c[i + dir_i[dir]][j + dir_j[dir]];
            if (suji != 0 && suji != 6) {
                isUsed[suji - 1] = true;
            }
        }
        rep(k, 5) {
            if (!isUsed[k]) {
                c[i][j] = k + 1;
                break;
            }
        }
    }

    rep(loop, mawari3.size()) {
        int i = mawari3[loop].first;
        int j = mawari3[loop].second;
        bool isUsed[5] = { false };
        rep(dir, 4) {
            int suji = c[i + dir_i[dir]][j + dir_j[dir]];
            if (suji != 0 && suji != 6) {
                isUsed[suji - 1] = true;
            }
        }
        rep(k, 5) {
            if (!isUsed[k]) {
                c[i][j] = k + 1;
                break;
            }
        }
    }

    rep(loop, mawari2.size()) {
        int i = mawari2[loop].first;
        int j = mawari2[loop].second;
        bool isUsed[5] = { false };
        rep(dir, 4) {
            int suji = c[i + dir_i[dir]][j + dir_j[dir]];
            if (suji != 0 && suji != 6) {
                isUsed[suji - 1] = true;
            }
        }
        rep(k, 5) {
            if (!isUsed[k]) {
                c[i][j] = k + 1;
                break;
            }
        }
    }

    rep(loop, mawari1.size()) {
        int i = mawari1[loop].first;
        int j = mawari1[loop].second;
        bool isUsed[5] = { false };
        rep(dir, 4) {
            int suji = c[i + dir_i[dir]][j + dir_j[dir]];
            if (suji != 0 && suji != 6) {
                isUsed[suji - 1] = true;
            }
        }
        rep(k, 5) {
            if (!isUsed[k]) {
                c[i][j] = k + 1;
                break;
            }
        }
    }

    rep(loop, mawari0.size()) {
        int i = mawari0[loop].first;
        int j = mawari0[loop].second;
        bool isUsed[5] = { false };
        rep(dir, 4) {
            int suji = c[i + dir_i[dir]][j + dir_j[dir]];
            if (suji != 0 && suji != 6) {
                isUsed[suji - 1] = true;
            }
        }
        rep(k, 5) {
            if (!isUsed[k]) {
                c[i][j] = k + 1;
                break;
            }
        }
    }

    rep2(i, 1, H + 1) {
        rep2(j, 1, W + 1) {
            cout << c[i][j];
        }
        cout << endl;
    }


    return;
}

signed main() {
    cin >> H >> W;
    // 初期化
    rep(i, 702) {
        rep(j, 702) {
            c[i][j] = 6;
        }
    }
    rep(i, H) {
        rep(j, W) {
            char moji;
            cin >> moji;
            if (moji == '.') {
                c[i + 1][j + 1] = 0;
            }
            else {
                c[i + 1][j + 1] = moji - '0';
            }
        }
    }
    solve();
    return 0;
}