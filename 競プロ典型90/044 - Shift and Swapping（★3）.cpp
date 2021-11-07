#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

#define N_MAX (200000)
#define Q_MAX (200000)

int N,Q;
int T[Q_MAX],X[Q_MAX],Y[Q_MAX];
deque<int> ringBuff;

signed main(){
    cin >> N >> Q;
    rep(i,N){
        int A;
        cin>>A;
        ringBuff.push_back(A);
    }

    rep(i,Q){
        cin>>T[i] >> X[i] >> Y[i];
    }

    rep(i,Q){
        int t = T[i],x = X[i]-1,y = Y[i]-1;

        if(t==1){
            int tmp = ringBuff[x];
            ringBuff[x] = ringBuff[y];
            ringBuff[y] = tmp;
        }else if(t==2){
            int backNum = ringBuff.back();
            ringBuff.pop_back();
            ringBuff.push_front(backNum);
        }else{
            cout << ringBuff[x] << endl;
        }
        /*
        rep(j,ringBuff.size()){
            cout << ringBuff[j] << " ";
        }
        cout << endl;
        */
    }
    return 0;
}