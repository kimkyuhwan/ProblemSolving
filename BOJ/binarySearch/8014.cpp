#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;
ll sum, sol;
int arr[50010];
ll psum[50010];
ll getDistance(int a,int b,int type){
	if(a>b) swap(a,b);
	ll dist=psum[b]-psum[a];
	if(type==0)	return dist;
	return sum-dist;
}
ll solution(ll val){
	return min(val,sum-val);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
		psum[i]=psum[i-1]+arr[i];
	}
	for(int t=0;t<2;t++){
		for(int i=1;i<=n;i++){
			int l=0, r=n-1;
			while(l<=r){
				int mid=(l+r)/2;
				int next = (i+mid)%n;
				if(next==0) next=n;
				ll dist=getDistance(i,next,t);
				sol=max(sol,solution(dist));
				if(dist < sum/2){
					l = mid+1;
				}
				else{
					r = mid-1;
				}
			}
		}
	}
	printf("%lld\n",sol);
}