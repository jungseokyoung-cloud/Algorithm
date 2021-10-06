#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
struct Point {
    int x, y;
};
int N;
vector<Point> Xarr(3000000);
vector<Point> temp(3000000);

int getPoint(Point a, bool XorY){
    if(XorY) return a.x;
    else return a.y;
}

void Merge(vector<Point> &arr ,int st, int en, bool XorY){
    int mid = (st + en)/2;
    int lft = st;
    int rft = mid;
    for(int i = st; i<en; i++){
        if(rft == en) temp[i] = arr[lft++];
        else if(lft == mid) temp[i] = arr[rft++];
        else if(getPoint(arr[lft], XorY) > getPoint(arr[rft], XorY)) temp[i] = arr[rft++];
        else temp[i] = arr[lft++];
    }
    for(int i = st; i<en; i++) arr[i] = temp[i];
}

void merge_sort(vector<Point> &arr ,int st, int en, bool XorY){
    if(st + 1 >= en) return;
    
    int mid = (st + en)/2;
    merge_sort(arr, st, mid, XorY);
    merge_sort(arr, mid, en, XorY);
    
    Merge(arr, st, en, XorY);
}

ll GetDistance(ll x, ll y, ll x1, ll y1){
    ll tmp = (x-x1)*(x-x1) + (y-y1)*(y- y1);
    return tmp;
}

ll dividePoint(int st, int en){
    if(st + 1 == en) return GetDistance(Xarr[st].x,Xarr[st].y ,Xarr[en].x, Xarr[en].y);// 점이 2개인 경우
    
    if(st + 2 == en){ // 점이 3개인 경우
        ll temp1 = GetDistance(Xarr[st].x,Xarr[st].y ,Xarr[en].x, Xarr[en].y);
        ll temp2 = GetDistance(Xarr[st].x,Xarr[st].y ,Xarr[st+1].x, Xarr[st+1].y);
        ll temp3 = GetDistance(Xarr[st+1].x,Xarr[st+1].y ,Xarr[en].x, Xarr[en].y);
        
        ll value = min(temp1, temp2);
        value = min(value, temp3);
        return value;
    }
    
    int mid = (st + en)/2;
    
    ll CPL = dividePoint(st, mid);
    ll CPR = dividePoint(mid + 1, en);
    
    ll value = min(CPL, CPR); // 왼쪽 값
    ll d = sqrt(value); // 바운더리
    int lft = st;
    int rft = en;
    bool choose = false;
    
    for(int i = st; i<=en; i++){  // 왼쪽 바운더리 오른쪽 바운더리 찾음
        int xPos = Xarr[i].x;
        if(!choose && xPos >= Xarr[mid].x - d){
            lft = i;
            choose = true;
        }
        if(xPos <= Xarr[mid].x + d) rft = i;
    }
    
    vector<Point> pos;
    for(int i = lft; i<=rft; i++){
        Point a = Xarr[i];
        pos.push_back(a);
    } // y값 정렬 위해서
    
    merge_sort(pos, 0, (int)pos.size(), false); // y값 기준 정렬
    for(int i = 0; i<pos.size(); i++){
        for(int j = i + 1; j<pos.size(); j++){
            ll y1 = pos[i].y;
            ll y2 = pos[j].y;
            
            if((y2 - y1)*(y2 - y1) >= value) break; // 더크다면 탐색 종료
            value = min(value, GetDistance(pos[i].x, y1, pos[j].x, y2));
        }
    }
    return value;
}

void Solve(){
    merge_sort(Xarr, 0 , N, true); // x값 기준 정렬
    ll ans = dividePoint(0, N-1);
    printf("%.6lf", sqrt(ans));
  }

void Input(){
    cin>>N;
    for(int i = 0; i<N; i++){
   //     scanf("%d, %d", &Xarr[i].x , &Xarr[i].y);
        scanf("%d, %d", &Xarr[i].x , &Xarr[i].y);
    }
}
int main(){
    //FAST;
    Input();
    Solve();
}
 
