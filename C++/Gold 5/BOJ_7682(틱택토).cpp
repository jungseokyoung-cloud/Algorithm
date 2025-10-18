#include <iostream>
#include <string>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
void toBoard(string &str);

char board[3][3];

bool solution(string &str) {
  int xCnt = 0, oCnt = 0;
  for(auto c: str) {
    if(c == 'X') xCnt += 1;
    else if(c == 'O') oCnt += 1;
  }
  if(!(xCnt - oCnt == 1 || xCnt == oCnt)) return false;
// 둘다 완성되어있는 경우
  toBoard(str);
  int xScore = 0, oScore = 0;
  for(int i = 0; i < 3; i++) {
    if(board[i][0] != '.' && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) board[i][0] == 'O' ? oScore += 1 : xScore +=1;
    if(board[0][i] != '.' && (board[0][i] == board[1][i]) && (board[0][i] == board[2][i])) board[0][i] == 'O' ? oScore += 1 : xScore +=1;
  }
  
  if(board[0][0] != '.' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) board[0][0] == 'O' ? oScore += 1 : xScore +=1;
  if(board[0][2] != '.' && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) board[0][2] == 'O' ? oScore += 1 : xScore +=1;

  if(xScore >= 1 && oScore >= 1) return false;
  if(xCnt + oCnt != 9 && xScore == 0 && oScore == 0) return false;
  if(xScore >= 1 && xCnt - oCnt != 1) return false;
  if(oScore >= 1 && xCnt != oCnt) return false;
  return true;
}

void toBoard(string &str) {
  for(int i = 0; i < str.size(); i++) {
    board[i/3][i%3] = str[i];
  }
}

int main(){
  FAST;
  string temp;
  while(true) {
    cin >> temp;
    if(temp == "end") break;
    bool res = solution(temp);
    string printVal = res ? "valid" : "invalid";
    cout << printVal << endl;
  }
}
