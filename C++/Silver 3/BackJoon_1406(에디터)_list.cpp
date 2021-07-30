#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
    FAST;
    string s;
    cin>>s;
    list<char> addit;
    for(auto c: s)
        addit.push_back(c);
    auto cusor=addit.end();
    int t;
    cin>>t;
    char in;
    while(t--)
    {
        cin>>in;
        if(in=='P')
        {
            cin>>in;
            addit.insert(cusor, in);
        }
        else if(in=='L' && cusor!=addit.begin())
            cusor--;
        else if(in=='D' && cusor!=addit.end())
            cusor++;
        else if(in=='B' && cusor!=addit.begin())
        {
            cusor--;
            cusor=addit.erase(cusor);
        }

    }
    for(auto c: addit)
        cout<<c;
    cout<<'\n';
}
