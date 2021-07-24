#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,T;
int topIdx[52];
int circleNum[51][1000];
bool isDel[51][1000];
int sum , cnt;

bool canDel(int i, int j){
    int idx = (topIdx[i] + j)%M;
    int now = circleNum[i][idx]; // 먼저 위아래 비교부터 하자
    
    int beforeIdx;
    if(idx == 0) beforeIdx = M-1;
    else beforeIdx = idx-1;
    
    int nextIdx = (idx + 1)%M;
    
    if(!isDel[i][beforeIdx] && now == circleNum[i][beforeIdx]) return true;
    if(!isDel[i][nextIdx] && now == circleNum[i][nextIdx]) return true;
    
    int upIdx = (topIdx[i+1]+j)%M;
    int downIdx = (topIdx[i-1]+j)%M;
    
    if(i < N && !isDel[i+1][upIdx] && now == circleNum[i+1][upIdx]) return true;
    if(i > 0 && !isDel[i-1][downIdx] && now == circleNum[i-1][downIdx]) return true;
    return false;
}

void SetCircle(){
    float aver = (float)sum/(float)cnt;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<M; j++){
            if(isDel[i][j]) continue;
            if(aver < circleNum[i][j]){
                circleNum[i][j] --;
                sum--;
            }
            else if(aver > circleNum[i][j]){
                circleNum[i][j] ++;
                sum++;
            }
        }
    }
}

void DeleteNum(){
    bool candel = false;
    vector<pair<int, int>>delIdx;
    for(int i = 1; i<=N; i++){
        int top = topIdx[i];
        for(int j = 0; j<M; j++){
            int idx = (top+j)%M;
            if(isDel[i][idx]) continue;
            bool res = canDel(i,j);
            if(res){
                delIdx.push_back({i,idx});
                candel = true;
            }
        }
    }
    
    if(candel){
        for(int i = 0; i<delIdx.size(); i++){
            int x = delIdx[i].first;
            int y = delIdx[i].second;
            sum -= circleNum[x][y];
            cnt--;
            isDel[x][y] = true;
        }
    }
    else SetCircle();
        
}

void Rotate(int x, int dir, int k){
    int temp = 1;
    while(x*temp <= N){
        if(dir == 0)    topIdx[x*temp] -= k;
        else topIdx[x*temp] += k;
        
        if(topIdx[x*temp] < 0) topIdx[x*temp] += M;
        topIdx[x*temp] %= M;
        temp++;
    }
}

void Solve(){
    int x,dir,k;
    while(T--){
        cin>>x>>dir>>k;
        Rotate(x, dir, k);
        DeleteNum();
    }
}

int main(){
    FAST;
    cin>>N>>M>>T;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<M; j++){
            cin>>circleNum[i][j];
            sum += circleNum[i][j];
            cnt++;
        }
    }
    Solve();
    cout<<sum<<'\n';
}
