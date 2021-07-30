#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
void Move_Tower(int n, int start,int end) // 이동 횟수
{
    if(n==1)
    {
      cout<<start<<' '<<end<<'\n';
        return;
    }
    
    Move_Tower(n-1,start,6-start-end);
    cout<<start<<' '<<end<<'\n';
    Move_Tower(n-1, 6-start-end, end);
}
int Move(int n)
{
    FAST;
   if(n==1)
       return 1;
    int before=Move(n-1);
    return 2*before+1;
}
int main()
{
    int N;
    cin>>N;
    cout<<Move(N)<<'\n';
    Move_Tower(N, 1, 3);
    
}
