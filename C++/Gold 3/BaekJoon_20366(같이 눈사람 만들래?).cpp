#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[601];
int ans = INT_MAX;

void init() {
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
    sort(arr, arr+N);
}

void solve() {
    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            int temp = arr[i] + arr[j];
            int lft = i+1, rft = j-1;
            
            while(lft < rft) {
                int temp2 = arr[lft] + arr[rft];
                
                if(temp2 == temp) {
                    ans = 0;
                    return;
                }

                else if(temp2 > temp) rft --;
                else lft ++;
                
                ans = min(ans, abs(temp2 - temp));
            }
        }
    }
   
}

int main(){
    FAST;
    init();
    solve();
    cout<<ans<<endl;
}
