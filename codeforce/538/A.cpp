#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int n, cnt;
int c[5010];
int val;
int dp[5010][5010];


int solution(int l, int r) {
	if (l >= r) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = 987654321;
	if(c[l] == c[r]){
		ret=solution(l+1,r-1)+1;
	}
	ret=min(ret,min(solution(l+1,r)+1,solution(l,r-1)+1));
	return ret;
}


int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	int pre = -1;
	for (int i = 0; i<n; i++) {
		scanf("%d", &val);
		if (val != pre) {
			c[cnt++] = val;
			pre = val;
		}
	}
	printf("%d", solution(0, cnt-1));

	return 0;
}