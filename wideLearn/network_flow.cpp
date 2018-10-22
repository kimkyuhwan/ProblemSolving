#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace  std;

#define INF 987654321
#define MAX_SIZE 52
// Edmonds-Karp Algorithm
int capacity[MAX_SIZE][MAX_SIZE]; // 간선 용량
int flow[MAX_SIZE][MAX_SIZE]; // 간선에 흐른 유량
vector<int> adj[MAX_SIZE]; // 연결된 간선

int ekNetworkFlow(){
    int totalFlow=0;
    int source;
    int sink;
    while(1){
        int prev[MAX_SIZE];
        memset(prev,-1,sizeof(MAX_SIZE));

        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int here=q.front();
            q.pop();
            for(int i=0;i<adj[here].size();i++){
                int there=adj[here][i];
                if(prev[there]!=-1) continue;

                if(capacity[here][there] - flow[here][there] > 0){
                    q.push(there);
                    prev[there]=here;
                    if(there==sink) break;
                }
            }
        }
        if(prev[sink]==-1) break;

        int _flow=INF;
        for(int i=sink;i!=source;i=prev[i]){
            int p=prev[i];
            _flow=min(_flow,capacity[p][i]-flow[p][i]);
        }
        for(int i=sink;i!=source;i=prev[i]){
            int p=prev[i];
            flow[p][i]+=_flow;
            flow[i][p]-=_flow;
        }
        totalFlow+=_flow;
    }
    return totalFlow;
}
