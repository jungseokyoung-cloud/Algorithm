#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int N;
int members[10000];
vector<int> map[10000];
vector<int> childs[10000];
bool isVis[10000];
int answer[10000][2];

void configureTree(int current) {
  for(auto next: map[current]) {
    if (isVis[next]) { continue; }
    childs[current].push_back(next);
    isVis[next] = true;
  }
  
  for(auto next: childs[current]) configureTree(next);
}

void input() {
  memset(isVis, false, size(isVis));
  cin >> N;
  for(int i = 0; i < N; i++) cin >> members[i];
  int temp1, temp2;
  for(int i = 0; i < N - 1; i++) {
    cin >> temp1 >> temp2;
    map[temp1 - 1].push_back(temp2 - 1);
    map[temp2 - 1].push_back(temp1 - 1);
  }
  
  isVis[0] = true;
  configureTree(0);
}

void treeDP(int current) {
  if(childs[current].size() == 0) {
    answer[current][0] = members[current];
    return;
  }
  
  int sum1 = 0, sum2 = 0;
  for(auto next: childs[current]) {
    treeDP(next);
    sum1 += answer[next][1];
    sum2 += max(answer[next][0], answer[next][1]);
  }
  
  answer[current][0] = sum1 + members[current];
  answer[current][1] = sum2;
}

int solution() {
  treeDP(0);
  
  return max(answer[0][0], answer[0][1]);
}

int main(){
  FAST;
  input();
  cout << solution() << endl;
}
