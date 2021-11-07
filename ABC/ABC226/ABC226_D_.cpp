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

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return(b);
    }
    else
    {
        return(gcd(b, a % b));
    }
}

int N;
vector<pair<int, int>> points;

vector<pair<int, int>> mahouArray;

void solve() {
    rep(i, N) {
        rep(j,N) {
            if (i == j) continue;
            pair<int, int> tmpMahou;
            tmpMahou.first = points[j].first - points[i].first;
            tmpMahou.second = points[j].second - points[i].second;
            // 最大公約数を求める
            if (tmpMahou.first != 0 && tmpMahou.second != 0) {
                int gcdNum = gcd(abs(tmpMahou.first), abs(tmpMahou.second));
                tmpMahou.first = tmpMahou.first / gcdNum;
                tmpMahou.second = tmpMahou.second / gcdNum;
            }
            else if (tmpMahou.first == 0) {
                if (tmpMahou.second > 0) {
                    tmpMahou.second = 1;
                }
                else {
                    tmpMahou.second = -1;
                }
            }
            else if (tmpMahou.second == 0) {
                if (tmpMahou.first > 0) {
                    tmpMahou.first = 1;
                }
                else {
                    tmpMahou.first = -1;
                }
            }
            mahouArray.push_back(tmpMahou);
        }
    }

    sort(ALL(mahouArray));
    mahouArray.erase(unique(mahouArray.begin(), mahouArray.end()), mahouArray.end());
    cout << mahouArray.size() << endl;
    return;
}

signed main() {
    cin >> N;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    solve();
    return 0;
}