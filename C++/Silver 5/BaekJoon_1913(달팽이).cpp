#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int temp_cnt=1;
    int find_num,n,x,y;
    cin>>n>>find_num;
//    vector<vector<int>>snail(n,vector<int>(n,0));
    int snail[n][n];
    int direction=0,i=0,j=0; //0은 아래, 1은 오른쪽, 2는 위, 3은 왼쪽
    for(int num=n*n; num>=1; num--)
    {
        snail[i][j]=num;
        if(num==find_num)
        {
            x=i+1;
            y=j+1;
        }
        if(direction==0)
        {
            i++;
            if(i==(n-temp_cnt))
                direction=1;
        }
        else if(direction==1)
        {
            j++;
            if(j==(n-temp_cnt))
                direction=2;
        }
        else if(direction==2)
        {
            i--;
            if(i==(temp_cnt-1))
                direction=3;
        }
        else if(direction==3)
        {
            j--;
            if(j==temp_cnt)
            {
                direction=0;
                temp_cnt++;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        cout<<snail[i][j]<<' ';
        cout<<endl;
    }
    cout<<x<<' '<<y<<endl;
}
