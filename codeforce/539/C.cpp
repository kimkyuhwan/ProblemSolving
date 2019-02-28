#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int n;
ll sol;
int a[300010];
int xr[1100000][2];

int main(){
	scanf("%d",&n);
	int val=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		val^=a[i];
		if(val==0 && i%2==0){
			sol++;
		}
		sol+=xr[val][i%2];
		xr[val][i%2]++;
	}	
	printf("%lld\n",sol);
	return 0;
}