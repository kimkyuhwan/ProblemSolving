#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_SIZE 210
int N,M,K;
int val, sol;
bool visited[MAX_SIZE];
int selectedByCow[MAX_SIZE];
vector<int> adj[MAX_SIZE];

bool dfs(int here){
    if(visited[here]) return false;
    visited[here]=true;
    for(int i=0;i<adj[here].size();i++){
        int there=adj[here][i];
        if(selectedByCow[there]==-1 || dfs(selectedByCow[there])){
            selectedByCow[there]=here;
            return true;
        }
    }
    return false;
}


int main(){
    memset(selectedByCow,-1,sizeof(selectedByCow));
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&K);
        for(int j=0;j<K;j++){
            scanf("%d",&val);
            adj[i].push_back(val);
        }
    }
    for(int i=1;i<=N;i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i)){
            sol++;
        }
    }
    printf("%d\n",sol);
}
