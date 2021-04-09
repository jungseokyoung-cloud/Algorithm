#include <iostream>
using namespace std;

int main()
{
    int num;
    cin>>num;
    int answer=num%8;
    if(answer==0)
        answer=2;
    if(answer>5)
        answer=10-answer;
    cout<<answer<<endl;
}
