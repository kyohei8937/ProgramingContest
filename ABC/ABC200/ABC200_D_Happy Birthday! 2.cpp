//https://atcoder.jp/contests/abc200/tasks/abc200_d
//https://atcoder.jp/contests/abc200/editorial/1246
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// タイプ定義
typedef long long llong;
// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

llong N, A[200000];
llong result;

void output(vector<llong> &a){
  cout << a.size();
  for(auto &nx : a){
    cout << ' ' << nx;
  }
  cout << '\n';
}

int main()
{
    cin >> N;
    rep(i,N){
        cin >> A[i];
    }

    // 鳩ノ巣原理により
    //「201 個の数列を、含まれる要素の総和を200で割った余りという200個のグループに分けるとき、 2個以上の数列を含んだグループが少なくとも 1つ以上存在する」
    // と考えられる。Nが8以上なら255通り探索されるので、必ず答えが存在する。
    N = min((int)N,8);

    // bit全探索
    vector<llong> hash[200];
    memset(hash,0,sizeof(llong)*200);
    for (llong bit = 1; bit < (1<<N); bit++) {
        llong sum = 0;
        vector<llong> S;
        rep(i,N) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                sum = sum + A[i];
                S.push_back(i+1);
            }
        }
        if(hash[sum%200].size() == 0){
            hash[sum % 200] = S;
        }else{
            cout << "Yes" << endl;
            output(hash[sum % 200]);
            output(S);
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}