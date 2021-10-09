#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int arr[10000];
int M,T;
vector<int>ansData;

void Solve(){
    priority_queue<int> upper;
    priority_queue<int> lower;
    
    for(int i = 0; i<M; i++){
        if(upper.size() == lower.size()) upper.push(arr[i]);
        else lower.push(-arr[i]);
        
        if(!lower.empty() && !upper.empty()){
            int upperNum = upper.top();
            int lowerNum = -lower.top();
            
            if(lowerNum < upperNum){
                upper.pop();
                lower.pop();
                
                upper.push(lowerNum);
                lower.push(-upperNum);
            }
        }
        
        if(i%2 == 0) ansData.push_back(upper.top());
    }
}

void Input(){
    cin>>M;
    for(int i = 0; i<M; i++) cin>>arr[i];
}

void Print(){
    cout<<ansData.size()<<endl;
    for(int i = 0; i<ansData.size(); i++){
        cout<<ansData[i]<<' ';
        if((i + 1)%10 == 0) cout<<endl;
    }
    cout<<endl;
}

int main(){
    FAST;
    cin>>T;
    while(T--){
        ansData.clear();
        Input();
        Solve();
        Print();
    }
}
