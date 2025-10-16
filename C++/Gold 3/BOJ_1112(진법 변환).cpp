#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

string solution(int x, int b) {
  if(x == 0) return "0";
  string answer;
  
  int temp = x;

  if(x < 0 && b > 0) temp = -x;
  
  while(temp != 0) {
    int remainder = temp % b;
    temp /= b;
    
    if(remainder < 0) {
      remainder += abs(b);
      temp += 1;
    }
    answer += remainder + '0';
  }
  
  reverse(answer.begin(), answer.end());
  
  return (x < 0 && b > 0) ? "-" + answer : answer;
}

int main(){
  FAST;
  int x, b;
  cin >> x >> b;

  cout << solution(x, b) << endl;
}

/*
 10진수
 x를 b진법으로 바꾸면 됨.
 음의 진법일 때 -부호가 있으면 안됨.
 
 */
