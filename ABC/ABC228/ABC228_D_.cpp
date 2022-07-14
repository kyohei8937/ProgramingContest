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

#define N 1048576
int Q;
int A[N];

bool isUsed[N];

set<int> mySet;

void solve() {
    memset(A, -1, sizeof(int) * N);
    vector<int> ansList;
    rep(i, Q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            int h = x;
            int start = h % N;

            // 使用済みかどうか確認
            set<int>::iterator it = mySet.find(start);
            // 未使用
            if (it != mySet.end()) {
                A[start] = x;
                mySet.erase(start);
            }
            else {
                set<int>::iterator it2 = mySet.upper_bound(start);
                if (it2 == mySet.end()) {
                    it2 = mySet.upper_bound(-1);
                }
                start = *(it2);
                A[start] = x;
                mySet.erase(start);
            }
            //cout << start << endl;
        }
        else {
            ansList.push_back(A[x % N]);
        }
    }

    rep(i, ansList.size()) {
        cout << ansList[i] << endl;
    }
    return;
}

signed main() {
    cin >> Q;
    rep(i, N) {
        mySet.insert(i);
    }
    solve();
    return 0;
}