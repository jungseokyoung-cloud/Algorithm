#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,H,ans=INT_MAX;
int ladder[31][11];
bool Check_ladder(){
    for(int i=1; i<=N; i++){
        int com=i;
        for(int j=1; j<=H; j++){
            if(ladder[j][com]!=0)
                com=ladder[j][com];
        }
        if(com!=i) return false;
    }
    return true;
}
void Add_ladder(int idx,int cnt){
    if(cnt>3) return;
    if(Check_ladder()){
        ans=min(ans, cnt);
        return;
    }
    for(int i=idx; i<N; i++)
    {
        for(int j=1; j<=H; j++){
            if(ladder[j][i]==0 && ladder[j][i+1]==0){
                ladder[j][i]=i+1;
                ladder[j][i+1]=i;
                Add_ladder(i,cnt+1);
                ladder[j][i]=0;
                ladder[j][i+1]=0;
            }
        }
    }
}
int main(){
    FAST;
    cin>>N>>M>>H;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        ladder[a][b]=b+1;
        ladder[a][b+1]=b;
    }
    Add_ladder(1,0);
    if(ans==INT_MAX)
        cout<<"-1"<<'\n';
    else
        cout<<ans<<'\n';
}
