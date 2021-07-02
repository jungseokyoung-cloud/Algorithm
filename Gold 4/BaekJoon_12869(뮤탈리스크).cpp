#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int hp[61][61][61];
int N;
int arr[3];

void MaekZero(int (&next)[3]){
    for(int i = 0; i<3; i++){
        if(next[i] < 0) next[i] = 0;
    }
}

int Solve(int now[3]){
    if(now[0] <= 0 && now[1] <= 0 && now[2] <= 0){
        return 0;
    }
    
    if(hp[now[0]][now[1]][now[2]]!=-1) return hp[now[0]][now[1]][now[2]];
    
    int next[3];
    
    hp[now[0]][now[1]][now[2]] = INT_MAX;
    
    for(int i= 0; i<3; i++){
        if(now[i] <= 0) continue;
        next[i] = now[i]-9;
        for(int j = 0; j<3; j++){
            if(i == j) continue;
            next[j] = now[j]-3;
            next[3-i-j] = now[3-i-j] - 1;
            MaekZero(next);


            hp[now[0]][now[1]][now[2]] = min(hp[now[0]][now[1]][now[2]],Solve(next) + 1);
        }
    }
    return hp[now[0]][now[1]][now[2]];
}

int main(){
    FAST;
    memset(hp, -1, sizeof(hp));
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    
    int ans = Solve(arr);
    cout<<ans<<'\n';
}
