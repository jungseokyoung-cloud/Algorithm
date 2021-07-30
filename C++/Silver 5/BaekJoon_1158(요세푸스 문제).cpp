#include<iostream>
#include<queue>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int n,k,cnt=0;
    cin>>n>>k;
    queue<int> q;
    for(int i=1; i<=n; i++)
    q.push(i);
    cout<<"<";
    while(q.size()!=0)
    {
        cnt++;
        if(cnt==k)
        {
            if(q.size()==1)
                cout<<q.front()<<">"<<'\n';
            else
            {
                cout<<q.front()<<", ";
                cnt=0;
            }
            q.pop();
        }
        else{
        q.push(q.front());
        q.pop();
        }
    }
}
