#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_SIZE 210
int N,M,K;
int val, sol;
bool visited[MAX_SIZE];
int selected[MAX_SIZE];
vector<int> adj[MAX_SIZE];

bool dfs(int here){
    if(visited[here]) return false;
    visited[here]=true;
    for(int i=0;i<adj[here].size();i++){
        int there=adj[here][i];
        if(selected[there]==-1 || dfs(selected[there])){
            selected[there]=here;
            return true;
        }
    }
    return false;
}

void init(){
    memset(selected,-1,sizeof(selected));
}
