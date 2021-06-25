#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M;
vector<int> death_name(1000);
int deathNote[1000][1000];

int Solve(int idx, int len){
    if(idx == N) return 0;
    else if(deathNote[idx][len] != -1) return deathNote[idx][len];
    
    deathNote[idx][len] = (M - len +1)*(M - len +1) + Solve(idx+1, death_name[idx]+1);
    
    if(len + death_name[idx] <= M)
        deathNote[idx][len] = min(deathNote[idx][len], Solve(idx+1, len + death_name[idx] +1));
    return deathNote[idx][len];
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>death_name[i];
    memset(deathNote, -1, sizeof(deathNote));
    cout<<Solve(1, death_name[0] +1)<<'\n';
}
