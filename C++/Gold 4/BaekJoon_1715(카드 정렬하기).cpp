#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
priority_queue<int> card;
int N,ans;

void Solve(){
    while(card.size()>1){
        int num1 = -card.top();
        card.pop();
        
        int num2 = -card.top();
        card.pop();
        ans += num1 + num2;
        card.push(-(num1 + num2));
    }
}

int main(){
    FAST;
    cin>>N;
    int num;
    for(int i = 0; i<N; i++){
        cin>>num;
        card.push(-num);
    }
    Solve();
    cout<<ans<<endl;
}
