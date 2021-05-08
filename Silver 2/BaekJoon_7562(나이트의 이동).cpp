#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    int dis_x[]={-1,1,2,2,1,-1,-2,-2};
    int dis_y[]={2,2,1,-1,-2,-2,-1,1};
    FAST;
    int t,l;
    cin>>t;
    while(t--)
    {
        cin>>l;
        int arr[l][l];
        memset(arr, -1, sizeof(arr));
        pair<int, int> p;
        pair<int, int> target;
        cin>>p.first>>p.second>>target.first>>target.second;
        queue<pair<int, int>>pos;
        pos.push({p.first,p.second});
        arr[p.first][p.second]=0;
        while(!pos.empty())
        {
            auto p=pos.front();
            pos.pop();
            if(p.first==target.first && p.second==target.second)
            {
                cout<<arr[p.first][p.second]<<'\n';
                break;
            }
            for(int i=0; i<8; i++)
            {
                int nx=p.first+dis_x[i];
                int ny=p.second+dis_y[i];
                if(nx<0 || nx>=l || ny<0 || ny>=l)continue;
                if(arr[nx][ny]>=0) continue;
                pos.push({nx,ny});
                arr[nx][ny]=arr[p.first][p.second]+1;
            }
        }
    }
}
