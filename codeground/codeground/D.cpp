#include <cstdio>
#include <cmath>
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
vector < vector < pair<int, ll>  > > adj, tree;
vector<vector<int> > group;
vector<ll> dist;
priority_queue<pair<ll, pair<int, int> > > E;
int tin[MAXN], tout[MAXN], up[MAXN][MAXL];
void remove_edge(int a, int b);
int makeTree(int start);
void dfs(int here, int prev);
void fillGroup(int cur, int pp);
ll getDistance(int _a, int _b, ll _d);
void dfs(int here, int prev) {
	tin[here] = timer++; //���� �湮�ߴ��� ���
	up[here][0] = prev;
	for (int i = 1; i < MAXL; i++) {
		//here�� 2^i��° ������ ����
		up[here][i] = up[up[here][i - 1]][i - 1];
	}

	for (int i = 0; i < tree[here].size(); i++) {
		int next = tree[here][i].first;
		if (next != prev) {
			dfs(next, here);
		}
	}
	tout[here] = timer++; //���� �������Դ��� ���
}
void remove_edge(int a, int b)
{
	for (int i = 0; i < adj[a].size(); i++)
	{
		int there = adj[a][i].first;
		if (b == there)
		{
			tree[a].push_back(make_pair(b, adj[a][i].second));
			adj[a].erase(adj[a].begin() + i);
			break;
		}
	}
	for (int i = 0; i < adj[b].size(); i++)
	{
		int there = adj[b][i].first;
		if (a == there)
		{
			tree[b].push_back(make_pair(a, adj[b][i].second));
		//	adj[b].erase(adj[b].begin() + i);
			break;
		}
	}
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
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll nextdist = adj[here][i].second + curdist;
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
	for (int i = 0; i < tree[cur].size(); i++)
	{
		int there = tree[cur][i].first;
		if (there == pp) continue;
		fillGroup(there, cur);
	}
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
	ret -= (distAbsB[1])*szB + (_d*(szB + 1))*(cA[1] + cA[2]) + ((szB + 1)*distAbsA[0]);
	ret -= (distAbsA[1] * szA + (_d*(szA + 1))*(cB[1] + cB[2]) + ((szA + 1)*distAbsB[0]));
	ret -= (cA[1] * cA[2])*(_d + dist[b] + distAbsA[1] - distAbsA[0]) + distAbsA[0] * cA[0];
	ret -= (cB[1] * cB[2])*(_d + dist[a] + distAbsB[1] - distAbsB[0]) + distAbsB[0] * cB[0];
	ret -= (tri - 2*dist[b])*(N - 1 - szA - szB);
	ret -= (tri - 2 * dist[a])*(N - 1 - szA - szB);
	return ret;
}


int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d %d", &N, &M);
		cnt = timer = 0;
		adj = vector < vector<pair<int, ll> > >(N + 1);
		tree = vector< vector<pair<int, ll> > >(N + 1);
		E = priority_queue<pair<ll, pair<int, int> > >();
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &a, &b, &d);
			adj[a].push_back(make_pair(b, d));
			adj[b].push_back(make_pair(a, d));
			E.push(make_pair(-d, make_pair(a, b)));
		}
		makeTree(1);
		dfs(1, 1);
		group = vector<vector<int> >(tree[1].size());
		for (int i = 0; i < tree[1].size(); i++)
		{
			int there = tree[1][i].first;
			fillGroup(there, 1);
			cnt++;
		}
		bool isPossible = false;
		ll sol = 0;
		while (!E.empty() && !isPossible)
		{
			ll dist = -E.top().first;
			a = E.top().second.first;
			b = E.top().second.second;
			E.pop();
			if (a == 1 || b == 1) continue;
			if (whereV[a]==whereV[b]) continue;
			ll sum = getDistance(a, b, dist);
			sol = sum;
			break;
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n%lld\n", test_case, sol);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}