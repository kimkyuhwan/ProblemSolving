#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
typedef long long ll;
const int N = 200010;
const int L = 20;

int n,m, a,b,u,v;
int timer;
int tin[N], tout[N], up[N][L];
/*
timer는 시간의 흐름을 나타냄
tin은 해당 정점에 방문한 시간
tout은 해당 정점에서 기능을 모두 수행마쳤을 떄 시간
up[i][j]는 i의 2^j번째 조상이다.
*/
vector<vector<int> > adj;
void dfs(int here, int prev) {
	tin[here] = timer++; //언제 방문했는지 기록
	up[here][0] = prev;
	for (int i = 1; i < L; i++) {
		//here의 2^i번째 조상을 저장
		up[here][i] = up[up[here][i - 1]][i - 1];
	}

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (next != prev) {
			dfs(next, here);
		}
	}
	tout[here] = timer++; //언제 빠져나왔는지 기록
}

bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v) {
	if (upper(u, v)) return u; //u가 lca라면
	if (upper(v, u)) return v; //v가 lca라면
							   //설명하기 힘든데 모든 경우를 커버할 수 있음..
	for (int i = L - 1; i >= 0; i--) {
		if (!upper(up[u][i], v)) {
			u = up[u][i]; // up[u][2] == up[up[u][1]][1]
		}
	}
	return up[u][0];
}
int main() {
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &u, &v);
		printf("%d\n", get_lca(u, v));
	}
	return 0;
}