#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
string U;
string sol1,sol2;
int num[10],cnt,sz;
bool isFind;
void settings()
{
	for (int i = 0; i < 10; i++) num[i] = 2;
}
int main()
{
	cin >> U;
	cnt = 9;
	sz = U.size();
	settings();
	for (int i = 0;i<sz-1;i++)
	{
		if (num[cnt] == 0)
			cnt--;
		sol1 += '0' + cnt;
		num[cnt]--;
	}
	for (int i = 0; i <= sz; i++)
	{
		bool flag = false;
		settings();
		for (int j = 0; j < i; j++) {
			num[U[j] - '0']--;
			if (num[U[j] - '0'] < 0)
				flag = true;
		}
		if (flag) continue;
		if (sz == i) {
			sol2 = U;
			break;
		}
		int cur = U[i] - '0';
		string temp = U;
		if (cur == 0) continue;
		else
		{
			cur--;
			while (cur>=0 && num[cur] == 0)
				cur--;
			if (cur == -1) continue;
			temp[i] = cur + '0';
			num[cur]--;
			int A = 9;
			for (int j = i + 1; j < sz; j++)
			{
				while (num[A] == 0)
					A--;
				temp[j] = '0' + A;
				num[A]--;
			}
		}
		sol2 = max(sol2, temp);
	}
	if (sol2[0] != '0')
		cout << sol2;
	else
		cout << sol1;
}