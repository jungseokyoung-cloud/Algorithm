#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int arr[1000000];
int temp[1000000];
int N;

void Merge(int st, int en){
    int mid = (st + en)/2;
    int lft = st;
    int rft = mid;
    for(int i = st; i<en; i++){
        if(rft == en) temp[i] = arr[lft++];
        else if(lft == mid) temp[i] = arr[rft++];
        else if(arr[lft] > arr[rft]) temp[i] = arr[rft++];
        else temp[i] = arr[lft++];
    }
    for(int i = st; i<en; i++) arr[i] = temp[i];
}

void merge_sort(int st, int en){
    if(st + 1 >= en) return;
    
    int mid = (st + en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    
    Merge(st, en);
}

void Print(int st, int en){
    for(int i = st; i<en; i++) cout<<arr[i]<<' ';
    cout<<endl;
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    merge_sort(0, N);
    Print(0,N);
}
