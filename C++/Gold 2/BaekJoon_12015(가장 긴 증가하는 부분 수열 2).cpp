#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[1000000];
vector<int> lisDp;

int Search(int tar){
    int st = 0;
    int en = lisDp.size();
    while(st < en){
        int mid = (st + en)/2;
        if(lisDp[mid] < tar) st = mid + 1;
        else en = mid;
    }
    return en;
}

void Solve(){
    lisDp.push_back(arr[0]);
    for(int i = 1; i<N; i++){
        if(arr[i] > lisDp.back()) lisDp.push_back(arr[i]);
        else {
            int idx = Search(arr[i]);
            lisDp[idx] = arr[i];
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    Solve();
    cout<<lisDp.size()<<endl;
}
