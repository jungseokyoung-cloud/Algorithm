#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
struct Edge{
    int node1,node2,cost;
};
int N,M, islandCount, ans;
int board[11][11];
bool vis[11][11];
int dis_x[] = {1,0,-1,0};
int dis_y[] = {0,1,0,-1};
vector<Edge> graph;
int parent[10];
int level[10];

void FindPath(int x, int y, int dir, int cnt){
    int dis = 1;
    while(1){
        x = x + dis_x[dir];
        y = y + dis_y[dir];
        if(x < 0 || x >= N || y < 0 || y >= M) return;
        if(board[x][y] != 0){
            if(dis <= 1) return;
            graph.push_back({cnt, board[x][y], dis});
            return;
        }
        dis++;
    }
}

void BFS(int i, int j, int cnt, bool forPath){
    vis[i][j] = true;
    queue<pair<int, int>> pos;
    pos.push({i,j});
    
    while(!pos.empty()){
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();
        board[x][y] = cnt;
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == 0) {
                if(forPath)  FindPath(nx, ny, i, cnt);
                continue;
            }
            pos.push({nx,ny});
            vis[nx][ny] = true;
        }
    }
}

void Setting(bool forPath){
    int islandCnt = 1;
    memset(vis, false, sizeof(vis));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            BFS(i, j, islandCnt, forPath);
            islandCnt++;
        }
    }
    islandCount = islandCnt-1;
}

bool comp(Edge a, Edge b){
    return a.cost < b.cost;
}

int getRoot(int x){
    if(parent[x] == x) return x;
    else return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b){
    int par_a = getRoot(a);
    int par_b = getRoot(b);
    
    if(level[par_a] < level[par_b]) parent[par_a] = par_b;
    else parent[par_b] = par_a;
    if(level[par_a] == level[par_b]) level[par_a] ++;
}

bool CheckParent(int a, int b){
    return getRoot(a) == getRoot(b);
}

void Solve(){
    Setting(false);
    Setting(true);
    
    sort(graph.begin(), graph.end(), comp);
    for(int i = 1; i<=islandCount; i++) parent[i] = i;
    
    for(int i = 0; i<graph.size(); i++){
        int node1 = graph[i].node1;
        int node2 = graph[i].node2;
        int cost = graph[i].cost;
        if(CheckParent(node1, node2)) continue;
        Union(node1, node2);
        ans += cost;
    }
    int comp = getRoot(1);
    for(int i = 2; i<=islandCount; i++){
        if(getRoot(i) != comp){
            ans = -1;
            return;
        }
    }
}


int main(){
    FAST;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) cin>>board[i][j];
    }
    Solve();
    cout<<ans<<endl;
}
