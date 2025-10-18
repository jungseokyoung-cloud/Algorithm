#include <iostream>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int getCost(int cnt);

int solution(int n, vector<int> ramens) {
  int answer = 0;
  ramens.push_back(0); ramens.push_back(0);

  for(int i = 0; i < n; i++) {
    if(ramens[i] == 0) continue;
    if(ramens[i+1] > ramens[i+2]) {
      int minVal = min(ramens[i], ramens[i+1]-ramens[i+2]);
      
      answer += getCost(2) * minVal;
      ramens[i] -= minVal;
      ramens[i + 1] -= minVal;
    }
    int minVal = min(ramens[i], ramens[i+1]);
    minVal = min(minVal, ramens[i+2]);
    for(int j = 0; j < 3; j++) {
      ramens[i+j] -= minVal;
    }
    answer += getCost(3) * minVal;
    
    answer += getCost(1) * ramens[i];
  }
  
  return answer;
}

int getCost(int cnt) {
  if(cnt == 0) return 0;
  
  if(cnt == 1) return 3;
  else if(cnt == 2) return 5;
  else return 7;
}

int main(){
  FAST;
  int n;
  vector<int> ramens;
  cin >> n;
  int temp;
  for(int i = 0; i < n; i++) {
    cin>> temp;
    ramens.push_back(temp);
  }
  cout << solution(n, ramens) << endl;
}
