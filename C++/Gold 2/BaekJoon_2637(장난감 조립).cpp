#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M;
int part[101][101];
int ans[101];
bool isMiddle[101];
bool isVis[101];

void Input(){
    cin>>N>>M;
    for(int i = 0; i<M; i++){
        int idx, ppart, num;
        cin>>idx>>ppart>>num;
        part[idx][ppart] = num;
        isMiddle[idx] = true;
    }
}

void addNum(int idx, int now,int add){
    for(int i = 1; i<=N; i++){
        if(isMiddle[i]) continue;
        part[idx][i] += part[now][i]*add;
    }
}

void DFS(int idx){
    isVis[idx] = true;
    for(int i = 1; i<=N; i++){
        int add = part[idx][i];
        if(add == 0 || !isMiddle[i]) continue;
        if(isMiddle[i] && !isVis[i]){
            DFS(i);
            part[idx][i] = 0;
        }
        addNum(idx, i, add);
    }
}

void Print(){
    for(int i = 1; i<N; i++){
        if(isMiddle[i]) continue;
        cout<<i<<' '<<part[N][i]<<endl;
    }
}

int main(){
    FAST;
    Input();
    DFS(N);
    Print();
}
