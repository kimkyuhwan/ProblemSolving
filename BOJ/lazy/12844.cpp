#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, q;
int t, a, b, c;
int arr[500010];
struct treeNode{
	int value, lazy;
};
treeNode idxtree[4000010];
void lazyUpdate(int node,int left,int right){
	if(!idxtree[node].lazy) return;
	int cnt=right-left+1;
	if(cnt%2==1)
		idxtree[node].value^=idxtree[node].lazy;

	if(left!=right){
		idxtree[node*2].lazy^=idxtree[node].lazy;
		idxtree[node*2+1].lazy^=idxtree[node].lazy;
	}
	idxtree[node].lazy=0;
}

int getXor(int node,int start,int end,int left,int right){
	lazyUpdate(node,start,end);
	if(left>end || right<start) return 0;
	if(left<=start && end<=right){
		return idxtree[node].value;
	}
	int mid=(start+end)/2;
	return getXor(node*2,start,mid,left,right)^getXor(node*2+1,mid+1,end,left,right);
}


void update(int node,int start,int end,int left,int right,int value){
	lazyUpdate(node,start,end);
	if(left>end || right<start) return;
	if(left<=start && end<=right){
		int cnt = end-start+1;
		if(cnt%2==1){
			idxtree[node].value^=value;
		}
		if(start!=end){
			idxtree[node*2].lazy^=value;
			idxtree[node*2+1].lazy^=value;
		}
		return;
	} // {0,2} , {3,4}
	int mid=(start+end)/2;
	update(node*2,start,mid,left,right,value);
	update(node*2+1,mid+1,end,left,right,value);
	idxtree[node].value=idxtree[node*2].value^idxtree[node*2+1].value;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		update(1, 0, n-1, i, i, arr[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&t);
		if(t==1){ // [a , b] ^c
			scanf("%d %d %d",&a,&b,&c);
			update(1,0,n-1,min(a,b),max(a,b),c);
		}
		else if(t==2){
			scanf("%d %d",&a,&b);
			printf("%d\n",getXor(1,0,n-1,min(a,b),max(a,b)));
		}
	}

}