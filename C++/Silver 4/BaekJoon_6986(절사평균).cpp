#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    FAST;
    int n,k;
    double trimmed_mean=0, correction_mean=0; //trimmed -> 절사 correction ->보정
    cin>>n>>k;
    vector<double> score(n,0);
    for(int i=0; i<n; i++)
    cin>>score[i];
    sort(score.begin(), score.end());
    for(int i=0; i<n; i++)
    {
        if(i<k)
        {
            correction_mean+=score[k];
        }
        else if(i>=(n-k))
        {
            correction_mean+=score[n-k-1];
        }
        else if(i>=k && i<n-k)
        {
            trimmed_mean+=score[i];
            correction_mean+=score[i];
        }
    }
    trimmed_mean/=(n-k*2);
    correction_mean/=n;
    trimmed_mean=round(trimmed_mean*100)/100; // 소수점 3번째에서 반올림
    correction_mean=round(correction_mean*100)/100;
    printf("%0.2f \n%0.2f\n", trimmed_mean,correction_mean);
}
