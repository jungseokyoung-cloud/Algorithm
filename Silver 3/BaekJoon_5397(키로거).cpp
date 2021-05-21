#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    int t;
    cin>>t;
    bool ans=false;
    while(t--)
    {
        string s;
        cin>>s;
        list<char> pass;
        auto cursor=pass.end();
        for(auto c: s)
        {

            if(c!='<' && c!='>' && c!='-')
            {
                ans=true;
                pass.insert(cursor, c);
            }
            else if(ans)
            {
                if(c=='<' && cursor!=pass.begin())
                    cursor--;
                else if(c=='>' && cursor!=pass.end())
                    cursor++;
                else if(c=='-' && cursor!=pass.begin())
                   {
                       cursor--;
                       cursor=pass.erase(cursor);
                   }
            }
        }
        for(auto i: pass)
            cout<<i;
        cout<<'\n';
    }
}
