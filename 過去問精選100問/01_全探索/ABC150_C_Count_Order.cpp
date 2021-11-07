#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

int N;
int P[8],Q[8];

signed main() {
    cin >> N;

    int a_num=0,b_num=0;
    rep (i,N) {
        cin >> P[i];
        a_num = a_num + pow(10,N-i-1)*P[i];
    }
    rep (i,N) {
        cin >> Q[i];
        b_num = b_num + pow(10,N-i-1)*Q[i];
    }
    int P[8] = {1, 2, 3, 4, 5, 6, 7,8};

    int a_pos=0,b_pos=0;
    int count = 1;
    do {
        int current_num = 0;
        rep (i,N) {
            current_num = current_num + pow(10,N-i-1)*P[i];
        }
        if(current_num == a_num){
            a_pos = count;
        }
        if(current_num == b_num) {
            b_pos = count;
        }
        count++;
    } while(next_permutation(P, P + N));
    cout << abs(a_pos-b_pos) << endl;
    return 0;
}