#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    int x=0, y=0;
    int cnt=-1;
    cin>>n>>m>>k;

    if(k==0){
        cout<<x<<' '<<y<<endl;
    }
    else{
        while(k>=0){
            k -= m;
            cnt++;
            x = cnt;
        }
        y = k+m;

        cout<<x<<' '<<y<<endl;
    }
}
