#include<iostream>
using namespace std;
int main()
{
    int n,cnt=1,max=-100,vote_reault=0;
    cin>>n;
    int vote;
    int *arr=new int[n];
    for(int i=0; i<n; i++)
        arr[i]=0;
    for(int i=0; i<n; i++)
    {
        cin>>vote;
        if(vote!=0)
        arr[vote-1]+=1;
    }
    for(int i=0; i<n; i++)
    {
            if(max<arr[i])
            {
                vote_reault=i+1;
                max=arr[i];
                cnt=0;
            }
            else if(max==arr[i])
            {
                cnt++;
            }
    }
    if(cnt==0)
        cout<<vote_reault<<endl;
    else
        cout<<"skipped"<<endl;
}
