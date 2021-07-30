#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int L,C;
char arr[16];
vector<char>password;
void Print_Password()
{
    for(int i=0; i<password.size(); i++)
        cout<<password[i];
    cout<<'\n';
}
void Make_Password(int conso, int vowel, int legth, int idx)
{
    if(legth==L && vowel>0 && conso>1)
    {
        Print_Password();
        return;
    }
    for(int i=idx; i<C; i++)
    {
        password.push_back(arr[i]);
        if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u')
            Make_Password(conso, vowel+1, legth+1, i+1);
        else
            Make_Password(conso+1, vowel, legth+1, i+1);
        password.pop_back();
    }
}
int main()
{
    FAST;
    cin>>L>>C;
    for(int i=0; i<C; i++)
    cin>>arr[i];
    sort(arr, arr+C);
    Make_Password(0, 0, 0, 0);
}
