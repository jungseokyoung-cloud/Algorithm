#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int arr[1000000];
int N;

void Print(){
    for(int i = 0; i<N; i++) cout<<arr[i]<<' ';
    cout<<endl;
}

int Find_Fivo(int st, int en){ // 램덤하게 피보값 찾는 경우(3값중 중앙값)
    
    int mid = (st + en)/2;
    if (mid == st) return st;
    
    if(arr[st] <= arr[mid]){ // st mid
        if (arr[mid] <= arr[en]) return mid; // st mid en
        else if(arr[st] >= arr[en]) return st; // en st mid
        else return en; // st mid en  st en mid  st
    }
    else if(arr[st] >= arr[en]) return st;
    else if(arr[mid] >= arr[en]) return mid;
    else return en;
}

int Quick(int st, int en){
    int fivoIdx = Find_Fivo(st, en);
    swap(arr[st], arr[fivoIdx]);
    int fivo = arr[st];

    int rft = en;
    int lft = st + 1;
    
    while(rft >= lft){
        while(lft <= en && arr[lft] < fivo) lft++;
        while(st <= rft && arr[rft] > fivo) rft--;

        if(lft < rft)  swap(arr[lft], arr[rft]);
    }
    swap(arr[rft], arr[st]);
    return rft;
}

void quick_sort(int st, int en){
    if(st >= en) return;

    int fivoIdx = Quick(st, en);

    quick_sort(st, fivoIdx - 1);
    quick_sort(fivoIdx + 1, en);
    
}



int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    quick_sort(0, N-1);
    Print();
}
