#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
int c,s,r;
int o,d,n;

struct treeNode{
	ll value,lazy;
};
struct treeNode idxtree[300010];


void update(int node,int start,int end,int left,int right,ll value){
	if(idxtree[node].lazy!=0){
		idxtree[node].value+=idxtree[node].lazy;
		if(start!=end){
			idxtree[node*2].lazy+=idxtree[node].lazy;
			idxtree[node*2+1].lazy+=idxtree[node].lazy;
		}
		idxtree[node].lazy=0;
	}

	if(right < start || left > end) return;

	if(left<=start && right>=end) {
		idxtree[node].value+=value;
		if(start!=end){
			idxtree[node*2].lazy+=value;
			idxtree[node*2+1].lazy+=value;
		}
		return;
	}
	int mid=(start+end)/2;
	update(node*2,start,mid,left,right,value);
	update(node*2+1,mid+1,end,left,right,value);
	idxtree[node].value = max(idxtree[node*2].value,idxtree[node*2+1].value);

}


ll getMax(int node, int start, int end, int left, int right){
	if(idxtree[node].lazy!=0){
		idxtree[node].value+=idxtree[node].lazy;
		if(start!=end){
			idxtree[node*2].lazy+=idxtree[node].lazy;
			idxtree[node*2+1].lazy+=idxtree[node].lazy;
		}
		idxtree[node].lazy=0;
	}
	if(left>end || right<start) return 0;
	if(left<=start && right>=end ) return idxtree[node].value;
	int mid=(start+end)/2;
	return max(getMax(node*2,start,mid,left,right),getMax(node*2+1,mid+1,end,left,right));
}



int main(){
	memset(idxtree,0,sizeof(idxtree));
	scanf("%d %d %d",&c,&s,&r);
	for(int i=0;i<r;i++){
		scanf("%d %d %d",&o,&d,&n);
		ll maxx = getMax(1,1,c,o,d-1);
		if(maxx+n>s){
			puts("N");
		}
		else{
			puts("T");
			update(1,1,c,o,d-1,n);
		}
	}
	return 0;
}