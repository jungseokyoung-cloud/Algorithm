#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
int N;
int arr[10000000][2];

void Print(){
    for(int i = 0; i<N; i++){
        cout<<arr[i][0]<<' ';
    }
    cout<<endl;
}

int Find_Fivo(int st, int en){ // 램덤하게 피보값 찾는 경우(3값중 중앙값)
    
    int mid = (st + en)/2;
    if (mid == st) return st;
    
    if(arr[st] <= arr[mid]){ // st mid
        if (arr[mid] <= arr[en]) return mid; // st mid en
        else if(arr[st] >= arr[en]) return st; // en st mid
        else return en; // st mid en  st en mid  st
    }
    else if(arr[st] >= arr[en]) return st;
    else if(arr[mid] >= arr[en]) return mid;
    else return en;
}

int Quick(int st, int en, int pnt){
    int lft = st + 1;
    int rft = en;
    int pivotIdx = FindPivot(st, en, pnt);
    int pivot = arr[pivotIdx][pnt];
    swap(arr[st], arr[pivotIdx]);
    
    while(lft <= rft){
        while(lft <= en && arr[lft][pnt] < pivot) lft++;
        while(rft >= st && arr[rft][pnt] > pivot) rft--;
        
        if(lft < rft) swap(arr[lft], arr[rft]);
    }
    swap(arr[rft], arr[st]);
    return rft;
}

void quick_sort(int st, int en, int pnt){
    if(st >= en) return;
    
    int pivotIdx = Quick(st, en, pnt);
    quick_sort(st, pivotIdx-1, pnt);
    quick_sort(pivotIdx+1, en, pnt);
}

//x값 기준으로 정렬 !!!!!!

double GetDistance(int x, int y, int x1, int y1){
    double tmp = (x-x1)*(x-x1) + (y-y1)*(y- y1);
    double dis = tmp;
    
    for(int i = 0; i<20; i++){ // 뉴턴-램슨법 (찾아보기)
        if(dis < 1) break;
        dis = (dis*dis + tmp)/(2*dis);
    }
    return dis;
}

double dividePoint(int st, int en){
    
    if(st + 1 == en) return GetDistance(arr[st][0],arr[st][1] ,arr[en][0], arr[en][1]);// 점이 2개인 경우
    
    if(st + 2 == en){ // 점이 3개인 경우
        double temp1 = GetDistance(arr[st][0],arr[st][1] ,arr[en][0], arr[en][1]);
        double temp2 = GetDistance(arr[st][0],arr[st][1] ,arr[st+1][0], arr[st+1][1]);
        double temp3 = GetDistance(arr[st+1][0],arr[st+1][1] ,arr[en][0], arr[en][1]);
        
        double value = min(temp1, temp2);
        value = min(value, temp3);
        return value;
    }
    
    int mid = (st + en)/2;
    
    double CPL = dividePoint(st, mid);
    double CPR = dividePoint(mid + 1, en);
    
    double value = min(CPL, CPR);
    int d = value;
    
    int lft = -1;
    int rft = -1;
        
    for(int i = st; i<=en; i++){  // 왼쪽 바운더리 오른쪽 바운더리 찾음
        int xPos = arr[i][0];
        
        if(lft != -1 && rft != -1) break;
        
        if(lft == -1 && xPos >= arr[mid][0] + d) lft = i;
        if(rft == -1 && xPos <= arr[mid][0] + d) rft = i;
    }
    
    quick_sort(lft, rft, 1); // y값 기준으로 정렬 !
    
    for(int i = lft; i<=rft; i++){
        for(int j = i + 1; j<=rft; j++){
            int y1 = arr[i][1];
            int y2 = arr[j][1];
            
            if(y2 - y1 >= d) break;
            value = min(value, GetDistance(arr[i][0], y1, arr[j][0], y2));
        }
    }
    return value;
}

void Solve(){
    quick_sort(0, N-1, 0); // x값 기준으로 정렬 먼저
    cout<<dividePoint(0, N-1)<<endl;
  }

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++)  cin>>arr[i][0]>>arr[i][1];
    Solve();
//    Print();
}
