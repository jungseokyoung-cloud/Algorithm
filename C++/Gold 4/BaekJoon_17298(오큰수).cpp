#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1000000
int N;
int arr[MMAX];
int ans[MMAX];

void Solve(){
    stack<int> res;
    res.push(0);
    for(int i=1; i<N; i++){
        
        while(!res.empty() && arr[res.top()] < arr[i]){
            ans[res.top()] = arr[i];
            res.pop();
        }
        res.push(i);
    }
}

int main(){
    FAST;
    cin>>N;
    fill(ans, ans+N, -1);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    Solve();
    for(int i=0; i<N; i++) cout<<ans[i]<<' ';
    cout<<'\n';
}
