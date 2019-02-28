#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MOD 998244353 
typedef long long ll;
int N;
int l,r;
int f,b;
ll sol=1;
int nf=1,nb=1;
char str[200010],temp,temp2;
int main(){
	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	scanf(" %s",str);
	sol=1;
	temp=str[N-1];
	for(int i=N-2;i>=0;i--){
		if(str[i]!=temp){
			b=i+1;
			break;
		}
		nf++;
	}
	if(nf==N){
		for(int i=1;i<N;i++){
			sol+=(i+1);
			sol%=MOD;
		}
		printf("%lld\n",sol);
		return 0;
	}
	sol+=nf;
	temp2=str[0];
	for(int i=1;i<N;i++){
		if(str[i]!=temp2){
			f=i-1;
			break;
		}
		nb++;
	}
	sol+=nb;
	if(temp==temp2){
		sol+=nf*nb;
	}
	printf("%lld\n",sol);
	return 0;
}