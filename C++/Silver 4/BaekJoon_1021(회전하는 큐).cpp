#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int n,m,cnt=0,find_idx,num;
    cin>>n>>m;
    deque<int>d;
    for(int i=1; i<=n; i++)
        d.push_back(i);
    for(int i=0; i<m; i++)
    {
        cin>>num;
            for(int i=0; i<d.size(); i++) //지우고자 하는 원소의 인덱스
            {
                if(num==d[i])
                {
                    find_idx=i;
                    break;
                }
            }
           
            if(find_idx>(d.size()-find_idx)) //오른쪽으로 더 치우쳤다면
            {
                while(num!=d.front())
                {
                    d.push_front(d.back());
                    d.pop_back();
                    cnt++;
                }
            }
            else
            {
                while(num!=d.front())
                {
                    d.push_back(d.front());
                    d.pop_front();
                    cnt++;
                }
            }
            if(d.front()==num)
                d.pop_front();
    }
    cout<<cnt<<'\n';
}
