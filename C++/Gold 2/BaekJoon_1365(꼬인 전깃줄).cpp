#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
int arr[100000];
vector<int> ansArr;

int binarySearch(int target){
    int st = 0;
    int en = ansArr.size()-1;
    while(st < en) {
        int mid = (st + en)/2;
        if(ansArr[mid] < target) st = mid + 1;
        else en = mid;
    }
    return en;
}

void input(){
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
}

void solve(){
    ansArr.push_back(arr[0]);
    
    for(int i = 1; i<N; i++){
        if(arr[i] > ansArr.back()) ansArr.push_back(arr[i]);
        else{
            int idx = binarySearch(arr[i]);
            ansArr[idx] = arr[i];
        }
    }
}

int main(){
    FAST;
    input();
    solve();
    cout<<N-ansArr.size()<<endl;
}
