#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001
int inOrder[MMAX];
int FindIdx[MMAX];
vector<int> postOrder;
int N;
vector<int> tree[MMAX];

void DFS(int st, int en, int now){
    if(st >= en) return;
    if(postOrder.size() == 0) return;
    
    for(int i = 0; i<2; i++){
        if(postOrder.size() == 0) return;
        
        int target = postOrder.back();
        int idx = FindIdx[target];
        int now_idx = FindIdx[now];
        
        if(st > idx || en < idx) return;
        postOrder.pop_back();
        
        tree[now].push_back(target);
        if(now_idx < idx)   DFS(now_idx+1, en, target);
        else DFS(st, now_idx-1, target);
    }
}

void Print(int node){
    cout<<node<<' ';
    if(tree[node].size() == 0)  return;
    
    for(int i = tree[node].size()-1; i>=0; i--){
        int next = tree[node][i];
        Print(next);
    }
}

void Solve(){
    int root = postOrder.back();
    postOrder.pop_back();
    DFS(1,N, root);
    Print(root);
    cout<<'\n';
}


int main(){
    FAST;
    cin>>N;
    for(int i = 1; i<=N; i++){
        cin>>inOrder[i];
        FindIdx[inOrder[i]] = i;
    }
    
    for(int i = 1; i<=N; i++){
        int num;
        cin>>num;
        postOrder.push_back(num);
    }
    
    Solve();
}
