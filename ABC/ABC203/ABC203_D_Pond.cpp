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

llong N,K;
llong A[801][801];

struct block{
    pair<llong,llong> pos;
    llong value;
};
vector<block> blocks;

int main()
{
    cin >> N >> K;
    memset(A,-1,sizeof(llong)*801*801);
    rep(i,N){
        rep(j,N) {
            cin >> A[i+1][j+1];
            block tmp = {make_pair(i+1,j+1),A[i+1][j+1]};
            blocks.push_back(tmp);
        }
    }

    sort(blocks.begin(),blocks.end());

    rep(now,N*N) {
        // k*kを作る
        llong current_i = blocks[now].pos.first;
        llong current_j = blocks[now].pos.second;
        rep(i,K){
            rep(j,K){
                
            }
        }
    }

    return 0;
}