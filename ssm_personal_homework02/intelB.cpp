#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
set<vector<int> > sol;
vector<int> normal;
vector<vector<int> > A;
int N, M,K;
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
		normal.push_back(i + 1);
	sol.insert(normal);
	for(int i=0;i<M;i++)
	{
		for (int j = i+1; j < M; j++)
		{
			vector<int> temp=normal;
			swap(temp[i], temp[j]);
			sol.insert(temp);
		}
	}
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &K);
			temp.push_back(K);
		}
		A.push_back(temp);
	}
	for(int i=0;i<M;i++)
		for (int j = i; j < M; j++)
		{
			vector< vector<int> > temp = A;
			int cnt = 0;
			for (int k = 0; k < N; k++)
			{
				swap(temp[k][i], temp[k][j]);
				if (sol.count(temp[k]))
					cnt++;
			}
			if (cnt == N)
			{
				puts("YES");
				return 0;
			}
		}
	puts("NO");
}