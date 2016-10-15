#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1010][1010];
string A, B;
int solution(int a, int b)
{
	if (a == A.size() || b == B.size())
		return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = 0;
	if (A[a] == B[b])
		ret += solution(a + 1, b + 1) + 1;
	else
		ret = max(solution(a, b + 1), solution(a + 1, b));
	return ret;
}
int main()
{
	while (cin >> A >> B)
	{
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solution(0, 0));
	}


}