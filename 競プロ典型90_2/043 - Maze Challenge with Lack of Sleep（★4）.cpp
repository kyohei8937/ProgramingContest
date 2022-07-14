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
template<class T> inline bool ChMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool ChMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// ...中央値
template <typename T> T Median(std::vector<T>& c) { size_t n = c.size() / 2; std::nth_element(c.begin(), c.begin() + n, c.end()); return c[n]; }
// ...べき乗のmodで割った余り
int ModPow(int a, int n, int mod) { int res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }return res; }
// ...最大公約数
int GCD(int a, int b) { if (b == 0) return a; else return GCD(b, a % b); }
// ...最小公倍数
int LCM(int a, int b) { return a * b / GCD(a, b); }

//============================================================================
//ここまでテンプレ
//============================================================================
int H, W;
int rs, cs, rt, ct;
int S[1002][1002];
//vector<int> A,B;

#ifndef RANDOM_CHECK

int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };


void solve() {

    queue<pair<pair<int, int>, int>> bfs;
    pair<int, int> src_pos = make_pair(rs, cs);
    pair<int, int> tar_pos = make_pair(rt, ct);

    bfs.push(make_pair(src_pos, -1));

    int ans = INF;
    while (!bfs.empty()) {
        pair<pair<int, int>, int> cur = bfs.front();
        bfs.pop();

        int curCnt = S[cur.first.first][cur.first.second];
        bool isGoal = false;
        rep(dir, 4) {
            pair<int, int> nxtPos = cur.first;
            nxtPos.first += dir_r[dir];
            nxtPos.second += dir_c[dir];
            // 壁の場合はスキップ
            if (S[nxtPos.first][nxtPos.second] == -1) {
                continue;
            }

            int nxtCnt = curCnt;
            if (dir != cur.second) {
                nxtCnt++;
            }

            // ゴール到達
            if (nxtPos == tar_pos) {
                isGoal = true;
                ChMin(ans, nxtCnt);
                continue;
            }

            if ((S[nxtPos.first][nxtPos.second] == 0) || 
                (nxtCnt <= S[nxtPos.first][nxtPos.second])) {
                bfs.push(make_pair(nxtPos, dir));
                S[nxtPos.first][nxtPos.second] = nxtCnt;
            }
        }
        if (isGoal) break;
    }
    cout << ans-1 << endl;
    return;
}

signed main() {
    cin >> H >> W >> rs >> cs >> rt >> ct;
    rep(i, 1002) {
        rep(j, 1002) {
            S[i][j] = -1;
        }
    }
    rep(i, H) {
        rep(j, W) {
            char c;
            cin >> c;
            if (c == '.') {
                S[i + 1][j + 1] = 0;
            }
        }
    }
    solve();
    return 0;
}
#else // RANDOM_CHECK
//============================================================================
//ここからランダムチェッカー用
//============================================================================
int solve_fast() {
    return 0;
}
// ここに愚直法を書く
int solve_Jury() {
    return 0;
}

void random_generate() {
    // ここでランダム生成をする。例えば次のような感じ。
    // for (int i = 0; i < N; i++) A[i] = rand() % 10 + 1;
    // for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
}
signed main() {
    srand((unsigned int)time(NULL));
    for (int t = 1; t <= 1000; t++) {
        //N = 8; // 入力データのサイズ（適当に決めて良い）
        //A.resize(N), B.resize(N); // プログラムで使用する変数
        random_generate();
        int J1 = solve_fast();
        int J2 = solve_Jury();
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            // テストケースを出力
            return;
        }
    }
    cout << "OK!" << endl;
    return 0;
}
#endif // RANDOM_CHECK