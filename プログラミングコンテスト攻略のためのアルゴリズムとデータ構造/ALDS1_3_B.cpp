#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct process{
    string name;
    int time;
};

int main()
{
    queue<process> process_queue;
    int n=0,q=0;
    cin >> n;
    cin >> q;
    int totalTime = 0;
    for(int i =0; i < n; i++) {
        process tmpProcess;
        cin >> tmpProcess.name;
        cin >> tmpProcess.time;
        process_queue.push(tmpProcess);
    }
    // キューが空になるまで
    while(!process_queue.empty()){
        process currentProcess = process_queue.front();
        process_queue.pop();
        if(currentProcess.time > q) {
            totalTime = totalTime + q;
            currentProcess.time = currentProcess.time - q;
            process_queue.push(currentProcess);

        }else{
            totalTime = totalTime + currentProcess.time;
            cout << currentProcess.name << " " << totalTime << endl;
        }
    }
    return 0;
}