#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,cnt;
string str[110];
queue<int> q;
vector<int> adj[26];
int isExisted[26];
int ind[26];
int visited[26];
string solution()
{
	string ret = "";
	int cnt = q.size();
	while (!q.empty()) {
		if (q.size() != 1) return "?";
		int here = q.front();
		q.pop();
		ret += (here + 'a');
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			ind[there]--;
			if (ind[there] == 0)
			{
				q.push(there);
				visited[there] = 1;
			}
		}
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++)
		{
			if (isExisted[str[i][j] - 'a']) continue;
			isExisted[str[i][j] - 'a'] = 1;
			cnt++;
		}
	}
	for(int i=1;i<N;i++)
		for (int j = 0; j < str[i].size() && j < str[i - 1].size(); j++)
		{
			if (str[i][j] != str[i - 1][j])
			{
				int a = str[i-1][j] - 'a';
				int b = str[i][j] - 'a';
				adj[a].push_back(b);
				ind[b]++;
				for (int k = 0; k < adj[b].size(); k++)
				{
					int there = adj[b][k];
					if (there == a)
					{
						cout << "!";
						return 0;
					}
				}
				break;
			}
		}
	for (int i = 0; i < 26; i++)
	{
		if (isExisted[i] && ind[i] == 0)
			q.push(i);
	}
	cout << solution();
}