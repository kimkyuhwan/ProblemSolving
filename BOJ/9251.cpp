#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string A, B,S;
int dp[1010][1010];
pair<int,int> p[1010][1010];
int szA, szB;
int solution(int a, int b)
{
	if (a == szA || b == szB) return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = (A[a] == B[b]) ? 1 : 0;
	if (ret == 1)
	{
		ret += solution(a + 1, b + 1);
		p[a + 1][b + 1] = make_pair(a, b);
	}
	else
	{
		if (solution(a + 1, b) > solution(a, b + 1))
		{
			ret = solution(a + 1, b);
			p[a + 1][b] = make_pair(a, b);
		}
		else
		{
			ret = solution(a, b + 1);
			p[a][b+1] = make_pair(a, b);
		}
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> A >> B;
	szA = A.size();
	szB = B.size();
	int sol = solution(0, 0);
	cout << sol <<endl;
}