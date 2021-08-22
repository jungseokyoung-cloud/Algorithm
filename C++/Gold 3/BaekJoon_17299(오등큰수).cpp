#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define MMAX 1000001
int freq[MMAX];
int arr[MMAX];
int ans[MMAX];
int N;
stack<int> temp;

void Solve(){
    for(int i = 0; i<N; i++){
        int num = arr[i];
        
        while(!temp.empty()){
            int comp = arr[temp.top()];
            if(freq[comp] >= freq[num]) break;
            ans[temp.top()] = arr[i];
            temp.pop();
        }
        temp.push(i);
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        freq[arr[i]] ++;
    }
    fill(ans, ans+MMAX, -1);
    Solve();
    for(int i = 0; i<N; i++) cout<<ans[i]<<' ';
    cout<<endl;
}
