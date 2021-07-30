#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ld long double
int N,K;
vector<int>arr(501);

ld average(int idx, int num)
{
    ld sum=0;
    for(int i=idx; i<idx+num; i++)
        sum+=arr[i];
    sum/=num;
    return sum;
}
ld standard_deviation(double aver,int idx, int num)
{
    ld deviation=0;
    for(int i=idx; i<idx+num; i++)
    {
        deviation=deviation+(arr[i]-aver)*(arr[i]-aver);
    }
    deviation/=num;
    return sqrt(deviation);
}
int main()
{
    FAST;
    cin>>N>>K;
    ld min=DBL_MAX,compare;
    for(int i=0; i<N; i++)
    cin>>arr[i];
    for(int j=K; j<=N; j++)
    {
        for(int i=0; i<=N-j; i++)
        {
            double aver=average(i,j);
            compare=standard_deviation(aver, i,j);
            if(min>compare)
                min=compare;
        }
    }
    cout << fixed;
    cout.precision(11);
    cout<<min<<'\n';
}
