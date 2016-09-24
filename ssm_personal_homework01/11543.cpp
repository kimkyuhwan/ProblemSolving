#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> dot;
dot d[200010];
int N;
ll total;
ll ccw(dot A, dot B, dot C)
{
	ll ret = A.second*B.first + B.second*C.first + C.second*A.first;
	ret -= A.first*B.second + B.first*C.second + C.first*A.second;
	return ret;
}
ll solution(int a,int b)
{
	ll ret = 0;
	for (int i = a; i <=b ; i++)
	{
		ret += ccw(make_pair(0,0),d[i], d[i+1]);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &d[i].second, &d[i].first);
		d[i + N].second = d[i].second;
		d[i + N].first = d[i].first;
	}
	total = solution(0, N-1);
	ll sum=0;
	ll sol = LLONG_MAX;
	int a = 0;
	int b = 1;
	for (a = 0; a < N ; a++)
	{
		
		while (sum < total / 2)
		{
			sum += ccw(d[a],d[b],d[ b + 1]);
			b++;
		}
		ll plast = sum - ccw(d[a], d[b - 1], d[b]);
		ll val = max(min(total - sum, sum), min(total - (plast), plast));
		sol = min(sol, val);
		sum -= ccw(d[a], d[a+1], d[b]);
	}
	printf("%lld %lld",total-sol, sol);
}