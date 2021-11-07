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
int N,Q;
int A[1000000];
int K[1000000];

signed main(){
    cin >> N >> Q;

    vector<int> before_count;
    int before_num[1000000];
    rep(i,N){
        cin>>A[i];
        if(A[i]-1 == A[i-1]) {
            before_num[i] = before_num[i-1];
        }else{
            before_num[i] = A[i] - 1;
        }
        before_count.push_back(A[i] - (i+1));
        //cout << before_num[i] << endl;
        //cout << "---" << endl;
    };

    //cout << "====================================================" << endl;
    rep(i,Q){
        cin>>K[i];

        // 2分探索
        vector<int>::iterator position;
        position = lower_bound(before_count.begin(), before_count.end(), K[i]);
        int idx_lower = distance(before_count.begin(), position);

        //cout << idx_lower << endl;
        if(idx_lower <= (N-1)){
            //cout << "before_num:" << before_num[idx_lower] << endl;
            //cout << "before_count:" << before_count[idx_lower] << endl;
            //cout << "K[i]:" << K[i] << endl;
            cout << before_num[idx_lower] - (before_count[idx_lower]-K[i]) << endl;
        }else{
            //cout << "A[N-1]+1:" << A[N-1]+1 << endl;
            //cout << "before_count:" << before_count[N-1] << endl;
            //cout << "K[i]:" << K[i] << endl;
            cout << (A[N-1]+1) + (K[i]-before_count[N-1]-1) << endl;
        }
        //cout << "-----------------------------" << endl;
    };
     
    return 0;
}