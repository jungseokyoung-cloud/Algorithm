#include <iostream>
using namespace std;

int main()
{
    int n,k;
    char temp;
    cin>>n;
    char **arr=new char*[n];
    char *str;
    for(int i=0; i<n; i++)
    {
        arr[i] = new char[n];
        cin>>arr[i];
    }
    cin>>k;
    if(k==3)
    {
        for(int i=0; i<n/2; i++)
        {
            str=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=str;
        }
    }
    if(k==2)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n/2; j++)
            {
                temp=arr[i][j];
                arr[i][j]=arr[i][n-1-j];
                arr[i][n-1-j]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
