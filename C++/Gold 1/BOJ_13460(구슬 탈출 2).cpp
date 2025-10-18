#include <iostream>
#include <vector>

using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

void tracking(pair<int, int> redPos, pair<int, int> bluePos, int cnt);
void move(pair<int, int> &pos, int dir);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, answer;
pair<int, int> desti;
vector<vector<char>> board;
void tracking(pair<int, int> redPos, pair<int, int> bluePos, int cnt);

int solution(pair<int, int> redPos, pair<int, int> bluePos) {
  answer = 20;
  tracking(redPos, bluePos, 0);
  return answer == 20 ? -1 : answer;
}

void tracking(pair<int, int> redPos, pair<int, int> bluePos, int cnt) {
  if(answer < cnt || cnt >= 10) return;

  board[redPos.first][redPos.second] = '.';
  board[bluePos.first][bluePos.second] = '.';

  for(int i = 0; i < 4; i++) {
    pair<int, int> firstMove = redPos;
    pair<int, int> secondMove = bluePos;
    bool redIsFirst = true;
    
    if(i == 0 && bluePos.first < redPos.first) { swap(firstMove, secondMove); redIsFirst = false;
    } else if(i == 1 && bluePos.second < redPos.second) {
      swap(firstMove, secondMove); redIsFirst = false;
    } else if(i == 2 && bluePos.first > redPos.first) {
      swap(firstMove, secondMove); redIsFirst = false;
    } else if(i == 3 && bluePos.second > redPos.second) {
      swap(firstMove, secondMove); redIsFirst = false;
    }
   
    move(firstMove, i);
    if(firstMove != desti) board[firstMove.first][firstMove.second] = '#';
    
    move(secondMove, i);
    if(secondMove != desti) board[secondMove.first][secondMove.second] = '#';
    
    if(firstMove != desti) board[firstMove.first][firstMove.second] = '.';
    if(secondMove != desti) board[secondMove.first][secondMove.second] = '.';
        
    if(redIsFirst && secondMove == desti) continue;
    if(!redIsFirst && firstMove == desti) continue;

    if(redIsFirst && firstMove == desti) { answer = min(answer, cnt + 1); return; }
    else if(!redIsFirst && secondMove == desti) { answer = min(answer, cnt + 1); return; }
    if(redIsFirst) tracking(firstMove, secondMove, cnt + 1);
    else tracking(secondMove, firstMove, cnt + 1);
  }
}

void move(pair<int, int> &pos, int dir) {
  while(true) {
    int nx = pos.first + dx[dir];
    int ny = pos.second + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
    if(board[nx][ny] == '#') break;
    pos = {nx, ny};
    
    if(desti.first == nx && desti.second == ny) return;
  }
}

int main() {
  FAST;
  cin >> n >> m;
  pair<int, int> redPos;
  pair<int, int> bluePos;
  
  board = vector<vector<char>>(n, vector<char>(m, 0));
  char temp;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> temp;
      if(temp == 'R') redPos = {i, j};
      else if(temp == 'B') bluePos = {i, j};
      else if(temp == 'O') desti = {i, j};
      
      if(temp == 'R' || temp == 'B') temp = '.';
      board[i][j] = temp;
    }
    
  }
  cout << solution(redPos, bluePos) << endl;

}
