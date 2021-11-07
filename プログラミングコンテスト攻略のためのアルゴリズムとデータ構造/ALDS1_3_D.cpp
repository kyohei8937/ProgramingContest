#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

//参考：https://mtdtx9.hatenablog.com/entry/2017/04/24/230941
int main()
{
    string S;
    cin >> S;

    int i = 0;
    stack<int> downPosStack;
    stack<pair<int,int>> areaStack;
    int result = 0;
    while(S[i]!='\0') {
        if(S[i] == '\\'){
            downPosStack.push(i);
        }else if(S[i] == '/' && !downPosStack.empty()){
            int nearDownPos = downPosStack.top();
            downPosStack.pop();
            int area = i - nearDownPos;
            if(areaStack.empty() || nearDownPos > areaStack.top().first) {
                areaStack.push(make_pair(nearDownPos,area));
            }
            // 結合
            else{
                pair<int,int> margedArea;
                while(!areaStack.empty() && nearDownPos < areaStack.top().first) {
                    //cout << "nearDownPos:" << nearDownPos << "areaStack.top().first:" <<areaStack.top().first << endl;
                    margedArea.first = nearDownPos;
                    margedArea.second = margedArea.second + areaStack.top().second;
                    areaStack.pop();
                }
                margedArea.second = margedArea.second + area;
                areaStack.push(margedArea);
            }
        }

        // スタックの中身出力
        /*
        cout << "S[i]:" << S[i] << endl;
        stack<int> downPosStackForOutput = downPosStack;
        cout << "stack1:";
        while(!downPosStackForOutput.empty()) {
            cout << downPosStackForOutput.top() << "," ;
            downPosStackForOutput.pop();
        }
        cout << endl;
        stack<pair<int,int>> margedAreaForOutput = areaStack;
        cout << "stack2:";
        while(!margedAreaForOutput.empty()) {
            cout << "[" << margedAreaForOutput.top().first <<"-"<< margedAreaForOutput.top().second << "]" << "," ;
            margedAreaForOutput.pop();
        }
        cout << endl << "-----------------------------" << endl;
        */

        i++;        
    }
    int sumArea = 0;
    vector<int> areaArray;
    while(!areaStack.empty()) {
        areaArray.push_back(areaStack.top().second);
        sumArea = sumArea + areaStack.top().second;
        areaStack.pop();
    }
    cout << sumArea << endl;
    cout << areaArray.size();
    for(int i = areaArray.size()-1; i >= 0; i--) {
        cout << " " << areaArray[i];
    }
    cout << endl;
    return 0;
}