#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }
    sort(num.begin(),num.end());
    for(int i=0; i<n; i++)
    {
        if(i==0)
            cout<<num[i]<<endl;
        else
        {
            if(num[i-1]!=num[i])
                cout<<num[i]<<endl;
        }
    }
}
