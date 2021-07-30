#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

struct Edge{
    int node1,node2,cost;
};

int getRoot(vector<int> & v, int x){
    if(v[x]==x) return x; // 루트 노드는 자기 자신을 가르킴.
    return v[x]=getRoot(v, v[x]); //v[x] 는 x의 부모임.
}
void UnionParent(vector<int> & v, int a, int b){
    int par_a=getRoot(v, a);
    int par_b=getRoot(v, b);
    if(par_a<par_b) v[par_b]=par_a; // 더 값이 작은 애를 부모로 함.
    else v[par_a]=par_b;
}
bool Find(vector<int> & v, int a, int b){
    int par_a=getRoot(v, a);
    int par_b=getRoot(v, b);
    if(par_b==par_a) return true;
    else return false;
}
bool compare(Edge a, Edge b ){
    return a.cost<b.cost;
}
int Solve(vector<Edge> &e, int n){
    int sum=0;
    
    sort(e.begin(), e.end(), compare);
    
    vector<int> parent(n+1);
    
    for(int i=1; i<=n; i++){
        parent[i]=i; // 처음에 부모노드는 자신을 가르키도록 세팅
    }
    
    for(int i=0; i<e.size(); i++){
        if(!Find(parent, e[i].node1, e[i].node2)){
            UnionParent(parent, e[i].node1, e[i].node2);
            sum+=e[i].cost;
        }
    }
    return sum;
}

