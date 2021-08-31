#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[100000];
vector<int> ans;

void Solve(){
    priority_queue<int> maxHeap, minHeap;
    for(int i = 0; i<N; i++){
        if(maxHeap.size() > minHeap.size()) minHeap.push(-arr[i]);
        else maxHeap.push(arr[i]);
        
        if(minHeap.size() != 0 && maxHeap.top() > -minHeap.top()){
            int temp1 = maxHeap.top();
            int temp2 = -minHeap.top();
            
            maxHeap.pop();
            minHeap.pop();
            
            maxHeap.push(temp2);
            minHeap.push(-temp1);
        }
        ans.push_back(maxHeap.top());
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    Solve();
    for(auto res : ans) cout<<res<<endl;
}
