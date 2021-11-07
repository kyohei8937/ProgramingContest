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

vector<pair<pair<int, int>, int>> cityList;
vector<pair<int, pair<int, int>>> cityIDList;

void solve() {
    sort(ALL(cityList));

    int cityNo = 1;

    cityIDList.push_back(make_pair(cityList[0].second, make_pair(cityList[0].first.first, 1)));

    rep2(i, 1, M) {
        // 県が変わった。
        if (cityList[i].first.first != cityList[i - 1].first.first) {
            cityNo = 1;
        }
        else {
            cityNo++;
        }
        cityIDList.push_back(make_pair(cityList[i].second, make_pair(cityList[i].first.first, cityNo)));
    }

    sort(ALL(cityIDList));
    rep(i, M) {
        printf("%06lld%06lld\n", cityIDList[i].second.first, cityIDList[i].second.second);
    }

    return;
}

signed main() {
    cin >> N >> M;
    rep(i, M) {
        pair<int, int> city;
        cin >> city.first >> city.second;
        cityList.push_back(make_pair(city, i));
    }
    solve();
    return 0;
}