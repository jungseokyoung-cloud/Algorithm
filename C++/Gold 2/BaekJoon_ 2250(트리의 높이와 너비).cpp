#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

vector<int> tree[10001];
int N,nowIdx,rootNode;
int ans[10001][2];
int nodeCount[10001];
int width, level = INT_MAX;

void Setting(){
    for(int i = 1; i<=N; i++){
        if(nodeCount[i] == 1) rootNode = i;
        ans[i][0] = INT_MAX;
        ans[i][1] = 0;
    }
}

void Input (){
    cin>>N;
    int now,lleft,rright;
    for(int i = 0; i<N; i++){
        cin>>now>>lleft>>rright;
        nodeCount[now] ++;
        if(lleft != -1) nodeCount[lleft]++;
        if(rright != -1) nodeCount[rright]++;

        tree[now].push_back(lleft);
        tree[now].push_back(rright);
    }
}

void Find_Size(int now, int d){ //  트리 중위선회
    int lleft = tree[now][0];
    int rright = tree[now][1];
    
    if(lleft != -1) Find_Size(lleft, d+1);
    nowIdx++;
    ans[d][0] = min(nowIdx, ans[d][0]);
    ans[d][1] = max(nowIdx, ans[d][1]);

    int comp = ans[d][1] - ans[d][0] + 1;
    
    if(comp > width){
        level = d;
        width = comp;
    }
    else if(comp == width && level > d) level = d;
    if(rright != -1) Find_Size(rright, d+1);
}


int main(){
    FAST;
    Input();
    Setting();
    Find_Size(rootNode, 1);
   
    cout<<level<<' '<<width<<endl;
}
