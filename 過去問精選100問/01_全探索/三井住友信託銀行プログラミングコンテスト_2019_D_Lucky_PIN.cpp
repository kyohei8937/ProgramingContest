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
string S;

signed main(){
    cin >> N >> S;


    int result = 0;
    rep(i,1000){
        int num[3];
        num[0] = i / 100;
        num[1] = (i % 100) / 10;
        num[2] = (i % 100) % 10;  
        int hitCount = 0;
        rep(j,N){
            int number = S[j]-'0';
            if(number == num[hitCount]){
                if(hitCount == 2) {
                    result++;
                    break;
                }else{
                    hitCount++;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}