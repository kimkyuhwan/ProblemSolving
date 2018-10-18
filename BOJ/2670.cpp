#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

double a[10001];
double dp[10001];
int n;
double solution(int x) {
	double &ret = dp[x];
	if (ret!=0)return ret;
	return ret = a[x] > a[x] * solution(x + 1) ? a[x] : a[x] * solution(x + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &a[i]);
	dp[n] = a[n];
	double result = solution(1);
	for (int i = 2; i <= n; i++) {
		if (result < dp[i])
			result = dp[i];
	}
	printf("%.3lf\n", result);
	return 0;
}