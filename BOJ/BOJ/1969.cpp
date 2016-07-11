#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int w[52][256];
int score[1010];
string str[1010];
int N,M,maxx;
string sol;
char dna[4] = { 'A','C','G','T' };
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		for (int j = 0; j < M; j++)
			w[j][str[i][j]]++;
	}
	for (int i = 0; i < M; i++)
	{
		char a = 0;
		int weight=0;
		for (int j = 0; j < 4; j++)
		{
			if (weight < w[i][dna[j]])
			{
				weight = w[i][dna[j]];
				a = dna[j];
			}
		}
		sol += a;
	}
	cout << sol << endl;
	int hm = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (sol[j] != str[i][j])
				hm++;
		}
	}
	cout << hm << endl;
}