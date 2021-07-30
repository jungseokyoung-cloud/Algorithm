#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 10000
bool PrimeNum[MMAX];
bool vis[MMAX];
int Min, num1, num2;

void Eratosthenes(){
    memset(PrimeNum, true, sizeof(PrimeNum));
    for(int i=2; i<MMAX; i++){
        if(!PrimeNum[i]) continue;
        for(int j=2; j*i<MMAX; j++){
            PrimeNum[j*i] = false;
        }
    }
}
void Solve(){
    queue<pair<int, int>> now;
    now.push({num1, 0});
    vis[num1] = true;
    while(!now.empty()){
        int now_num = now.front().first;
        int now_cnt = now.front().second;
        now.pop();
        if(now_num == num2){
            Min = now_cnt;
            return;
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<10; j++){
                string next_num = to_string(now_num);
                next_num[i] = j + '0';
                int Next = stoi(next_num);
                if(vis[Next]) continue;
                if(!PrimeNum[Next]) continue;
                if(Next<1000) continue;
                now.push({Next, now_cnt+1});
                vis[Next] = true;
            }
        }
    }
}

int main(){
    FAST;
    int T;
    cin>>T;
    Eratosthenes();
    while(T--){
        memset(vis, false, sizeof(vis));
        Min = INT_MAX;
        cin>>num1>>num2;
        Solve();
        if(Min ==  INT_MAX) cout<<"Impossible"<<'\n';
        else cout<<Min<<'\n';
    }
}
