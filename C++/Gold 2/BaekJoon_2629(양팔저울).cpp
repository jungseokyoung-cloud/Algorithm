#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int weightCnt, ballCnt;
int weight[30];
int ball[7];
bool canMeasure[15001][30];

void Input(){
    cin>>weightCnt;
    for(int i = 0; i<weightCnt; i++) cin>>weight[i];
    cin>>ballCnt;
    for(int i = 0; i<ballCnt; i++) cin>>ball[i];
}

void DP(int idx, int value){
    bool &ref = canMeasure[value][idx];

    if(ref) return;
    ref = true;
    if(idx == weightCnt)  return;
    
    DP(idx + 1, value);
    DP(idx + 1, value + weight[idx]);
    DP(idx + 1, abs(value - weight[idx]));
}

void Solve(){
    DP(0, 0);
    
    for(int i = 0; i<ballCnt; i++){
        if(ball[i] > 15000 || !canMeasure[ball[i]][weightCnt]) cout<<"N"<<' ';
        else cout<<"Y"<<' ';
    }
    cout<<endl;
}
int main(){
    FAST;
    Input();
    Solve();
     
}
