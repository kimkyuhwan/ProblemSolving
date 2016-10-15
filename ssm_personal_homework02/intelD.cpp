#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <deque>
using namespace std;
int N,last;
string str;
bool isPossible[100010];
bool Use[26];
vector<deque<int> > sss;
int main()
{
	cin >> N >> str;
	sss.resize(26);
	for (int i = 0; i < str.size(); i++)
	{
		int cu = str[i] - 'a';
		sss[cu].push_back(i);
		if (i>=N)
		{
			int pr = str[i - N] - 'a';
			sss[pr].pop_front();
		}
		if (i >= N - 1)
		{
			for (int j = 0; j < 26; j++)
			{
				if (sss[j].empty()) continue;
				bool flag = false;
				for (int k = 0; k < sss[j].size(); k++)
				{
					if (isPossible[sss[j][k]])
					{
						flag = true;
						break;
					}
				}
				if (flag) break;
				last = max(last, j);
				isPossible[sss[j].back()] = true;
				break;
			}
		}	
	}
	string sol = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (isPossible[i] || str[i]<(char)(last+'a')) 
			sol.push_back(str[i]);
	}
	sort(sol.begin(), sol.end());
	cout << sol;
}