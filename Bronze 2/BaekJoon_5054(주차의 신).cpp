#include<iostream>
using namespace std;

int main()
{
    int test,store;
    cin>>test;
    for(int i=0; i<test; i++)
    {
        int min=100,max=0;
        cin>>store;
        int arr[store];
        for(int j=0; j<store; j++)
        {
            cin>>arr[j];
            if(min>=arr[j])
                min=arr[j];
            if(max<=arr[j])
                max=arr[j];
        }
        cout<<(max-min)*2<<endl;
    }
}
