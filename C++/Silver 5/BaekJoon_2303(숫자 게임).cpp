#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int person,num=0,compare_num=0,idx,idx_num;
    cin>>person;
    vector<vector<int>> arr(person, vector<int>(5,0));
    for(int i=0; i<person; i++)
    {
        compare_num=0;
        for(int j=0; j<5; j++)
            cin>>arr[i][j];
        for(int j=0; j<5; j++)
        {
            for(int k=j+1; k<5; k++)
            {
                for(int l=k+1; l<5; l++)
                {
                   idx_num=(arr[i][j]+arr[i][k]+arr[i][l]);
                    if((idx_num%10)>=compare_num)
                        compare_num=(idx_num%10);
                }
            }
        }
        if(num<=compare_num)
        {
            num=compare_num;
            idx=(i+1);
        }
    }
    cout<<idx<<'\n';
}
