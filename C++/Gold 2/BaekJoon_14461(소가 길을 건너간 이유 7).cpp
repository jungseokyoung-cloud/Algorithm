#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = INT_MAX;
int N,T;
int board[100][100];
int isVis[100][100];
int dis_x[] = {1, -1,  0,  0,  0,  1,  2,  3,  2,  1,  0, -1, -2, -3, -2, -1};
int dis_y[] = {0,  0,  1, -1,  3,  2,  1,  0, -1, -2, -3, -2, -1,  0,  1,  2};

void init() {
    cin>>N>>T;
    for(int i = 0; i<N; i++){
        fill(isVis[i], isVis[i] + N, INF);
        for(int j = 0; j<N; j++) cin>>board[i][j];
    }
    
}

void solve() {
    priority_queue<pair<int, int>> pq;
    
    pq.push({0,0});
    isVis[0][0] = 0;
    int ans = INF;
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second / N;
        int y = pq.top().second % N;
        pq.pop();
        
        if(isVis[x][y] < cost) continue;
        
        int temp = (N - x - 1) + (N - y -1);
        if(temp <= 2) ans = min(ans, cost + temp*T);
        
        for(int i = 0; i<16; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            
            int temp = abs(nx - x - 1) + abs(ny - y - 1);
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int nCost = cost + (3*T) + board[nx][ny];
            
            if(nCost > isVis[nx][ny]) continue;
            isVis[nx][ny] = nCost;
            
            pq.push({-nCost, nx*N + ny});
        }
    }
    cout<<ans<<endl;
}

int main(){
    FAST;
    init();
    solve();
}
