#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//int ans[501][501];
int matrix[501][2];
int ans[501][501]; // i ~ j 까지 곱한 값중 최소값 !
int N;

int Solve(int s, int e){
    if(ans[s][e] != -1) return ans[s][e];
    
    if(s == e) return 0;
    
    ans[s][e] = INT_MAX;
    
    for(int i = s; i<e; i++){
        ans[s][e] = min(ans[s][e], Solve(s, i) + Solve(i+1, e) + matrix[s][0]*matrix[i][1]*matrix[e][1]);
    }
    return ans[s][e];
}

int main(){
    FAST;
    cin>>N;
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i<=N; i++) cin>>matrix[i][0]>>matrix[i][1];
    cout<<Solve(1, N)<<'\n';
}
