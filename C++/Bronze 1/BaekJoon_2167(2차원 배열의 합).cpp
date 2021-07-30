#include<iostream>
using namespace std;

int main()
{
    int n,m,k;
    int start_x,start_y,finish_x,finish_y;
    long long int sum;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=new int[m];
        for(int j=0; j<m; j++)
        cin>>arr[i][j];
    }
    cin>>k;
    for(int i=0; i<k; i++)
    {
        sum=0;
        cin>>start_x>>start_y>>finish_x>>finish_y;
        for(int j=start_x-1; j<finish_x; j++)
        {
            for(int k=start_y-1; k<finish_y; k++)
            {
                    sum+=arr[j][k];
            }
            
        }
        cout<<sum<<endl;
    }
}
