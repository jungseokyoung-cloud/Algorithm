#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
int N;
ll Min = LLONG_MAX;
int liquid[5000];
int ans[3];
int BinarySearch(int star, ll target){
    
    int end = N-1;
    int start = star;
    while(end>start){
        int mid = (end + start)/2;
        if(liquid[mid] >= target) end = mid;
        else if(liquid[mid] < target) start = mid + 1;
    }
    if(end > 0 && end>star && abs(-target + liquid[end]) > abs(-target + liquid[end-1])){
        end--;
    }
    return end;
}

void Solve(){
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            ll tar = liquid[i] + liquid[j];
            int idx = BinarySearch(j+1, -tar);
            ll comp = tar + liquid[idx];
            if(abs(Min) > abs(comp)){
                Min = comp;
                ans[0] = liquid[i];
                ans[1] = liquid[j];
                ans[2] = liquid[idx];
            }
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i=0; i<N; i++) cin>>liquid[i];
    sort(liquid, liquid+N);
    Solve();
    sort(ans, ans+3);
    for(int i=0; i<3; i++) cout<<ans[i]<<' ';
    cout<<'\n';
}
