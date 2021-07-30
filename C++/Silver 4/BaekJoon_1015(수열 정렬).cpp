#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first==b.first)
        return a.second < b.second;
    else
    return a.first < b.first;
}
bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
int main()
{
    FAST;
    int n;
    cin>>n;
    vector<pair<int, int>>v(n);
    vector<int> v2(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i].first;
        v[i].second=i;
        v2[i]=i;
    }
    sort(v.begin(), v.end(),cmp); //정렬함 만약 같을시에 두번째 인자(사전순으로) 정렬
    for(int i=0; i<n; i++) //원래 순서를 배열의 첫번째에 저장함. --> 원래배열의 인덱스, 바뀐후에 인덱스 이런식으로 됨
    v[i].first=v2[i];
    sort(v.begin(), v.end(),cmp2); // 바뀐 인덱스를 원래대로 돌려주면 원래배열 기준에서 정렬한 인덱스값이 나옴.
    for(int i=0; i<n; i++)
    cout<<v[i].first<<' ';
}
