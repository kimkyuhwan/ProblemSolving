#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;
#define ZEGOP 100000LL
#define MAXX 10000000LL
#define MAXXX 100000000000000
vector < ll > prime;
vector<vector<ll> > p;
map<ll,ll> mm;
vector < pair < ll, ll > > D;
bool isPrime[MAXX + 1];
int tc;
int main()
{
	freopen("input.txt", "r", stdin);
	memset(isPrime, true, sizeof(isPrime));
	for (ll i = 2; i <= MAXX; i++)
	{
		if (!isPrime[i])
			continue;
		prime.push_back(i);
		//p.push_back(vector<ll>());
		for (ll j = i + i; j <= MAXX; j += i)
			isPrime[j] = false;
		if (i >=ZEGOP)
		{
		//	p.back().push_back(i);
		//	p.back().push_back(i*i);
		//	mm[i] = 1;
			mm[i*i] = i;
		}
		else
		{
		//	p.back().push_back(i);
		//	mm[i] = 1;
			for (ll j = i*i; j <= MAXXX; j *= i)
			{
//				p.back().push_back(j);
				mm[j] = i;
			}
		}
	}
	ll ppp = 1;
	mm[1] = 1;
	for (auto it = mm.begin(); it != mm.end(); it++)
	{
		it->second = (it->second*ppp) % MOD;
		ppp = it->second;
//		cout << it->first << ' ' << it->second <<  endl;
	}

	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		ll num;
		scanf("%lld", &num);
		auto sol = mm.upper_bound(num);
		sol--;
		printf("Case %d: %lld\n", i, sol->second);
	}
}