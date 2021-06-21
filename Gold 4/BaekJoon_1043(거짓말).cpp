#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,ans;
bool knowTruth[51]; // 사실을 알면 truth
vector<int> lieParty[50];

void clear(int i){
    for(auto c : lieParty[i])
        knowTruth[c] = true;
    lieParty[i].clear();
}

void Check(int idx){
    for(int i=0; i<idx; i++){
        bool res = true;
        for(auto c : lieParty[i]){
            if(knowTruth[c]) res = false;
        }
        if(!res){
            clear(i);
            Check(i);
            ans--;
        }
    }
}

void Solve(){
    int partynum,person;
    for(int i=0; i<M; i++){
        bool cantlie = false;
        cin>>partynum;
        while(partynum--){
            cin>>person;
            lieParty[i].push_back(person);
            if(knowTruth[person]) cantlie = true;
        }
        
        if(cantlie) clear(i);
        else ans++;
    }
    Check(M);
}

int main(){
    FAST;
    cin>>N>>M;
    
    int know,num;
    cin>>know;
    while(know--){
        cin>>num;
        knowTruth[num]=true;
    }
    Solve();
    cout<<ans<<'\n';
}
