#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int A[100];
int N;

void printArray(){
    printf("%d",A[0]);
    for(int i = 1; i < N; i++) {
        printf(" %d",A[i]);
    }
    printf("\n");
}

void solve(){
    int v;
    for(int i = 1; i < N; i++) {
        v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray();
    }
}

int main()
{
    // 整数の入力
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    printArray();
    solve();
    return 0;
}


