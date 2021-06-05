#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100001;
struct Edge{
    int node1, node2, cost;
};

vector<Edge> edge;
vector<int> vis;
vector<int> unvis;

int V,E;
int solution(int n, int start_node){
    
    vector<vector<int>> graph(V+1, vector<int>(V+1));
    fill(graph.begin(), graph.end(), -1);
    int sum=0;
    
    for(int i=0 ; i<edge.size(); i++){
        graph[edge[i].node1][edge[i].node2]=edge[i].cost;
        graph[edge[i].node2][edge[i].node1]=edge[i].cost;
    }
    
    vis.push_back(start_node);
    for(int i=1; i<=V; i++){
        if(i==start_node) continue;
        unvis.push_back(i);
    }
    
    for(int i=1; i<=V; i++){  // i는 방문한 정점의 개수
        int min=INT_MAX;
        int min_idx = 0;
        for(int j=0; j<i ; j++){ // j는 지금 까지 방문한 vis 배열을 보기 위함.
            for(int k=0; k<V-i; k++){ // k는 지금 까지 방문하지 않은 노드의 개수
                if(graph[vis[j]][unvis[k]]>=0 && min>graph[vis[j]][unvis[k]]){
                    min=graph[vis[j]][unvis[k]];
                    min_idx=k;
                }
            }
        }
        vis.push_back(unvis[min_idx]);
        unvis.erase(unvis.begin()+min_idx);
        sum+=min;
    }
    
    return sum;
}
