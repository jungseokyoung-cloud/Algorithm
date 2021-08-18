#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int MMAX = 200001;
vector<int> arr[MMAX];
int N,M;
int ans[MMAX];
vector<int> belive;

void Input(){
    cin>>N;
    for(int i = 1; i<=N; i++){
        while(1){
            int person;
            cin>>person;
            if(person == 0) break;
            arr[i].push_back(person);
        }
    }
    cin>>M;
    for(int i = 0; i<M; i++){
        int num;
        cin>>num;
        belive.push_back(num);
    }
    memset(ans, -1, sizeof(ans));
}

void BFS(){
    queue<pair<int, int>> node;
    for(int i = 0; i<M; i++)    node.push({belive[i],0});
    
    while(!node.empty()){
        int now = node.front().first;
        int value = node.front().second;
        
        node.pop();
        if(ans[now] != -1) continue;
        ans[now] = value;
        
        for(int i = 0; i<arr[now].size(); i++){
            int next = arr[now][i];
            if(ans[next] != -1) continue;
            
            int ssize = (int)arr[next].size();
            int cnt = 0;
            for(int j = 0; j<arr[next].size(); j++){
                int nnext = arr[next][j];
                if(ans[nnext] == -1) continue;
                cnt++;
            }
            
            if(cnt*2 >= ssize) node.push({next ,value+1});
        }
    }
}

int main(){
    FAST;
    Input();
    BFS();
    for(int i = 1; i<=N; i++) cout<<ans[i]<<' ';
    cout<<endl;
}
