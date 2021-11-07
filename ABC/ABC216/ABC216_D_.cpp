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

int N, M;

queue<int> pole[200000];
map<int, int> mp;
int ans = 0;
void rensa(int poleNo, int nextNum) {
    if (mp[nextNum] == 0) {
        mp[nextNum] = poleNo + 1;
    }
    else {
        int pairPoleNo = mp[nextNum]-1;
        mp[nextNum] = 0;

        pole[pairPoleNo].pop();
        pole[poleNo].pop();
        
        if (!pole[pairPoleNo].empty()) {
            rensa(pairPoleNo, pole[pairPoleNo].front());
        }
        if (!pole[poleNo].empty()) {
            rensa(poleNo, pole[poleNo].front());
        }
        ans++;
    }
}

void solve() {
    rep(i, M) {
        rensa(i, pole[i].front());
    }
    if (ans == N) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return;
}

signed main() {
    cin >> N >> M;
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            pole[i].push(a);
        }
    }
    solve();
    return 0;
}