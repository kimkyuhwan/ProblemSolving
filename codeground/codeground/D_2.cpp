#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define INF 9876543212345
const int MAXN = 200010;
const int MAXL = 20;
int whereV[10010];
int N, M;
int a, b, d, timer, cnt;
int adj[510][510], tree[510][510];
ll arr[510][510];
vector<vector<int> > group;
vector<ll> dist;
priority_queue<pair<ll, pair<int, int> > > E;
int tin[MAXN], tout[MAXN], up[MAXN][MAXL];
void remove_edge(int a, int b);
bool upper(int u, int v);
int makeTree(int start);
int get_lca(int u, int v);
void dfs(int here, int prev);
void fillGroup(int cur, int pp);
ll getDistance(int _a, int _b, ll _d);
void dfs(int here, int prev) {
	tin[here] = timer++; //언제 방문했는지 기록
	up[here][0] = prev;
	for (int i = 1; i < MAXL; i++) {
		//here의 2^i번째 조상을 저장
		up[here][i] = up[up[here][i - 1]][i - 1];
	}

	for (int i = 1; i <= N; i++) {
		if (tree[here][i]!=-1 && i != prev) {
			dfs(i, here);
		}
	}
	tout[here] = timer++; //언제 빠져나왔는지 기록
}
void remove_edge(int a, int b)
{
	tree[a][b] = adj[a][b];
	tree[b][a] = adj[b][a];
	adj[a][b] = -1;
	adj[b][a] = -1;
}
bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int makeTree(int start)
{
	dist = vector<ll>(N + 1, INF);
	vector<int> parent(N + 1);
	dist[1] = 0;
	priority_queue<pair<ll, int> > pq;
	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		int here = pq.top().second;
		ll curdist = -pq.top().first;
		pq.pop();
		for (int there = 1; there <= N; there++)
		{
			if (adj[here][there] == -1) continue;
			ll nextdist = adj[here][there] + curdist;
			if (dist[there] > nextdist)
			{
				dist[there] = nextdist;
				parent[there] = here;
				pq.push(make_pair(-dist[there], there));
			}
		}
	}
	ll totaldist = 0;
	for (int i = 2; i <= N; i++)
	{
		totaldist += dist[i];
		int there = parent[i];
		remove_edge(i, there);
	}
	return totaldist;
}
void fillGroup(int cur, int pp)
{
	group[cnt].push_back(cur);
	whereV[cur] = cnt;
	for (int i = 1; i <= N; i++)
	{
		if (tree[cur][i]==-1 || pp==i) continue;
		fillGroup(i, cur);
	}
}
int get_lca(int u, int v) {
	if (upper(u, v)) return u; //u가 lca라면
	if (upper(v, u)) return v; //v가 lca라면
							   //설명하기 힘든데 모든 경우를 커버할 수 있음..
	for (int i = MAXL - 1; i >= 0; i--) {
		if (!upper(up[u][i], v)) {
			u = up[u][i]; // up[u][2] == up[up[u][1]][1]
		}
	}
	return up[u][0];
}
ll getDistance(int _a, int _b, ll _d)
{
	ll ret = 0;
	int gA = whereV[a];
	int gB = whereV[b];
	int szA = group[gA].size();
	int szB = group[gB].size();
	ll newAtoB = _d - dist[a] + dist[b];
	ll distA[3] = {}, distB[3] = {};
	ll tri = dist[a] + dist[b] + _d;
	int cA[3] = {}, cB[3] = {};
	ll distAbsA[2] = {}, distAbsB[2] = {};
	for (int i = 0; i < szA; i++)
		distAbsA[1] += abs(dist[a] - dist[group[gA][i]]);
	for (int i = 0; i < szB; i++)
		distAbsB[1] += abs(dist[b] - dist[group[gB][i]]);
	for (int i = 0; i < szA; i++)
	{
		int here = group[gA][i];
		if (dist[here] < dist[a] - dist[here])
		{
			cA[0]++;
			distA[0] += dist[here];
			continue;
		}if (dist[a] < dist[here])
		{
			cA[1]++;
			distA[1] += dist[here];
		}
		else
		{
			cA[2]++;
			distA[2] += dist[here];
		}
	}
	for (int i = 0; i < szB; i++)
	{
		int here = group[gB][i];
		if (dist[here] < dist[b] - dist[here])
		{
			cB[0]++;
			distB[0] += dist[here];
			continue;
		}if (dist[b] < dist[here])
		{
			cB[1]++;
			distB[1] += dist[here];
		}

		else
		{
			cB[2]++;
			distB[2] += dist[here];
		}

	}

	for (int i = 0; i < cA[0]; i++)
		distAbsA[0] -= abs(dist[a] - dist[group[gA][i]]);
	distAbsA[0] += distAbsA[1];
	distAbsA[1] += dist[a];
	for (int i = 0; i < cB[0]; i++)
		distAbsB[0] -= abs(dist[b] - dist[group[gB][i]]);
	distAbsB[0] += distAbsB[1];
	distAbsB[1] += dist[b];
	ll dist_A = distA[0] + distA[1] + distA[2], dist_B = distB[0] + distB[1] + distB[2];
	/*	ret = (distA[1] + distA[2])*szB;
	ret -= (distAbsB[1] * (cA[1] + cA[2]) + distAbsA[0] * szB);
	ret += (distB[1] + distB[2])*szA;
	ret -= dist[a] + dist[b] - _d;
	ret -= (distAbsA[1] * (cB[1] + cB[2]) + distAbsB[0] * szA);
	ret -= cA[0] * distAbsA[0] + ((cB[1] + cB[2])*cA[0])*(dist[b] + _d) + distA[0] * (cA[1] + cA[2]);
	ret -= cB[0] * distAbsB[0] + ((cA[1] + cA[2])*cB[0])*(dist[a] + _d) + distB[0] * (cB[1] + cB[2]);
	*/
	ret += (dist[a] + dist[b]) * 2;
	ret += (dist_A)*szB + (dist_B)*szA;
	ret -= (distAbsB[1])*(szB)+ (_d*(szB + 1))*(cA[1] + cA[2]) + ((szB + 1)*distAbsA[0]);
	ret -= (distAbsA[1] * (szA)) + (_d*(szA + 1))*(cB[1] + cB[2]) + ((szA + 1)*distAbsB[0]);
	ret -= (cA[1] * cA[2])*(_d + dist[b] + distAbsA[1] - distAbsA[0]) + distAbsA[0] * cA[0];
	ret -= (cB[1] * cB[2])*(_d + dist[a] + distAbsB[1] - distAbsB[0]) + distAbsB[0] * cB[0];

	return ret;
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.		scanf("%d %d", &N, &M);
		cnt = timer = 0;
		ll sol = 0;
		memset(adj, -1, sizeof(adj));
		memset(tree, -1, sizeof(tree));
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &a, &b, &d);
			if (N > 100)
			{
				sol = -1;
				continue;
			}
			adj[a][b] = d;
			adj[b][a] = d;
			E.push(make_pair(-d, make_pair(a, b)));
		}
		
		if(N<=100)
		{
			makeTree(1);
			dfs(1, 1);
			vector<int> onecnt;
			for (int i = 1; i <= N; i++)
				if (tree[1][i] != -1)
					onecnt.push_back(i);
			group = vector<vector<int> >(onecnt.size());
			for (int i = 0; i < onecnt.size(); i++)
			{
				int there = onecnt[i];
				fillGroup(there, 1);
				cnt++;
			}
			bool isPossible = false;
			
			while (!E.empty() && !isPossible)
			{
				ll dist = -E.top().first;
				a = E.top().second.first;
				b = E.top().second.second;
				E.pop();
				if (a == 1 || b == 1) continue;
				if (get_lca(a, b) != 1) continue;	
				tree[a][b] = dist;
				sol = getDistance(a,b,dist);
				tree[a][b] = -1;
				break;
			}
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n%lld\n", test_case, sol);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}