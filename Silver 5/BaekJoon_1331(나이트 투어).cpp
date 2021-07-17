#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    int ex,ey,nx,ny,cnt=0;
    int arr[6][6]={0,};
    cin>>s1;
    nx=s1[0]-'A';
    ny=s1[1]-'1';
    int sx=nx,sy=ny;
    arr[nx][ny]+=1;
    for(int i=1; i<36; i++)
    {
        ex=nx;
        ey=ny;
        cin>>s1;
        nx=s1[0]-'A';
        ny=s1[1]-'1';
        if((abs(nx-ex)==2&&abs(ny-ey)==1)||(abs(nx-ex)==1&&abs(ny-ey)==2))
        {
                    arr[nx][ny]=+1;
        }
        else
            cnt++;
        if(i==35)
        {
            if((abs(nx-sx)==2&&abs(ny-sy)==1)||(abs(nx-sx)==1&&abs(ny-sy)==2))
            {}
            else
                cnt++;
        }
    }
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(arr[i][j]==0 || arr[i][j]>1)
                cnt+=1;
        }
    }
    if(cnt==0)
        cout<<"Valid"<<'\n';
    else
        cout<<"Invalid"<<'\n';
}
