#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MMAX 100000
int N;
vector<int> postorder;
int inorder[MMAX];
vector<int> preorder;
void FindTree(int in_s, int in_e, int now){ // 1을 기준으로
    if(postorder.size() == 0) return;
   
    int tar = postorder.back();
    
    for(int i = now + 1; i <= in_e; i++){
        if(tar == inorder[i]){
            postorder.pop_back();
            FindTree(now, in_e, i);
            preorder.push_back(inorder[i]);
            break;
        }
    }
    if(postorder.size() == 0) return;
    tar = postorder.back();
    
    for(int i = in_s; i < now; i++){
        if(tar == inorder[i]){
            postorder.pop_back();
            FindTree(in_s, now - 1, i);
            preorder.push_back(inorder[i]);
        }
    }
}
void Solve(){
    for(int i = 0; i<N; i++){
        if(postorder.back() == inorder[i]){
            postorder.pop_back();
            FindTree(0, N-1, i);
            preorder.push_back(inorder[i]);
            return;
        }
    }
}

int main(){
    FAST;
    cin>>N;
    for(int i = 0; i<N; i++) cin>>inorder[i];
    for(int i = 0; i<N; i++){
        int N;
        cin>>N;
        postorder.push_back(N);
    }
    Solve();
    for(int i = preorder.size()-1; i>=0; i--) cout<<preorder[i]<<' ';
    cout<<'\n';
}
