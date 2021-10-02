#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
struct Jewel{
    int weight, price;
};
int N,K;
long long ans;
Jewel jewel[300001];
int begWeight[300001];

bool comp(Jewel a, Jewel b){
    return a.weight < b.weight;
}

void Input(){
    cin>>N>>K;
    for(int i = 0; i<N; i++)  cin>>jewel[i].weight>>jewel[i].price;
    for(int i = 0; i<K; i++)  cin>>begWeight[i];
    sort(jewel, jewel + N, comp);
    sort(begWeight, begWeight+K);
}

void Solve(){
    int idx = 0;
    priority_queue<int> now;
    for(int i = 0; i<K; i++){
        while(idx < N && jewel[idx].weight <= begWeight[i]){
            now.push(jewel[idx].price);
            idx++;
        }
        if(!now.empty()){
            ans += now.top();
            now.pop();
        }
    }
}

int main(){
    FAST;
    Input();
    Solve();
    cout<<ans<<endl;
}
