#include <iostream>
#include<algorithm>
#include <vector>
#include <utility>
#include<cstring>
#include <queue>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int dis_x[]={-1,-1,-1,1,1,1,0,0};
int dis_y[]={-1,0,1,-1,0,1,1,-1};
int N,M,K,ans;
vector<int> board[10][10];
int fertiInfo[10][10];
int add_ferti[10][10];

void Spring_Summer(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            vector<int> next;
            int temp=0;
            for(int k=0; k<board[i][j].size(); k++){
                int age=board[i][j][k];
                if(fertiInfo[i][j]<age) temp+=(age/2);
                else{
                    fertiInfo[i][j]-=age;
                    next.push_back(age+1);
                }
            }
            board[i][j].clear();
            for(int k=0; k<next.size(); k++) board[i][j].push_back(next[k]);
            fertiInfo[i][j]+=temp;
        }
    }
}
void Fall(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<board[i][j].size(); k++){
                int age=board[i][j][k];
                if(age%5!=0) continue;
                for(int dis=0; dis<8; dis++){
                    int nx=i+dis_x[dis];
                    int ny=j+dis_y[dis];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    board[nx][ny].insert(board[nx][ny].begin(), 1);
                }
            }
        }
    }
}
void Winter(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            fertiInfo[i][j]+=add_ferti[i][j];
        }
    }
}
void Check(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans+=board[i][j].size();
        }
    }
}
void Solve(){
    while(K--){
        Spring_Summer();
//        cout<<"spring"<<endl;
        Fall();
//        cout<<"fall"<<endl;
        Winter();
//        cout<<"winter"<<endl;
        
    }
    Check();
}
int main(){
    FAST;
    cin>>N>>M>>K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>add_ferti[i][j];
            fertiInfo[i][j]=5;
        }
    }
    int x,y,age;
    for(int i=0; i<M; i++){
        cin>>x>>y>>age;
        board[x-1][y-1].push_back(age);
    }
    Solve();
    cout<<ans<<'\n';
}
