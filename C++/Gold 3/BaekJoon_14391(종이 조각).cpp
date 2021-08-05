#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,ans;
char board[4][4];
bool vis[4][4];

void Find_Next(int &x, int &y){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(vis[i][j]) continue;
            x = i;
            y = j;
            return;
        }
    }
}

void Solve(int cnt){
    int x = -1;
    int y = -1;
    Find_Next(x, y);
    if(x == -1 && y == -1){
        ans = max(ans, cnt);
        return;
    }
    
    int temp = 10;
    int sum = 0;

    for(int i = x; i<N; i++){
        if(vis[i][y]){
            for(int j = x; j<i; j++) vis[j][y] = false;
            break;
        }
        
        sum *= temp;
        sum += (board[i][y] - '0');
        for(int j = x; j<=i; j++) vis[j][y] = true;
        Solve(cnt + sum);
        for(int j = x; j<=i; j++) vis[j][y] = false;
    }
        
    sum  = 0;
    for(int i = y; i<M; i++){
        if(vis[x][i]){
            for(int j = y; j < i; j++) vis[x][j] = false;
            break;
        }
        
        sum *= temp;
        sum += board[x][i] -'0';
        for(int j = y; j<=i; j++) vis[x][j] = true;
        Solve(cnt + sum);
        for(int j = y; j<=i; j++) vis[x][j] = false;
    }
}

int main(){
    FAST;
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) cin>>board[i][j];
    }
    Solve(0);
    cout<<ans<<endl;
}
