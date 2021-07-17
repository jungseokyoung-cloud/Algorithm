#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 1000001
int N;
int ans[MMAX][2];

void Print(){
    int res = N;
    while(1){
        cout<<res<<' ';
        if(res == 1)  break;
        
        res = ans[res][1];
    }
    cout<<'\n';
}

void Solve(){
    ans[1][1] = 1;
    for(int i = 2; i<=N; i++){
        ans[i][0] = ans[i-1][0] + 1;
        ans[i][1] = i-1;
        
        if(i % 2 == 0 && ans[i/2][0] + 1 < ans[i][0]){
            ans[i][0] = ans[i/2][0] + 1;
            ans[i][1] = i/2;
        }
        if(i % 3 == 0 && ans[i/3][0] +1 < ans[i][0]){
            ans[i][0] = ans[i/3][0] + 1;
            ans[i][1] = i/3;
        }
    }
}

int main(){
    cin>>N;
    
    Solve();
    cout<<ans[N][0]<<'\n';
    Print();
}
