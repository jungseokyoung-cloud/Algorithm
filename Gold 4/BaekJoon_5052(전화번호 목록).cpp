#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int T,N;
bool ans;
string number;
const int NUMBER = 10;

struct Trie{
    Trie * next[NUMBER]; // 자신과 타입이 같은 자식이 10개 있어야함
    bool end, child;
    
    Trie(){  // 생성자(막 노드마다 0~9까지 공간을 trie 를 가져와여되기 때문)
        fill(next, next+NUMBER, nullptr);
        end=false;
        child=false;
    }
    
    ~Trie(){
        for(int i=0; i<NUMBER; i++){
            if(next[i]!=nullptr){
                delete next[i];
            }
        }
    }
    
    bool Insert(int idx){
        if(idx==number.size()){
            end=true;
            if(child)   return false;
            else    return true;
        }
        child=true;
        int nextNode = number[idx]-'0';
                
        if(next[nextNode]==nullptr)
            next[nextNode] = new Trie();
        
        bool res = next[nextNode] -> Insert(idx+1); // idx==number.size()-1일때 값반환
        
        if(res && !end) return true;
        else return false;
    }
 
};

int main(){
    FAST;
    cin>>T;
    while (T--) {
        ans=true;
        Trie * Root = new Trie();
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>number;
            if(ans){
                bool res=Root->Insert(0);
                if(!res) ans=false;
            }
        }
        
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
