#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int arr[] = {8,3,11,9,12,2,6,15,18,10,7,4};
int K;

int Find_Pivot(int st, int en){
    int mid = (st + en)/2;
    if(st == mid) return st;
    if(arr[st] <= arr[mid]){
        if(arr[mid] <= arr[en]) return mid;
        else if(arr[en] <= arr[st]) return st;
        else return en;
    }
    else if (arr[st] <= arr[en]) return st;
    else if(arr[en] <= arr[mid]) return mid;
    else return en;
}

int Sort(int st, int en){
    int pivotIdx = Find_Pivot(st, en);
    int lft = st+1;
    int rft = en;
    int pivot = arr[pivotIdx];
    swap(arr[st], arr[pivotIdx]);
    
    while(lft <= rft){
        while(lft <= en && arr[lft] < pivot) lft++;
        while(st <= rft && arr[rft] > pivot) rft--;
        
        if(lft < rft) swap(arr[lft], arr[rft]);
    }
    swap(arr[rft], arr[st]);
    
    
    for(int i = 0; i<12; i++) cout<<arr[i]<<' ';
    cout<<endl;
    return rft;
}

int quick_sort(int st, int en, int k){
    if(st > en) return -1;
    else if(st == en) return arr[st];
    
    int pivotIdx = Sort(st, en);

    if(pivotIdx + 1 == k) return arr[pivotIdx];
    else if(pivotIdx + 1 > K) return quick_sort(st, pivotIdx-1, k);
    else return quick_sort(pivotIdx+1, en, k);
        
    return -1;
}

int main(){
    FAST;
    cin>>K;
    cout<<quick_sort(0, 11, K)<<endl;;
}
