#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N;
int Min[3];
int Max[3];
int copy_min[3];
int copy_max[3];
int dis[]={-1,0,1};
int Find_Min_Max(bool mmax, int idx){
    int num=INT_MAX;
    if(mmax) num=0;
    for(int i=0; i<3; i++){
        int now=idx+dis[i];
        if(now>=3 || now<0) continue;
        if(mmax) num=max(num, Max[now]);
        else     num=min(num, Min[now]);
    }
    return num;
}
int main(){
    FAST;
    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>num;
            copy_min[j]=num+Find_Min_Max(false ,j);
            copy_max[j]=num+Find_Min_Max(true, j);
        }
        memcpy(Min, copy_min, sizeof(Min));
        memcpy(Max, copy_max, sizeof(Max));
    }
    cout<<Find_Min_Max(true, 1)<<' '<<Find_Min_Max(false, 1)<<'\n';
}
