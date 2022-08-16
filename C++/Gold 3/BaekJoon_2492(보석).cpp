#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N,M,T,K;
vector<pair<int, int>> arr;


void init() {
    cin>>N>>M>>T>>K;
    for(int i = 0; i<T; i++){
        int x,y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
}

int checkNum(int x, int y){
    int tot = 0;
    int maxX = x + K;
    int maxY = y + K;
    
    for(int i = 0; i<arr.size(); i++){
        int tempX = arr[i].first;
        int tempY = arr[i].second;
        
        if(tempX >= x && tempX <= maxX && tempY >= y && tempY <= maxY) tot ++;
    }
    
    return tot;
}

void solve() {
    int len = (int)arr.size();
    int maxNum = 0;
    int ansX = 0, ansY = 0;
    for(int i = 0; i<len; i++){
        int x = arr[i].first;
        if(x + K > N) x = N - K;
        
        for(int j = 0; j<len; j++){
            int y = arr[j].second;
            if(y + K > M) y = M - K;
            
            int temp = checkNum(x, y);
            if(maxNum > temp) continue;
            ansX = x;
            ansY = y+K;
            maxNum = temp;
        }
    }
    cout<<ansX<<' '<<ansY<<endl;
    cout<<maxNum<<endl;
}

int main(){
    FAST;
    init();
    solve();
}
