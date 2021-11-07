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

int N, Q;
int mp[100001];

vector<vector<int>> myArray;
vector<vector<int>> ansList;

signed main() {
    cin >> N >> Q;
    rep(i, N + 1) {
        mp[i] = -1;
    }

    rep(loopCount, Q) {
        int q, x, y;
        cin >> q;
        if (q == 1 || q == 2) {
            cin >> x >> y;
        }
        else {
            cin >> x;
        }

        if (q == 1) {
            // どちらも初めて
            if (mp[x] == -1 && mp[y] == -1) {
                vector<int> newArray;
                newArray.push_back(x);
                newArray.push_back(y);
                myArray.push_back(newArray);
                mp[x] = myArray.size();
                mp[y] = myArray.size();
                continue;
            }

            // xだけ初めての場合、yにxを連結
            else if (mp[x] == -1) {
                myArray[mp[y] - 1].push_back(x);
                mp[x] = mp[y];
                continue;
            }

            // yだけ初めての場合、xにyを連結
            else if (mp[y] == -1) {
                myArray[mp[x] - 1].push_back(y);
                mp[y] = mp[x];
                continue;
            }
            // 両方既出の場合、xがいる配列とyがいる配列を結合
            else {
                int front = mp[x] - 1;
                int back = mp[y] - 1;
                myArray[front].insert(myArray[front].end(), myArray[back].begin(), myArray[back].end()); // 連結
                rep(i, myArray[back].size()) {
                    int oldY = myArray[back][i];
                    myArray[back][i] = -1;
                    mp[oldY] = mp[x];
                }
                continue;
            }
        }

        else if (q == 2) {
            int arrayNo = mp[x] - 1;
            std::vector<int>::iterator itr;
            myArray[arrayNo];
            const int wanted = x;
            itr = find(myArray[arrayNo].begin(), myArray[arrayNo].end(), wanted);
            const int wanted_index = distance(myArray[arrayNo].begin(), itr);

            vector<int> newArray;
            int newArrayNo = myArray.size() + 1;
            for(int i = wanted_index +1; i < myArray[arrayNo].size(); i++){
                mp[myArray[arrayNo][i]] = newArrayNo;
                newArray.push_back(myArray[arrayNo][i]);
            }
            myArray[arrayNo].erase(myArray[arrayNo].begin() + wanted_index, myArray[arrayNo].end());
            myArray.push_back(newArray);
        }

        else {
            ansList.push_back(myArray[mp[x] - 1]);
        }
    }

    rep(i, ansList.size()) {
        cout << ansList[i].size();
        rep(j, ansList[i].size()) {
            cout << " " << ansList[i][j];
        }
        cout << endl;
    }
    return 0;
}