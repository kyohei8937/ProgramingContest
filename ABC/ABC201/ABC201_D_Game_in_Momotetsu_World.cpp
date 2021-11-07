#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <unistd.h>
using namespace std;
// タイプ定義
typedef long long llong;
// マクロ
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(llong i=llong(a);i<llong(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int H,W,A[2002][2002];


void printmap(){
    rep(i,H) {
        rep(j,W){
            printf("%02d ", A[i+1][j+1]);
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

int main()
{
    memset(A,0,sizeof(int)*2002*2002);
    cin >> H >> W;
    rep(i,H) {
        rep(j,W){
            char tmp;
            cin >> tmp;
            if(tmp=='-'){
                A[i+1][j+1] = -1;
            }else{
                A[i+1][j+1] = 1;
            }
        }
    } 

    pair<int,int> currentPos = {1,1};
    int score[2] = {0,0};
    int moveCount = 0;
    while(true){
        moveCount++;
        printmap();
        bool isEnableMode = false;
        vector<pair<int,int>> priority={{0,0},{0,0},{0,0},{0,0}};
        rep(i,2) {
            A[currentPos.first][currentPos.second] = 0;
            pair<int,int> nextPos;
            if(i==0) {
                nextPos = {currentPos.first,currentPos.second+1};
            }else if(i==1) {
                nextPos = {currentPos.first+1,currentPos.second};
            }
            // 通過不可なら次確認
            if(A[nextPos.first][nextPos.second] == 0){                
                priority[i] = {0,i}; 
                continue;
            }

           
            if(A[nextPos.first][nextPos.second] == 1){
                 // 次が+で、次いける場所に+がなければ最優先
                if( A[nextPos.first][nextPos.second+1] != 1 &&
                    A[nextPos.first+1][nextPos.second] != 1)
                {
                    priority[i] = {4,i};
                    isEnableMode = true;          
                    continue;
                }
                // 次が+で、次行ける場所に+があれば第二候補
                else
                {
                    priority[i] = {3,i};
                    isEnableMode = true;          
                    continue;
                }
            }

            
            else{
                // 次が-で、次いける場所に+がなければ第三候補
                if( A[nextPos.first][nextPos.second+1] != 1 &&
                    A[nextPos.first+1][nextPos.second] != 1)
                {
                    priority[i] = {2,i};
                    isEnableMode = true;
                    continue;
                }
                // 次が-で、次いける場所に+があれば第四候補
                else
                {
                    priority[i] = {1,i};
                    isEnableMode = true;          
                    continue;
                }
            }
        }
        // 移動できない状態なら終了
        if(isEnableMode == false){
            break;
        }
        // 移動できる状態なら一番優先度が高い方向に移動
        else{
            std::sort(priority.begin(), priority.end());
            pair<int,int> nextPos;
            if(priority[3].second == 0){
                nextPos = {currentPos.first,currentPos.second+1};
            }else if(priority[3].second == 1){
                nextPos = {currentPos.first+1,currentPos.second};
            }
            if(A[nextPos.first][nextPos.second] == 1){
                score[moveCount % 2]++;
            }else{
                score[moveCount % 2]--;
                
            } 
            currentPos = nextPos; 
        }
    }
    if(score[0] < score[1]) {
        cout << "Takahashi" << endl;
    }else if(score[0] > score[1]){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }
    return 0;
}