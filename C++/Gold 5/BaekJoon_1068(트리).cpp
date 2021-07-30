#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<int> connect[51];
int N,delete_node,ans;
bool isposible[51];
void Leaf_Node(int node)
{
    if(isposible[node]) return;
    int cnt=0;
    for(int i=0; i<connect[node].size(); i++){
        int next=connect[node][i];
        if(isposible[next]) continue;
        cnt++;
        Leaf_Node(next);
    }
    if(cnt==0)
        ans++;
}
void Delete_Node(int node){
    isposible[node]=true;
    for(int i=0; i<connect[node].size(); i++){
        int next=connect[node][i];
        Delete_Node(next);
    }
}
int main(){
    FAST;
    cin>>N;
    int mom,root;
    for(int node=0; node<N; node++)
    {
        cin>>mom;
        if(mom==-1)
            root=node;
        else
            connect[mom].push_back(node);
    }
    cin>>delete_node;
    Delete_Node(delete_node);
    Leaf_Node(root);
    cout<<ans<<'\n';
}
// 트리 구조에서 loop나 self loop은 없다.
// 트리 구조에서는 root노드는 하나이다.
// 트리 구조에서는 모든 자식의 부모는 하나이다.
