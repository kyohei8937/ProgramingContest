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
#define ALL(a)  (a).begin(),(a).end()

int N;
vector<int> A;
vector<int> B;
//vector<int> C;
vector<int> D;

int main()
{
    A.reserve(1000000);
    B.reserve(1000000);
    D.reserve(1000000);

    cin >> N;
    int tmp = 0;
    rep(i,N) {
        cin >> tmp;
        A.push_back(tmp);
    }
    rep(i,N) {
        cin >> tmp;
        B.push_back(tmp);
    }
    rep(i,N) {
        cin >> tmp;
        D.push_back(B[tmp-1]);
    }
    sort(D.begin(), D.end());

    llong count = 0;
    rep(i,N){
        // 2分探索でlower境界を見つける
        auto lower_iter = lower_bound(ALL(D),A[i]);
        int lower_pos = lower_iter-D.begin();
        if(lower_pos >= N || D[lower_pos] != A[i]){
            //printf("%d is not found\n",A[i]);
            continue;
        }else{
            auto upper_iter = upper_bound(ALL(D),A[i]);
            int upper_pos = upper_iter-D.begin();
            int num = upper_pos - lower_pos;
            //printf("num:%d(%d ~ %d)\n",num, lower_pos, upper_pos-1);
            count = count + num;
        }
    }
    cout << count << endl;
    return 0;
}