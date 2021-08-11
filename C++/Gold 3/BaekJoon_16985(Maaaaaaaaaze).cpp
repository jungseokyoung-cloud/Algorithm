#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int dx[] = {0, -1, 0, 0, 1, 0};
int dy[] = {0, 0, 1, 0, 0, -1};
int dz[] = {-1, 0, 0, 1, 0, 0};
int dir[5];
int arr[5][5][5];
int coppyarr[5][5][5];
int vis[5][5][5];
int ans = INT_MAX;
int rotateDir[5];
bool choice[5];


void BFS(){
    if(arr[0][0][0] == 0 || arr[4][4][4] == 0) return;
  
    queue<tuple<int, int, int>> pos;
    pos.push({0,0,0});
    vis[0][0][0] = 0;
    
    while(!pos.empty()){
        int x = get<0>(pos.front());
        int y = get<1>(pos.front());
        int z = get<2>(pos.front());

        pos.pop();
        if(x == 4 && y == 4 && z == 4){
            ans = min(ans, vis[x][y][z]);
            return;
        }
        
        for(int i = 0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if(vis[nx][ny][nz] > -1 || arr[nx][ny][nz] == 0) continue;
            
            pos.push({nx,ny,nz});
            vis[nx][ny][nz] = vis[x][y][z] + 1;
        }
    }
}

void Rotate(int z){
    dir[z] = (dir[z] + 1)%4;
    int temp[5][5];
    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<5; j++){
            temp[i][j]=arr[5-j-1][i][z];
        }
    }
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            arr[i][j][z] = temp[i][j];
        }
    }
}

void Make_floor(int z){
    if(z == 5){
        memset(vis, -1, sizeof(vis));
        BFS();
        return;
    }
    for(int k = 0; k<5; k++){
        if(choice[k]) continue;
        choice[k] = true;
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                arr[i][j][z] = coppyarr[i][j][k];
            }
        }
        Make_floor(z+1);
        choice[k] = false;
    }
}

void Make_dir(int z){
    if(z == 5){
        for(int i = 0; i<5; i++){
            while(rotateDir[i] != dir[i]){
                Rotate(i);
            }
        }
        memcpy(coppyarr, arr, sizeof(arr));
        memset(choice, false, sizeof(choice));
        Make_floor(0);
        return;
    }
    
    for(int i = 0; i<4; i++){
        rotateDir[z] = i;
        Make_dir(z+1);
    }
}

int main(){
    FAST;
    for(int k = 0; k<5; k++){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                cin>>arr[i][j][k];
            }
        }
    }
    Make_dir(0);
    if(ans == INT_MAX) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
