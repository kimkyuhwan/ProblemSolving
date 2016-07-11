#include <cstdio>
#include <vector>
using namespace std;
int idx=1,n,m;
int cmd, a, b, c;
vector<int> tree;
vector<int> lazy;
void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] ^= lazy[node];
		lazy[node] = 0;
	}
}
void update_range(int node, int start, int end, int left, int right, int diff) {
	update_lazy(node, start, end);
	if (left > end || right < start) {
		return;
	}
	if (left <= start && end <= right) {
		tree[node] ^= diff;
		return;
	}
	update_range(node * 2, start, (start + end) / 2, left, right, diff);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int my_xor(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return my_xor(node * 2, start, (start + end) / 2, left, right)^ my_xor(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}



int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (idx < n)
		idx <<= 1;
	tree.resize(idx * 2+1);
	lazy.resize(tree.size());
	for (int i = 0; i < n; i++)
		scanf("%d", &tree[i + idx]);
	for (int i = idx - 1; i >= 1; i--)
		tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			scanf("%d%d%d", &a, &b, &c);
			update_range(1, 0, n - 1, a - 1, b - 1, c);
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%d\n", my_xor(1, 0, n - 1, a-1, b - 1));
		}
	}
}