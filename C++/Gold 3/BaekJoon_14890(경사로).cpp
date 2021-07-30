#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,L,ans;
int board[100][100];
bool vis1[100][100];


void Rotate(){
    int arr[100][100];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            arr[i][j]=board[N-j-1][i];
        }
    }
    memcpy(board, arr, sizeof(board));
}

void MakeRamp(){
    for(int i = 0; i<N; i++){
        bool canGo1 = true;
        
        for(int j = 1; j<N; j++){
            if(!canGo1) break;
            if(board[i][j-1] != board[i][j] && abs(board[i][j-1] - board[i][j]) != 1)    canGo1 = false;
            
            else if(abs(board[i][j-1] - board[i][j]) == 1){
                vector<pair<int, int>> pos;
                
                if(board[i][j-1] > board[i][j]){
                    for(int k = j; k < j+L; k++){
                        if(k>=N || board[i][k] != board[i][j] || vis1[i][k]){
                            canGo1 = false;
                            break;
                        }
                        pos.push_back({i,k});
                    }
                    j+=(L - 1);
                }
                    
                else{
                    for(int k = j-1; k > j - L -1; k--){
                        if( k<0 || board[i][k]!= board[i][j-1] || vis1[i][k]){
                            canGo1 = false;
                            break;
                        }
                        pos.push_back({i,k});
                    }
                }
                if(canGo1){
                    for(int i = 0; i<pos.size(); i++){
                        vis1[pos[i].first][pos[i].second] = true;
                    }
                }
                
            }
           
        }
        if(canGo1) ans ++;
    }
}

void Solve(){
    MakeRamp();
    Rotate();
    memset(vis1, false, sizeof(vis1));
    MakeRamp();
}

int main(){
    FAST;
    cin>>N>>L;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) cin>>board[i][j];
    }
    Solve();
    cout<<ans<<'\n';
}
