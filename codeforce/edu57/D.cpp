#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define LINF 398765432112345678LL
#define MOD 998244353 
typedef long long ll;
int N;
int a[100010];
ll dp[100010][5];
ll sol;
char str[100010];
char pattern[5] ={'h','a','r','d',' '};
ll solution(int pos,int state){
	if(pos==N) {
		if(state==4) return LINF;
		return 0;
	}
	ll &ret=dp[pos][state];
	if(ret!=-1) return ret;
	ret=LINF;
	if(pattern[state]==str[pos]){
		ret=min(solution(pos+1,state)+a[pos],solution(pos+1,state+1));
	}
	else{
		ret=min(ret,solution(pos+1,state));
	}
	return ret;
}



int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	scanf(" %s",str);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
	sol=solution(0,0);
	printf("%lld\n",sol);
	return 0;
}