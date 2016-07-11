#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
#define MAXX(a,b) (a>b) ? a : b
int N, cost[100010];
ll sol;
stack<int> st;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &cost[i]);
	cost[N] = 0;
	for (int i = 0; i <= N; i++)
	{
		while (!st.empty())
		{
			int cur = st.top();
			int last = cur;
			if (cost[cur] <= cost[i]) break;
			st.pop();
			last = (st.empty()) ? 0 : st.top() + 1;
			sol = MAXX(sol, cost[cur] * (i - last));
		}
		st.push(i);
	}
	printf("%lld", sol);
}