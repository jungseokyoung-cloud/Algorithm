#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n;
    cin>>n;
    queue<int>card;
    for(int i=1; i<=n; i++)
    card.push(i);
    while(card.size()>1)
    {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    cout<<card.front()<<'\n';
}
