#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_CARD 36

struct card{
    char mark;
    int value;
};

void swap(card* C,int i,int j){
    card tmp = C[i];
    C[i] = C[j];
    C[j] = tmp;
}

void printCardArray(card* C, int N){
    cout << C[0].mark << C[0].value;
    for(int i = 1; i < N; i++) {
        cout << " " << C[i].mark << C[i].value;
    }
    printf("\n");
}

// バブルソート
void BubbleSort(card* C,int N){
    int flag = 1;
    int i = 0;
    while(flag) {
        flag = 0;
        for(int j = N-1; j >= i + 1; j --) {
            if(C[j].value < C[j-1].value) {
                swap(C,j,j-1);
                flag = 1;
            }
        }
        i++;
    }
}

// 選択ソート
void SelectionSort(card* C, int N){
    bool isStable = true;
    for(int i = 0; i < N; i++) {
        int minj = i;
        for(int j = i; j < N; j++) {
            if(C[j].value < C[minj].value) {
                minj = j;
            }
        }
        swap(C,i,minj);
    }
}

int main()
{
    // 整数の入力
    int N;
    cin >> N;

    card cardArray[36];
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        cardArray[i].mark = tmp[0];
        cardArray[i].value = tmp[1] - '0';
    }
    // バブルソート
    card bubbleCardArray[MAX_CARD];
    memcpy(bubbleCardArray, cardArray, sizeof(card)*MAX_CARD);
    BubbleSort(bubbleCardArray, N);
    printCardArray(bubbleCardArray, N);

    // バブルソートは常に安定
    cout << "Stable" << endl;

    // 選択ソート
    card selectionCardArray[MAX_CARD];
    memcpy(selectionCardArray, cardArray, sizeof(card)*MAX_CARD);
    SelectionSort(selectionCardArray, N);
    printCardArray(selectionCardArray, N);

    // バブルソート結果と一致していないなら不安定
    bool isStable = true;
    for(int i = 0; i < N; i++) {
        if((bubbleCardArray[i].mark != selectionCardArray[i].mark) || 
           (bubbleCardArray[i].value != selectionCardArray[i].value)) {
               isStable = false;
               break;
        }
    }
    if(isStable){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    return 0;
}