#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MOD 998244353 
typedef long long ll;
int T,ang;
int dp[181];

void getRadius(int dot){
	ll total=(dot-2)*180;
	double large=(double)total/dot;
	double b = (double)large/(dot-2);
	for(int i=1;i<=dot-2;i++){
		double val=b*i+(1e-12);
		ll val2 = val;
		if(val-val2>=1e-9) continue; 
		if(dp[val2]!=-1) continue;
		dp[val2]=dot;
	}
}


int main(){
	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	for(int i=3;i<=360;i++){
		getRadius(i);
	}
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&ang);
		printf("%d\n",dp[ang]);
	}
	return 0;
}