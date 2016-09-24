#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N,last,cnt,sol;
int A[10];
int B[26];
vector<int> val(10);
bool visited[26];
bool isFirst[26];
string str[10];
set<vector<int> > s;
bool isPossible()
{
	for (int i = 0; i < cnt; i++)
	{
		if (isFirst[A[i]] && val[i]==0) 
			return false;
	}
	return true;
}
bool isSol()
{
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < str[last].size(); i++)
	{
		sumB *= 10;
		sumB += val[B[str[last][i]-'A']];
	}
	for (int i = 0; i < last; i++)
	{
		int temp = 0;
		for (int j = 0; j < str[i].size(); j++)
		{
			temp *= 10;
			temp += val[B[str[i][j] - 'A'] ];
		}
		sumA += temp;
	}
	return sumA == sumB;
}

int main()
{
	scanf("%d", &N);
	last = N - 1;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		isFirst[str[i][0] - 'A'] = true;
		for (int j = 0; j < str[i].size(); j++)
		{
			if (visited[str[i][j] - 'A']) continue;
			visited[str[i][j] - 'A'] = true;
			B[str[i][j] - 'A'] = cnt;
			A[cnt++]=str[i][j] - 'A';

		}
		//reverse(str[i].begin(), str[i].end());
	}
	for (int i = 0; i < 10; i++)
		val[i] = i;
	do {
		if (!isPossible()) continue;
		if (isSol())
		{
			vector<int> temp = val;
			for (int i = 0; i <= 10 - cnt; i++)
				temp.pop_back();
			s.insert(temp);
		}
	}while(next_permutation(val.begin(),val.end()));
	printf("%d", s.size());
}