#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

int T, N; // N은 최재 20!
double ans;
pair<int, int> point[20];
bool isChoice[20];

void Input(){
    cin>>N;
    
    ans = 1e9+7;
    memset(isChoice, false, sizeof(isChoice));
    
    for(int i = 0; i<N; i++){
        cin>>point[i].first>>point[i].second;
    }
}

double getDistance(){
    ll x = 0 ,y = 0;
    for(int i = 0; i<N; i++){
        if(isChoice[i]){
            x+=point[i].first;
            y+=point[i].second;
        }
        else {
            x-=point[i].first;
            y-=point[i].second;
        }
    }
    return sqrt(x*x + y*y);
}

void Solve(int now, int cnt){ //시작점 N/2개 선택 나머지는 끝점임
    if(cnt == N/2){
        ans = min(ans, getDistance());
        return;
    }
    
    for(int i = now; i<N; i++){
        isChoice[i] = true; // 시작점임
        Solve(i + 1, cnt + 1);
        isChoice[i] = false;
    }
}

int main(){
    cin>>T;
    while(T--){
        Input();
        Solve(0, 0);
        printf("%.7f\n", ans);
    }
}
