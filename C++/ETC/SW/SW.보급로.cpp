#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int INF = INT_MAX;
char board[100][100];
int ans[100][100];
int N,T;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};

void Solve(){
    queue<pair<int, int>> pos;
    pos.push({0,0});
    ans[0][0] = 0;
    while (!pos.empty()) {
        int x = pos.front().first;
        int y = pos.front().second;
        int cost = ans[x][y];
//        cout<<x<<' '<<y<<" : " <<endl;
        pos.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dis_x[i];
            int ny = y + dis_y[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int add = board[nx][ny] -'0';
//            cout<<nx<<' '<<ny<<"  : "<<ans[nx][ny]<<' '<<cost<<' '<<add<<endl;
            if(ans[nx][ny] > cost + add){
//                cout<<"add"<<endl;
                pos.push({nx,ny});
                ans[nx][ny] = cost + add;
            }
        }
    }
}

int  main(){
    FAST;
    cin>>T;
    for(int t = 1; t<=T; t++){
        cin>>N;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                cin>>board[i][j];
                ans[i][j] = INF;
            }
        }
        Solve();
        cout<<"#"<<t<<' '<<ans[N-1][N-1]<<'\n';
    }
   
    
}
