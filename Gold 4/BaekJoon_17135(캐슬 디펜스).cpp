#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,D,ans;
vector<int>archer_pos;
vector<pair<int, int>> enemy;
int board[15][15];

int Kill_Enemy(vector<pair<int, int>> &use){ //궁수 공격
    int kill_num=0;
    vector<int> dead_idx;
    for(int i=0; i<archer_pos.size(); i++){
        int ax = N;
        int ay = archer_pos[i];
        int min_dis = INT_MAX;
        int min_idx=-1;
        for(int j=0; j<use.size(); j++){
            int ex = use[j].first;
            int ey = use[j].second;
            int comp = abs(ex-ax) + abs(ay-ey);
            if(comp>D || ex==-1) continue; // -1이라면 이미 죽은적
            if(comp<min_dis){
                min_dis=comp;
                min_idx=j;
            }
            else if(comp==min_dis && use[min_idx].second>ey){ // 왼쪽 --> y값 더 작음
                min_idx=j;
            }
        }
        if(min_idx!=-1){
            kill_num++;
            dead_idx.push_back(min_idx);
        }
    }
    for(int i=0; i<dead_idx.size(); i++){
        if(use[dead_idx[i]].first==-1)    kill_num--;
        use[dead_idx[i]].first=-1;
    }
    return kill_num;
}

int Enemy_Move(vector<pair<int, int>> &use){ // 적 이동
    int dead_enemy=0;
    for(int i=0; i<use.size(); i++){
        if(use[i].first==-1) continue; // 만약 적이 죽었다면
        use[i].first++;
        if(use[i].first==N){ // 성에 도달했다면
            dead_enemy++;
            use[i].first=-1;
        }
    }
    return dead_enemy;
}
void Solve(){
    vector<pair<int, int>> use;
    for(int i=0; i<enemy.size(); i++){
        use.push_back({enemy[i].first, enemy[i].second});
    }
    int num1=0,num2=0; // num1에는 궁수가 죽인 적수를 num2에는 성에 도달해 죽은 적의 수
    while(num1+num2!=use.size()){ //
        num1+=Kill_Enemy(use);
        num2+=Enemy_Move(use);
    }
    ans=max(ans, num1);
}

void Archer_Choice(int cnt, int idx){
    if(cnt==3){
        Solve();
        return;
    }
    for(int i=idx; i<M; i++){
        archer_pos.push_back(i); // y값 저장
        Archer_Choice(cnt+1, i+1);
        archer_pos.pop_back();
    }
}

int main(){
    FAST;
    cin>>N>>M>>D;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j]==1) enemy.push_back({i,j});
        }
    }
    Archer_Choice(0, 0);
    cout<<ans<<'\n';
}
