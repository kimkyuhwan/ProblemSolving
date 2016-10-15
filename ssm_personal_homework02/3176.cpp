#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
typedef long long ll;
const int N = 200010;
const int L = 20;
int n, A, B, C, K,timer;
int tin[N], tout[N], up[N][L];
int maxx[N][L];
int minn[N][L];
vector<vector<pair<int, int> > > adj;
void dfs(int here, int prev,int cost) {
	tin[here] = timer++; //언제 방문했는지 기록
	up[here][0] = prev;
	minn[here][0] = cost;
	maxx[here][0] = cost;
	for (int i = 1; i < L; i++) {
		//here의 2^i번째 조상을 저장
		minn[here][i] = min(minn[here][i], minn[up[here][i - 1]][i - 1]);
		maxx[here][i] = max(maxx[here][i], maxx[up[here][i - 1]][i - 1]);
		up[here][i] = up[up[here][i - 1]][i - 1];
	}

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i].first;
		if (next != prev) {
			dfs(next, here,adj[here][i].second);
		}
	}
	tout[here] = timer++; //언제 빠져나왔는지 기록
}

bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

pair<int,int> get_lca(int u, int v) {
	if (upper(u, v)) return make_pair(minn[v][0], maxx[v][0]); //u가 lca라면
	if (upper(v, u)) return make_pair(minn[u][0], maxx[u][0]);
 //v가 lca라면
							   //설명하기 힘든데 모든 경우를 커버할 수 있음..
	int MInn=min(minn[u][0],minn[v][0]), MAxx=max(maxx[u][0],maxx[v][0]);
	for (int i = L - 1; i >= 0; i--) {
		if (!upper(up[u][i], v)) {
			MInn = min(MInn, minn[u][i]);
			MAxx = max(MAxx, minn[u][i]);
			u = up[u][i]; // up[u][2] == up[up[u][1]][1]
		}
	}
	
	return make_pair(MInn,MAxx);
}
int main()
{
	freopen("input.txt", "r", stdin);
	memset(minn, 0x1f, sizeof(minn));
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		adj[B].push_back(make_pair(A, C));
		adj[A].push_back(make_pair(B, C));
	}
	dfs(1, 1,0);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &A, &B);
		pair<int, int> sol = get_lca(A, B);
		printf("%d %d\n", sol.first, sol.second);
	}

}