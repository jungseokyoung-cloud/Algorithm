#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 50001

int N, M;
int parent[MMAX][20];
int depth[MMAX];
vector<int> edge[MMAX];
 
void MakeTree(int now, int par){
    depth[now] = depth[par] + 1;
    
    parent[now][0] = par;
    
    for(int i = 1; i<20; i++){
        int tmp = parent[now][i-1];
        if(tmp == -1) continue;
        parent[now][i] = parent[tmp][i-1];
    }
    for(int i = 0; i<edge[now].size(); i++){
        int next = edge[now][i];
        if(next != par) MakeTree(next, now);
    }
}
 
void Setting(){
    depth[1] = 0;
    for(int i = 0; i<edge[1].size(); i++){
        int now = edge[1][i];
        MakeTree(now, 1);
    }
}

int Solve(int a, int b){
    if(depth[a] != depth[b]){
        if(depth[a] > depth[b]) swap(a, b); // b의 깊이가 더 깊도록!
        
        for(int i = 19; i>=0 ; i--){
            if(parent[b][i] == -1) continue;
            if(depth[a] <= depth[parent[b][i]]) b = parent[b][i];
        }
    } // 높이를 맞추는 과정!!
    if(a!=b){
        for(int i = 19; i>=0; i--){
            if(parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        a = parent[a][0];
    }
    return a;
}
 
int main(){
   
    memset(parent, -1, sizeof(parent));
    cin>>N;
    
    int node1,node2;
    for(int i =0; i<N-1; i++){
        cin>>node1>>node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }
    Setting();
    
    cin>>M;
    for(int i =0 ; i<M; i++){
        cin>>node1>>node2;
        cout<<Solve(node1, node2)<<'\n';
    }
}
