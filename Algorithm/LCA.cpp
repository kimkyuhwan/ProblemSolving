#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
typedef long long ll;
const int N = 200010;
const int L = 20;

int n, m;
int timer;
int tin[N], tout[N], up[N][L];
/*
timer는 시간의 흐름을 나타냄
tin은 해당 정점에 방문한 시간
tout은 해당 정점에서 기능을 모두 수행마쳤을 떄 시간
up[i][j]는 i의 2^j번째 조상이다.
*/
vector<int> adj[N];

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

void init() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main() {
	init();
	dfs(1, 1);

	for (int node = 1; node <= n; node++) {
		printf("node %d:  ", node);
		for (int i = 0; i < L; i++) {
			printf("%d ", up[node][i]);
		}
		puts("");
	}
	return 0;
}