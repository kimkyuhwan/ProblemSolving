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
timer�� �ð��� �帧�� ��Ÿ��
tin�� �ش� ������ �湮�� �ð�
tout�� �ش� �������� ����� ��� ���ึ���� �� �ð�
up[i][j]�� i�� 2^j��° �����̴�.
*/
vector<vector<int> > adj;
void dfs(int here, int prev) {
	tin[here] = timer++; //���� �湮�ߴ��� ���
	up[here][0] = prev;
	for (int i = 1; i < L; i++) {
		//here�� 2^i��° ������ ����
		up[here][i] = up[up[here][i - 1]][i - 1];
	}

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (next != prev) {
			dfs(next, here);
		}
	}
	tout[here] = timer++; //���� �������Դ��� ���
}

bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v) {
	if (upper(u, v)) return u; //u�� lca���
	if (upper(v, u)) return v; //v�� lca���
							   //�����ϱ� ���絥 ��� ��츦 Ŀ���� �� ����..
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