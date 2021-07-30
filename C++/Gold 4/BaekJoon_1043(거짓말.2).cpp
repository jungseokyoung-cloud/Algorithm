#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int N,M,ans;

vector<int>knowTruth;
vector<int>party[51];
int parent[51];

int Find(int x){
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int a, int b){
    int parent_a=Find(a);
    int parent_b=Find(b);
    if(parent_a<parent_b) parent[parent_b]=parent_a;
    else parent[parent_a]=parent_b;
}
bool SameParent(int a, int b){
    return Find(a)==Find(b);
}

void Check(){
    for(int i=0; i<M; i++){
        bool canlie = true;
        for(int j=0; j<party[i].size(); j++){
            int comp = party[i][j];
            if(!canlie) break;
            for(int k=0; k<knowTruth.size(); k++){
                if(!canlie) break;
                if(SameParent(comp, knowTruth[k]))  canlie = false;
            }
        }
        if(canlie) ans++;
    }
}

void Solve(){
    for(int i=1; i<=N; i++) parent[i] = i;
    
    for(int i=0; i<M; i++){
        for(int j=1; j<party[i].size(); j++){
            Union(party[i][j-1], party[i][j]);
        }
    }
    Check();
}
int main(){
    FAST;
    cin>>N>>M;
    
    int know,num;
    cin>>know;
    while(know--){
        cin>>num;
        knowTruth.push_back(num);
    }
    
    int partynum,person;
    for(int i=0; i<M; i++){
        cin>>partynum;
        while(partynum--){
            cin>>person;
            party[i].push_back(person);
        }
    }
    
    Solve();
    cout<<ans<<'\n';
}
