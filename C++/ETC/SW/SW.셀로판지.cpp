#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
struct Circle{
    int p,q,r;
};
struct Square{
    int xLow,yLow,xHigh,yHigh;
};
bool res[4];
char ans[2];
Circle red;
Square blue;

bool InCircle(int x, int y){
    int result = (red.p - x)*(red.p - x) + (red.q - y)*(red.q - y);
    if(result <= red.r*red.r) return true;
    return false;
}

void Solve(){
    res[0] = InCircle(blue.xLow, blue.yLow);
    res[1] = InCircle(blue.xLow, blue.yHigh);
    res[2] = InCircle(blue.xHigh, blue.yLow);
    res[3] = InCircle(blue.xHigh, blue.yHigh);
    if(res[0] && res[1] && res[2] && res[3]) ans[0] = 'Y';
    else if(!res[0] && !res[1] && !res[2] && !res[3]){
        ans[1] = 'Y';
        if(red.p - red.r < blue.xLow || red.p + red.r > blue.xHigh || red.q - red.r < blue.yLow || red.q + red.r > blue.yHigh)
            ans[0] = 'Y';
    }
    else{
        ans[0] = 'Y';
        ans[1] = 'Y';
    }
}

int T;
int main(){
    FAST;
    cin>>T;
    for(int t = 1; t<=T; t++){
        memset(ans, 'N', sizeof(ans));
        cin>>red.p>>red.q>>red.r;
        cin>>blue.xLow>>blue.yLow>>blue.xHigh>>blue.yHigh;
        Solve();
        cout<<"#"<<t<<" ";
        for(int i = 0; i<2; i++)    cout<<ans[i];
        cout<<'\n';
    }
}

