#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
vector<pair<int, int>> arr(10000000);

bool comp(pair<int, int >a, pair<int, int>b){
    return a.second < b.second;
}

int GetDistance(int x, int y, int x1, int y1){
    int tmp = (x-x1)*(x-x1) + (y-y1)*(y- y1);
    return tmp;
}

int dividePoint(int st, int en){
    if(st + 1 == en) return GetDistance(arr[st].first,arr[st].second ,arr[en].first, arr[en].second);// 점이 2개인 경우
    
    if(st + 2 == en){ // 점이 3개인 경우
        int temp1 = GetDistance(arr[st].first,arr[st].second ,arr[en].first, arr[en].second);
        int temp2 = GetDistance(arr[st].first,arr[st].second ,arr[st+1].first, arr[st+1].second);
        int temp3 = GetDistance(arr[st+1].first,arr[st+1].second ,arr[en].first, arr[en].second);
        
        int value = min(temp1, temp2);
        value = min(value, temp3);
        return value;
    }
    
    int mid = (st + en)/2;
    
    int CPL = dividePoint(st, mid);
    int CPR = dividePoint(mid + 1, en);
    
    int value = min(CPL, CPR);
    int d = sqrt(value);
    
    int lft = st;
    int rft = en;
    bool choose = false;
    
    for(int i = st; i<=en; i++){  // 왼쪽 바운더리 오른쪽 바운더리 찾음
        int xPos = arr[i].first;
        if(!choose && xPos >= arr[mid].first - d){
            lft = i;
            choose = true;
        }
        if(xPos <= arr[mid].first + d) rft = i;
    }
    
    
    vector<pair<int, int>> pos;
    for(int i = lft; i<=rft; i++) pos.push_back({arr[i].first, arr[i].second});
    
    sort(pos.begin(), pos.end(), comp); // y값에 대하여 정렬
    
    for(int i = 0; i<pos.size(); i++){
        for(int j = i + 1; j<pos.size(); j++){
            int y1 = pos[i].second;
            int y2 = pos[j].second;
            
            if((y2 - y1)*(y2 - y1) >= value) break;
            value = min(value, GetDistance(pos[i].first, y1, pos[j].first, y2));
        }
    }
    return value;
}

void Solve(){
    sort(arr.begin(), arr.begin() + N); // x값에 대하여 정렬
    int ans = dividePoint(0,N-1);
    cout<<ans<<endl;
  }

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++)  cin>>arr[i].first>>arr[i].second;
    Solve();
}
